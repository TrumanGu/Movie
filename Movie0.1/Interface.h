#pragma once
class Interface
{
public:
	Interface();
	~Interface();
	void mainInt();//������
	void registerInt();//ע��ҳ��
	void loginInt();//��½ҳ��
	void searchFilmInt();//������Ӱҳ��
	void loginSuccInt();//��½��ҳ��
	void viewInformationInt1();//�鿴��Ϣ
	void changeInformationInt1();//�޸���Ϣ
	void viewCommentsInt1();//�鿴Ӱ��(�Լ���
	void searchCommentsInt1();//����Ӱ��
	void writeCommentsInt1();//дӰ��

	//void managerInt();//����Ա
	void viewFilmInformation();//�����Ӱ������Ϣ
	void viewInformationInt0();//�鿴�û���Ϣ
	void changeInformationInt0();//�޸��û���Ϣ
	//void viewCommentsInt0();//�鿴Ӱ��
	void searchCommentsInt0();//����Ӱ��
	void writeCommentsInt0();//дӰ��


	void getRecomments(); //��ȡ��Ӱ�Ƽ�

	void loginOut();//ע��
					//void quit();//�˳�ϵͳ
private:
	Film film1;
	User user1;
	Option Option1;
	int ID;
};