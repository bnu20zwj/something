#include <iostream>
using namespace std;
class Student
{
    friend class Teacher;
  private:
    string name;
    int credit;
    double score;
  public:
    Student(string name = "XXX", int credit = 0, double score = 0);
    void setname(string);  //设置学生姓名
    string getname();      //获得学生姓名
    void setcredit(int);   //设置学生学分
    void setscore(double); //设置学生成绩
    void show();
};

Student::Student(string name, int credit, double score)
{
   this -> name = name;
   this -> credit =credit;
   this -> score = score;
}


void Student::setname(string s) //设置学生姓名
{
   name = s;
}

string Student::getname()      //获得学生姓名
{
    return name;
}

void Student::setcredit(int c)   //设置学生学分
{
    credit = c;
}

void Student::setscore(double s) //设置学生成绩
{
    score = s;
}

void Student::show()
{
    cout << name << "     " << credit << "       " << score<< endl;
}

class Teacher
{
  private:
    string name;
  public:
    void setname(string);  //设置老师姓名
    string getname();      //获得老师姓名
    void addcredit(Student &, int);
    void addscore(Student &, double);
};

void Teacher::setname(string s)
{
    name = s;
}

string Teacher::getname()
{
    return name;
}

void Teacher::addcredit(Student &s, int a)
{
   s.credit += a;
}

void Teacher::addscore(Student &s, double b)
{
    s.score += b;
}

int main()
{
  int n_s, n_t;
  string n;
  cout << "您需要建立几位学生（M）和几位教师（N）：";
  cin >> n_s >> n_t;
  Student* students =  new Student[n_s];
  Teacher* teachers =  new Teacher[n_t];

//输入学生和老师的姓名
  cout << "请输入" << n_s << "位学生的姓名：";
  for(int i=0; i<n_s; i++)
  {
      cin >> n;
      students[i].setname(n);
  }
  cout << "请输入" << n_t << "位教师的姓名：";
  for(int j=0; j<n_t; j++)
  {
      cin >> n;
      teachers[j].setname(n);
  }

//增加学分、总成绩
  string tname, sname;
  int m_credit,i,j;
  double m_score;
  char judge;
  do{
     cout << "请选择一位教师：";
     cin >> tname;
     for(i=0; i<n_t; i++)
     {
        if(teachers[i].getname() == tname)break;
     }
     if(i>= n_t)
     {
         cout << "没有找到教师！"<< endl; continue;
     }

     bool judge1 = false;
     do
     {
         cout << "请选择一位学生：";
         cin >> sname;
         for(j =0; j<n_s;j++)
         {
           if(students[j].getname() == sname){ judge1 = true;break;}
         }
         if(j >= n_s)
            cout << "没有找到学生！"<<endl;}while(!judge1);

     cout << "请输入要增加的学分：";
     cin >> m_credit;
     teachers[i].addcredit(students[j],m_credit);
     cout << "教师" << teachers[i].getname() << "给学生" << students[j].getname() << "增加" << m_credit << "学分，操作成功。" << endl;
     cout << "请输入要增加的总成绩：";
     cin >> m_score;
     teachers[i].addscore(students[j],m_score);
     cout << "教师" << teachers[i].getname() << "给学生" << students[j].getname() << "增加总成绩" << m_score << "，操作成功。" <<endl;
     cout << "还要继续吗？（Y/N）：";
     cin  >> judge;}while(judge != 'n' && judge != 'N');

     cout << "学生信息：" << endl;
     cout << "姓名" << "  " << "总学分" << "  " << "总成绩" << endl;
     for(int k=0; k<n_s;k++)
        students[k].show();
return 0;
}

