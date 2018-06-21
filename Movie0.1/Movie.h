#pragma once
class Movie
{
public:
	Movie();
	~Movie();

	void runMovie();
	//int getCookie();


	void registView(int&);
	void loginView(int&);
private:
	User userDB;
	Film filmDB;
	Option optionDB;
};

