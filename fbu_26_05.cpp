#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;
int N= 400;

double Fx(double x){
	return 1/x;
}
double TrpzInt(double a, double b){
	double h = (b-a)/N;
	double s=0;
	double x=a;
	s=Fx(a)+Fx(b);
	for(int i=1;i<N ; i++){
		x=x+h;
		s=s+2*Fx(x);
	}
	return s*h/2;
}

int main(){
	double a=1;
	double b=10;
	
	cout << "int sonucu :" << TrpzInt(a,b) << endl;
}