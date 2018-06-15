#pragma once

struct CommentModel
{
	int ID;
	int status;			// 0审核中(默认) 1.通过 2.作废（删除）
	int filmID;			//关联电影主键
	int UserID;			//关联用户主键
	double scores;		//评分

	int userAgeGroup;	//用户信息三连！
	int userIntreset;
	int userJob;

	string content;		//评论内容
};


class Option
{
public:
	friend class Recommend;
	Option();
	~Option();

	//===========用户权限=============
	//bool make_com(int fid, int uid, string content, double score);
	//bool queryMyCom(int uid);
	//bool changeCom(int uid);//管理员也可改用户评论

	//===========管理员权限===========
	bool passComByID(int id);
	bool delComByID(int id);


	//===========增删改查=============
	CommentModel initDeafultCom(int fid, int uid, double score, int ag, int intre, int job, string content);
	bool _insertCom(CommentModel&);
	//根据id查询评论
	bool queryComByID(int cid,CommentModel*&);
	bool queryComByID_with_del(int cid, CommentModel*&);
	//根据用用户id或电影id查询所有评论
	bool queryComByUserID(int uid, vector<CommentModel>&);
	bool queryComByFilmID(int fid, vector<CommentModel>&);



	//查询用户信息三连的所有评论
	bool _queryComByUserIntrest(int interest,vector<CommentModel>&);
	bool _queryComByUserAgeGroup(int group, vector<CommentModel>&);
	bool _queryComByUserJob(int job, vector<CommentModel>&);

	//返回所有排名
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

