/************************************************
* 2019.11.07   ����    ѧ������ϵͳ   vs2015    *
************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<io.h>
#include<direct.h>
#include<string>
int * p = NULL;     //ָ��ListShow_1()�е�num_2
char File_system[] = "C:\\Users\\FdogMain\\Desktop\\sms.ini";//ϵͳ��ʼ�������ļ�(�����û��������ļ���ַ,�Զ���Ŀ�Ŀ�ȵ�)
                                                             //�ҵ������ַ������������Ĳ���,���޸�
void ShowP();											//��ʾ�������
int ListShow_1();										//����Ϣά�� ����Ϣ���� ����Ϣͳ�� ���˳�ϵͳ
int ListShow_2();										//�ٽ���ѧ���ɼ��� �����ѧ����¼ ��ɾ��ѧ���ļ�¼ ���޸�ѧ����Ϣ �ݲ鿴��¼����Ϣ �޷����ϼ��˵�
int ListShow_3();										//�ٰ��������� �ڰ��༶���� �۷����ϼ��˵�
int ListShow_4();										//�ٳɼ�ͳ�� �ڷ����ϼ��˵�
void FoundStudent(char *File_system);					//����ѧ���ɼ���
void AddStudent(char * File_system);					//���ѧ����¼  
void DeleteStudent(char * File_system);					//ɾ��ѧ����¼  
void ChooesStudent(char * File_system);					//�޸�ѧ����Ϣ  
void ClassSeatch(char * File_system);					//���༶����	  
void NameSeatch(char * File_system);					//����������    
void NumberSum(char * File_system);						//�ɼ�ͳ��      
void ShowNew(char * File_system);						//��ʾ����ѧ������Ϣ���
void SubjectJudge(int * number);						//����û��Զ�����Ҫ���������
void Function_1(int i,char * Name);                     //���ûʲô��˵��
using namespace std;
int main(){
	const string password = "huagou"; //��ʼ�趨����
	string password_2;		          //��������
	if (IDYES == MessageBoxA(NULL, "�������������ϵͳ,������������ϵ����QQ2506897252\n(��ֻ�����λ�������)", "��ʾ", MB_YESNO));
	//����MessageBoxA�᷵��һ��ֵ���������IDYES��ִ�У�����˳�
	else exit(0); 
	for (int I_F = 3; I_F >= 1; I_F--)
	{
		getline(cin, password_2); //getline�Ǵ���string��ĺ���;
		system("cls");
		if (password == password_2)
		{
			MessageBoxA(NULL, "������ȷ", "��ʾ", MB_OK);
			break;
		}
		else if (I_F == 1 && IDOK == MessageBoxA(NULL, "�������", "��ʾ", MB_OK))
		{
			cout << "�������þ������˳�ϵͳ";
			system("pause>nul");
			exit(0);
		}//���һ�λ��Ǵ��� ֱ���˳�
		else
		{
			MessageBoxA(NULL, "�������", "��ʾ", MB_OK);
		}
	}
	if (-1 == GetPrivateProfileIntA("�Ƿ��һ�δ�", "Frist", -1, "C:\\Users\\FdogMain\\Desktop\\sms.ini"))
	{                             
		ShowP();
		MessageBoxA(NULL, "����,�������ǵ�һ��ʹ�ñ����\nϣ�����ܹ���ϸ�Ķ��������Ķ��갴������������", "��ʾ", MB_OK);
		//�ж��û��Ƿ��һ�δ򿪳��� �����һ�δ� ����������ϸ��Ϣ
		getchar();//�ȴ��û���Ӧ
	}
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//����
	while (1)
	{
		switch (ListShow_1())
		{
		case 1:
			get_1:
				ListShow_2();
				if (*p == 1)FoundStudent(File_system);
				if (*p == 2)AddStudent(File_system);
				if (*p == 3)DeleteStudent(File_system);
				if (*p == 4)ChooesStudent(File_system);
				if (*p == 5)ShowNew(File_system);
				if (*p == 6)break;
				system("cls");
				goto get_1;
				break;
		case 2:
			get_2:
				ListShow_3();
				if (*p == 1)NameSeatch(File_system);
				if (*p == 2)ClassSeatch(File_system);
				if (*p == 3)break;
				system("cls");
				goto get_2;
				break;
		case 3:
			get_3:
				ListShow_4();
				if (*p == 1)NumberSum(File_system);
				if (*p == 2)break;
				system("cls");
				goto get_3;
				break;
		default:
			exit(0);
		}
	}
	return 0;
}
void FoundStudent(char *File_system)
{
	char File_[100];								//�Զ����ļ���ַ
	char Name_[20];									//�ļ�����
	int	 number[9] = { 31,31,31,31,31,31,31,31,31 };//��Ŀѡ�� 
	int  sum = 0;									//��Ŀ�� 
	cout << "�������ļ������ַ(���� D:\\�ҵ����\\ѧ������ϵͳ  ��ַ�в�Ҫ���ڿո�)";
	cin >> File_;
	if (_access(File_, 00) == 0)
	{
		MessageBoxA(NULL, "ָ����ַ�ɹ���", "��ӭʹ��", MB_OK);
	}
	else
	{
		MessageBoxA(NULL, "�����·�������ڣ�Ϊ��������·�����������������ļ������ļ�����׺��дΪ.ini��", "��ӭʹ��", MB_OK);
		_mkdir(File_);//���·����û��ָ�����ļ���,�򴴽����ļ���
	}
	cout << "�������ļ���:";
	cin >> Name_;
	strcat_s(File_, "\\");
	strcat_s(File_, Name_);//���ļ���������·������
	system("cls");
	cout << "                     �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
	cout << "                     �U�T�T ������ �T�T ����ѧ �T�T ��Ӣ�� �T�T ������ �T�T�U\n";
	cout << "                     �U                                          �U\n";
	cout << "                     �U�T�T ����ʷ �T�T �޵��� �T�T ������ �T�T ������ �T�T�U\n";
	cout << "                     �U                                          �U\n";
	cout << "                     �U�T�T �ữѧ                                 �U\n";
	cout << "                     �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
	MessageBoxA(NULL, "��ѡ���Ŀ(ѡ��һ�ΰ�һ�λس�\n����ѡ�����ſ�Ŀ\n�������ѡ��������0)", "��ӭʹ��", MB_OK);
	ofstream fout_1(File_);		//Ĭ�ϵĵ��÷�ʽ ��ʽΪofstream fout.open(File_);
	fout_1.close();          
	ofstream fout(File_system);
	fout << "[FILE]" << endl;	//���ļ���ַ����������
	fout << "��ַ=" << File_ << endl;
	fout << "[SUBGECT]" << endl;//����Ŀ����
	for (int i = 0; i < 9; i++)
	{
		cin >> number[i];
		if (number[i] != 0)sum += 1;
		if (number[i] == 0)
		{
			number[i] = 31;
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		fout << "��Ŀ����" << i + 1 << "=" << number[i] << endl;
	}
	fout << "��Ŀ����=" << sum << endl;
	fout << "[��¼����]" << endl;
	fout << "total=0" << endl;
	fout << "[�Ƿ��һ�δ�]" << endl;
	fout << "Frist=1" << endl;
	fout << "[�Ƿ��һ�μ�¼]" << endl;
	fout << "F=0" << endl;
	fout.close();
	cout << "ѧ���ɼ����ѽ������" << endl;
	cout << "�������ѧ����Ϣ(1), ������һ���˵�(0)" << endl;
	int CinJ = 0;
	cin >> CinJ;
	if (CinJ == 1)
	{
		system("cls");
		AddStudent(File_system);
	}
 //�������������н����� �����ŷ�����һ��
}
void AddStudent(char * File_system)
{
	char * Studata = NULL;
	Studata = new char[20];	//��Ϣ
	char * NUM_1 = NULL;
	NUM_1 = new char[100];
	char File_[100];		//��ȡ�ļ���ַ
	int ReturnSu = 0;		//��ȡ��Ŀ��
	int total;				//��ȡ��¼��������
	char * total_f = NULL;
	total_f = new char[1000];
	GetPrivateProfileStringA("FILE", "��ַ", "δ֪", File_, sizeof(File_), File_system);
	ReturnSu = GetPrivateProfileIntA("SUBGECT", "��Ŀ����", -1, File_system);
	total = GetPrivateProfileIntA("��¼����", "total", -1, File_system);
	int number[9];			//���File_system�����ļ����汣��Ŀ�Ŀ
	for (int i = 0; i < 9; i++) //Ϊnumber�ṩ����
	{
		char Name[30] = "��Ŀ����";
		switch (i)
		{
		case 1:
			Function_1(i, Name);
			break;
		case 2:
			Function_1(i, Name);
			break;
		case 3:
			Function_1(i, Name);
			break;
		case 4:
			Function_1(i, Name);
			break;
		case 5:
			Function_1(i, Name);
			break;
		case 6:
			Function_1(i, Name);
			break;
		case 7:
			Function_1(i, Name);
			break;
		case 8:
			Function_1(i, Name);
			break;
		}
		char *stu_ = Name;
		number[i] = GetPrivateProfileIntA("SUBGECT", stu_, -1, File_system);
	}
	cout << "��ѡ��ÿ�Ŀ,�밴���¸�ʽ��¼ѧ����Ϣ:\n";
	SubjectJudge(number);	//��ʾ��Ҫ��������� 
	MessageBoxA(NULL, "���ϸ���������Ϣ˳������\n������ѧ������Ϣ���ٰ��س�\n�������Ϣ���ÿո����\n�������������һλѧ����Ϣ,������\"T\"����", "��ʾ", MB_OK);
	ofstream fout(File_, ios::ate | ios::app);		//��ȡ�ļ�
	for (int j = total + 1; j <= 1000; j++)
	{
		sprintf(NUM_1, "%d", j);
		if (strcmp(Studata, "T") == 0)
		{
			break;
		}
		for (int i = 1; i <= ReturnSu + 3; i++)
		{
			cin >> Studata;
			if (i == 1)
			{
				if (strcmp(Studata, "T") == 0) //�������T���˳�
				{
					break;
				}
				WritePrivateProfileStringA(NUM_1, "����", Studata, File_);
				total += 1;
				sprintf(total_f, "%d", total); //int ת �ַ���
				WritePrivateProfileStringA("��¼����", "total", total_f, File_system);
			}
			if (i == 2)
			{
				WritePrivateProfileStringA(NUM_1, "ѧ��", Studata, File_);
			}
			if (i == 3)
			{
				WritePrivateProfileStringA(NUM_1, "�༶", Studata, File_);
			}
			if (i == 4)
			{
				WritePrivateProfileStringA(NUM_1, "����", Studata, File_);
			}
			if (i == 5)
			{
				WritePrivateProfileStringA(NUM_1, "��ѧ", Studata, File_);
			}
			if (i == 6)
			{
				WritePrivateProfileStringA(NUM_1, "Ӣ��", Studata, File_);
			}
			if (i == 7)
			{
				WritePrivateProfileStringA(NUM_1, "����", Studata, File_);
			}
			if (i == 8)
			{
				WritePrivateProfileStringA(NUM_1, "��ʷ", Studata, File_);
			}
			if (i == 9)
			{
				WritePrivateProfileStringA(NUM_1, "����", Studata, File_);
			}
			if (i == 10)
			{
				WritePrivateProfileStringA(NUM_1, "����", Studata, File_);
			}
			if (i == 11)
			{
				WritePrivateProfileStringA(NUM_1, "����", Studata, File_);
			}
			if (i == 12)
			{
				WritePrivateProfileStringA(NUM_1, "��ѧ", Studata, File_);
			}
			WritePrivateProfileStringA("�Ƿ��һ�μ�¼", "F", "1", File_system);
		}
	}
	fout.close();			//�ر��ļ�
	delete[]Studata;
	delete[]NUM_1;
	delete[]total_f;
	cout << "��Ϣ��¼�����" << endl;
	cout<<"������һ���˵�(�����)"<<endl;
	int e;
	cin >> e;
}
void DeleteStudent(char * File_system)
{
	char File_[100];		//��ȡ�ļ���ַ
	int total;				//��ȡ��¼��������
	int N;					//��ȡ��Ŀ��
	int F;					//��ȡ��¼
	char CH[10];			//��ȡ���ַ�������
	int  IN_;				//��ȡ����������
	int * percase = NULL;	//��¼ɾ�����
	percase = new int[sizeof(int) * 100];
	int persum = 0;			//��¼ɾ������
	char * SuIT = NULL;
	SuIT = new char[20];
	GetPrivateProfileStringA("FILE", "��ַ", "δ֪", File_, sizeof(File_), File_system);
	total = GetPrivateProfileIntA("��¼����", "total", -1, File_system);
	N = GetPrivateProfileIntA("SUBGECT", "��Ŀ����", -1, File_system);
	F = GetPrivateProfileIntA("�Ƿ��һ�μ�¼", "F", -1, File_system);
	if (F == -1)MessageBoxA(NULL, "��û�м�¼���κ�ѧ����Ϣ,�޷�ɾ��", "��Ϣ", MB_OK);
	if (F == 0) MessageBoxA(NULL, "��û�м�¼���κ�ѧ����Ϣ,�޷�ɾ��", "��Ϣ", MB_OK);
	if (F == 1)
	{
		for (int j = 1; j <= total; j++)
		{
			int sum = 0;      //���ϸ��Ŀ
			char Delename[50] = "";
			for (int i = 1; i <= N + 3; i++)
			{
				char CH_F[10];//����ת�ַ�
				sprintf(SuIT, "%d", j);
				if (i == 1)
				{
					GetPrivateProfileStringA(SuIT, "����", "δ֪", CH, sizeof(CH), File_);
					strcat(Delename, CH);
					strcat(Delename, "  ");
				}
				if (i == 2)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "ѧ��", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
				}
				if (i == 3)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "�༶", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
				}
				if (i == 4)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)
						sum += 1;
				}
				if (i == 5)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 6)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "Ӣ��", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 7)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 8)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ʷ", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 9)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 10)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 11)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
				if (i == 12)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
					sprintf(CH_F, "%d", IN_);
					strcat(Delename, CH_F);
					strcat(Delename, "  ");
					if (IN_ <= 60)sum += 1;
				}
			}
			if (sum >= 3) //����������Ŀ�����������ӡ����ͬѧ����Ϣ
			{
				cout << Delename;
				cout << endl;
				percase[persum] = j;
				persum += 1;//ɾ������
			}
		}
	}
	if (IDYES == MessageBoxA(NULL, "�Ƿ�ɾ��\n �� \"��\"ȷ��ɾ��", "��Ϣ(��������)", MB_YESNO))
	{
		for (int j = 1; j <= persum; j++)
		{
			char LS[10];
			sprintf(LS, "%d", percase[j - 1]);
			WritePrivateProfileStringA(LS, NULL, NULL, File_);
		}
	}
	else
	{
		cout << "����ȡ��ɾ��......";
	}
	delete[]percase;
	delete[]SuIT;
	cout << "��Ϣ�Ѵ������(��������ز˵�)" << endl;
	int e;
	cin >> e;
}
void ChooesStudent(char * File_system)
{
	int Stunumer = 0;	//��ȡ��ѧ��ѧ��
	char File_[100];	//��ȡ�ļ���ַ
	char CH[10];		//��ȡ���ַ�������
	int  IN_;			//��ȡ����������
	char CH_[20];
	int total;			//��ȡ��¼��������
	int N;				//��ȡ��Ŀ��
	char * SuIT = NULL;
	SuIT = new char[20];
	int a = 0;			//������������Ϣ���û�и�ѧ����Ϣ,��aΪ0,��ʾ�Ƿ���������ٴ�����
	char CH_1[20];
	GetPrivateProfileStringA("FILE", "��ַ", "δ֪", File_, sizeof(File_), File_system);
	total = GetPrivateProfileIntA("��¼����", "total", -1, File_system);
	N = GetPrivateProfileIntA("SUBGECT", "��Ŀ����", -1, File_system);
	cout << "����ѧ���޸�ѧ����Ϣ\n";
	cin >> Stunumer;
	for (int j = 1; j <= total; j++)
	{
		sprintf(CH_1, "%d", j);
		a = GetPrivateProfileIntA(CH_1, "ѧ��", -1, File_);
		if (Stunumer == a)
		{
			for (int i = 1; i <= N + 3; i++)
			{
				sprintf(SuIT, "%d", j);
				if (i == 1)
				{
					GetPrivateProfileStringA(SuIT, "����", "error", CH, sizeof(CH), File_);
					cout << "����:";
					cout << CH << endl;
				}
				if (i == 2)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "ѧ��", -1, File_);
					cout << "ѧ��:";
					cout << IN_ << endl;
				}
				if (i == 3)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "�༶", -1, File_);
					cout << "�༶:";
					cout << IN_ << endl;
				}
				if (i == 4)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸����ĳɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "����", CH_, File_);
					}
				}
				if (i == 5)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸���ѧ�ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "��ѧ", CH_, File_);
					}
				}
				if (i == 6)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "Ӣ��", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸�Ӣ��ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "Ӣ��", CH_, File_);
					}
				}
				if (i == 7)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸����γɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "����", CH_, File_);
					}
				}
				if (i == 8)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ʷ", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸���ʷ�ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "��ʷ", CH_, File_);
					}
				}
				if (i == 9)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸ĵ���ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "����", CH_, File_);
					}
				}
				if (i == 10)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸�����ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "����", CH_, File_);
					}
				}
				if (i == 11)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸�����ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "����", CH_, File_);
					}
				}
				if (i == 12)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
					if (IDYES == MessageBoxA(NULL, "�Ƿ��޸Ļ�ѧ�ɼ�\n��  \"��\"  �޸�    ��  \"��\"  ������һ���޸�", "��Ϣ", MB_YESNO))
					{
						cin >> IN_;
						sprintf(CH_, "%d", IN_);
						WritePrivateProfileStringA(SuIT, "��ѧ", CH_, File_);
					}
				}
			}
			++a;
		}
	}
	delete[]SuIT;
	cout << "��Ϣ���޸����(��������ز˵�)" << endl;
	int e;
	cin >> e;
}
void ShowNew(char * File_system)
{
	char File_[100];	//��ȡ�ļ���ַ
	int total;			//��ȡ��¼��������
	int N;				//��ȡ��Ŀ��
	int F;				//��ȡ��¼
	char CH[10];		//��ȡ���ַ�������
	int  IN_;			//��ȡ����������
	char * SuIT = NULL;
	SuIT = new char[20];
	GetPrivateProfileStringA("FILE", "��ַ", "δ֪", File_, sizeof(File_), File_system);
	total = GetPrivateProfileIntA("��¼����", "total", -1, File_system);
	N = GetPrivateProfileIntA("SUBGECT", "��Ŀ����", -1, File_system);
	F = GetPrivateProfileIntA("�Ƿ��һ�μ�¼", "F", -1, File_system);
	if (F == -1)MessageBoxA(NULL, "��û�м�¼���κ�ѧ����Ϣ", "��Ϣ", MB_OK);
	if (F == 0) MessageBoxA(NULL, "��û�м�¼���κ�ѧ����Ϣ", "��Ϣ", MB_OK);
	if (F == 1)
	{
		for (int j = 1; j <= total; j++)
		{
			int a = 0;
			for (int i = 1; i <= N + 3; i++)
			{
				sprintf(SuIT, "%d", j);
				if (i == 1)
				{
					GetPrivateProfileStringA(SuIT, "����", "error", CH, sizeof(CH), File_);
					if (strcmp(CH, "error") != 0)cout << CH << "   ";
					else ++a;
				}
				if (i == 2)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "ѧ��", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 3)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "�༶", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 4)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 5)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 6)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "Ӣ��", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 7)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 8)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ʷ", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 9)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 10)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 11)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
				if (i == 12)
				{
					IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
					if (IN_ != -1)cout << IN_ << "   ";
				}
			}
			if (a == 0)cout << endl;
		}
	}
	delete[]SuIT;
	cout << "��Ϣ�Ѳ鿴���(��������ز˵�)" << endl;
	int e;
	cin >> e;
}
void NameSeatch(char * File_system)
{
	char Stunumer[10];  //��ȡ��ѧ������
	char File_[100];	//��ȡ�ļ���ַ
	char CH[10];		//��ȡ���ַ�������
	char CH_[20];
	char CH_1[20];
	int  IN_;			//��ȡ����������
	int total;			//��ȡ��¼��������
	int N;				//��ȡ��Ŀ��
	char * SuIT = NULL;
	SuIT = new char[20];
	int a = 0;			//������������Ϣ���û�и�ѧ����Ϣ,��aΪ0,��ʾ�Ƿ���������ٴ�����
	int b = 0;
	GetPrivateProfileStringA("FILE", "��ַ", "δ֪", File_, sizeof(File_), File_system);
	total = GetPrivateProfileIntA("��¼����", "total", -1, File_system);
	N = GetPrivateProfileIntA("SUBGECT", "��Ŀ����", -1, File_system);
	cout << "����ѧ�������鿴ѧ����Ϣ\n";
	while (1)
	{
		cin >> Stunumer;
		b = 0;
		for (int j = 1; j <= total; j++)
		{
			sprintf(CH_1, "%d", j);
			GetPrivateProfileStringA(CH_1, "����", "δ֪", CH_, sizeof(CH_), File_);
			if (strcmp(Stunumer, CH_) == 0)
			{
				for (int i = 1; i <= N + 3; i++)
				{
					sprintf(SuIT, "%d", j);
					if (i == 1)
					{
						GetPrivateProfileStringA(SuIT, "����", "error", CH, sizeof(CH), File_);
						cout << "����:";
						cout << CH << endl;
					}
					if (i == 2)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "ѧ��", -1, File_);
						cout << "ѧ��:";
						cout << IN_ << endl;
					}
					if (i == 3)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "�༶", -1, File_);
						cout << "�༶:";
						cout << IN_ << endl;
					}
					if (i == 4)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 5)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
						cout << "��ѧ:";
						cout << IN_ << endl;
					}
					if (i == 6)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "Ӣ��", -1, File_);
						cout << "Ӣ��:";
						cout << IN_ << endl;
					}
					if (i == 7)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 8)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "��ʷ", -1, File_);
						cout << "��ʷ:";
						cout << IN_ << endl;
					}
					if (i == 9)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 10)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 11)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 12)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
						cout << "��ѧ:";
						cout << IN_ << endl;
					}
				}
				b = 1;
			}
		}
		if (b == 0)
		{
			cout << "������������������û�и�ѧ��" << endl;
			cout << "�Ƿ񰴰༶����������밴1�����������������밴2������������ϼ��˵�" << endl;
			int w;
			cin >> w;
			if (w == 1)
			{
				ClassSeatch(File_system);
			}
			if (w != 1 && w != 2)
			{
				cout << "tuichu";
				break;
			}
		}
	}
	delete[]SuIT;
}
void ClassSeatch(char * File_system) 
{
	int Stunumer = 0;	//��ȡ��ѧ���༶
	char File_[100];	//��ȡ�ļ���ַ
	char CH[10];		//��ȡ���ַ�������
	char CH_1[20];
	int  IN_;			//��ȡ����������
	int total;			//��ȡ��¼��������
	int N=0;            //��ȡ��Ŀ��
	char * SuIT = NULL;
	SuIT = new char[20];
	int a = 0;			//������������Ϣ���û�и�ѧ����Ϣ,��aΪ0,��ʾ�Ƿ���������ٴ�����
	int b = 0;			//����Ƿ��ҵ�
	GetPrivateProfileStringA("FILE", "��ַ", "δ֪", File_, sizeof(File_), File_system);
	total = GetPrivateProfileIntA("��¼����", "total", -1, File_system);
	N = GetPrivateProfileIntA("SUBGECT", "��Ŀ����", -1, File_system);
	cout << "����ѧ���༶�鿴ѧ����Ϣ\n";
	while (1)
	{
		cin >> Stunumer; //��ȡ�༶
		for (int j = 1; j <= total; j++)
		{
			sprintf(CH_1, "%d", j);
			a = GetPrivateProfileIntA(CH_1, "�༶", -1, File_);
			if (Stunumer == a)
			{
				for (int i = 1; i <= N + 3; i++)
				{
					sprintf(SuIT, "%d", j);
					if (i == 1)
					{
						GetPrivateProfileStringA(SuIT, "����", "error", CH, sizeof(CH), File_);
						cout << "����:";
						cout << CH << endl;
					}
					if (i == 2)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "ѧ��", -1, File_);
						cout << "ѧ��:";
						cout << IN_ << endl;
					}
					if (i == 3)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "�༶", -1, File_);
						cout << "�༶:";
						cout << IN_ << endl;
					}
					if (i == 4)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 5)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
						cout << "��ѧ:";
						cout << IN_ << endl;
					}
					if (i == 6)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "Ӣ��", -1, File_);
						cout << "Ӣ��:";
						cout << IN_ << endl;
					}
					if (i == 7)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 8)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "��ʷ", -1, File_);
						cout << "��ʷ:";
						cout << IN_ << endl;
					}
					if (i == 9)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 10)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 11)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "����", -1, File_);
						cout << "����:";
						cout << IN_ << endl;
					}
					if (i == 12)
					{
						IN_ = GetPrivateProfileIntA(SuIT, "��ѧ", -1, File_);
						cout << "��ѧ:";
						cout << IN_ << endl;
					}
				}
				b = 1;
			}
		}
		if (b==0)
		{
			cout << "������İ༶�������û�����ڸð༶" << endl;
			cout << "�Ƿ���������������밴1���������༶�����밴2������������ϼ��˵�" << endl;
			int w;
			cin >> w;
			if (w == 1)
			{
				NameSeatch(File_system);
			}
			if (w == 2)
			{
			}
			if (w != 1 && w != 2)
			{
				cout << "tuichu";
				break;
			}
		}
	}
	delete[]SuIT;
}
void NumberSum(char * File_system)
{
}
int ListShow_1()
{
	cout << "                     �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
	cout << "                     �U�T�T  ����Ϣά��  �T�T  ����Ϣ����  �T�T�U\n";
	cout << "                     �U                                  �U\n";
	cout << "                     �U�T�T  ����Ϣͳ��  �T�T  ���˳�ϵͳ  �T�T�U\n";
	cout << "                     �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
	MessageBoxA(NULL, "��ѡ����", "��Ϣ(��������)", MB_OK);
	int num_1;
	cin >> num_1; //�û�ѡ��
	system("cls");
	return num_1;
}

int ListShow_2()
{
	cout << "                     �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
	cout << "                     �U�T�T  �ٽ���ѧ���ɼ���  �T�T  �����ѧ����¼  �T�T�U\n";
	cout << "                     �U                                            �U\n";
	cout << "                     �U�T�T  ��ɾ��ѧ���ļ�¼  �T�T  ���޸�ѧ����Ϣ  �T�T�U\n";
	cout << "                     �U                                            �U\n";
	cout << "                     �U�T�T  �ݲ鿴��¼����Ϣ  �T�T  �޷����ϼ��˵�  �T�T�U\n";
	cout << "                     �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
	MessageBoxA(NULL, "���ٴ�ѡ����(������ǵ�һ��ʹ���벻Ҫѡ��1)", "��Ϣ(��������)", MB_OK);
	int num_2;
	cin >> num_2; //�û�ѡ��
	p = &num_2;   
	system("cls");
	return num_2;
}
int ListShow_3()
{
	cout << "                     �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
	cout << "                     �U�T�T  �ٰ���������  �T�T  �ڰ��༶����  �T�T�U\n";
	cout << "                     �U                                      �U\n";
	cout << "                     �U�T�T  �۷����ϼ��˵�                    �U\n";
	cout << "                     �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
	MessageBoxA(NULL, "���ٴ�ѡ����", "��Ϣ(��������)", MB_OK);
	int num_2;
	cin >> num_2; //�û�ѡ��
	p = &num_2;
	system("cls");
	return num_2;
}
int ListShow_4()
{
	cout << "                     �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
	cout << "                     �U�T�T  �ٳɼ�ͳ��  �T�T  �ڷ����ϼ��˵�  �T�T�U\n";
	cout << "                     �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
	MessageBoxA(NULL, "���ٴ�ѡ����", "��Ϣ(��������)", MB_OK);
	int num_2;
	cin >> num_2; //�û�ѡ��
	p = &num_2;
	system("cls");
	return num_2;
}
void ShowP()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_RED);//��
	cout << "ѧУѧ����Ϣ����ϵͳ(�������� QQ/VX:2506897252 ����ѧϰʹ��)\n"<< endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_BLUE);//��
	cout << "��Ҫ����˵����" << endl;
	cout << "1.���������½(ģ��a)" << endl;
	cout << "��������ʽ��֤����Ա���(����������)��������ȷ�ɽ��룬������������" << endl;
	cout << "2.����ѧ���ɼ���ģ��b��" << endl;
	cout << "�����µ�ѧ���ɼ��ļ���" << endl;
	cout << "��������ѧ����¼������������ѧ�š��༶���γ̡��ɼ����������ѧ����¼��" << endl;
	cout << "3.���ѧ����¼��ģ��c��" << endl;
	cout << "���Ѵ��ڵ�ѧ���ɼ��ļ�������¼�¼��" << endl;
	cout << "4.ɾ��ѧ����¼��ģ��d)" << endl;
	cout << "��ѧ���ɼ��ļ���ɾ�������ſγ̲������ѧ����¼��" << endl;
	cout << "ɾ��ǰ��������ʾ����ɾ��������ѧ���������ɼ���ȷ�Ϻ���ɾ����" << endl;
	cout << "5.�޸�ѧ����Ϣ��ģ��e��" << endl;
	cout << "����ѧ��ѧ�ţ���ѧ���ɼ��ļ����ҳ���ѧ����¼��" << endl;
	cout << "����Ļ��������ʾ��ѧ���ĸ�����¼��" << endl;
	cout << "ÿ��ʾһ����ѯ���Ƿ��޸ģ������Y���������޸ĺ����ݣ�" << endl;
	cout << "���ļ�ԭ��¼ɾ���������µļ�¼��" << endl;
	cout << "6.�������Ͱ༶���ң�ģ��f��" << endl;
	cout << "����������ʾ��Ӧ��Ϣ��" << endl;
	cout << "7.��Ϣͳ�ƣ�ģ��g��" << endl;
	cout << "ͬʱ���հ༶�Ϳγ�ͳ��ÿ�ſγ̡�ÿ���༶��ƽ���ɼ�����߷֡���ͷ֣�" << endl;
	cout << "����Ļ����������ʾ���ſγ̣���Ӧ�ĸ����༶��ͳ�����ݡ�" << endl;
	cout << "8.�˳���Ϣ����ϵͳ�����ز���ϵͳ��(ģ��h)" << endl;
}
void SubjectJudge(int * number)
{
	cout << "����  ѧ��  �༶  ";
	for (int i = 0; i < 9; i++)
	{
		if (*(number + i) == 1)cout << "����  ";
		if (*(number + i) == 2)cout << "��ѧ  ";
		if (*(number + i) == 3)cout << "Ӣ��  ";
		if (*(number + i) == 4)cout << "����  ";
		if (*(number + i) == 5)cout << "��ʷ  ";
		if (*(number + i) == 6)cout << "����  ";
		if (*(number + i) == 7)cout << "����  ";
		if (*(number + i) == 8)cout << "����  ";
		if (*(number + i) == 9)cout << "��ѧ  ";
	}
	cout << endl;
}
void Function_1(int i,char * Name)
{
	int a = i+1;
	char   NUM[3];
	sprintf(NUM, "%d", i);
	strcat_s(Name, 30, NUM);
}


































