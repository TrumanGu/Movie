#pragma once
#include "stdafx.h"
#include "Interface.h"

Interface::Interface() {
	//cout << __LINE__;
	mainInt();
}
Interface::~Interface() {
	cout << "��ӭ�´�ʹ�ã�����" << endl;
}
void Interface::mainInt() {
	cout << "//��ӭ���������Ӱ��ҳ" << endl;
	cout << "//1.������Ӱ" << endl;
	cout << "//2.��½" << endl;
	cout << "//3.ע��" << endl;
	int i;
	do {
		cin >> i;
		switch (i) {
		case 1:
			searchFilmInt();
			mainInt();
			break;
		case 2:
			loginInt();
			break;
		case 3:
			registerInt();
			break;
		default:
			cout << "//������������������:" << endl;
			break;
		}
	} while (i == 1);

}
void Interface::registerInt() {
	cout << "//��ӭע�Ṥ���Ӱ��" << endl;
	string Email;
	string pwd;
	string name;
	do {
		cout << "//����������:" << endl;
		cin >> Email;
	} while (Email == "");
	do {
		cout << "//�������ǳ�:" << endl;
		cin >> name;
	} while (name == "");
	do {
		cout << "//����������:" << endl;
		cin >> pwd;
	} while (pwd == "");
	if (user1.regist(Email, name, pwd, ID))
	{
		cout << "//ע��ɹ���" << endl;
		cout << "������Ϣ�������ƣ��޷���ȡ���ǵĵ�Ӱ�Ƽ������Ƿ�������Ϣ��y/n" << endl;
		char x;
		do {
			cin >> x;
			if (x != 'y'&&x != 'n')cout << "������������������" << endl;
		} while (x != 'y'&&x != 'n');
		if (x == 'y') {
			//changeInformationInt1();
			loginSuccInt();
		}
		else {
			loginSuccInt();
		}
		//break;
	}
	else
	{
		cout << "//ע��ʧ�ܣ�������ע�ᣡ" << endl;
		registerInt();
	}


}
void Interface::loginInt() {
	cout << "//��ӭ��½�����Ӱ��" << endl;
	string Email;
	string pwd;
	do
	{
		cout << "//���������䣺" << endl;
		cin >> Email;
		cout << "//���������룺" << endl;
		cin >> pwd;
		if (user1.login(Email, pwd, ID))
		{
			UserModel *userUnit;
			user1.queryUserByID(ID, userUnit);
			if (ID && userUnit->level != 0)
				loginSuccInt();
			else if (ID && userUnit->level == 0)
			{
				//managerInt();
				cout << "����Ա��ûд";
			}
		}
		else
		{
			cout << "//��¼ʧ�ܣ������µ�¼��" << endl;
		}
	} while (!user1.login(Email, pwd, ID));
}
void Interface::searchFilmInt() {
	cout << "//��ӭ������Ӱ��" << endl;
	cout << "//1.����Ƭ����ӰƬ��" << endl;
	cout << "//2.���ݵ��ݲ�ӰƬ��" << endl;
	cout << "//3.������Ա��ӰƬ��" << endl;
	cout << "//4.����������� �õ����֮�������ӰƬ��" << endl;
	int i, year1, year2;
	string name, Director, Actor;
	vector<FilmModel> films;
	do {
		cin >> i;
		switch (i) {
		case 1:
			do {
				cout << "//������Ƭ��:" << endl;
				cin >> name;
				if (name == "")cout << "//�����������������룺" << endl;
			} while (name == "");
			if (film1.queryFilmByName(name, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//û���ҵ���" << endl;
			break;
		case 2:
			do {
				cout << "//�����뵼����:" << endl;
				cin >> Director;
				if (Director == "")cout << "//�����������������룺" << endl;
			} while (Director == "");
			if (film1.queryFilmByDirector(Director, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//û���ҵ���" << endl;
			break;
		case 3:
			do {
				cout << "//��������Ա��:" << endl;
				cin >> Actor;
				if (Actor == "")cout << "//�����������������룺" << endl;
			} while (Actor == "");
			if (film1.queryFilmByActor(Actor, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//û���ҵ���" << endl;
			break;
		case 4:
			do {
				cout << "//��������ʼ���:" << endl;
				cin >> year1;
				if (year1 >2018 || year1<1900)cout << "//��ݳ�����Ӱ�ⷶΧ�����������룺" << endl;
			} while (year1 >2018 || year1<1900);
			do {
				cout << "//������������:" << endl;
				cin >> year2;
				if (year2 >2018 || year2<1900)cout << "//��ݳ�����Ӱ�ⷶΧ�����������룺" << endl;
			} while (year2 >2018 || year2<1900);
			if (film1.queryFilmByYear(year1, year2, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//û���ҵ���" << endl;
			break;
		default:
			cout << "//������������������:" << endl;
			break;
		}
	} while (i < 1 || i>4);
	cout << "������������������档" << endl;
	cin.get();
	cin.get();

}
void Interface::loginSuccInt() {
	UserModel *userUnit;
	user1.queryUserByID(ID, userUnit);
	int i;
	do
	{
		cout << "//��ӭ" << userUnit->name << "!" << endl;

		cout << "//����";
		if (userUnit->level == 1)
			cout << "//��ͨ�û���" << endl;
		else if (userUnit->level == 2)
			cout << "//�𾴵�VIP�û���" << endl;

		cout << "//1.�鿴������Ϣ��" << endl;
		cout << "//2.�޸ĸ�����Ϣ��" << endl;
		cout << "//3.���ҵ�Ӱ��" << endl;
		cout << "//4.��ȡ��Ӱ�Ƽ�" << endl;
		cout << "//5.дӰ����" << endl;
		cout << "//6.�鿴Ӱ����" << endl;
		cout << "//7.ע��" << endl;
		cout << "//8.�˳�" << endl;


		do {
			cin >> i;
			switch (i) {
			case 4:
				getRecomments();
				break;
			case 2:
				changeInformationInt1();
				break;
			case 1:
				viewInformationInt1();
				break;
			case 3:
				searchFilmInt();
				break;
			case 6:
				viewCommentsInt1();
				break;
			case 5:
				writeCommentsInt1();
				break;
			case 7:
				loginOut();
				break;
			case 8:
				break;
			default:
				cout << "//������������������:" << endl;
				break;
			}
		} while (i < 1 || i>8);
	} while (i != 8 && i != 7);
}
void Interface::viewInformationInt1() {
	UserModel *userUnit;
	user1.queryUserByID(ID, userUnit);
	cout << "//��ӭ" << userUnit->name << "!" << endl;
	cout << "//���� ";
	if (userUnit->level == 1)
		cout << "��ͨ�û���" << endl;
	else
		cout << "�𾴵�VIP�û���" << endl;
	cout << "//���������� " << userUnit->email << endl;
	cout << "//����Warning Times�� " << userUnit->warTime << endl;
	cout << "//����ְҵ�� ";
	switch (userUnit->job)
	{
	case 0:cout << "δ���ã�" << endl;
		break;
	case 1:cout << "ѧ��" << endl;
		break;
	case 2:cout << "������Ա" << endl;
		break;
	case 3:cout << "������Ա" << endl;
		break;
	case 4:cout << "��ҵ����Ա" << endl;
		break;
	case 5:cout << "������ҵ" << endl;
		break;
	case 6:
		cout << "����" << endl;
		break;
	}
	cout << "//������������ ";
	switch (userUnit->ageGroup)
	{
	case 0:
		cout << " δ���ã�" << endl;
		break;
	case 1:cout << "60��" << endl;
		break;
	case 2:cout << "70��" << endl;
		break;
	case 3:cout << "80��" << endl;
		break;
	case 4:cout << "90��" << endl;
		break;
	case 5:cout << "00��" << endl;
		break;
	case 6:cout << "10��" << endl;
		break;
	}
	cout << "//������Ȥ�� ";
	switch (userUnit->ageGroup)
	{
	case 0:
		cout << "δ���ã�" << endl;
		break;
	case 1:cout << "�ƻ�" << endl;
		break;
	case 2:cout << "����" << endl;
		break;
	case 3:cout << "ϲ��" << endl;
		break;
	case 4:cout << "�ֲ�" << endl;
		break;
	case 5:cout << "��ʷ" << endl;
		break;
	case 6:cout << "����" << endl;
		break;
	default:
		cout << "�ڲ��洢���ִ�������ϵ110������" << endl;
		break;
	}
	cout << "������������������档" << endl;
	cin.get();
	cin.get();
	loginSuccInt();
}
void Interface::changeInformationInt1() {
	cout << "//1.�޸����롣" << endl;
	cout << "//2.�޸��ǳơ�" << endl;
	cout << "//3.�޸�ְҵ��" << endl;
	cout << "//4.�޸����䷶Χ��" << endl;
	cout << "//5.�޸���Ȥ��" << endl;
	int i, newinfo; string newInfo;
	do {
		cin >> i;
		switch (i)
		{
		case 1:cout << "�����������룺" << endl;
			cin >> newInfo;
			if (user1.changePwd(ID, newInfo)) cout << "�޸ĳɹ���\n";
			else cout << "�޸�ʧ��\n";
			break;
		case 2:cout << "���������ǳ�" << endl;
			cin >> newInfo;
			if (user1.changeName(ID,newInfo)) cout << "�޸ĳɹ���\n";
			else cout << "�޸�ʧ��\n";
			break;
		case 3:cout << "������ְҵ\n1.ѧ��  2.������Ա  3.������Ա  4.��ҵ����ҵ  5.������ҵ  6.����" << endl;

			cin >> newinfo;
			if (user1.changeJob(ID, newinfo)) cout << "�޸ĳɹ���\n";
			else cout << "�޸�ʧ��\n";
			break;
		case 4:cout << "�������������䷶Χ\n1.60��   2.70��  3.80��  4.90��  5.00��  6.10��" << endl;
			cin >> newinfo;
			if (user1.changeAgeGroup(ID, newinfo)) cout << "�޸ĳɹ���\n";
			else cout << "�޸�ʧ��\n";
			break;
		case 5:cout << "������������Ȥ\n1.�ƻ�  2.����  3.ϲ��  4.�ֲ�  5.��ʷ  6.����" << endl;
			cin >> newinfo;
			if (user1.changeInterset(ID, newinfo)) cout << "�޸ĳɹ���\n";
			else cout << "�޸�ʧ��\n";
			break;
		default:
			cout << "�����������������룺" << endl;
			break;
		}
	} while (i < 1 || i>6);
}
void Interface::viewCommentsInt1() {
	vector<CommentModel> comments;
	FilmModel *film;
	Option1.queryComByUserID(ID, comments);
	for (auto x : comments)
	{
		if (x.status == 1)
		{
			cout << "ͨ����ˣ�" << endl;
			film1.queryFilmByID(x.filmID, film);
			cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
			cout << x.content << endl;
		}
		else if (x.status == 0)
		{
			cout << "����У�" << endl;
			film1.queryFilmByID(x.filmID, film);
			cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
			cout << x.content << endl;
		}
	}
	cout << "//�����������δͨ����" << endl;
}
void Interface::searchCommentsInt1() {
	cout << "//��ӭ���������Ӱ���������ݣ�����" << endl;
	cout << "//1.������Ȥ��" << endl;
	cout << "//2.���������顣" << endl;
	cout << "//3.����ְҵ��" << endl;
	int i, x; vector<CommentModel> comments;
	FilmModel *film; UserModel *user;
	do {
		cin >> i;
		switch (i) {

		case 1:
			cout << "���������Ȥ��" << endl;
			cout << "1=�ƻ� 2=���� 3=ϲ�� 4=�ֲ� 5=��ʷ 6=����" << endl;
			cin >> x;
			Option1._queryComByUserIntrest(x, comments);
			for (auto x : comments)
			{
				if (x.status == 1)
				{
					cout << "ͨ����ˣ�" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
				else if (x.status == 0)
				{
					cout << "����У�" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
			}
			cout << "�����������δͨ��������" << endl;
			break;
		case 2:
			cout << "������������飡" << endl;
			cout << "1.60��  2.70�� 3.80��....6.10��	Ĭ��Ϊ0" << endl;
			cin >> x;
			Option1._queryComByUserAgeGroup(x, comments);
			for (auto x : comments)
			{
				if (x.status == 1)
				{
					cout << "ͨ����ˣ�" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
				else if (x.status == 0)
				{
					cout << "����У�" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
			}
			cout << "�����������δͨ��������" << endl;
			break;
		case 3:
			cout << "�������ְҵ��" << endl;
			cout << "0.���� 1.ѧ�� 2.������Ա 3.������Ա 4.��ҵ����ҵ 5.������ҵ 6.����" << endl;
			cin >> x;
			Option1._queryComByUserJob(x, comments);
			for (auto x : comments)
			{
				if (x.status == 1)
				{
					cout << "ͨ����ˣ�" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
				else if (x.status == 0)
				{
					cout << "����У�" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
			}
			cout << "�����������δͨ��������" << endl;
			break;
		default:
			cout << "//������������������:" << endl;
			break;
		}
	} while (i < 1 || i>3);
}
void Interface::writeCommentsInt1() {
	int fid, uid; string content, name; double score;
	vector<FilmModel> films;
	UserModel *userUnit;
	user1.queryUserByID(ID, userUnit);
	do {
		cout << "//������Ƭ��:" << endl;
		cin >> name;
		if (name == "")cout << "//�����������������룺" << endl;
	} while (name == "");
	if (film1.queryFilmByName(name, films))
	{
		for (auto x : films)
			fid = x.ID;
		uid = ID;
		cout << "//����������֣���λ��0~10��������С����" << endl;
		cin >> score;
		cout << "//����������ۣ�" << endl;
		cin >> content;
		CommentModel ooo = Option1.initDeafultCom(fid, uid, score, userUnit->ageGroup, userUnit->intreset, userUnit->job, content);
		if (Option1._insertCom(ooo))cout << "���۳ɹ��ϴ���" << endl;
		else cout << "��������" << endl;
	}
	else
		cout << "//û���ҵ���" << endl;


}
void Interface::getRecomments() {
	UserModel *p;
	if (!user1.queryUserByID(ID, p)) return;

	vector<CommentModel> wait1;
	vector<CommentModel> wait2;
	vector<CommentModel> wait3;
	Option1._queryComByUserAgeGroup(p->ageGroup, wait1);
	Option1._queryComByUserIntrest(p->intreset, wait2);
	Option1._queryComByUserJob(p->job, wait3);

	if (wait1.size() || wait2.size() || wait3.size()) {
		cout << "���������Ƹ�����Ϣ���ܻ�ø��Ի��ĵ�Ӱ�Ƽ���\n";
	}
	double shit1[250][2] = { 0 };
	double shit2[250][2] = { 0 };
	double shit3[250][2] = { 0 };

	for (auto i : wait1) {
		shit1[i.ID][0] += i.scores;
		shit1[i.ID][1] ++;
	}
	for (auto i : wait2) {
		shit2[i.ID][0] += i.scores;
		shit2[i.ID][1] ++;
	}for (auto i : wait3) {
		shit3[i.ID][0] += i.scores;
		shit3[i.ID][1] ++;
	}

	for (int i = 0; i < 250; i++) {
		shit1[i][0] = shit1[i][0] / shit1[i][1];
	}
	for (int i = 0; i < 250; i++) {
		shit2[i][0] = shit2[i][0] / shit2[i][1];
	}
	for (int i = 0; i < 250; i++) {
		shit3[i][0] = shit3[i][0] / shit3[i][1];
	}

	int rec_fid[3] = { 0 };
	double max1 = shit1[0][0];
	int m1 = 0;
	for (int i = 0; i < 250; i++) {
		if (shit1[i][0] > max1) {
			max1 = shit1[i][0];
			m1 = i;
		}
	}rec_fid[0] = m1;

	double max2 = shit2[0][0];
	int m2 = 0;
	for (int i = 0; i < 250; i++) {
		if (shit2[i][0] > max2) {
			max2 = shit2[i][0];
			m2 = i;
		}
	}rec_fid[1] = m2;

	 double max3 = shit3[0][0];
	int m3 = 0;
	for (int i = 0; i < 250; i++) {
		if (shit3[i][0] > max3) {
			max3 = shit3[i][0];
			m3 = i;
		}
	}rec_fid[2] = m3;

	cout << "�����Ƽ�:\n";
	for (int i = 0; i < 3; i++) {
		if (rec_fid[i] == 0) continue;
		FilmModel* p;
		film1.queryFilmByID(rec_fid[i], p);
		cout << p->filmName<<"\n";
	}

}
void Interface::loginOut() {
	ID = 0;
	mainInt();
}
/*
void Interface::managerInt() {

	UserModel *userUnit;
	user1.queryUserByID(ID, userUnit);

	int y;
	do {
		cout << "��ӭ��������Ա" << userUnit->name << endl;
		cout << "��ʹ����Ȩ����" << endl;
		cout << "1.�����û�" << endl;
		cout << "2.���ڵ�Ӱ" << endl;
		cout << "3.����Ӱ��" << endl;
		cout << "4.ע��" << endl;
		cout << "5.�˳�" << endl;
		do {
			cin >> y;
			switch (y) {
			case 1:
				viewInformationInt0();
				break;
			case 2:
				viewFilmInformation();
				break;
			case 3:
				//viewCommentsInt0();
				break;
			case 4:
				loginOut();
				break;
			case 5:
				break;
			default:
				cout << "�����������������룡" << endl;
			}
		} while (y < 1 || y>5);
	} while (y != 4 && y != 5);
}
*/
/*
void Interface::viewInformationInt0() {
	cout << "�����ӰĿǰ��" << user1.getuserNumber() << "λ�û���" << endl;
	cout << "1.�����û�id��ɾ�Ĳ��û���Ϣ" << endl;
	cout << "2.�����û�������ɾ�Ĳ��û���Ϣ" << endl;
	int y;
	do {
		cin >> y;
		switch (y) {
		case 1:
			int a; cout << "�����û�ID:" << endl;
			cin >> a;
			UserModel * userUnit;
			user1.queryUserByID(a, userUnit);
			cout << "//�û� " << userUnit->name << "" << endl;
			cout << "//�� ";
			if (userUnit->level == 1)
				cout << "��ͨ�û���" << endl;
			else
				cout << "VIP�û���" << endl;
			cout << "ID�� " << userUnit->ID << endl;
			cout << "�˺�״̬Ϊ " << userUnit->isDeleted << endl;
			cout << "//������ " << userUnit->email << endl;
			cout << "��������Ȩ�鿴��" << endl;
			cout << "//Warning Times�� " << userUnit->warTime << endl;
			cout << "//ְҵ�� ";
			switch (userUnit->warTime)
			{
			case 0:cout << "δ���ã�" << endl;
				break;
			case 1:cout << "ѧ��" << endl;
				break;
			case 2:cout << "������Ա" << endl;
				break;
			case 3:cout << "������Ա" << endl;
				break;
			case 4:cout << "��ҵ����Ա" << endl;
				break;
			case 5:cout << "������ҵ" << endl;
				break;
			case 6:
				cout << "����" << endl;
				break;
			}
			cout << "//�������� ";
			switch (userUnit->ageGroup)
			{
			case 0:
				cout << " δ���ã�" << endl;
				break;
			case 1:cout << "60��" << endl;
				break;
			case 2:cout << "70��" << endl;
				break;
			case 3:cout << "80��" << endl;
				break;
			case 4:cout << "90��" << endl;
				break;
			case 5:cout << "00��" << endl;
				break;
			case 6:cout << "10��" << endl;
				break;
			}
			cout << "//��Ȥ�� ";
			switch (userUnit->ageGroup)
			{
			case 0:
				cout << "δ���ã�" << endl;
				break;
			case 1:cout << "�ƻ�" << endl;
				break;
			case 2:cout << "����" << endl;
				break;
			case 3:cout << "ϲ��" << endl;
				break;
			case 4:cout << "�ֲ�" << endl;
				break;
			case 5:cout << "��ʷ" << endl;
				break;
			case 6:cout << "����" << endl;
				break;
			default:
				cout << "�ڲ��洢���ִ�������ϵ�˽��Σ�����" << endl;
				break;
			}

			cout << "1.Warning Times+1" << endl;
			cout << "2.�޸���Level" << endl;
			cout << "3.ɾ�����û�������" << endl;
			cout << "4.�˳�" << endl;
			int b;
			do {
				cin >> b;
				switch (b) {
				case 1:
					if (user1.warning(a))cout << "�ɹ�" << endl;
					else cout << "ʧ�ܣ�" << endl;
					break;
				case 2:
					int c;
					cout << "�����µȼ���" << endl;
					cin >> c;
					if (user1.changeUserLevel(a, c))cout << "�޸ĳɹ�" << endl;
					else cout << "�޸�ʧ�ܣ�" << endl;
					break;
				case 3:
					if (user1.delUser(a))cout << "ɾ���ɹ�" << endl;
					else cout << "ɾ��ʧ�ܣ�" << endl;
					break;
				case 4:
					break;
				default:
					cout << "�����������������룡" << endl;

				}
			} while (b < 1 || b>4);
			break;
		case 2:
			viewFilmInformation();
			break;

		default:
			cout << "�����������������룡" << endl;
		}
	} while (y < 1 || y>2);

}
*/
void Interface::viewFilmInformation()
{
	cout << "�����ӰĿǰ��" << film1.getfilmNumber() << "����Ӱ��" << endl;
	cout << "1.���ӵ�Ӱ��Ϣ" << endl;
	cout << "2.ɾ����Ӱ��Ϣ" << endl;
	cout << "3.���ĵ�Ӱ��Ϣ" << endl;
	//cout << "4.���ӵ�Ӱ��Ϣ" << endl;

	FilmModel aaa;
	int x, y, year, classifyByType, classifyByCountry; string filmName, filmDirector, mainActor, produceco;
	do {
		cin >> y;
		switch (y) {
		case 1:
			cout << "�������Ӱ���ƣ�" << endl;
			cin >> filmName;
			cout << "�������Ӱ���ݣ�" << endl;
			cin >> filmDirector;
			cout << "�������Ӱ��Ҫ��Ա��" << endl;
			cin >> mainActor;
			cout << "�������Ӱ�����̣�" << endl;
			cin >> produceco;
			cout << "�������Ӱ��ݣ�" << endl;
			cin >> year;
			cout << "�������Ӱ���ͣ�" << endl;
			cin >> classifyByType;
			cout << "�������Ӱ������" << endl;
			cin >> classifyByCountry;
			aaa = film1.initDefaultFilm(filmName, filmDirector, mainActor, produceco, year, classifyByType, classifyByCountry);
			if (film1.insertFilm(aaa))cout << "����ɹ���" << endl;
			else cout << "ʧ��" << endl;
			break;
		case 2:
			cin >> x;
			if (film1.delFilm(x))cout << "ɾ���ɹ�" << endl;
			else cout << "ʧ�ܣ�" << endl;
			break;

		default:
			cout << "�����������������룡" << endl;
		}
	} while (y < 1 || y>2);

}