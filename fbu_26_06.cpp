#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;
int N= 100;
double E=1.2;
double k=8.617e-5;
double s=1e10;
double fnk(double x){
	return s*exp(-E/(k*x));
}

double Simpson(double a, double b){
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

int main(){
	double x1=300;
	double x2=600;
	cout << "S integral :" << Simpson(x1,x2) << endl;
}