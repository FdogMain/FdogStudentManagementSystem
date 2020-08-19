>写在前面：
>大家好，我是 _花狗Fdog_ ，来自内蒙古的一个小城市，目前在泰州读书。
>很感谢能有这样一个平台让我能够在这里分享所学所感。
>我喜欢编程，喜欢代码，喜欢去做一个程序员。
>努力学习，争取多年后，给亲人更好的生活。
>QQ/WX：2506897252   欢迎交流。
    
    
**我的第二篇博客，C++语言学生管理系统，由于个人原因NumberSum（）没有写。。。，该程序==最大的亮点不是可以存储学生的数据，而是当你关闭程序，第二次打开后，以前写的数据还会存在==，如果你需要写一个学生管理系统，这个一定会让你眼前一亮！话又说回来，别人写的总归是别人写的，如果你有幸看了我写的，也希望你能够自己亲自写一遍！废话不多说，贴代码，源代码我也放到了下载，需要的赶紧去下载。**


@[TOC]
# 1.软件效果
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200123121144860.gif)
# 2.显示软件介绍

```c
void ShowP()
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
  FOREGROUND_INTENSITY | FOREGROUND_RED);//红
 cout << "学校学生信息管理系统(花狗制作 QQ/VX:2506897252 仅供学习使用)\n" << endl;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
  FOREGROUND_INTENSITY | FOREGROUND_BLUE);//蓝
 cout << "主要功能说明：" << endl;
 cout << "1.建立密码登陆(模块a)" << endl;
 cout << "用密码形式验证管理员身份(可输入三次)，密码正确可进入，否则程序结束。" << endl;
 cout << "2.建立学生成绩表（模块b）" << endl;
 cout << "建立新的学生成绩文件；" << endl;
 cout << "建立若干学生记录，包括姓名、学号、班级、课程、成绩、包括添加学生记录。" << endl;
 cout << "3.添加学生记录（模块c）" << endl;
 cout << "在已存在的学生成绩文件中添加新记录。" << endl;
 cout << "4.删除学生记录（模块d)" << endl;
 cout << "在学生成绩文件中删除有三门课程不及格的学生记录；" << endl;
 cout << "删除前，逐条显示符合删除条件的学生姓名、成绩，确认后再删除。" << endl;
 cout << "5.修改学生信息（模块e）" << endl;
 cout << "输入学生学号，在学生成绩文件中找出该学生记录；" << endl;
 cout << "在屏幕上逐条显示该学生的各条记录；" << endl;
 cout << "每显示一条，询问是否修改，如果“Y”，输入修改后数据，" << endl;
 cout << "将文件原记录删除，保存新的记录；" << endl;
 cout << "6.按姓名和班级查找（模块f）" << endl;
 cout << "输入姓名显示相应信息。" << endl;
 cout << "7.信息统计（模块g）" << endl;
 cout << "同时按照班级和课程统计每门课程、每个班级的平均成绩，最高分、最低分；" << endl;
 cout << "在屏幕上先依次显示各门课程，对应的各个班级的统计数据。" << endl;
 cout << "8.退出信息管理系统，返回操作系统。(模块h)" << endl;
}
```

# 3.①信息维护 ②信息检索 ③信息统计 ④退出系统

```c
int ListShow_1()
{
 cout << "                     ╔══════════════════════════════════╗\n";
 cout << "                     ║══  ①信息维护  ══  ②信息检索  ══║\n";
 cout << "                     ║                                  ║\n";
 cout << "                     ║══  ③信息统计  ══  ④退出系统  ══║\n";
 cout << "                     ╚══════════════════════════════════╝\n";
 MessageBoxA(NULL, "请选择功能", "消息(花狗制作)", MB_OK);
 int num_1;
 cin >> num_1; //用户选择
 system("cls");
 return num_1;
}
```

# 4.①建立学生成绩表 ②添加学生记录 ③删除学生的记录 ④修改学生信息 ⑤查看记录的信息 ⑥返回上级菜单

```c
int ListShow_2()
{
 cout << "                     ╔════════════════════════════════════════════╗\n";
 cout << "                     ║══  ①建立学生成绩表  ══  ②添加学生记录  ══║\n";
 cout << "                     ║                                            ║\n";
 cout << "                     ║══  ③删除学生的记录  ══  ④修改学生信息  ══║\n";
 cout << "                     ║                                            ║\n";
 cout << "                     ║══  ⑤查看记录的信息  ══  ⑥返回上级菜单  ══║\n";
 cout << "                     ╚════════════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请再次选择功能(如果不是第一次使用请不要选择1)", "消息(花狗制作)", MB_OK);
 int num_2;
 cin >> num_2; //用户选择
 p = &num_2;
 system("cls");
 return num_2;
}
```

# 5.①按姓名查找 ②按班级查找 ③返回上级菜单

```c
int ListShow_3()
{
 cout << "                     ╔══════════════════════════════════════╗\n";
 cout << "                     ║══  ①按姓名查找  ══  ②按班级查找  ══║\n";
 cout << "                     ║                                      ║\n";
 cout << "                     ║══  ③返回上级菜单                    ║\n";
 cout << "                     ╚══════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请再次选择功能", "消息(花狗制作)", MB_OK);
 int num_2;
 cin >> num_2; //用户选择
 p = &num_2;
 system("cls");
 return num_2;
}
```

# 6.①成绩统计 ②返回上级菜单

```c
int ListShow_4()
{
 cout << "                     ╔══════════════════════════════════════╗\n";
 cout << "                     ║══  ①成绩统计  ══  ②返回上级菜单  ══║\n";
 cout << "                     ╚══════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请再次选择功能", "消息(花狗制作)", MB_OK);
 int num_2;
 cin >> num_2; //用户选择
 p = &num_2;
 system("cls");
 return num_2;
}
```

# 7.建立学生成绩表

