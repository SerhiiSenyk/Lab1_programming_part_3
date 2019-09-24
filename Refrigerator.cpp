#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	firmManufacturer = "";
	totalVolume = 0.0;
	weight = 0.0;
	power = 0.0;
}

Refrigerator::Refrigerator(string firmManufacturer, double totalVolume, double weight, double power)
{
	this->firmManufacturer = firmManufacturer;
	this->totalVolume = totalVolume;
	this->weight = weight;
	this->power = power;
}

Refrigerator::~Refrigerator()
{
}

void Refrigerator::setFirmManufacturer(string firmManufacturer)
{
	this->firmManufacturer = firmManufacturer;
}

string Refrigerator::getFirmManufacturer() const
{
	return firmManufacturer;
}

void Refrigerator::setTotalVolume(double totalVolume)
{
	this->totalVolume = totalVolume;
}

double Refrigerator::getTotalVolume() const
{
	return totalVolume;
}

void Refrigerator::setWeight(double weight)
{
	this->weight = weight;
}

double Refrigerator::getWeight() const
{
	return weight;
}

void Refrigerator::setPower(double power)
{
	this->power = power;
}

double Refrigerator::getPower() const
{
	return power;
}

