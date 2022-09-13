#pragma once
#include <iostream>
#include <string>

using namespace std;
class Status
{
protected:
	string _weight;
	string _height;
	string _bloodPressure;
	string _gender;
public:
	Status();
	Status(string, string, string, string);
	~Status();
	string weight();
	string height();
	string bloodPressure();
	string gender();
	void setWeight(string);
	void setHeight(string);
	void setBloodPressure(string);
	void setGender(string);
	void addStatus();
	void changeStatus();
};