```c
void FoundStudent(char *File_system)
{
 char File_[100];          //自定义文件地址
 char Name_[20];           //文件名字
 int  number[9] = { 31,31,31,31,31,31,31,31,31 };//科目选择 
 int  sum = 0;          //科目数 
 cout << "请输入文件保存地址(例如 D:\\我的软件\\学生管理系统  地址中不要存在空格)";
 cin >> File_;
 if (_access(File_, 00) == 0)
 {
  MessageBoxA(NULL, "指定地址成功！", "欢迎使用", MB_OK);
 }
 else
 {
  MessageBoxA(NULL, "输入的路径不存在，为您创建了路径！接下来请输入文件名（文件名后缀请写为.ini）", "欢迎使用", MB_OK);
  _mkdir(File_);//如果路径中没有指定的文件夹,则创建该文件夹
 }
 cout << "请输入文件名:";
 cin >> Name_;
 strcat(File_, "\\");
 strcat(File_, Name_);//将文件名拷贝到路径后面
 system("cls");
 cout << "                     ╔══════════════════════╗\n";
 cout << "                     ║══①语文══②数学══③英语══④政治══║\n";
 cout << "                     ║                                            ║\n";
 cout << "                     ║══⑤历史══⑥地理══⑦生物══⑧物理══║\n";
 cout << "                     ║                                            ║\n";
 cout << "                     ║══⑨化学                                  ║\n";
 cout << "                     ╚══════════════════════╝\n";
 MessageBoxA(NULL, "请选择科目(选择一次按一次回车\n最少选择三门科目\n如果不在选择请输入0)", "欢迎使用", MB_OK);
 ofstream fout_1(File_);//默认的调用方式 显式为ofstream fout.open(File_);
 fout_1.close();
 ofstream fout(File_system);
 fout << "[FILE]" << endl;//将文件地址及名字配置
 fout << "地址=" << File_ << endl;
 fout << "[SUBGECT]" << endl;//将科目配置
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
  fout << "科目代码" << i + 1 << "=" << number[i] << endl;
 }
 fout << "科目总数=" << sum << endl;
 fout << "[记录人数]" << endl;
 fout << "total=0" << endl;
 fout << "[是否第一次打开]" << endl;
 fout << "Frist=1" << endl;
 fout << "[是否第一次记录]" << endl;
 fout << "F=0" << endl;
 fout.close();
 cout << "学生成绩表已建立完毕" << endl;
 cout << "立即添加学生信息(1), 返回上一级菜单(0)" << endl;
 int CinJ = 0;
 cin >> CinJ;
 if (CinJ == 1)
 {
  system("cls");
  AddStudent(File_system);
 }
 //当程序正常运行结束后 代表着返回上一层
}
```

# 8.添加学生记录

```c
void AddStudent(char * File_system)
{
 char * Studata = NULL;
 Studata = new char[20];//信息
 char * NUM_1 = NULL;
 NUM_1 = new char[100];
 char File_[100];  //读取文件地址
 int ReturnSu = 0; //读取科目数
 int total;        //读取记录的总人数
 char * total_f = NULL;
 total_f = new char[1000];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 ReturnSu = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 int number[9];//存放File_system配置文件里面保存的科目
 for (int i = 0; i < 9; i++) //为number提供数据
 {
  char Name[30] = "科目代码";
  if (i == 0)
  {
   char   NUM[3] = "1";
   strcat(Name, NUM);
  }
  if (i == 1)
  {
   char   NUM[3] = "2";
   strcat(Name, NUM);
  }
  if (i == 2)
  {
   char   NUM[3] = "3";
   strcat(Name, NUM);
  }
  if (i == 3)
  {
   char   NUM[3] = "4";
   strcat(Name, NUM);
  }
  if (i == 4)
  {
   char   NUM[3] = "5";
   strcat(Name, NUM);
  }
  if (i == 5)
  {
   char   NUM[3] = "6";
   strcat(Name, NUM);
  }
  if (i == 6)
  {
   char   NUM[3] = "7";
   strcat(Name, NUM);
  }
  if (i == 7)
  {
   char   NUM[3] = "8";
   strcat(Name, NUM);
  }
  if (i == 8)
  {
   char   NUM[3] = "9";
   strcat(Name, NUM);
  }
  char *stu_ = Name;
  number[i] = GetPrivateProfileIntA("SUBGECT", stu_, -1, File_system);
 }
 cout << "已选择好科目,请按以下格式记录学生信息:\n";
 SubjectJudge(number); //显示需要输入的内容 
 MessageBoxA(NULL, "请严格按照以上信息顺序输入\n输入完学生的信息后再按回车\n输入的信息请用空格隔开\n如果不在输入下一位学生信息,请输入\"T\"结束", "提示", MB_OK);
 ofstream fout(File_, ios::ate | ios::app);  //读取文件
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
    if (strcmp(Studata, "T") == 0) //如果输入T就退出
    {
     break;
    }
    WritePrivateProfileStringA(NUM_1, "姓名", Studata, File_);
    total += 1;
    sprintf(total_f, "%d", total); //int 转 字符串
    WritePrivateProfileStringA("记录人数", "total", total_f, File_system);
   }
   if (i == 2)
   {
    WritePrivateProfileStringA(NUM_1, "学号", Studata, File_);
   }
   if (i == 3)
   {
    WritePrivateProfileStringA(NUM_1, "班级", Studata, File_);
   }
   if (i == 4)
   {
    WritePrivateProfileStringA(NUM_1, "语文", Studata, File_);
   }
   if (i == 5)
   {
    WritePrivateProfileStringA(NUM_1, "数学", Studata, File_);
   }
   if (i == 6)
   {
    WritePrivateProfileStringA(NUM_1, "英语", Studata, File_);
   }
   if (i == 7)
   {
    WritePrivateProfileStringA(NUM_1, "政治", Studata, File_);
   }
   if (i == 8)
   {
    WritePrivateProfileStringA(NUM_1, "历史", Studata, File_);
   }
   if (i == 9)
   {
    WritePrivateProfileStringA(NUM_1, "地理", Studata, File_);
   }
   if (i == 10)
   {
    WritePrivateProfileStringA(NUM_1, "生物", Studata, File_);
   }
   if (i == 11)
   {
    WritePrivateProfileStringA(NUM_1, "物理", Studata, File_);
   }
   if (i == 12)
   {
    WritePrivateProfileStringA(NUM_1, "化学", Studata, File_);
   }
   WritePrivateProfileStringA("是否第一次记录", "F", "1", File_system);
  }
 }
 fout.close(); //关闭文件
 delete[]Studata;
 delete[]NUM_1;
 delete[]total_f;
 cout << "信息已录入完毕" << endl;
 cout << "返回上一级菜单(任意键)" << endl;
 int e;
 cin >> e;
}
```

