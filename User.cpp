#include "User.h"

User::User()
{
	this->_id = "0";
	this->_pass = "0";
	this->_name = "None";
	this->_phoneNumber = "None";
	this->_admin = false;
}

User::User(string id, string pass, string name, string phoneNumber, bool admin)
{
	this->_id = id;
	this->_pass = pass;
	this->_name = name;
	this->_phoneNumber = phoneNumber;
	this->_admin = admin;
}

User::~User()
{
}

string User::id()
{
	return this->_id;
}

string User::pass()
{
	return this->_pass;
}

string User::name()
{
	return this->_name;
}

string User::phoneNumber()
{
	return this->_phoneNumber;
}

bool User::checkAdmin()
{
	return this->_admin;
}

void User::setID(string id)
{
	this->_id = id;
}

void User::setPass(string pass)
{
	this->_pass = pass;
}

void User::setName(string name)
{
	this->_name = name;
}

void User::setPhoneNumber(string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void User::setAdmin(bool admin)
{
	this->_admin = admin;
}

void User::addUser()
{
	cout << "Nhap id: " << endl;
	getline(cin, this->_id);
	cout << "Nhap pass: " << endl;
	getline(cin, this->_pass);
	cout << "Nhap ten: " << endl;
	getline(cin, this->_name);
	cout << "Nhap sdt: " << endl;
	getline(cin, this->_phoneNumber);
	this->_admin = false;
}

void User::addAdmin()
{
	cout << "Nhap id: " << endl;
	getline(cin, this->_id);
	cout << "Nhap pass: " << endl;
	getline(cin, this->_pass);
	cout << "Nhap ten: " << endl;
	getline(cin, this->_name);
	cout << "Nhap sdt: " << endl;
	getline(cin, this->_phoneNumber);
	this->_admin = true;
}

void User::changeUser()
{
	int command;
	cout << "1. Doi id" << endl;
	cout << "2. Doi pass" << endl;
	cout << "3. Doi ten" << endl;
	cout << "4. Doi pass" << endl;
	cout << "5 Thoat" << endl;
	cin >> command;
	cin.ignore();
	if (command == 1) {
		cout << "Nhap ID moi" << endl;
		getline(cin, this->_id);
	}
	else if (command == 2) {
		cout << "Nhap pass moi" << endl;
		getline(cin, this->_pass);
	}
	else if (command == 3) {
		cout << "Nhap ten moi" << endl;
		getline(cin, this->_name);
	}
	else if (command == 4) {
		cout << "Nhap so dien thoai moi" << endl;
		getline(cin, this->_phoneNumber);
	}
	else if (command == 5) {
		system("cls");
		return;
	}
	else {
		system("cls");
		changeUser();
	}
	system("cls");
}
