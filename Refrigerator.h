#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H
#include <string>
using namespace std;



/*Створити клас “холодильна камера” котрий містить поля :
-фірма - виробник
- Загальний об'єм, л
- Вага(кг)
- споживана потужність(Ватт)*/
class Refrigerator
{
	private:
		string firmManufacturer;
		double totalVolume;
		double weight;
		double power;
	public:
		void setFirmManufacturer(string firmManufacturer);
		string getFirmManufacturer() const;
		void setTotalVolume(double totalVolume);
		double getTotalVolume() const;
		void setWeight(double weight);
		double getWeight() const;
		void setPower(double power);
		double getPower() const;
		Refrigerator(string firmManufacturer, double totalVolume,
					double weight, double power);
		Refrigerator();
		~Refrigerator();
};
#endif //!REFRIGERATOR_H