# 9.删除学生记录 

```c
void DeleteStudent(char * File_system)
{
 char File_[100];  //读取文件地址
 int total;        //读取记录的总人数
 int N;            //获取科目数
 int F;            //获取记录
 char CH[10];      //获取的字符类类型
 int  IN_;         //获取的数字类型
 int * percase = NULL;  //记录删除标号
 percase = new int[sizeof(int) * 100];
 int persum = 0;   //记录删除人数
 char * SuIT = NULL;
 SuIT = new char[20];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 F = GetPrivateProfileIntA("是否第一次记录", "F", -1, File_system);
 if (F == -1)MessageBoxA(NULL, "您没有记录过任何学生信息,无法删除", "消息", MB_OK);
 if (F == 0) MessageBoxA(NULL, "您没有记录过任何学生信息,无法删除", "消息", MB_OK);
 if (F == 1)
 {
  for (int j = 1; j <= total; j++)
  {
   int sum = 0;      //不合格科目
   char Delename[50] = "";
   for (int i = 1; i <= N + 3; i++)
   {
    char CH_F[10];//数字转字符
    sprintf(SuIT, "%d", j);
    if (i == 1)
    {
     GetPrivateProfileStringA(SuIT, "姓名", "未知", CH, sizeof(CH), File_);
     strcat(Delename, CH);
     strcat(Delename, "  ");
    }
    if (i == 2)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
    }
    if (i == 3)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
    }
    if (i == 4)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)
      sum += 1;
    }
    if (i == 5)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 6)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 7)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 8)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 9)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 10)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 11)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 12)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
   }
   if (sum >= 3) //如果不及格科目超过三门则打印该名同学的信息
   {
    cout << Delename;
    cout << endl;
    percase[persum] = j;//012
    persum += 1;//删除人数 //123  //BUG出现 
   }
  }
 }
 if (IDYES == MessageBoxA(NULL, "是否删除\n 按 \"是\"确认删除", "消息(花狗制作)", MB_YESNO))
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
  cout << "您已取消删除......";
 }
 delete[]percase;
 delete[]SuIT;
 cout << "信息已处理完毕(任意键返回菜单)" << endl;
 int e;
 cin >> e;
}
```

# 10.修改学生信息 

```c
void ChooesStudent(char * File_system)
{
 int Stunumer = 0;  //获取的学生学号
 char File_[100];  //读取文件地址
 char CH[10];      //获取的字符类类型
 int  IN_;          //获取的数字类型
 char CH_[20];
 int total;        //读取记录的总人数
 int N;            //获取科目数
 char * SuIT = NULL;
 SuIT = new char[20];
 int a = 0;        //当找完所以信息如果没有该学号信息,则a为0,提示是否输入错误再次输入
 char CH_1[20];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 cout << "输入学号修改学生信息\n";
 cin >> Stunumer;
 for (int j = 1; j <= total; j++)
 {
  sprintf(CH_1, "%d", j);
  a = GetPrivateProfileIntA(CH_1, "学号", -1, File_);
  if (Stunumer == a)
  {
   for (int i = 1; i <= N + 3; i++)
   {
    sprintf(SuIT, "%d", j);
    if (i == 1)
    {
     GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
     cout << "姓名:";
     cout << CH << endl;
    }
    if (i == 2)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
     cout << "学号:";
     cout << IN_ << endl;
    }
    if (i == 3)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
     cout << "班级:";
     cout << IN_ << endl;
    }
    if (i == 4)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改语文成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "语文", CH_, File_);
     }
    }
    if (i == 5)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改数学成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "数学", CH_, File_);
     }
    }
    if (i == 6)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改英语成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "英语", CH_, File_);
     }
    }
    if (i == 7)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改政治成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "政治", CH_, File_);
     }
    }
    if (i == 8)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改历史成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "历史", CH_, File_);
     }
    }
    if (i == 9)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改地理成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "地理", CH_, File_);
     }
    }
    if (i == 10)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改生物成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "生物", CH_, File_);
     }
    }
    if (i == 11)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改物理成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "物理", CH_, File_);
     }
    }
    if (i == 12)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改化学成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "化学", CH_, File_);
     }
    }
   }
   ++a;
  }
 }
 delete[]SuIT;
 cout << "信息已修改完毕(任意键返回菜单)" << endl;
 int e;
 cin >> e;
}
```

# 11.按班级查找

```c
void ClassSeatch(char * File_system)
{
 int Stunumer = 0;  //获取的学生班级
 char File_[100];  //读取文件地址
 char CH[10];      //获取的字符类类型
 char CH_1[20];
 int  IN_;          //获取的数字类型
 int total;        //读取记录的总人数
 int N = 0;            //获取科目数
 char * SuIT = NULL;
 SuIT = new char[20];
 int a = 0;        //当找完所以信息如果没有该学号信息,则a为0,提示是否输入错误再次输入
 int b = 0;        //检测是否找到
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 cout << "输入学生班级查看学生信息\n";
 while (1)
 {
  cin >> Stunumer; //获取班级
  for (int j = 1; j <= total; j++)
  {
   sprintf(CH_1, "%d", j);
   a = GetPrivateProfileIntA(CH_1, "班级", -1, File_);
   if (Stunumer == a)
   {
    for (int i = 1; i <= N + 3; i++)
    {
     sprintf(SuIT, "%d", j);
     if (i == 1)
     {
      GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
      cout << "姓名:";
      cout << CH << endl;
     }
     if (i == 2)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
      cout << "学号:";
      cout << IN_ << endl;
     }
     if (i == 3)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
      cout << "班级:";
      cout << IN_ << endl;
     }
     if (i == 4)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
      cout << "语文:";
      cout << IN_ << endl;
     }
     if (i == 5)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
      cout << "数学:";
      cout << IN_ << endl;
     }
     if (i == 6)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
      cout << "英语:";
      cout << IN_ << endl;
     }
     if (i == 7)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
      cout << "政治:";
      cout << IN_ << endl;
     }
     if (i == 8)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
      cout << "历史:";
      cout << IN_ << endl;
     }
     if (i == 9)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
      cout << "地理:";
      cout << IN_ << endl;
     }
     if (i == 10)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
      cout << "生物:";
      cout << IN_ << endl;
     }
     if (i == 11)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
      cout << "物理:";
      cout << IN_ << endl;
     }
     if (i == 12)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
      cout << "化学:";
      cout << IN_ << endl;
     }
    }
    b = 1;
   }
  }
  if (b == 0)
  {
   cout << "你输入的班级错误或者没有人在该班级" << endl;
   cout << "是否按名字搜索如果是请按1，继续按班级查找请按2，任意键返回上级菜单" << endl;
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
```

