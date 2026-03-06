#include<cmath>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
const float PI=3.141593;

double N=10;

double fx(double x){
	return x*x;
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
	double b=3;
	cout << "integral Trapez :" << IntT(a,b) << endl;
	cout << "integral Simpson:" << IntS(a,b) << endl;
}