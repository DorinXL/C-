#include<iostream>
#include<cstring>
using namespace std;
enum sex{man,woman};

class Cperson{
	public:
		Cperson():name("��������"),age(114514),astu(man){};
		Cperson(string a,int b,sex c):name(a),age(b),astu(c){};
		void SetPerson(string a,int b,sex c){
			name = a; age = b; astu = c;
		}
		string GetName(){return name;}
		int GetAge(){return age;}
		sex GetSex(){return astu;}
	private:
		string name;
		int age;
		sex astu;
};
class CCourse{
	public:
		CCourse():course_name("������Ŀ"),credit(0),score(0){};
		CCourse(string a,double b,double c):course_name(a),credit(b),score(c){};
		void SetCourse(string a,double b,double c){
			course_name = a; credit = b; score = c;
		}
		string GetCoure_Name(){return course_name;}
		double GetCreidt(){return credit;}
		double GetScore(){return score;}
	private:
		string course_name;
		double credit;
		double score;
};
class CStudent :virtual public Cperson{
	public:
		CStudent():Cperson(),rank(0),total_score(0),total_credit(0),ave_score(0){};
		CStudent(string a,int b,sex c,int r):Cperson(a,b,c),rank(r),total_score(0){};
		CCourse* GetCourse(int n){
			return course + n;
		}
		void SetStudent(string a,int b,sex c,int r){
			this->SetPerson(a,b,c);
			this->rank = r;
		}
		int GetRank(){return rank;}
		double GetTotal_Score();
		double GetTotal_Credit();
		double GetAve_Score();
	private:
		int rank;
		CCourse course[8];
		double total_score;
		double total_credit;
		double ave_score;
		
};
double CStudent::GetTotal_Score(){
	for(int i = 1;i <= 7;i++){
		if(course[i].GetScore()){
			total_score += course[i].GetScore();
		}
	}
	return total_score;
}
double CStudent::GetTotal_Credit(){
	for(int i = 1;i <= 8;i ++){
		if(course[i].GetCreidt()){
			this->total_credit += course[i].GetCreidt();
		}
	}
	return total_credit;
}
double CStudent::GetAve_Score(){
	int i,sum = 0,flag = 0;
	for(i = 1;i <= 8;i++){
		if(course[i].GetScore()){
			sum += course[i].GetScore();
			flag++;
		}
	}
	ave_score = sum / flag;
	return ave_score;
}
class CClass{
	public:
		CClass(){pstu = new CStudent [10];}
		CClass(int n){pstu = new CStudent [n];}
		CStudent* GetStudent(int n){
			return (pstu + n);
		}
		void Seek(int);
	private:
		CStudent *pstu;
		int class_num,people_num;
		
};
void CClass::Seek(int num){
	cout<<"ѧ���������� "<< pstu[num].GetName() <<endl;
	cout<<"ѧ�������䣺 "<< pstu[num].GetAge() <<endl;
	cout<<"ѧ�����Ա� ";
	if(pstu[num].GetSex() == 0) cout<<"man"<<endl;
	else cout<<"woman"<<endl;
	cout<<"ѧ����ѧ�ţ� "<< pstu[num].GetRank() <<endl;
	cout<<"ѧ����ƽ���ɼ��� "<< pstu[num].GetAve_Score() <<endl;
	cout<<"ѧ�����ܳɼ��� "<< pstu[num].GetTotal_Score() <<endl;
	cout<<"ѧ������ѧ�֣� "<< pstu[num].GetTotal_Credit() <<endl<<endl;
}

class CTutor : public Cperson{
	public:
		CTutor():Cperson(){position = "tutor";}
		CTutor(string a,int b,sex c,string d):Cperson(a,b,c){position = d;}
		void SetPosition(string a){
			position = a;
		}
		string GetPosition(){
				return position;
		}
	private:
		string position;
};

class CGraduateStudent : public CStudent,virtual public Cperson{
	public:
		CGraduateStudent():CStudent(){}
		CGraduateStudent(string a,int b,sex c,string d):Cperson(a,b,c){totur_name = d;};
		void SetGraduateStudent(string a){
			totur_name = a;
		}
		string GetTotur_name(){
				return totur_name;
		}
	private:
		string totur_name;
};
int main(){
	CTutor tutor("��ʦ",34,man,"amaizng!");
	cout<<tutor.GetName()<<"��ְλ: "<<tutor.GetPosition()<<endl;
	CGraduateStudent stu("�о���",20,woman,"��ʦ");
	cout<<stu.Cperson::GetName()<<"�ĵ�ʦ�� "<<stu.GetTotur_name()<<endl; 

	return 0;
}
