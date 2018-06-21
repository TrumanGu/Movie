#pragma once
#include "stdafx.h"
#include "Interface.h"

Interface::Interface() {
	//cout << __LINE__;
	mainInt();
}
Interface::~Interface() {
	cout << "欢迎下次使用！！！" << endl;
}
void Interface::mainInt() {
	cout << "//欢迎来到工大电影主页" << endl;
	cout << "//1.搜索电影" << endl;
	cout << "//2.登陆" << endl;
	cout << "//3.注册" << endl;
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
			cout << "//输入有误，请重新输入:" << endl;
			break;
		}
	} while (i == 1);

}
void Interface::registerInt() {
	cout << "//欢迎注册工大电影！" << endl;
	string Email;
	string pwd;
	string name;
	do {
		cout << "//请输入邮箱:" << endl;
		cin >> Email;
	} while (Email == "");
	do {
		cout << "//请输入昵称:" << endl;
		cin >> name;
	} while (name == "");
	do {
		cout << "//请输入密码:" << endl;
		cin >> pwd;
	} while (pwd == "");
	if (user1.regist(Email, name, pwd, ID))
	{
		cout << "//注册成功！" << endl;
		cout << "您的信息还不完善，无法获取我们的电影推荐服务，是否完善信息？y/n" << endl;
		char x;
		do {
			cin >> x;
			if (x != 'y'&&x != 'n')cout << "输入有误，请重新输入" << endl;
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
		cout << "//注册失败！请重新注册！" << endl;
		registerInt();
	}


}
void Interface::loginInt() {
	cout << "//欢迎登陆工大电影！" << endl;
	string Email;
	string pwd;
	do
	{
		cout << "//请输入邮箱：" << endl;
		cin >> Email;
		cout << "//请输入密码：" << endl;
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
				cout << "管理员还没写";
			}
		}
		else
		{
			cout << "//登录失败，请重新登录。" << endl;
		}
	} while (!user1.login(Email, pwd, ID));
}
void Interface::searchFilmInt() {
	cout << "//欢迎搜索电影！" << endl;
	cout << "//1.根据片名查影片。" << endl;
	cout << "//2.根据导演查影片。" << endl;
	cout << "//3.根据演员查影片。" << endl;
	cout << "//4.输入两个年份 拿到年份之间的所有影片。" << endl;
	int i, year1, year2;
	string name, Director, Actor;
	vector<FilmModel> films;
	do {
		cin >> i;
		switch (i) {
		case 1:
			do {
				cout << "//请输入片名:" << endl;
				cin >> name;
				if (name == "")cout << "//输入有误，请重新输入：" << endl;
			} while (name == "");
			if (film1.queryFilmByName(name, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//没有找到！" << endl;
			break;
		case 2:
			do {
				cout << "//请输入导演名:" << endl;
				cin >> Director;
				if (Director == "")cout << "//输入有误，请重新输入：" << endl;
			} while (Director == "");
			if (film1.queryFilmByDirector(Director, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//没有找到！" << endl;
			break;
		case 3:
			do {
				cout << "//请输入演员名:" << endl;
				cin >> Actor;
				if (Actor == "")cout << "//输入有误，请重新输入：" << endl;
			} while (Actor == "");
			if (film1.queryFilmByActor(Actor, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//没有找到！" << endl;
			break;
		case 4:
			do {
				cout << "//请输入起始年份:" << endl;
				cin >> year1;
				if (year1 >2018 || year1<1900)cout << "//年份超出电影库范围，请重新输入：" << endl;
			} while (year1 >2018 || year1<1900);
			do {
				cout << "//请输入结束年份:" << endl;
				cin >> year2;
				if (year2 >2018 || year2<1900)cout << "//年份超出电影库范围，请重新输入：" << endl;
			} while (year2 >2018 || year2<1900);
			if (film1.queryFilmByYear(year1, year2, films))
			{
				for (auto x : films)
					cout << x.filmName << " " << x.filmDirector << " " << x.year << endl;
			}
			else
				cout << "//没有找到！" << endl;
			break;
		default:
			cout << "//输入有误，请重新输入:" << endl;
			break;
		}
	} while (i < 1 || i>4);
	cout << "输入任意键返回主界面。" << endl;
	cin.get();
	cin.get();

}
void Interface::loginSuccInt() {
	UserModel *userUnit;
	user1.queryUserByID(ID, userUnit);
	int i;
	do
	{
		cout << "//欢迎" << userUnit->name << "!" << endl;

		cout << "//您是";
		if (userUnit->level == 1)
			cout << "//普通用户。" << endl;
		else if (userUnit->level == 2)
			cout << "//尊敬的VIP用户。" << endl;

		cout << "//1.查看个人信息。" << endl;
		cout << "//2.修改个人信息。" << endl;
		cout << "//3.查找电影。" << endl;
		cout << "//4.获取电影推荐" << endl;
		cout << "//5.写影评。" << endl;
		cout << "//6.查看影评。" << endl;
		cout << "//7.注销" << endl;
		cout << "//8.退出" << endl;


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
				cout << "//输入有误，请重新输入:" << endl;
				break;
			}
		} while (i < 1 || i>8);
	} while (i != 8 && i != 7);
}
void Interface::viewInformationInt1() {
	UserModel *userUnit;
	user1.queryUserByID(ID, userUnit);
	cout << "//欢迎" << userUnit->name << "!" << endl;
	cout << "//您是 ";
	if (userUnit->level == 1)
		cout << "普通用户。" << endl;
	else
		cout << "尊敬的VIP用户。" << endl;
	cout << "//您的邮箱是 " << userUnit->email << endl;
	cout << "//您的Warning Times是 " << userUnit->warTime << endl;
	cout << "//您的职业是 ";
	switch (userUnit->job)
	{
	case 0:cout << "未设置！" << endl;
		break;
	case 1:cout << "学生" << endl;
		break;
	case 2:cout << "机关人员" << endl;
		break;
	case 3:cout << "技术人员" << endl;
		break;
	case 4:cout << "商业服务员" << endl;
		break;
	case 5:cout << "生产行业" << endl;
		break;
	case 6:
		cout << "军人" << endl;
		break;
	}
	cout << "//您的年龄组是 ";
	switch (userUnit->ageGroup)
	{
	case 0:
		cout << " 未设置！" << endl;
		break;
	case 1:cout << "60后" << endl;
		break;
	case 2:cout << "70后" << endl;
		break;
	case 3:cout << "80后" << endl;
		break;
	case 4:cout << "90后" << endl;
		break;
	case 5:cout << "00后" << endl;
		break;
	case 6:cout << "10后" << endl;
		break;
	}
	cout << "//您的兴趣是 ";
	switch (userUnit->ageGroup)
	{
	case 0:
		cout << "未设置！" << endl;
		break;
	case 1:cout << "科幻" << endl;
		break;
	case 2:cout << "爱情" << endl;
		break;
	case 3:cout << "喜剧" << endl;
		break;
	case 4:cout << "恐怖" << endl;
		break;
	case 5:cout << "历史" << endl;
		break;
	case 6:cout << "武侠" << endl;
		break;
	default:
		cout << "内部存储出现错误！请联系110！！！" << endl;
		break;
	}
	cout << "输入任意键返回主界面。" << endl;
	cin.get();
	cin.get();
	loginSuccInt();
}
void Interface::changeInformationInt1() {
	cout << "//1.修改密码。" << endl;
	cout << "//2.修改昵称。" << endl;
	cout << "//3.修改职业。" << endl;
	cout << "//4.修改年龄范围。" << endl;
	cout << "//5.修改兴趣。" << endl;
	int i, newinfo; string newInfo;
	do {
		cin >> i;
		switch (i)
		{
		case 1:cout << "请输入新密码：" << endl;
			cin >> newInfo;
			if (user1.changePwd(ID, newInfo)) cout << "修改成功！\n";
			else cout << "修改失败\n";
			break;
		case 2:cout << "请输入新昵称" << endl;
			cin >> newInfo;
			if (user1.changeName(ID,newInfo)) cout << "修改成功！\n";
			else cout << "修改失败\n";
			break;
		case 3:cout << "请输入职业\n1.学生  2.机关人员  3.技术人员  4.商业服务业  5.生产行业  6.军人" << endl;

			cin >> newinfo;
			if (user1.changeJob(ID, newinfo)) cout << "修改成功！\n";
			else cout << "修改失败\n";
			break;
		case 4:cout << "请输入您的年龄范围\n1.60后   2.70后  3.80后  4.90后  5.00后  6.10后" << endl;
			cin >> newinfo;
			if (user1.changeAgeGroup(ID, newinfo)) cout << "修改成功！\n";
			else cout << "修改失败\n";
			break;
		case 5:cout << "请输入您的兴趣\n1.科幻  2.爱情  3.喜剧  4.恐怖  5.历史  6.武侠" << endl;
			cin >> newinfo;
			if (user1.changeInterset(ID, newinfo)) cout << "修改成功！\n";
			else cout << "修改失败\n";
			break;
		default:
			cout << "输入有误，请重新输入：" << endl;
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
			cout << "通过审核：" << endl;
			film1.queryFilmByID(x.filmID, film);
			cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
			cout << x.content << endl;
		}
		else if (x.status == 0)
		{
			cout << "审核中：" << endl;
			film1.queryFilmByID(x.filmID, film);
			cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
			cout << x.content << endl;
		}
	}
	cout << "//其他评论审核未通过！" << endl;
}
void Interface::searchCommentsInt1() {
	cout << "//欢迎搜索工大电影库评论内容！！！" << endl;
	cout << "//1.根据兴趣。" << endl;
	cout << "//2.根据年龄组。" << endl;
	cout << "//3.根据职业。" << endl;
	int i, x; vector<CommentModel> comments;
	FilmModel *film; UserModel *user;
	do {
		cin >> i;
		switch (i) {

		case 1:
			cout << "输入你的兴趣！" << endl;
			cout << "1=科幻 2=爱情 3=喜剧 4=恐怖 5=历史 6=武侠" << endl;
			cin >> x;
			Option1._queryComByUserIntrest(x, comments);
			for (auto x : comments)
			{
				if (x.status == 1)
				{
					cout << "通过审核：" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
				else if (x.status == 0)
				{
					cout << "审核中：" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
			}
			cout << "其他评论审核未通过！！！" << endl;
			break;
		case 2:
			cout << "输入你的年龄组！" << endl;
			cout << "1.60后  2.70后 3.80后....6.10后	默认为0" << endl;
			cin >> x;
			Option1._queryComByUserAgeGroup(x, comments);
			for (auto x : comments)
			{
				if (x.status == 1)
				{
					cout << "通过审核：" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
				else if (x.status == 0)
				{
					cout << "审核中：" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
			}
			cout << "其他评论审核未通过！！！" << endl;
			break;
		case 3:
			cout << "输入你的职业！" << endl;
			cout << "0.其他 1.学生 2.机关人员 3.技术人员 4.商业服务业 5.生产行业 6.军人" << endl;
			cin >> x;
			Option1._queryComByUserJob(x, comments);
			for (auto x : comments)
			{
				if (x.status == 1)
				{
					cout << "通过审核：" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
				else if (x.status == 0)
				{
					cout << "审核中：" << endl;
					user1.queryUserByID(x.UserID, user);
					cout << user->name << " " << user->ageGroup << endl;
					film1.queryFilmByID(x.filmID, film);
					cout << film->filmName << " " << film->filmDirector << " " << film->year << endl;
					cout << x.content << endl;
				}
			}
			cout << "其他评论审核未通过！！！" << endl;
			break;
		default:
			cout << "//输入有误，请重新输入:" << endl;
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
		cout << "//请输入片名:" << endl;
		cin >> name;
		if (name == "")cout << "//输入有误，请重新输入：" << endl;
	} while (name == "");
	if (film1.queryFilmByName(name, films))
	{
		for (auto x : films)
			fid = x.ID;
		uid = ID;
		cout << "//输入你的评分：（位于0~10，可以是小数）" << endl;
		cin >> score;
		cout << "//输入你的评论：" << endl;
		cin >> content;
		CommentModel ooo = Option1.initDeafultCom(fid, uid, score, userUnit->ageGroup, userUnit->intreset, userUnit->job, content);
		if (Option1._insertCom(ooo))cout << "评论成功上传！" << endl;
		else cout << "发生错误！" << endl;
	}
	else
		cout << "//没有找到！" << endl;


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
		cout << "您必须完善个人信息才能获得个性化的电影推荐！\n";
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

	cout << "今日推荐:\n";
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
		cout << "欢迎您！管理员" << userUnit->name << endl;
		cout << "行使您的权力：" << endl;
		cout << "1.关于用户" << endl;
		cout << "2.关于电影" << endl;
		cout << "3.关于影评" << endl;
		cout << "4.注销" << endl;
		cout << "5.退出" << endl;
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
				cout << "输入有误！请重新输入！" << endl;
			}
		} while (y < 1 || y>5);
	} while (y != 4 && y != 5);
}
*/
/*
void Interface::viewInformationInt0() {
	cout << "工大电影目前有" << user1.getuserNumber() << "位用户。" << endl;
	cout << "1.输入用户id增删改查用户信息" << endl;
	cout << "2.输入用户邮箱增删改查用户信息" << endl;
	int y;
	do {
		cin >> y;
		switch (y) {
		case 1:
			int a; cout << "输入用户ID:" << endl;
			cin >> a;
			UserModel * userUnit;
			user1.queryUserByID(a, userUnit);
			cout << "//用户 " << userUnit->name << "" << endl;
			cout << "//是 ";
			if (userUnit->level == 1)
				cout << "普通用户。" << endl;
			else
				cout << "VIP用户。" << endl;
			cout << "ID是 " << userUnit->ID << endl;
			cout << "账号状态为 " << userUnit->isDeleted << endl;
			cout << "//邮箱是 " << userUnit->email << endl;
			cout << "密码您无权查看。" << endl;
			cout << "//Warning Times是 " << userUnit->warTime << endl;
			cout << "//职业是 ";
			switch (userUnit->warTime)
			{
			case 0:cout << "未设置！" << endl;
				break;
			case 1:cout << "学生" << endl;
				break;
			case 2:cout << "机关人员" << endl;
				break;
			case 3:cout << "技术人员" << endl;
				break;
			case 4:cout << "商业服务员" << endl;
				break;
			case 5:cout << "生产行业" << endl;
				break;
			case 6:
				cout << "军人" << endl;
				break;
			}
			cout << "//年龄组是 ";
			switch (userUnit->ageGroup)
			{
			case 0:
				cout << " 未设置！" << endl;
				break;
			case 1:cout << "60后" << endl;
				break;
			case 2:cout << "70后" << endl;
				break;
			case 3:cout << "80后" << endl;
				break;
			case 4:cout << "90后" << endl;
				break;
			case 5:cout << "00后" << endl;
				break;
			case 6:cout << "10后" << endl;
				break;
			}
			cout << "//兴趣是 ";
			switch (userUnit->ageGroup)
			{
			case 0:
				cout << "未设置！" << endl;
				break;
			case 1:cout << "科幻" << endl;
				break;
			case 2:cout << "爱情" << endl;
				break;
			case 3:cout << "喜剧" << endl;
				break;
			case 4:cout << "恐怖" << endl;
				break;
			case 5:cout << "历史" << endl;
				break;
			case 6:cout << "武侠" << endl;
				break;
			default:
				cout << "内部存储出现错误！请联系顾江涛！！！" << endl;
				break;
			}

			cout << "1.Warning Times+1" << endl;
			cout << "2.修改其Level" << endl;
			cout << "3.删除该用户！！！" << endl;
			cout << "4.退出" << endl;
			int b;
			do {
				cin >> b;
				switch (b) {
				case 1:
					if (user1.warning(a))cout << "成功" << endl;
					else cout << "失败！" << endl;
					break;
				case 2:
					int c;
					cout << "输入新等级：" << endl;
					cin >> c;
					if (user1.changeUserLevel(a, c))cout << "修改成功" << endl;
					else cout << "修改失败！" << endl;
					break;
				case 3:
					if (user1.delUser(a))cout << "删除成功" << endl;
					else cout << "删除失败！" << endl;
					break;
				case 4:
					break;
				default:
					cout << "输入有误！请重新输入！" << endl;

				}
			} while (b < 1 || b>4);
			break;
		case 2:
			viewFilmInformation();
			break;

		default:
			cout << "输入有误！请重新输入！" << endl;
		}
	} while (y < 1 || y>2);

}
*/
void Interface::viewFilmInformation()
{
	cout << "工大电影目前有" << film1.getfilmNumber() << "部电影。" << endl;
	cout << "1.增加电影信息" << endl;
	cout << "2.删除电影信息" << endl;
	cout << "3.更改电影信息" << endl;
	//cout << "4.增加电影信息" << endl;

	FilmModel aaa;
	int x, y, year, classifyByType, classifyByCountry; string filmName, filmDirector, mainActor, produceco;
	do {
		cin >> y;
		switch (y) {
		case 1:
			cout << "请输入电影名称：" << endl;
			cin >> filmName;
			cout << "请输入电影导演：" << endl;
			cin >> filmDirector;
			cout << "请输入电影主要演员：" << endl;
			cin >> mainActor;
			cout << "请输入电影发行商：" << endl;
			cin >> produceco;
			cout << "请输入电影年份：" << endl;
			cin >> year;
			cout << "请输入电影类型：" << endl;
			cin >> classifyByType;
			cout << "请输入电影国籍：" << endl;
			cin >> classifyByCountry;
			aaa = film1.initDefaultFilm(filmName, filmDirector, mainActor, produceco, year, classifyByType, classifyByCountry);
			if (film1.insertFilm(aaa))cout << "加入成功！" << endl;
			else cout << "失败" << endl;
			break;
		case 2:
			cin >> x;
			if (film1.delFilm(x))cout << "删除成功" << endl;
			else cout << "失败！" << endl;
			break;

		default:
			cout << "输入有误！请重新输入！" << endl;
		}
	} while (y < 1 || y>2);

}