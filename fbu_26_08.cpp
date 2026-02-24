#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;
int N= 400;
double E=1.2;
double k=8.617e-5;
double s=1e10;
double w[6]={0.17132449,0.17132449,0.36076157,0.36076157,0.46791393,0.46791393};
double x[6]={0.93246951,-0.93246951,0.66120939,-0.66120939,0.23861919,-0.23861919};
double fnk(double x){
	return s*exp(-E/(k*x));
}

// Gauss Sayısal integral yöntemi
double GaussInt(double a, double b){
	double integral=0;
	for(int i=0; i < 6; i++){
		integral =integral + w[i]*fnk(((b-a)*x[i]+(b+a))/2);
	}
	return (b-a)/2*integral;
}
// Simpson Sayısal İntegral Yöntemi
double SimpsonInt(double a, double b){
	double h=(b-a)/N;
	double integral=0;
	double x=a;
	int i;
	integral = fnk(a)+fnk(b);
	for(i=1;i<N;i++){
		x=a+i*h;
		if(i%2==0) integral +=2*fnk(x);
		else integral +=4*fnk(x);
	}
	return h/3*integral;
}
// Trapez Sayısal integral yömtemi
double TrpzInt(double a, double b){
	double h = (b-a)/N;
	double s=0;
	double x=a;
	s=fnk(a)+fnk(b);
	for(int i=1;i<N ; i++){
		x=x+h;
		s=s+2*fnk(x);
	}
	return s*h/2;
}
int main(){
	double x1=300;
	double x2=600;
	cout << "G integral :" << GaussInt(x1,x2) << endl;
	cout << "S integral :" << SimpsonInt(x1,x2) << endl;
	cout << "T integral :" << TrpzInt(x1,x2) << endl;
}