#include "Utility.h"

void Utility::addUserToFile(User U)
{
	ofstream user("user.txt", ios::out|ios::app);
	user << U.id() << ";" << U.pass() << ";" << U.name() << ";" << U.phoneNumber() << ";" << "false" << ";" << U.height() << ";" << U.weight() << ";" << U.bloodPressure() << ";" << U.gender() << endl;
	user.close();
}

void Utility::addAdminToFile(User U)
{
	ofstream user("user.txt", ios::out | ios::app);
	user << U.id() << ";" << U.pass() << ";" << U.name() << ";" << U.phoneNumber() << ";" << "true" << endl;
	user.close();
}

void Utility::addListUserToFile(vector<User> vu)
{
	for (int i = 0; i < vu.size(); i++) {
		if (vu.at(i).checkAdmin() == true) {
			Utility::addAdminToFile(vu.at(i));
		}
		else {
			Utility::addUserToFile(vu.at(i));
		}
	}
}

void Utility::printUser(User U)
{
	cout << "ID la: " << U.id() << endl;
	cout << "Ten la: " << U.name() << endl;
	cout << "So dien thoai la: " << U.phoneNumber() << endl;
	if (U.checkAdmin()) return;
	cout << "Chieu cao la: " << U.height() << endl;
	cout << "Can nang la: " << U.weight() << endl;
	cout << "Chi so huyet ap la: " << U.bloodPressure() << endl;
	cout << "Gioi tinh: " << U.gender() << endl;
}

void Utility::takeUserFromFile(vector<User>& vu)
{
	ifstream user("user.txt", ios::in);
	if (user.fail()) {
		cout << "Khong the mo hoac khong ton tai file user" << endl;
		return;
	}
	string s;
	while (getline(user, s)) {
		User U;
		stringstream ss(s);
		string tmp;
		vector<string> tmp_User;
		while (getline(ss, tmp, ';')) {
			tmp_User.push_back(tmp);
		}
		if (tmp_User.at(4) == "false") {
			U.setHeight(tmp_User.at(5));
			U.setWeight(tmp_User.at(6));
			U.setBloodPressure(tmp_User.at(7));
			U.setGender(tmp_User.at(8));
		}
		U.setID(tmp_User.at(0));
		U.setPass(tmp_User.at(1));
		U.setName(tmp_User.at(2));
		U.setPhoneNumber(tmp_User.at(3));
		U.setAdmin("true" == tmp_User.at(4));
		vu.push_back(U);
	}
}

void Utility::deleteUser(vector<User>& vu)
{
	string delID;
	cout << "Nhap ID can xoa:" << endl;
	getline(cin, delID);
	remove("user.txt");
	for (int i = 0; i < vu.size(); i++) {
		if (vu.at(i).id() == delID) {
			vu.erase(vu.begin() + i);
		}
	}
	string delID1 = delID + ".txt";
	remove(delID1.c_str());
}

void Utility::addMedicineToFile(vector<Medicine> vm, string id)
{
	ofstream userFile((id + ".txt").c_str(), ios::out | ios::app);
	for (int i = 0; i < vm.size(); i++) {
		userFile << vm.at(i).nameMed() << ";" << vm.at(i).dosage() << endl;
	}
}

void Utility::addPresToFile(User U)
{
	ofstream presFile((U.id() + ".txt").c_str());
	presFile << U.disease() << ";" << U.examDay() << ";" << U.reExamDay() << endl;
	Utility::addMedicineToFile(U.med(), U.id());
}

void Utility::deletePres(User U)
{
	remove((U.id() + ".txt").c_str());
}

void Utility::printMed(vector<Medicine> vm)
{
	for (int i = 0; i < vm.size(); i++) {
		cout << i + 1 << "." << endl;
		cout << "Ten thuoc: " << vm.at(i).nameMed() << endl;
		cout << "Lieu luong: " << vm.at(i).dosage() << endl;
		cout << endl;
	}
}

void Utility::printPres(User U)
{
	cout << "Ten benh: " << U.disease() << endl;
	cout << "Ngay kham: " << U.examDay() << endl;
	cout << "Ngay tai kham: " << U.reExamDay() << endl;
	cout << "Don thuoc" << endl;
	Utility::printMed(U.med());
}

void Utility::takePresFromFile(User& U)
{
	ifstream pres((U.id()+".txt").c_str(), ios::in);
	if (pres.fail()) {
		cout << "Khong the mo hoac khong ton tai file thuoc" << endl;
		return;
	}
	string S_pres;
	getline(pres, S_pres);
	stringstream ss(S_pres);
	vector<string> VS_pres;
	string temp;
	while (getline(ss, temp, ';')) {
		VS_pres.push_back(temp);
	}
	U.setDisease(VS_pres.at(0));
	U.setExamDay(VS_pres.at(1));
	U.setReExamDay(VS_pres.at(2));
	string med;
	while (getline(pres, med)) {
		stringstream ss(med);
		vector<string> v_med;
		string temp;
		while (getline(ss, temp, ';')) {
			v_med.push_back(temp);
		}
		U.addMed(v_med.at(0), v_med.at(1));
	}
}

void Utility::userMess(string id)
{
	string mess;
	string fileName = "mess" + id + ".txt";
	ofstream userMess(fileName.c_str(), ios::out | ios::app);
	cout << "Hay nhap tin nhan cua ban: " << endl;
	getline(cin, mess);
	userMess << mess << endl;
	system("cls");
}

void Utility::adminMess(string id)
{
	string mess;
	string fileName = "mess" + id + "_rep.txt";
	ofstream userMess(fileName.c_str(), ios::out | ios::app);
	cout << "Hay nhap tin nhan cua ban: " << endl;
	getline(cin, mess);
	userMess << mess << endl;
	system("cls");
}

void Utility::readMess(string id, bool admin)
{
	string mess;
	string fileName;
	if (admin) {
		fileName = "mess" + id + ".txt";
	}
	else {
		fileName = "mess" + id + "_rep.txt";
	}
	ifstream userMess(fileName.c_str(), ios::in);
	if (userMess.fail()) {
		cout << "Khong the mo hoac khong ton tai file tin nhan" << endl;
		return;
	}
	while (getline(userMess, mess)) {
		cout << mess << endl;
	}
}

bool Utility::checkExistAdmin(vector<User> vu)
{
	for (int i = 0; i < vu.size(); i++) {
		if (vu.at(i).checkAdmin()) return true;
	}
	return false;
}