# 12.按姓名查找

```c
void NameSeatch(char * File_system)
{
 char Stunumer[10];  //获取的学生姓名
 char File_[100];  //读取文件地址
 char CH[10];      //获取的字符类类型
 char CH_[20];
 char CH_1[20];
 int  IN_;          //获取的数字类型
 int total;        //读取记录的总人数
 int N;            //获取科目数
 char * SuIT = NULL;
 SuIT = new char[20];
 int a = 0;        //当找完所以信息如果没有该学号信息,则a为0,提示是否输入错误再次输入
 int b = 0;
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 cout << "输入学生姓名查看学生信息\n";
 while (1)
 {
  cin >> Stunumer;
  b = 0;
  for (int j = 1; j <= total; j++)
  {
   sprintf(CH_1, "%d", j);
   GetPrivateProfileStringA(CH_1, "姓名", "未知", CH_, sizeof(CH_), File_);
   if (strcmp(Stunumer, CH_) == 0)
   {
    for (int i = 1; i <= N + 3; i++)
    {
     sprintf(SuIT, "%d", j);
     if (i == 1)
     {
      GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
      cout << "姓名:";
      cout << CH << endl;
     }
     if (i == 2)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
      cout << "学号:";
      cout << IN_ << endl;
     }
     if (i == 3)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
      cout << "班级:";
      cout << IN_ << endl;
     }
     if (i == 4)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
      cout << "语文:";
      cout << IN_ << endl;
     }
     if (i == 5)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
      cout << "数学:";
      cout << IN_ << endl;
     }
     if (i == 6)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
      cout << "英语:";
      cout << IN_ << endl;
     }
     if (i == 7)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
      cout << "政治:";
      cout << IN_ << endl;
     }
     if (i == 8)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
      cout << "历史:";
      cout << IN_ << endl;
     }
     if (i == 9)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
      cout << "地理:";
      cout << IN_ << endl;
     }
     if (i == 10)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
      cout << "生物:";
      cout << IN_ << endl;
     }
     if (i == 11)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
      cout << "物理:";
      cout << IN_ << endl;
     }
     if (i == 12)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
      cout << "化学:";
      cout << IN_ << endl;
     }
    }
    b = 1;
   }
  }
  if (b == 0)
  {
   cout << "你输入的姓名错误或者没有该学生" << endl;
   cout << "是否按班级搜索如果是请按1，继续按姓名查找请按2，任意键返回上级菜单" << endl;
   int w;
   cin >> w;
   if (w == 1)
   {
    ClassSeatch(File_system);
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
```

# 13.成绩统计(空)

# 14.显示现有学生的信息情况

```c
void ShowNew(char * File_system)
{
 char File_[100];  //读取文件地址
 int total;        //读取记录的总人数
 int N;            //获取科目数
 int F;            //获取记录
 char CH[10];      //获取的字符类类型
 int  IN_;          //获取的数字类型
 char * SuIT = NULL;
 SuIT = new char[20];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 F = GetPrivateProfileIntA("是否第一次记录", "F", -1, File_system);
 if (F == -1)MessageBoxA(NULL, "您没有记录过任何学生信息", "消息", MB_OK);
 if (F == 0) MessageBoxA(NULL, "您没有记录过任何学生信息", "消息", MB_OK);
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
     GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
     if (strcmp(CH, "error") != 0)cout << CH << "   ";
     else ++a;
    }
    if (i == 2)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 3)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 4)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 5)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 6)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 7)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 8)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 9)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 10)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 11)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 12)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
   }
   if (a == 0)cout << endl;
  }
 }
 delete[]SuIT;
 cout << "信息已查看完毕(任意键返回菜单)" << endl;
 int e;
 cin >> e;
}
```

# 15.输出用户自定义需要输出的内容

```c
void SubjectJudge(int * number)
{
 cout << "姓名  学号  班级  ";
 for (int i = 0; i < 9; i++)
 {
  if (*(number + i) == 1)cout << "语文  ";
  if (*(number + i) == 2)cout << "数学  ";
  if (*(number + i) == 3)cout << "英语  ";
  if (*(number + i) == 4)cout << "政治  ";
  if (*(number + i) == 5)cout << "历史  ";
  if (*(number + i) == 6)cout << "地理  ";
  if (*(number + i) == 7)cout << "生物  ";
  if (*(number + i) == 8)cout << "物理  ";
  if (*(number + i) == 9)cout << "化学  ";
 }
 cout << endl;
}
```

#  16.完整代码奉上，也可自行下载。

