#include "Process.h"

void Process::login(User& U, vector<User> vu)
{
	string id;
	string pass;
	cout << "Hay nhap id:" << endl;
	getline(cin, id);
	cout << "Hay nhap pass:" << endl;
	getline(cin, pass);
	for (int i = 0; i < vu.size(); i++) {
		if (vu.at(i).id() == id && vu.at(i).pass() == pass) {
			U = vu.at(i);
			system("cls");
			break;
		}
		if (i == vu.size() - 1) {
			cout << "Sai id hoac pass:" << endl;
			system("cls");
			login(U, vu);
		}
	}
}

void Process::userMenu(User U)
{
	system("cls");
	cout << "1. Xem chi tiet thong tin ca nhan" << endl;
	cout << "2. Xem chi tiet don thuoc" << endl;
	cout << "3. Gui tin nhan cho bac si" << endl;
	cout << "4. Doc tin nhan tu bac si" << endl;
	cout << "5. Thoat" << endl;
	int command;
	cin >> command;
	if (command == 1) {
		Utility::printUser(U);
		cout << "Bam phim bat ki de tiep tuc" << endl;
		system("pause");
		userMenu(U);
	}
	else if (command == 2) {
		Utility::printPres(U);
		cout << "Bam phim bat ki de tiep tuc" << endl;
		system("pause");
		userMenu(U);
	}
	else if (command == 3) {
		cin.ignore();
		system("cls");
		Utility::userMess(U.id());
		cout << "Bam phim bat ki de tiep tuc" << endl;
		system("pause");
		userMenu(U);
	}
	else if (command == 4) {
		system("cls");
		Utility::readMess(U.id(), false);
		cout << "Bam phim bat ki de tiep tuc" << endl;
		system("pause");
		userMenu(U);
	}
	else if (command == 5) {
		system("cls");
		return;
	}
	else {
		userMenu(U);
	}
}

void Process::adminMenuAddUser(vector<User>& VU)
{
	system("cls");
	User U;
	cout << "1. Them admin user" << endl;
	cout << "2. Them normal user" << endl;
	cout << "3. Thoat" << endl;
	int command;
	cin >> command;
	if (command == 1) {
		cin.ignore();
		U.addAdmin();
		U.addStatus();
		Utility::addAdminToFile(U);
		VU.erase(VU.begin(), VU.end());
		Utility::takeUserFromFile(VU);
		adminMenuAddUser(VU);
	}
	else if (command == 2) {
		cin.ignore();
		U.addUser();
		U.addStatus();
		Utility::addUserToFile(U);
		VU.erase(VU.begin(), VU.end());
		Utility::takeUserFromFile(VU);
		adminMenuAddUser(VU);
	}
	else if (command == 3) {
		system("cls");
		return;
	}
	else {
		adminMenuAddUser(VU);
	}
}

void Process::adminMenuDeleteUser(vector<User>& VU)
{
	system("cls");
	cout << "1. Xoa User" << endl;
	cout << "2. Thoat" << endl;
	int command;
	cin >> command;
	if (command == 1) {
		cin.ignore();
		Utility::deleteUser(VU);
		Utility::addListUserToFile(VU);
		cout << "Da xoa user" << endl;
		system("pause");
		adminMenuDeleteUser(VU);
	}
	else if (command == 2) {
		system("cls");
		return;
	}
	else {
		adminMenuDeleteUser(VU);
	}
}

