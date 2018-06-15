#pragma once

struct CommentModel
{
	int ID;
	int status;			// 0�����(Ĭ��) 1.ͨ�� 2.���ϣ�ɾ����
	int filmID;			//������Ӱ����
	int UserID;			//�����û�����
	double scores;		//����

	int userAgeGroup;	//�û���Ϣ������
	int userIntreset;
	int userJob;

	string content;		//��������
};


class Option
{
public:
	friend class Recommend;
	Option();
	~Option();

	//===========�û�Ȩ��=============
	//bool make_com(int fid, int uid, string content, double score);
	//bool queryMyCom(int uid);
	//bool changeCom(int uid);//����ԱҲ�ɸ��û�����

	//===========����ԱȨ��===========
	bool passComByID(int id);
	bool delComByID(int id);


	//===========��ɾ�Ĳ�=============
	CommentModel initDeafultCom(int fid, int uid, double score, int ag, int intre, int job, string content);
	bool _insertCom(CommentModel&);
	//����id��ѯ����
	bool queryComByID(int cid,CommentModel*&);
	bool queryComByID_with_del(int cid, CommentModel*&);
	//�������û�id���Ӱid��ѯ��������
	bool queryComByUserID(int uid, vector<CommentModel>&);
	bool queryComByFilmID(int fid, vector<CommentModel>&);



	//��ѯ�û���Ϣ��������������
	bool _queryComByUserIntrest(int interest,vector<CommentModel>&);
	bool _queryComByUserAgeGroup(int group, vector<CommentModel>&);
	bool _queryComByUserJob(int job, vector<CommentModel>&);

	//������������
	/*
	bool queryRank(vector<FilmModel>&);
	bool queryInterestRank(int interest, vector<FilmModel>&);
	bool queryJobRank(int jon, vector<FilmModel>&);
	bool queryAgeGroupRank(int ageGroup, vector<FilmModel>&);
	*/


private:
	vector<CommentModel> commentList;
	int commentNumber = 0;

};

