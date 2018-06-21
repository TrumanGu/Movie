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
		cout << "ÇëÎÊÄúÓÐÊ²Ã´ÐèÒª?\n";
		cout << "1.×¢²á 2.µÇÂ½\n";
		int choice;
		cin >> choice;
		if (choice == 1) registView(cookie);
		else if (choice == 2) loginView(cookie);
	}
}



void Movie::registView(int &cookie)
{
	cout << "ÇëÊäÈëµç×ÓÓÊÏä¡¢ÕË»§Ãû¡¢ÃÜÂë\n";
	string email, name, pwd;
	cin >> email >> name >> pwd;
	if(userDB.regist(email, name, pwd, cookie)){
		cout << "×¢²á³É¹¦£¡\n";
	}else {
		cout << "×¢²áÊ§°Ü£¡\n";
	}
}

void Movie::loginView(int &cookie)
{
	cout << "ÇëÊäÈëµç×ÓÓÊÏä¡¢ÃÜÂë\n";
	string email, pwd;
	cin >> email >> pwd;
	if (userDB.login(email, pwd, cookie)) {
		cout << "µÇÂ½³É¹¦£¡\n";
	}
	else {
		cout << "µÇÂ½Ê§°Ü£¡\n";
	}
}

