#pragma once
#include "User.h"
#include <fstream>
#include <vector>
#include <sstream>
class Utility
{
public:
	static void addUserToFile(User);
	static void addAdminToFile(User);
	static void addListUserToFile(vector<User>);
	static void printUser(User);
	static void takeUserFromFile(vector<User>&);
	static void deleteUser(vector<User>&);
	static void addMedicineToFile(vector<Medicine>, string);
	static void addPresToFile(User);
	static void deletePres(User);
	static void printMed(vector<Medicine>);
	static void printPres(User);
	static void takePresFromFile(User&);
	static void userMess(string);
	static void adminMess(string);
	static void readMess(string, bool);
	static bool checkExistAdmin(vector<User>);
};

