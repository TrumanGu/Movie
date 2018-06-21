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
	int classifyByType;//6.default = -1��	1=�ƻ� 2=���� 3=ϲ�� 4=�ֲ� 5=��ʷ 6=����
	int classifyByCountry;//7.default = -1�� 1=�й���2=������3=�ձ���4=Ӣ����5=ӡ�ȡ�6=����˹��7=�¹���8=����
};

	/*

		TODO:ģ����ѯ
		
	*/
class Film
{
public:
	Film();
	~Film();
	friend class Movie;
	
		//=================================�û�Ȩ��==================================
	//����Ƭ����ӰƬ
	bool queryFilmByName(string,vector<FilmModel>&);
	
	//���ݵ��ݲ�ӰƬ
	bool queryFilmByDirector(string, vector<FilmModel>&);
	
	
	//������Ա��ӰƬ
	bool queryFilmByActor(string,vector<FilmModel>&);

	
	//����������� �õ����֮�������ӰƬ
	bool queryFilmByYear(int,int, vector<FilmModel>&);


	//=================================����ԱȨ��==================================
	//����id����film ����һ���ṹ��ָ�� 
	bool queryFilmByID(int, FilmModel*&);			//��������ɾ��
	bool queryFilmByID_with_deleted(int, FilmModel*&);//������ɾ��
	//����idɾ����Ӱ
	bool delFilm(int);

	//���ݿ����һ��film����(id��������)
	int insertFilm(FilmModel&);

	//����һ�� id=-1����ʱfilm����
	FilmModel initDefaultFilm(string, string, string, string, int, int, int);

	int getfilmNumber() { return this->filmNumber; }


	vector<FilmModel>& getFilmList() { return this->filmList;}

private:
	int filmNumber = 0;
	
	vector<FilmModel> filmList;
};

