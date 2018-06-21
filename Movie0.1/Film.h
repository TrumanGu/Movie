#pragma once


struct FilmModel
{	
	int ID;
	int isDeleted;
	string filmName;
	double stars;
	string filmDirector;
	string mainActor;
	string produceCO;
	int year;
	int classifyByType;//6.default = -1；	1=科幻 2=爱情 3=喜剧 4=恐怖 5=历史 6=武侠
	int classifyByCountry;//7.default = -1； 1=中国、2=美国、3=日本、4=英国、5=印度、6=俄罗斯、7=德国、8=韩国
};

	/*

		TODO:模糊查询
		
	*/
class Film
{
public:
	Film();
	~Film();
	friend class Movie;
	
		//=================================用户权限==================================
	//根据片名查影片
	bool queryFilmByName(string,vector<FilmModel>&);
	
	//根据导演查影片
	bool queryFilmByDirector(string, vector<FilmModel>&);
	
	
	//根据演员查影片
	bool queryFilmByActor(string,vector<FilmModel>&);

	
	//输入两个年份 拿到年份之间的所有影片
	bool queryFilmByYear(int,int, vector<FilmModel>&);


	//=================================管理员权限==================================
	//根据id查找film 传入一个结构体指针 
	bool queryFilmByID(int, FilmModel*&);			//不包括已删除
	bool queryFilmByID_with_deleted(int, FilmModel*&);//包括已删除
	//根据id删除电影
	bool delFilm(int);

	//数据库插入一个film对象(id内置自增)
	int insertFilm(FilmModel&);

	//返回一个 id=-1的零时film对象
	FilmModel initDefaultFilm(string, string, string, string, int, int, int);

	int getfilmNumber() { return this->filmNumber; }


	vector<FilmModel>& getFilmList() { return this->filmList;}

private:
	int filmNumber = 0;
	
	vector<FilmModel> filmList;
};

