#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{

}


Movie::~Movie()
{

}

void Movie::runMovie()
{
	int cookie = -1;
	while (cookie == -1) {
		cout << "��������ʲô��Ҫ?\n";
		cout << "1.ע�� 2.��½\n";
		int choice;
		cin >> choice;
		if (choice == 1) registView(cookie);
		else if (choice == 2) loginView(cookie);
	}
}



void Movie::registView(int &cookie)
{
	cout << "������������䡢�˻���������\n";
	string email, name, pwd;
	cin >> email >> name >> pwd;
	if(userDB.regist(email, name, pwd, cookie)){
		cout << "ע��ɹ���\n";
	}else {
		cout << "ע��ʧ�ܣ�\n";
	}
}

void Movie::loginView(int &cookie)
{
	cout << "������������䡢����\n";
	string email, pwd;
	cin >> email >> pwd;
	if (userDB.login(email, pwd, cookie)) {
		cout << "��½�ɹ���\n";
	}
	else {
		cout << "��½ʧ�ܣ�\n";
	}
}

