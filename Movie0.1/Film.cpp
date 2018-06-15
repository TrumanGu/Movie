#include "stdafx.h"
#include "Film.h"


Film::Film()
{

	ifstream fs("film.txt");
	while (!fs.eof())
	{
		FilmModel film;
		fs >> film.ID >> film.isDeleted >> film.filmName >>
			film.stars >> film.filmDirector >> film.mainActor >>
			film.produceCO >> film.year >> film.classifyByType >>
			film.classifyByCountry;
		if (film.filmName != "") {
			insertFilm(film);
		}
	}

	fs.close();
	
}


Film::~Film()
{
	ofstream of("film.txt",ios::in|ios::out);
	for (auto it= filmList.begin(); it != filmList.end(); it++)
	{
		if (it->filmName != "") {
			of << it->ID << " " << it->isDeleted << " " << it->filmName << " " << it->stars << " " << it->filmDirector << " " << it->mainActor << " " << it->produceCO << " " << it->year << " " << it->classifyByType << " " << it->classifyByCountry << " " << endl;
		}
	}
}




int Film::insertFilm(FilmModel& film){
	film.ID = this->filmNumber++;
	this->filmList.push_back(film);
	return 1;
}

FilmModel Film::initDefaultFilm(string filmName,  string filmDirector, string mainActor, string produceCO, int year, int classifyByType, int classifyByCountry)
{	
	return{ -1,0,filmName,0,filmDirector,
	mainActor,produceCO,year,classifyByType,classifyByCountry};
}

bool Film::queryFilmByID(int id, FilmModel* &p)
{
	for (auto i = this->filmList.begin(); i != filmList.end(); i++) {
		if (id == i->ID && !(i->isDeleted)) {
			p = &*i;
			return true;
		}
	}
	p = nullptr;
	return false;
}

bool Film::queryFilmByID_with_deleted(int id, FilmModel *&p)
{

	for (auto i = this->filmList.begin(); i != filmList.end(); i++) {
		if (id == i->ID) {
			p = &*i;
			return true;
		}
	}
	p->ID = -1;
	return false;
}

bool Film::queryFilmByName(string name, vector<FilmModel>& vec)
{
	for (auto i : filmList) {
		if (i.filmName == name && !(i.isDeleted)) {
			vec.push_back(i);
		}
	}
	if (vec.size() == 0) return false;
	return true;
}

bool Film::queryFilmByDirector(string dir, vector<FilmModel>& vec)
{
	for (auto i : filmList) {
		if (i.filmDirector == dir && !(i.isDeleted)) {
			vec.push_back(i);
		}
	}
	if (vec.size() == 0) return false;
	return true;
}

bool Film::queryFilmByActor(string actor, vector<FilmModel> &vec)
{

	for (auto i : filmList) {
		if (i.mainActor == actor && !(i.isDeleted)) {
			vec.push_back(i);
		}
	}
	if (vec.size() == 0) return false;
	return true;
}

bool Film::queryFilmByYear(int ya,int yb ,vector<FilmModel>& vec)
{

	for (auto i : filmList) {
		if (i.year>=ya && i.year<= yb && !(i.isDeleted)) {
			vec.push_back(i);
		}
	}
	if (vec.size() == 0) return false;
	return true;
}

bool Film::delFilm(int id)
{
	FilmModel *p = nullptr;
	if (queryFilmByID(id, p)) {
		p->isDeleted = 1;
		return true;
	}
	else cout << "É¾³ýÊ§°Ü£¡\n";

	return false;
}



