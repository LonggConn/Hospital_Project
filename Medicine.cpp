#include "Medicine.h"

Medicine::Medicine()
{
	this->_nameMed = "0";
	this->_dosage = "0";
}

Medicine::Medicine(string nameMed, string dosage)
{
	this->_nameMed = nameMed;
	this->_dosage = dosage;
}

Medicine::~Medicine()
{
}

string Medicine:: nameMed()
{
	return this->_nameMed;
}

string Medicine::dosage()
{
	return this->_dosage;
}

void Medicine::setNameMed(string nameMed)
{
	this->_nameMed = nameMed;
}

void Medicine::setDosage(string dosage)
{
	this->_dosage = dosage;
}
