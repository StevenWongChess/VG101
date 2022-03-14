#include <iostream> 
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
const float RATE = 6.20350;

void ex1(){
	int current_year, another_year, current_age, another_age;
	cin >> current_year >> current_age >> another_year;
	another_age = another_year + current_age - current_year;
	cout << another_age << endl;
};

void ex2(){
	int option,precision;
	float amount, result;
	cin >> option >> amount >> precision;
	result = (option==1)?amount*RATE:amount/RATE;
	cout << setprecision(precision) << result << endl;
};

void ex3(){
	ifstream in("1.txt");
	ofstream out("2.txt");
	string line; 
	stringstream ss;
	int n; 
	int tmp;
	getline(in, line);
	ss << line;
	while(ss >> tmp){
		n++;
	}
	// we first have to judge the size of matrix

	//in.close();
	//ifstream in2("1.txt");
	// Do not need to reopen
//https://stackoverflow.com/questions/28331017/rewind-an-ifstream-object-after-hitting-the-end-of-file
//https://stackoverflow.com/questions/5343173/returning-to-beginning-of-file-after-getline
	in.clear();
	in.seekg(0);
	int a[n][n];
	int b[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			in >> a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			in >> b[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			out << a[i][j]+b[i][j] << " ";
		}
		out << endl;
	}

	in.close(); out.close();
};

int fun1(int a){
	int index = 0;
	int last = a;
	while (last != 1){
		if (last%2==0)
			last /= 2;
		else
			last = last * 3 + 1;
		index ++;
	}
	return index;
};

int fun2(int M){
	int A = 2;
	int N_max = 0;
	for(int a = 2; a < M + 1; a++){
		int tmp = fun1(a);
		if (tmp > N_max){
			N_max = tmp;
			A = a;
		}
	}
	return A;
};

void ex4(){
	int choice;
	int initial;
	cin >> choice >> initial;
	int result = (choice==1)?fun1(initial):fun2(initial);
	cout << "result is " << result << endl;
};

static const char GRADES[] = {'F','F','F','F','F','F','D','C','B','A','A'};

class Grade{
public:
	void GradePrct(int prct);
	void GradeLtr(char ltr);
	void printGrade();
private:
	char ltr;
	int prct;
};

void Grade::GradePrct(int prct){
	this->prct = prct;
	this->ltr = GRADES[prct/10];
};

void Grade::GradeLtr(char ltr){
	this->ltr = ltr;
	this->prct = 100 - (ltr - 'A') * 10 - 5;
};

void Grade::printGrade(){
	cout << "Grade: " << prct << " -> " << ltr << endl;
};

void ex5(){
	Grade g;
	int prct; char ltr;
	cout << "Input two space seprated grades (1st in %%, 2nd in letter): ";
	cin >> prct >> ltr;
	g.GradePrct(prct);
	g.printGrade();
	g.GradeLtr(ltr);
	g.printGrade();
};

int main () { 
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
}
