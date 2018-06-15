#include "stdafx.h"
#include "User.h"


User::User()
{
	
	ifstream fs("users.txt",ios::in);
	while (!fs.eof())
	{
		UserModel user;
		fs >> user.ID >> user.isDeleted >> user.level >> user.name >> 
			user.pwd >> user.email >> user.warTime>>
			user.job >>user.ageGroup >>user.intreset;
		if (user.email != "") {
			_insertUser(user);
		}
	}
	fs.close();
}


User::~User()
{
	ofstream of;
	of.open("users.txt", ios::trunc | ios::_Nocreate | ios::out);
	for (auto user = userList.begin(); user != userList.end(); user++) {
		of << user->ID << " " << user->isDeleted << " " << user->level << " " << user->name << " " <<
			user->pwd << " " << user->email << " " << user->warTime << " " <<
			user->job << " " << user->ageGroup << " " << user->intreset << endl;
	}
	of.close();
}

bool User::login(string email,string pwd,int& cookie)
{
	cookie = -1;
	vector<UserModel> vec;
	if (queryUserByEmail_pwd(email, pwd, vec)) {
		cookie = vec[0].ID;
	}
	else {
		return false;
	}
}

bool User::regist(string email,string name, string pwd, int& cookie)
{
	vector<UserModel> vec;
	if (queryUserByEmail_pwd(email, pwd, vec)) return false;
	UserModel user = initDefaultUser(name, pwd, email);
	if (_insertUser(user)) {
		if (login(email, pwd, cookie)) return true;
		return false;
	}return false;
}

bool User::warning(int id)
{
	UserModel* p = nullptr;
	if (queryUserByID(id, p)) {
		p->warTime++;
		return true;
	}return false;
}

bool User::changeUserLevel(int id, int level)
{
	if (level < 0 || level >3) return false;
	UserModel* p = nullptr;
	if (queryUserByID(id,p)) {
		p->level = level;
		return true;
	}return false;

}

bool User::queryUserByID(int id,UserModel*& p)
{
	for (auto &user : userList) {
		if (user.ID == id && !(user.isDeleted)) {
			p = &user;
			return true;
		}
	}
	p = nullptr;
	return false;
}

bool User::quertUserByID_with_del(int id, UserModel*& p)
{
	for (auto &user : userList) {
		if (user.ID == id) {
			p = &user;
			return true;
		}
	}
	p = nullptr;
	return false;
}

bool User::queryUserByEmail_pwd(string email, string pwd, vector<UserModel>& vec)
{
	for (auto user : userList) {
		if (user.email == email && user.pwd == pwd && !(user.isDeleted)) {
			vec.push_back(user);
			return true;
		}
	}
	return false;
}

bool User::delUser(int id)
{
	UserModel* p = nullptr;
	if (queryUserByID(id, p)) {
		p->isDeleted = 1;
		return true;
	}
	return false;
}

int User::_insertUser(UserModel &user)
{
	user.ID = userNumber++;
	userList.push_back(user);
	return 1;
}

UserModel User::initDefaultUser(string name,string pwd,string email)
{
	return { -1, 0, 1, name, pwd, email, 0, 0, 0, 0};
}


