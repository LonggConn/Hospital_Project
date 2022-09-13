#pragma once
#include "Status.h"
#include "Prescription.h"
class User : public Status,public Prescription
{
private:
	string _id;
	string _pass;
	string _name;
	string _phoneNumber;
	bool _admin;
public:
	User();
	User(string, string, string, string, bool);
	~User();
	string id();
	string pass();
	string name();
	string phoneNumber();
	bool checkAdmin();
	void setID(string);
	void setPass(string);
	void setName(string);
	void setPhoneNumber(string);
	void setAdmin(bool);
	void addUser();
	void addAdmin();
	void changeUser();
};

