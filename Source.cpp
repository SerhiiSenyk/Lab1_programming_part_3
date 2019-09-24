/*Вашим завданням є реалізувати два алгоритми сортування, вказані в таблиці.
Вхідними даними буде файл, в якому через кому будуть записані значення полів класу з таблиці

Результат має виводити :
назва алгоритму
час роботи
кількість операцій порівняння
кількість операцій обміну
Результати сортування

Кожен студент повинен мати власний код !
Код слід залити в Github до демонстрації викладачу
Проект має мати коректно налаштований.gitignore(компіляційні файли, файли налаштування  
	IDE мать бути відсутні в репозиторії)
Проект має мати налаштовані файли зборки(pom.xml) 
або зрозумілу інструкцію, як запустити код(для коду, написаного на python або с / с++)
Код має бути написаний таким чином, щоб його можна було запустити з 
консолі, без потреби встановлення IDE*/

/*Сеник Сергій
Створити клас “холодильна камера” котрий містить поля :
- фірма - виробник
- Загальний об'єм, л
- Вага(кг)
- споживана потужність(Ватт)
Реалізувати Insertion алгоритм для сортування камер за загальним обємом 
по спаданню і QuickSort для сортування за зростанням за споживаною потужністю*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "Refrigerator.h"

void quickSortRefrigeratorsByPowerByAscending(Refrigerator *, int, int);
int readWithFile(Refrigerator *refrigerators);
void printRefrigeratorsData(const Refrigerator *refrigerators, const int countRefrigerators);
void insertionSortRerigeratorByVolumeByDescending(Refrigerator *array, const int size_of_array);
using namespace std;

int g_CountComparisons = 0;
int g_CountExchanges = 0;

int main()
{
	int count_refrigerators = 100;
	time_t  time;
	Refrigerator *refrigerators = new Refrigerator[count_refrigerators];
	count_refrigerators = readWithFile(refrigerators);
	cout << "Rerigerators" << endl;
	printRefrigeratorsData(refrigerators, count_refrigerators);
	
	time = clock();
	insertionSortRerigeratorByVolumeByDescending(refrigerators, count_refrigerators);
	time = clock() - time;
	cout << "\nInsertion sort rerigerators by volume by descending" << endl;
	printRefrigeratorsData(refrigerators, count_refrigerators);
	printf("Time insertion sort = %lf s\n", (double)time / (CLOCKS_PER_SEC));
	printf("Exchanges = %d\n", g_CountExchanges);
	printf("Comparisons = %d\n", g_CountComparisons);
	g_CountComparisons = 0;
	g_CountExchanges = 0;
	time = clock();
	quickSortRefrigeratorsByPowerByAscending(refrigerators,0, count_refrigerators - 1);
	time = clock() - time;
	cout << "\nQuick sort rerigerators by power by ascending" << endl;
	printRefrigeratorsData(refrigerators, count_refrigerators);
	printf("Time quick sort = %lf s\n", (double)time / (CLOCKS_PER_SEC));
	printf("Exchanges = %d\n", g_CountExchanges);
	printf("Comparisons = %d\n", g_CountComparisons);

	delete[] refrigerators;
	system("pause");
	return 0;
}

//за спаданням
void insertionSortRerigeratorByVolumeByDescending(Refrigerator *array, const int size_of_array)
{
	Refrigerator key;
	int	i;
	for (int k = 1; k < size_of_array; ++k) {
		key = array[k];
		for (i = k - 1; key.getTotalVolume() > array[i].getTotalVolume() && i >= 0; --i) {
			array[i + 1] = array[i];
			++g_CountComparisons;
			++g_CountExchanges;
		}
		++g_CountExchanges;
		array[i + 1] = key;
	}
	return;
}

void quickSortRefrigeratorsByPowerByAscending
(Refrigerator *array, int leftIndex, int rightIndex)
{
	if (leftIndex > rightIndex)
		return;
	int  i = leftIndex;
	int  j = rightIndex;
	Refrigerator baseElement = array[leftIndex];
	do {
		while (array[i].getPower() < baseElement.getPower()) {
			++g_CountComparisons;
			++i;
		}
		while (array[j].getPower() > baseElement.getPower()) {
			++g_CountComparisons;
			--j;
		}
		if (i <= j) {
			if (i < j) {
				Refrigerator temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				++g_CountExchanges;
			}
			++i;
			--j;
		}
	} while (i <= j);
	quickSortRefrigeratorsByPowerByAscending(array, i, rightIndex);
	quickSortRefrigeratorsByPowerByAscending(array, leftIndex, j);
	return;
}

int readWithFile(Refrigerator *refrigerators) 
{
	FILE *ptrFile = fopen("text.txt", "r");
	if (ptrFile == NULL) {
		perror("Error open file <text.txt> ");
		cout << "Press any key to continue program\n";
		_getch();
		return 0;
	}
	const char *separator = ",";
	const int iCntMaxStrSymbols = 30;
	char str[iCntMaxStrSymbols];
	int i = 0;
	while (!feof(ptrFile)) {
		fgets(str, iCntMaxStrSymbols, ptrFile);
		char *token = strtok(str, separator);
		if (*token == '\n')
			token = NULL;
		if (token != NULL) {
			refrigerators[i].setFirmManufacturer(token);
			if ((token = strtok(NULL, separator)) != NULL)
				refrigerators[i].setTotalVolume(atof(token));
			if ((token = strtok(NULL, separator)) != NULL)
				refrigerators[i].setWeight(atof(token));
			if ((token = strtok(NULL, separator)) != NULL)
				refrigerators[i].setPower(atof(token));
			token = NULL;
			++i;
		}
	}
	fclose(ptrFile);
	return i;
}

void printRefrigeratorsData(const Refrigerator *refrigerators, const int countRefrigerators)
{
	printf("\t\tRefrigerators list\n");
	printf("%-5s %-20s  %-15s  %-15s  %-15s\n", "#", "Firm manufacturer", 
		"Total volume", "Weight" , "Power");
	for (int i = 0; i < countRefrigerators; ++i) {
		printf("%-5d\t", i + 1);
		cout << refrigerators[i].getFirmManufacturer() << "\t\t\t";
		printf("%-15.2lf", refrigerators[i].getTotalVolume());
		printf("%-15.2lf\t", refrigerators[i].getWeight());
		printf("%-15.2lf\n", refrigerators[i].getPower());
	}
	return;
}
