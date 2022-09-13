#pragma once
#include "Medicine.h"
#include <vector>

using namespace std;
class Prescription
{
protected:
	vector<Medicine> _med;
	string _disease;
	string _examDay;
	string _reExamDay;
public:
	Prescription();
	Prescription(string, string, string);
	~Prescription();
	void addMed();
	void addMed(string, string);
	string disease();
	string examDay();
	string reExamDay();
	vector<Medicine> med();
	void setDisease(string);
	void setExamDay(string);
	void setReExamDay(string);
	void addPres();
	void changePres();
	void changeMed();
	void deleteAllMed();
	void deleteMed(string);
};