#include "Status.h"

Status::Status()
{
	this->_weight =	"0";
	this->_height = "0";
	this->_bloodPressure = "0/0";
	this->_gender = "None";
}

Status::Status(string weight, string height, string bloodPressure, string gender)
{
	this->_weight = weight;
	this->_height = height;
	this->_bloodPressure = bloodPressure;
	this->_gender = gender;
}

Status::~Status()
{
}

string Status::weight()
{
	return this->_weight;
}

string Status::height()
{
	return this->_height;
}

string Status::bloodPressure()
{
	return this->_bloodPressure;
}

string Status::gender()
{
	return this->_gender;
}

void Status::setWeight(string weight)
{
	this->_weight = weight;
}

void Status::setHeight(string height)
{
	this->_height = height;
}

void Status::setBloodPressure(string bloodPressure)
{
	this->_bloodPressure = bloodPressure;
}

void Status::setGender(string gender)
{
	this->_gender = gender;
}

void Status::addStatus()
{
	cout << "Nhap chieu cao: " << endl;
	getline(cin, this->_height);
	cout << "Nhap can nang: " << endl;
	getline(cin, this->_weight);
	cout << "Nhap huyet ap: " << endl;
	getline(cin, this->_bloodPressure);
	cout << "Nhap gioi tinh: " << endl;
	getline(cin, this->_gender);
}

void Status::changeStatus()
{
	int command;
	cout << "1. Doi chieu cao" << endl;
	cout << "2. Doi can nang" << endl;
	cout << "3. Doi huyet ap" << endl;
	cout << "4. Doi gioi tinh" << endl;
	cout << "5 Thoat" << endl;
	cin >> command;
	cin.ignore();
	if (command == 1) {
		cout << "Nhap chieu cao moi" << endl;
		getline(cin, this->_height);
	}
	else if (command == 2) {
		cout << "Nhap can nang moi" << endl;
		getline(cin, this->_weight);
	}
	else if (command == 3) {
		cout << "Nhap huyet ap moi" << endl;
		getline(cin, this->_bloodPressure);
	}
	else if (command == 4) {
		cout << "Nhap gioi tinh moi" << endl;
		getline(cin, this->_gender);
	}
	else if (command == 5) {
		system("cls");
		return;
	}
	else {
		system("cls");
		changeStatus();
	}
}
