#pragma once
#include <iostream>
#include <string>

using namespace std;
class Medicine
{
private:
	string _nameMed;
	string _dosage;
public:
	Medicine();
	Medicine(string, string);
	~Medicine();
	string nameMed();
	string dosage();
	void setNameMed(string);
	void setDosage(string);
};

