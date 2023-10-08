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
    void setname(string);  //����ѧ������
    string getname();      //���ѧ������
    void setcredit(int);   //����ѧ��ѧ��
    void setscore(double); //����ѧ���ɼ�
    void show();
};

Student::Student(string name, int credit, double score)
{
   this -> name = name;
   this -> credit =credit;
   this -> score = score;
}


void Student::setname(string s) //����ѧ������
{
   name = s;
}

string Student::getname()      //���ѧ������
{
    return name;
}

void Student::setcredit(int c)   //����ѧ��ѧ��
{
    credit = c;
}

void Student::setscore(double s) //����ѧ���ɼ�
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
    void setname(string);  //������ʦ����
    string getname();      //�����ʦ����
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
  cout << "����Ҫ������λѧ����M���ͼ�λ��ʦ��N����";
  cin >> n_s >> n_t;
  Student* students =  new Student[n_s];
  Teacher* teachers =  new Teacher[n_t];

//����ѧ������ʦ������
  cout << "������" << n_s << "λѧ����������";
  for(int i=0; i<n_s; i++)
  {
      cin >> n;
      students[i].setname(n);
  }
  cout << "������" << n_t << "λ��ʦ��������";
  for(int j=0; j<n_t; j++)
  {
      cin >> n;
      teachers[j].setname(n);
  }

//����ѧ�֡��ܳɼ�
  string tname, sname;
  int m_credit,i,j;
  double m_score;
  char judge;
  do{
     cout << "��ѡ��һλ��ʦ��";
     cin >> tname;
     for(i=0; i<n_t; i++)
     {
        if(teachers[i].getname() == tname)break;
     }
     if(i>= n_t)
     {
         cout << "û���ҵ���ʦ��"<< endl; continue;
     }

     bool judge1 = false;
     do
     {
         cout << "��ѡ��һλѧ����";
         cin >> sname;
         for(j =0; j<n_s;j++)
         {
           if(students[j].getname() == sname){ judge1 = true;break;}
         }
         if(j >= n_s)
            cout << "û���ҵ�ѧ����"<<endl;}while(!judge1);

     cout << "������Ҫ���ӵ�ѧ�֣�";
     cin >> m_credit;
     teachers[i].addcredit(students[j],m_credit);
     cout << "��ʦ" << teachers[i].getname() << "��ѧ��" << students[j].getname() << "����" << m_credit << "ѧ�֣������ɹ���" << endl;
     cout << "������Ҫ���ӵ��ܳɼ���";
     cin >> m_score;
     teachers[i].addscore(students[j],m_score);
     cout << "��ʦ" << teachers[i].getname() << "��ѧ��" << students[j].getname() << "�����ܳɼ�" << m_score << "�������ɹ���" <<endl;
     cout << "��Ҫ�����𣿣�Y/N����";
     cin  >> judge;}while(judge != 'n' && judge != 'N');

     cout << "ѧ����Ϣ��" << endl;
     cout << "����" << "  " << "��ѧ��" << "  " << "�ܳɼ�" << endl;
     for(int k=0; k<n_s;k++)
        students[k].show();
return 0;
}

