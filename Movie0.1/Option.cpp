#include "stdafx.h"
#include "Option.h"


Option::Option()
{
	ifstream fs("comments.txt", ios::in);
	while (!fs.eof())
	{
		CommentModel com;
		fs >> com.ID >> com.status >> com.filmID
			>> com.UserID >> com.scores >> com.userAgeGroup
			>> com.userIntreset >> com.userJob >> com.content;
		_insertCom(com);
	}
	fs.close();
}

Option::~Option()
{
	ofstream of;
	of.open("comments.txt", ios::trunc | ios::_Nocreate | ios::out);
	for (auto com = commentList.begin(); com != commentList.end(); com++) {
		of<<com->ID << " " << com->status << " " << com->filmID
			<< " " << com->UserID << " " << com->scores << " " << com->userAgeGroup
			<< " " << com->userIntreset << " " << com->userJob << " " << com->content;

	}
	of.close();
}

bool Option::passComByID(int id)
{
	CommentModel* p;
	if (queryComByID(id, p)) {
		p->status = 1;
		return true;
	}
	return false;
}

bool Option::delComByID(int id)
{
	CommentModel* p;
	if (queryComByID(id, p)) {
		p->status = 2;
		return true;
	}
	return false;
}

CommentModel Option::initDeafultCom(int fid, int uid, double score,int ag,int intre,int job,string content)
{
	return {-1,0,fid,uid,score,ag,intre,job,content};
}

bool Option::_insertCom(CommentModel &com)
{
	if (com.content == "") return false;
	com.ID = commentNumber++;
	commentList.push_back(com);
}

bool Option::queryComByID(int cid, CommentModel *&p)
{
	for (auto &com : commentList) {
		if (com.ID == cid && com.status != 2) {
			p = &com;
			return true;
		}
	}
	
	return false;
}

bool Option::queryComByID_with_del(int cid, CommentModel *&p)
{
	for (auto &com : commentList) {
		if (com.ID == cid) {
			p = &com;
			return true;
		}
	}

	return false;
}

bool Option::queryComByUserID(int uid, vector<CommentModel>& vec)
{
	for (auto com : commentList) {
		if (com.UserID == uid) {
			vec.push_back(com);
		}
	}
	if (vec.size() == 0) return false;
	return true;
}

bool Option::queryComByFilmID(int fid, vector<CommentModel>& vec)
{
	for (auto com : commentList) {
		if (com.filmID == fid) {
			vec.push_back(com);
		}
	}
	if (vec.size() == 0) return false;
	return true;
}

bool Option::_queryComByUserIntrest(int interest, vector<CommentModel>& vec)
{
	for (auto com : commentList) {
		if (com.userIntreset == interest) {
			vec.push_back(com);
		}
	}
	if (vec.size() == 0) return false;
	return true;
	return false;
}

bool Option::_queryComByUserAgeGroup(int group, vector<CommentModel>& vec)
{
	for (auto com : commentList) {
		if (com.userAgeGroup == group) {
			vec.push_back(com);
		}
	}
	if (vec.size() == 0) return false;
	return true;
	return false;
}

bool Option::_queryComByUserJob(int job, vector<CommentModel>& vec)
{
	for (auto com : commentList) {
		if (com.userJob == job) {
			vec.push_back(com);
		}
	}
	if (vec.size() == 0) return false;
	return true;
	return false;
}