```c

/************************************************
* 2019.11.07   花狗    学生管理系统   vs2015    *
************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<io.h>
#include<direct.h>
#include<string>
int * p = NULL;  //指向ListShow_1()中的num_2
char File_system[] = "C:\\Users\\FdogMain\\Desktop\\sms.ini";//系统初始化配置文件(包含用户创建的文件地址,自定义的科目等等)
                                                             //我的桌面地址是这个，如果你的不是,请修改
void ShowP();           //显示软件介绍
int ListShow_1();          //①信息维护 ②信息检索 ③信息统计 ④退出系统
int ListShow_2();          //①建立学生成绩表 ②添加学生记录 ③删除学生的记录 ④修改学生信息 ⑤查看记录的信息 ⑥返回上级菜单
int ListShow_3();          //①按姓名查找 ②按班级查找 ③返回上级菜单
int ListShow_4();          //①成绩统计 ②返回上级菜单
void FoundStudent(char *File_system);     //建立学生成绩表
void AddStudent(char * File_system);     //添加学生记录  
void DeleteStudent(char * File_system);     //删除学生记录  
void ChooesStudent(char * File_system);     //修改学生信息  
void ClassSeatch(char * File_system);     //按班级查找   
void NameSeatch(char * File_system);     //按姓名查找    
void NumberSum(char * File_system);      //成绩统计      
void ShowNew(char * File_system);      //显示现有学生的信息情况
void SubjectJudge(int * number);      //输出用户自定义需要输出的内容
using namespace std;

int main(){
 const string password = "huagou"; //初始设定密码
 string password_2;            //输入密码
 if (IDYES == MessageBoxA(NULL, "请输入密码进入系统,如若忘记请联系作者QQ2506897252\n(您只有三次机会输入)", "提示", MB_YESNO));
 //函数MessageBoxA会返回一个值，如果等于IDYES则执行，否就退出
 else exit(0); 
 for (int I_F = 3; I_F >= 1; I_F--)
 {
  getline(cin, password_2); //getline是处理string类的函数;
  system("cls");
  if (password == password_2)
  {
   MessageBoxA(NULL, "密码正确", "提示", MB_OK);
   break;
  }
  else if (I_F == 1 && IDOK == MessageBoxA(NULL, "密码错误", "提示", MB_OK))
  {
   cout << "次数已用尽，已退出系统";
   system("pause>nul");
   exit(0);
  }//最后一次还是错误 直接退出
  else
  {
   MessageBoxA(NULL, "密码错误", "提示", MB_OK);
  }
 }
 if (-1 == GetPrivateProfileIntA("是否第一次打开", "Frist", -1, "C:\\Users\\FdogMain\\Desktop\\sms.ini"))
 {                             
  ShowP();
  MessageBoxA(NULL, "您好,由于您是第一次使用本软件\n希望您能够仔细阅读，如若阅读完按任意键进入软件", "提示", MB_OK);
  //判断用户是否第一次打开程序 如果第一次打开 则输出软件详细信息
  getchar();//等待用户相应
 }
 system("cls");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//亮蓝
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
 char File_[100];        //自定义文件地址
 char Name_[20];         //文件名字
 int  number[9] = { 31,31,31,31,31,31,31,31,31 };//科目选择 
 int  sum = 0;         //科目数 
 cout << "请输入文件保存地址(例如 D:\\我的软件\\学生管理系统  地址中不要存在空格)";
 cin >> File_;
 if (_access(File_, 00) == 0)
 {
  MessageBoxA(NULL, "指定地址成功！", "欢迎使用", MB_OK);
 }
 else
 {
  MessageBoxA(NULL, "输入的路径不存在，为您创建了路径！接下来请输入文件名（文件名后缀请写为.ini）", "欢迎使用", MB_OK);
  _mkdir(File_);//如果路径中没有指定的文件夹,则创建该文件夹
 }
 cout << "请输入文件名:";
 cin >> Name_;
 strcat_s(File_, "\\");
 strcat_s(File_, Name_);//将文件名拷贝到路径后面
 system("cls");
 cout << "                     ╔══════════════════════════════════════════╗\n";
 cout << "                     ║══ ①语文 ══ ②数学 ══ ③英语 ══ ④政治 ══║\n";
 cout << "                     ║                                          ║\n";
 cout << "                     ║══ ⑤历史 ══ ⑥地理 ══ ⑦生物 ══ ⑧物理 ══║\n";
 cout << "                     ║                                          ║\n";
 cout << "                     ║══ ⑨化学                                 ║\n";
 cout << "                     ╚══════════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请选择科目(选择一次按一次回车\n最少选择三门科目\n如果不在选择请输入0)", "欢迎使用", MB_OK);
 ofstream fout_1(File_);  //默认的调用方式 显式为ofstream fout.open(File_);
 fout_1.close();          
 ofstream fout(File_system);
 fout << "[FILE]" << endl; //将文件地址及名字配置
 fout << "地址=" << File_ << endl;
 fout << "[SUBGECT]" << endl;//将科目配置
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
  fout << "科目代码" << i + 1 << "=" << number[i] << endl;
 }
 fout << "科目总数=" << sum << endl;
 fout << "[记录人数]" << endl;
 fout << "total=0" << endl;
 fout << "[是否第一次打开]" << endl;
 fout << "Frist=1" << endl;
 fout << "[是否第一次记录]" << endl;
 fout << "F=0" << endl;
 fout.close();
 cout << "学生成绩表已建立完毕" << endl;
 cout << "立即添加学生信息(1), 返回上一级菜单(0)" << endl;
 int CinJ = 0;
 cin >> CinJ;
 if (CinJ == 1)
 {
  system("cls");
  AddStudent(File_system);
 }
 //当程序正常运行结束后 代表着返回上一层
}
void AddStudent(char * File_system)
{
 char * Studata = NULL;
 Studata = new char[20]; //信息
 char * NUM_1 = NULL;
 NUM_1 = new char[100];
 char File_[100];  //读取文件地址
 int ReturnSu = 0;  //读取科目数
 int total;    //读取记录的总人数
 char * total_f = NULL;
 total_f = new char[1000];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 ReturnSu = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 int number[9];   //存放File_system配置文件里面保存的科目
 for (int i = 0; i < 9; i++) //为number提供数据
 {
  char Name[30] = "科目代码";
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
 cout << "已选择好科目,请按以下格式记录学生信息:\n";
 SubjectJudge(number); //显示需要输入的内容 
 MessageBoxA(NULL, "请严格按照以上信息顺序输入\n输入完学生的信息后再按回车\n输入的信息请用空格隔开\n如果不在输入下一位学生信息,请输入\"T\"结束", "提示", MB_OK);
 ofstream fout(File_, ios::ate | ios::app);  //读取文件
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
    if (strcmp(Studata, "T") == 0) //如果输入T就退出
    {
     break;
    }
    WritePrivateProfileStringA(NUM_1, "姓名", Studata, File_);
    total += 1;
    sprintf(total_f, "%d", total); //int 转 字符串
    WritePrivateProfileStringA("记录人数", "total", total_f, File_system);
   }
   if (i == 2)
   {
    WritePrivateProfileStringA(NUM_1, "学号", Studata, File_);
   }
   if (i == 3)
   {
    WritePrivateProfileStringA(NUM_1, "班级", Studata, File_);
   }
   if (i == 4)
   {
    WritePrivateProfileStringA(NUM_1, "语文", Studata, File_);
   }
   if (i == 5)
   {
    WritePrivateProfileStringA(NUM_1, "数学", Studata, File_);
   }
   if (i == 6)
   {
    WritePrivateProfileStringA(NUM_1, "英语", Studata, File_);
   }
   if (i == 7)
   {
    WritePrivateProfileStringA(NUM_1, "政治", Studata, File_);
   }
   if (i == 8)
   {
    WritePrivateProfileStringA(NUM_1, "历史", Studata, File_);
   }
   if (i == 9)
   {
    WritePrivateProfileStringA(NUM_1, "地理", Studata, File_);
   }
   if (i == 10)
   {
    WritePrivateProfileStringA(NUM_1, "生物", Studata, File_);
   }
   if (i == 11)
   {
    WritePrivateProfileStringA(NUM_1, "物理", Studata, File_);
   }
   if (i == 12)
      {
    WritePrivateProfileStringA(NUM_1, "化学", Studata, File_);
   }
   WritePrivateProfileStringA("是否第一次记录", "F", "1", File_system);
  }
 }
 fout.close();   //关闭文件
 delete[]Studata;
 delete[]NUM_1;
 delete[]total_f;
 cout << "信息已录入完毕" << endl;
 cout<<"返回上一级菜单(任意键)"<<endl;
 int e;
 cin >> e;
}
void DeleteStudent(char * File_system)
{
 char File_[100];  //读取文件地址
 int total;    //读取记录的总人数
 int N;     //获取科目数
 int F;     //获取记录
 char CH[10];   //获取的字符类类型
 int  IN_;    //获取的数字类型
 int * percase = NULL; //记录删除标号
 percase = new int[sizeof(int) * 100];
 int persum = 0;   //记录删除人数
 char * SuIT = NULL;
 SuIT = new char[20];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 F = GetPrivateProfileIntA("是否第一次记录", "F", -1, File_system);
 if (F == -1)MessageBoxA(NULL, "您没有记录过任何学生信息,无法删除", "消息", MB_OK);
 if (F == 0) MessageBoxA(NULL, "您没有记录过任何学生信息,无法删除", "消息", MB_OK);
 if (F == 1)
 {
  for (int j = 1; j <= total; j++)
  {
   int sum = 0;      //不合格科目
   char Delename[50] = "";
   for (int i = 1; i <= N + 3; i++)
   {
    char CH_F[10];//数字转字符
    sprintf(SuIT, "%d", j);
    if (i == 1)
    {
    GetPrivateProfileStringA(SuIT, "姓名", "未知", CH, sizeof(CH), File_);
     strcat(Delename, CH);
     strcat(Delename, "  ");
    }
    if (i == 2)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
    }
    if (i == 3)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
    }
    if (i == 4)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)
      sum += 1;
    }
    if (i == 5)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 6)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 7)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 8)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 9)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 10)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
    if (i == 11)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
     if (i == 12)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
     sprintf(CH_F, "%d", IN_);
     strcat(Delename, CH_F);
     strcat(Delename, "  ");
     if (IN_ <= 60)sum += 1;
    }
   }
   if (sum >= 3) //如果不及格科目超过三门则打印该名同学的信息
   {
    cout << Delename;
    cout << endl;
    percase[persum] = j;
    persum += 1;//删除人数
   }
  }
 }
 if (IDYES == MessageBoxA(NULL, "是否删除\n 按 \"是\"确认删除", "消息(花狗制作)", MB_YESNO))
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
  cout << "您已取消删除......";
 }
 delete[]percase;
 delete[]SuIT;
 cout << "信息已处理完毕(任意键返回菜单)" << endl;
 int e;
 cin >> e;
}
void ChooesStudent(char * File_system)
{
 int Stunumer = 0; //获取的学生学号
 char File_[100]; //读取文件地址
 char CH[10];  //获取的字符类类型
 int  IN_;   //获取的数字类型
 char CH_[20];
 int total;   //读取记录的总人数
 int N;    //获取科目数
 char * SuIT = NULL;
 SuIT = new char[20];
 int a = 0;   //当找完所以信息如果没有该学号信息,则a为0,提示是否输入错误再次输入
 char CH_1[20];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 cout << "输入学号修改学生信息\n";
 cin >> Stunumer;
 for (int j = 1; j <= total; j++)
 {
  sprintf(CH_1, "%d", j);
  a = GetPrivateProfileIntA(CH_1, "学号", -1, File_);
  if (Stunumer == a)
  {
   for (int i = 1; i <= N + 3; i++)
   {
    sprintf(SuIT, "%d", j);
    if (i == 1)
    {
     GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
     cout << "姓名:";
     cout << CH << endl;
    }
    if (i == 2)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
     cout << "学号:";
     cout << IN_ << endl;
    }
    if (i == 3)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
     cout << "班级:";
     cout << IN_ << endl;
    }
    if (i == 4)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改语文成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "语文", CH_, File_);
     }
    }
    if (i == 5)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改数学成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "数学", CH_, File_);
     }
    }
    if (i == 6)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改英语成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "英语", CH_, File_);
     }
    }
    if (i == 7)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改政治成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "政治", CH_, File_);
     }
    }
    if (i == 8)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改历史成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "历史", CH_, File_);
     }
    }
    if (i == 9)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改地理成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "地理", CH_, File_);
     }
    }
    if (i == 10)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改生物成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "生物", CH_, File_);
     }
    }
    if (i == 11)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改物理成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "物理", CH_, File_);
     }
    }
    if (i == 12)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
     if (IDYES == MessageBoxA(NULL, "是否修改化学成绩\n按  \"是\"  修改    按  \"否\"  进入下一项修改", "消息", MB_YESNO))
     {
      cin >> IN_;
      sprintf(CH_, "%d", IN_);
      WritePrivateProfileStringA(SuIT, "化学", CH_, File_);
     }
    }
   }
   ++a;
  }
 }
 delete[]SuIT;
 cout << "信息已修改完毕(任意键返回菜单)" << endl;
 int e;
 cin >> e;
}
void ShowNew(char * File_system)
{
 char File_[100]; //读取文件地址
 int total;   //读取记录的总人数
 int N;    //获取科目数
 int F;    //获取记录
 char CH[10];  //获取的字符类类型
 int  IN_;   //获取的数字类型
 char * SuIT = NULL;
 SuIT = new char[20];
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 F = GetPrivateProfileIntA("是否第一次记录", "F", -1, File_system);
 if (F == -1)MessageBoxA(NULL, "您没有记录过任何学生信息", "消息", MB_OK);
 if (F == 0) MessageBoxA(NULL, "您没有记录过任何学生信息", "消息", MB_OK);
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
     GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
     if (strcmp(CH, "error") != 0)cout << CH << "   ";
     else ++a;
    }
    if (i == 2)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 3)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 4)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 5)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 6)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 7)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 8)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 9)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 10)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 11)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
    if (i == 12)
    {
     IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
     if (IN_ != -1)cout << IN_ << "   ";
    }
   }
   if (a == 0)cout << endl;
  }
 }
 delete[]SuIT;
 cout << "信息已查看完毕(任意键返回菜单)" << endl;
 int e;
 cin >> e;
}
void NameSeatch(char * File_system)
{
 char Stunumer[10];  //获取的学生姓名
 char File_[100]; //读取文件地址
 char CH[10];  //获取的字符类类型
 char CH_[20];
 char CH_1[20];
 int  IN_;   //获取的数字类型
 int total;   //读取记录的总人数
 int N;    //获取科目数
 char * SuIT = NULL;
 SuIT = new char[20];
 int a = 0;   //当找完所以信息如果没有该学号信息,则a为0,提示是否输入错误再次输入
 int b = 0;
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 cout << "输入学生姓名查看学生信息\n";
 while (1)
 {
  cin >> Stunumer;
  b = 0;
  for (int j = 1; j <= total; j++)
  {
   sprintf(CH_1, "%d", j);
   GetPrivateProfileStringA(CH_1, "姓名", "未知", CH_, sizeof(CH_), File_);
   if (strcmp(Stunumer, CH_) == 0)
   {
    for (int i = 1; i <= N + 3; i++)
    {
     sprintf(SuIT, "%d", j);
     if (i == 1)
     {
      GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
      cout << "姓名:";
      cout << CH << endl;
     }
     if (i == 2)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
      cout << "学号:";
      cout << IN_ << endl;
     }
     if (i == 3)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
      cout << "班级:";
      cout << IN_ << endl;
     }
     if (i == 4)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
      cout << "语文:";
      cout << IN_ << endl;
     }
     if (i == 5)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
      cout << "数学:";
      cout << IN_ << endl;
     }
     if (i == 6)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
      cout << "英语:";
      cout << IN_ << endl;
     }
     if (i == 7)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
      cout << "政治:";
      cout << IN_ << endl;
     }
     if (i == 8)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
      cout << "历史:";
      cout << IN_ << endl;
     }
     if (i == 9)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
      cout << "地理:";
      cout << IN_ << endl;
     }
     if (i == 10)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
      cout << "生物:";
      cout << IN_ << endl;
     }
     if (i == 11)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
      cout << "物理:";
      cout << IN_ << endl;
     }
     if (i == 12)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
      cout << "化学:";
      cout << IN_ << endl;
     }
    }
    b = 1;
   }
  }
  if (b == 0)
  {
   cout << "你输入的姓名错误或者没有该学生" << endl;
   cout << "是否按班级搜索如果是请按1，继续按姓名查找请按2，任意键返回上级菜单" << endl;
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
 int Stunumer = 0; //获取的学生班级
 char File_[100]; //读取文件地址
 char CH[10];  //获取的字符类类型
 char CH_1[20];
 int  IN_;   //获取的数字类型
 int total;   //读取记录的总人数
 int N=0;            //获取科目数
 char * SuIT = NULL;
 SuIT = new char[20];
 int a = 0;   //当找完所以信息如果没有该学号信息,则a为0,提示是否输入错误再次输入
 int b = 0;   //检测是否找到
 GetPrivateProfileStringA("FILE", "地址", "未知", File_, sizeof(File_), File_system);
 total = GetPrivateProfileIntA("记录人数", "total", -1, File_system);
 N = GetPrivateProfileIntA("SUBGECT", "科目总数", -1, File_system);
 cout << "输入学生班级查看学生信息\n";
 while (1)
 {
  cin >> Stunumer; //获取班级
  for (int j = 1; j <= total; j++)
  {
   sprintf(CH_1, "%d", j);
   a = GetPrivateProfileIntA(CH_1, "班级", -1, File_);
   if (Stunumer == a)
   {
    for (int i = 1; i <= N + 3; i++)
    {
     sprintf(SuIT, "%d", j);
     if (i == 1)
     {
      GetPrivateProfileStringA(SuIT, "姓名", "error", CH, sizeof(CH), File_);
      cout << "姓名:";
      cout << CH << endl;
     }
     if (i == 2)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "学号", -1, File_);
      cout << "学号:";
      cout << IN_ << endl;
     }
     if (i == 3)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "班级", -1, File_);
      cout << "班级:";
      cout << IN_ << endl;
     }
     if (i == 4)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "语文", -1, File_);
      cout << "语文:";
      cout << IN_ << endl;
     }
     if (i == 5)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "数学", -1, File_);
      cout << "数学:";
      cout << IN_ << endl;
     }
     if (i == 6)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "英语", -1, File_);
      cout << "英语:";
      cout << IN_ << endl;
     }
     if (i == 7)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "政治", -1, File_);
      cout << "政治:";
      cout << IN_ << endl;
     }
     if (i == 8)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "历史", -1, File_);
      cout << "历史:";
      cout << IN_ << endl;
     }
     if (i == 9)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "地理", -1, File_);
      cout << "地理:";
      cout << IN_ << endl;
     }
     if (i == 10)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "生物", -1, File_);
      cout << "生物:";
      cout << IN_ << endl;
     }
     if (i == 11)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "物理", -1, File_);
      cout << "物理:";
      cout << IN_ << endl;
     }
     if (i == 12)
     {
      IN_ = GetPrivateProfileIntA(SuIT, "化学", -1, File_);
      cout << "化学:";
      cout << IN_ << endl;
     }
    }
    b = 1;
   }
  }
  if (b==0)
  {
   cout << "你输入的班级错误或者没有人在该班级" << endl;
   cout << "是否按名字搜索如果是请按1，继续按班级查找请按2，任意键返回上级菜单" << endl;
   int w;
   cin >> w;
   if (w == 1)
   {
    NameSeatch(File_system);
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
int ListShow_1()
{
 cout << "                     ╔══════════════════════════════════╗\n";
 cout << "                     ║══  ①信息维护  ══  ②信息检索  ══║\n";
 cout << "                     ║                                  ║\n";
 cout << "                     ║══  ③信息统计  ══  ④退出系统  ══║\n";
 cout << "                     ╚══════════════════════════════════╝\n";
 MessageBoxA(NULL, "请选择功能", "消息(花狗制作)", MB_OK);
 int num_1;
 cin >> num_1; //用户选择
 system("cls");
 return num_1;
}
int ListShow_2()
{
 cout << "                     ╔════════════════════════════════════════════╗\n";
 cout << "                     ║══  ①建立学生成绩表  ══  ②添加学生记录  ══║\n";
 cout << "                     ║                                            ║\n";
 cout << "                     ║══  ③删除学生的记录  ══  ④修改学生信息  ══║\n";
 cout << "                     ║                                            ║\n";
 cout << "                     ║══  ⑤查看记录的信息  ══  ⑥返回上级菜单  ══║\n";
 cout << "                     ╚════════════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请再次选择功能(如果不是第一次使用请不要选择1)", "消息(花狗制作)", MB_OK);
 int num_2;
 cin >> num_2; //用户选择
 p = &num_2;   
 system("cls");
 return num_2;
}
int ListShow_3()
{
 cout << "                     ╔══════════════════════════════════════╗\n";
 cout << "                     ║══  ①按姓名查找  ══  ②按班级查找  ══║\n";
 cout << "                     ║                                      ║\n";
 cout << "                     ║══  ③返回上级菜单                    ║\n";
 cout << "                     ╚══════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请再次选择功能", "消息(花狗制作)", MB_OK);
 int num_2;
 cin >> num_2; //用户选择
 p = &num_2;
 system("cls");
 return num_2;
}
int ListShow_4()
{
 cout << "                     ╔══════════════════════════════════════╗\n";
 cout << "                     ║══  ①成绩统计  ══  ②返回上级菜单  ══║\n";
 cout << "                     ╚══════════════════════════════════════╝\n";
 MessageBoxA(NULL, "请再次选择功能", "消息(花狗制作)", MB_OK);
 int num_2;
 cin >> num_2; //用户选择
 p = &num_2;
 system("cls");
 return num_2;
}
void ShowP()
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
  FOREGROUND_INTENSITY | FOREGROUND_RED);//红
 cout << "学校学生信息管理系统(花狗制作 QQ/VX:2506897252 仅供学习使用)\n"<< endl;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
  FOREGROUND_INTENSITY | FOREGROUND_BLUE);//蓝
 cout << "主要功能说明：" << endl;
 cout << "1.建立密码登陆(模块a)" << endl;
 cout << "用密码形式验证管理员身份(可输入三次)，密码正确可进入，否则程序结束。" << endl;
 cout << "2.建立学生成绩表（模块b）" << endl;
 cout << "建立新的学生成绩文件；" << endl;
 cout << "建立若干学生记录，包括姓名、学号、班级、课程、成绩、包括添加学生记录。" << endl;
 cout << "3.添加学生记录（模块c）" << endl;
 cout << "在已存在的学生成绩文件中添加新记录。" << endl;
 cout << "4.删除学生记录（模块d)" << endl;
 cout << "在学生成绩文件中删除有三门课程不及格的学生记录；" << endl;
 cout << "删除前，逐条显示符合删除条件的学生姓名、成绩，确认后再删除。" << endl;
 cout << "5.修改学生信息（模块e）" << endl;
 cout << "输入学生学号，在学生成绩文件中找出该学生记录；" << endl;
 cout << "在屏幕上逐条显示该学生的各条记录；" << endl;
 cout << "每显示一条，询问是否修改，如果“Y”，输入修改后数据，" << endl;
 cout << "将文件原记录删除，保存新的记录；" << endl;
 cout << "6.按姓名和班级查找（模块f）" << endl;
 cout << "输入姓名显示相应信息。" << endl;
 cout << "7.信息统计（模块g）" << endl;
 cout << "同时按照班级和课程统计每门课程、每个班级的平均成绩，最高分、最低分；" << endl;
 cout << "在屏幕上先依次显示各门课程，对应的各个班级的统计数据。" << endl;
 cout << "8.退出信息管理系统，返回操作系统。(模块h)" << endl;
}
void NumberSum(char * File_system)
{
}
```

>如有不对，欢迎指出，期待我的下一篇文章。 >如有不对，欢迎指出，期待我的下一篇文章。
==_每文一句：心存希望，幸福就会降临你；心存理想，机遇就会笼罩你。_==

