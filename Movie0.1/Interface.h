#pragma once
class Interface
{
public:
	Interface();
	~Interface();
	void mainInt();//主界面
	void registerInt();//注册页面
	void loginInt();//登陆页面
	void searchFilmInt();//搜索电影页面
	void loginSuccInt();//登陆后页面
	void viewInformationInt1();//查看信息
	void changeInformationInt1();//修改信息
	void viewCommentsInt1();//查看影评(自己的
	void searchCommentsInt1();//搜索影评
	void writeCommentsInt1();//写影评

	//void managerInt();//管理员
	void viewFilmInformation();//浏览电影总体信息
	void viewInformationInt0();//查看用户信息
	void changeInformationInt0();//修改用户信息
	//void viewCommentsInt0();//查看影评
	void searchCommentsInt0();//搜索影评
	void writeCommentsInt0();//写影评


	void getRecomments(); //获取电影推荐

	void loginOut();//注销
					//void quit();//退出系统
private:
	Film film1;
	User user1;
	Option Option1;
	int ID;
};