void Process::adminMenuChangePres(User& U)
{
	system("cls");
	cout << "1. Them thong tin don thuoc" << endl;
	cout << "2. Sua thong tin don thuoc" << endl;
	cout << "3. Xoa thong tin don thuoc" << endl;
	cout << "4. Sua thuoc" << endl;
	cout << "5. Thoat" << endl;
	int command;
	cin >> command;
	if (command == 1) {
		cin.ignore();
		U.addPres();
		Utility::addPresToFile(U);
		adminMenuChangePres(U);
	}
	else if (command == 2) {
		cin.ignore();
		U.changePres();
		Utility::addPresToFile(U);
		adminMenuChangePres(U);
	}
	else if (command == 3) {
		remove((U.id() + "txt").c_str());
		U.setDisease("None");
		U.setExamDay("0/0/0000");
		U.setReExamDay("0/0/0000");
		U.deleteAllMed();
		cout << "Da xoa don thuoc" << endl;
		system("pause");
	}
	else if (command == 4) {
		bool repeat = true;
		cout << "1. Them thuoc" << endl;
		cout << "2. Xoa thuoc" << endl;
		cout << "3. Sua thuoc" << endl;
		int localCommand;
		cin >> localCommand;
		if (localCommand == 1) {
			cin.ignore();
			U.addMed();
			Utility::addPresToFile(U);
			adminMenuChangePres(U);
		}
		else if (localCommand == 2) {
			cin.ignore();
			cout << "Ten thuoc muon xoa" << endl;
			string delMed;
			getline(cin, delMed);
			U.deleteMed(delMed);
			Utility::addPresToFile(U);
			cout << "Da xoa thuoc" << endl;
			system("pause");
			adminMenuChangePres(U);
		}
		else if (localCommand == 3) {
			cin.ignore();
			U.changeMed();
			Utility::addPresToFile(U);
			adminMenuChangePres(U);
		}
	}
	else if (command == 5) {
		system("cls");
		return;
	}
	else
	{
		adminMenuChangePres(U);
	}
}

void Process::adminMenuChangeUser(vector<User>& VU, string ID)
{
	system("cls");
	User U;
	int pos = -1;
	for (int i = 0; i < VU.size(); i++) {
		if (ID == VU.at(i).id()) {
			U = VU.at(i);
			pos = i;
		}
	}
	if (pos == -1) {
		cout << "Khong tim thay ID nay" << endl;
		return;
	}
	cout << "1. Thay doi thong tin user" << endl;
	cout << "2. Thay doi status user" << endl;
	cout << "3. Thay doi don thuoc user" << endl;
	cout << "4. Thoat" << endl;
	int command;
	cin >> command;
	if (command == 1) {
		U.changeUser();
		VU.at(pos) = U;
	}
	else if (command == 2) {
		U.changeStatus();
		VU.at(pos) = U;
	}
	else if (command == 3) {
		adminMenuChangePres(U);
	}
	else if (command == 4) {
		system("cls");
		return;
	}
	else {
		adminMenuChangeUser(VU, U.id());
	}
}

void Process::adminMenu(User U, vector<User>& VU)
{
	cout << "1. Them user" << endl;
	cout << "2. Xoa user" << endl;
	cout << "3. Sua user" << endl;
	cout << "4. Nhan tin cho user" << endl;
	cout << "5. Doc tin nhan cua user" << endl;
	cout << "6. Thoat" << endl;
	int command;
	cin >> command;
	if (command == 1) {
		adminMenuAddUser(VU);
		adminMenu(U, VU);
	}
	else if (command == 2) {
		adminMenuDeleteUser(VU);
		adminMenu(U, VU);
	}
	else if (command == 3) {
		cin.ignore();
		cout << "Nhap ID can sua" << endl;
		string newId;
		getline(cin, newId);
		adminMenuChangeUser(VU,newId);
		adminMenu(U, VU);
	}
	else if (command == 4) {
		cin.ignore();
		cout << "Nhap id user muon gui toi:" << endl;
		string mess;
		getline(cin, mess);
		Utility::adminMess(mess);
		adminMenu(U, VU);
	}
	else if (command == 5) {
		cin.ignore();
		cout << "Nhap id user muon gui toi:" << endl;
		string mess;
		getline(cin, mess);
		Utility::readMess(mess, true);
		adminMenu(U, VU);
	}
	else if (command == 6) {
		system("cls");
		return;
	}
	else {
		adminMenu(U, VU);
	}
}

void Process::mainMenu()
{
	vector<User> VU;
	User U;
	Utility::takeUserFromFile(VU);
	if (VU.empty() || !Utility::checkExistAdmin(VU)) {
		cout << "Hay tao tai khoan admin" << endl;
		U.addAdmin();
		VU.push_back(U);
		Utility::addAdminToFile(U);
	}
	system("cls");
	login(U, VU);
	if (U.checkAdmin() == false) {
		Utility::takePresFromFile(U);
		userMenu(U);
	}
	else {
		adminMenu(U, VU);
	}
	cout << "Cam on da su dung chuong trinh, Bye bye :)" << endl;
}
