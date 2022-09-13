#pragma once
#include "User.h"
#include "Status.h"
#include "Utility.h"
#include <Windows.h>

class Process
{
public:
	static void login(User&, vector<User>);
	static void userMenu(User);
	static void adminMenuAddUser(vector<User>&);
	static void adminMenuDeleteUser(vector<User>&);
	static void adminMenuChangePres(User& U);
	static void adminMenuChangeUser(vector<User>&, string);
	static void adminMenu(User, vector<User>&);
	static void mainMenu();
};

