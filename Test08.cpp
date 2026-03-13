#include<cmath>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
const float PI=3.141593;

int N=6;
double w[6]={0.17132449,0.17132449,0.36076157,0.36076157,0.46791393,0.46791393};
double x[6]={0.93246951,-0.93246951,0.66120939,-0.66120939,0.23861919,-0.23861919};

double fx(double x){
	return exp(x);
}

double IntG(double a, double b){
	double s=0,u;
	for(int i=0;i<N;i++){
		u=((b-a)*x[i]+(b+a))/2;
		s=s+w[i]*fx(u);
	}
	return s=(b-a)/2*s;
}
double IntT(double a, double b){
	double h = (b-a)/N;
	double s=0,x;
	int i;
	s=fx(a)+fx(b);
	for(i=1;i<N;i++) {
		x=a+i*h;
		s=s+2*fx(x);
	} 
	return s*h/2;
}
double IntS(double a, double b){
	double h=(b-a)/N;
	double s=0,x;
	x=a; int i;
	s=fx(a)+fx(b);
	for(i=1;i<N;i++){
		x=a+i*h;
		if(i%2==0) s=s+2*fx(x);
		else s=s+4*fx(x);
	}
	return s*h/3;
}
int main(){
	
	double a=0;
	double b=1;
	cout << "integral Trapez :" << IntT(a,b) << endl;
	cout << "integral Simpson:" << IntS(a,b) << endl;
    cout << "integral Gaussn:" << IntG(a,b) << endl;
}