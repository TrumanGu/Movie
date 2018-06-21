#pragma once
struct UserModel
{
	int ID;
	int isDeleted;		//默认 0
	int level;			//0.管理员 1.普通用户 2.vip		默认为1
	string name;
	string pwd;
	string email;
	int warTime;		//默认为0; warTime=3删除用户
	//===========用于推荐=======
	int job;			//职业 0.其他 1.学生 2.机关人员 3.技术人员 4.商业服务业 5.生产行业 6.军人
	int ageGroup;		//1.60后  2.70后 3.80后....6.10后	默认为0
	int intreset;		//对应电影分类classifyByType 默认为0
};

class User
{
public:
	friend class Movie;
	//==========普通用户==============
	bool login(string email, string pwd, int& cookie);
	bool regist(string email, string name, string pwd, int& cookie);
	bool changePwd(int id,string pwd);
	bool changeJob(int id, int job);
	bool changeInterset(int id, int interest);
	bool changeAgeGroup(int id, int ag);
	bool changeName(int id, string name);
	//==========vip权限===============
	//对不起还没有vip
	
	//==========管理员权限============
	bool warning(int id);
	bool changeUserLevel(int id, int level);
	
	//===========公共函数============
	bool queryUserByID(int, UserModel*&);
	bool quertUserByID_with_del(int, UserModel*&);
	bool queryUserByEmail_pwd(string name, string pwd, vector < UserModel>&);
	bool delUser(int id);

	//将一个用户模型插入数据库（id自增）
	int _insertUser(UserModel&);
	//拿到数据初始化一个具有默认值的用户模型（可以用于注册）
	UserModel initDefaultUser(string name,string pwd,string email);

	int getuserNumber() { return this->userNumber; }
	vector<UserModel>& getUserList() { return this->userList; }
	User();
	~User();
private:
	int userNumber = 0;
	vector<UserModel> userList;
};

