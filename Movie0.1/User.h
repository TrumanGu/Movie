#pragma once
struct UserModel
{
	int ID;
	int isDeleted;		//Ĭ�� 0
	int level;			//0.����Ա 1.��ͨ�û� 2.vip		Ĭ��Ϊ1
	string name;
	string pwd;
	string email;
	int warTime;		//Ĭ��Ϊ0; warTime=3ɾ���û�
	//===========�����Ƽ�=======
	int job;			//ְҵ 0.���� 1.ѧ�� 2.������Ա 3.������Ա 4.��ҵ����ҵ 5.������ҵ 6.����
	int ageGroup;		//1.60��  2.70�� 3.80��....6.10��	Ĭ��Ϊ0
	int intreset;		//��Ӧ��Ӱ����classifyByType Ĭ��Ϊ0
};

class User
{
public:
	friend class Recommend;
	//==========��ͨ�û�==============
	bool login(string email, string pwd, int& cookie);


	bool regist(string email, string name, string pwd, int& cookie);


	//==========vipȨ��===============
	//�Բ���û��vip
	
	//==========����ԱȨ��============
	bool warning(int id);
	bool changeUserLevel(int id, int level);
	
	//===========��������============
	bool queryUserByID(int, UserModel*&);
	bool quertUserByID_with_del(int, UserModel*&);
	bool queryUserByEmail_pwd(string name, string pwd, vector < UserModel>&);
	bool delUser(int id);

	//��һ���û�ģ�Ͳ������ݿ⣨id������
	int _insertUser(UserModel&);
	//�õ����ݳ�ʼ��һ������Ĭ��ֵ���û�ģ�ͣ���������ע�ᣩ
	UserModel initDefaultUser(string name,string pwd,string email);

	User();
	~User();
private:
	int userNumber = 0;
	vector<UserModel> userList;
};

