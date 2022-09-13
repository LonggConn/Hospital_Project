#include "Prescription.h"

Prescription::Prescription()
{
	this->_disease = "None";
	this->_examDay = "0/0/0000";
	this->_reExamDay = "0/0/0000";
}

Prescription::Prescription(string disease, string examDay, string reExamDay)
{
	this->_disease = disease;
	this->_examDay = examDay;
	this->_reExamDay = reExamDay;
}

Prescription::~Prescription()
{
}

void Prescription::addMed()
{
	string idMed, nameMed, dosage;
	Medicine M;
	cout << "Nhap ten thuoc: " << endl;
	getline(cin, nameMed);
	cout << "Nhap so luong va lieu luong: " << endl;
	getline(cin, dosage);
	M.setNameMed(nameMed);
	M.setDosage(dosage);
	this->_med.push_back(M);
}

void Prescription::addMed(string nameMed, string dosage)
{
	Medicine M;
	M.setNameMed(nameMed);
	M.setDosage(dosage);
	this->_med.push_back(M);
}

string Prescription::disease()
{
	return this->_disease;
}

string Prescription::examDay()
{
	return this->_examDay;
}

string Prescription::reExamDay()
{
	return this->_reExamDay;
}

vector<Medicine> Prescription::med()
{
	return this->_med;
}

void Prescription::setDisease(string disease)
{
	this->_disease = disease;
}

void Prescription::setExamDay(string examDay)
{
	this->_examDay = examDay;
}

void Prescription::setReExamDay(string reExamDay)
{
	this->_reExamDay = reExamDay;
}

void Prescription::addPres()
{
	cout << "Nhap benh: " << endl;
	getline(cin, this->_disease);
	cout << "Nhap ngay kham: " << endl;
	getline(cin, this->_examDay);
	cout << "Nhap ngay tai kham: " << endl;
	getline(cin, this->_reExamDay);
}

void Prescription::changePres()
{
	int command;
	cout << "1. Doi ten benh" << endl;
	cout << "2. Doi ngay kham" << endl;
	cout << "3. Doi ngay tai kham" << endl;
	cout << "4. Thoat" << endl;
	cin >> command;
	cin.ignore();
	if (command == 1) {
		cout << "Nhap ten benh moi:" << endl;
		getline(cin, this->_disease);
	}
	else if (command == 2) {
		cout << "Nhap ngay kham moi:" << endl;
		getline(cin, this->_examDay);
	}
	else if (command == 3) {
		cout << "Nhap ngay tai kham moi" << endl;
		getline(cin, this->_reExamDay);
	}
	else if (command == 4) return;
	system("cls");
	changePres();
}

void Prescription::changeMed()
{
	string findName;
	cout << "Nhap ten thuoc muon thay doi" << endl;
	getline(cin, findName);
	int pos;
	for (int i = 0; i < this->_med.size(); i++) {
		if (this->_med.at(i).nameMed() == findName) {
			pos = i;
			break;
		}
	}
	int command;
	string newNameMed;
	string newDosage;
	cout << "1. Doi ten thuoc" << endl;
	cout << "2. Doi lieu luong" << endl;
	cout << "3. Doi ca ten thuoc va lieu luong" << endl;
	cout << "4. Thoat" << endl;
	cin >> command;
	cin.ignore();
	if (command == 1) {
		cout << "Nhap ten thuoc moi:" << endl;
		getline(cin, newNameMed);
		this->_med.at(pos).setNameMed(newNameMed);
	}
	else if (command == 2) {
		cout << "Nhap lieu luong moi:" << endl;
		getline(cin, newDosage);
		this->_med.at(pos).setDosage(newDosage);
	}
	else if (command == 3) {
		cout << "Nhap ten thuoc moi:" << endl;
		getline(cin, newNameMed);
		this->_med.at(pos).setNameMed(newNameMed);
		cout << "Nhap lieu luong moi:" << endl;
		getline(cin, newDosage);
		this->_med.at(pos).setDosage(newDosage);
	}
	else if (command == 4) {
		system("cls");
		return;
	}
	else {
		system("cls");
		changePres();
	}
}

void Prescription::deleteAllMed()
{
	this->_med.erase(this->_med.begin(), this->_med.end());
}

void Prescription::deleteMed(string nameMed)
{
	getline(cin, nameMed);
	for (int i = 0; i < this->_med.size(); i++) {
		if (nameMed == this->_med.at(i).nameMed()) {
			this->_med.erase(this->_med.begin() + i);
		}
	}
}
