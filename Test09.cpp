#include<cmath>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
const float PI=3.141593;

double fx(double x){
	return x*tan(x)-1;
}

double KokY(double a, double b){
	double dx;
	double xm;
	
	dx = abs(a-b);
	if(fx(a)*fx(b)<0){
		xm=(a+b)/2;
		while (dx > 1e-5 ) {
		   if(fx(xm)*fx(a)<=0) b=xm;
		   else
		   if(fx(xm)*fx(b)<=0) a=xm;
		   	xm=(a+b)/2; 
		   	dx = abs(a-b);
		}
	} else return -1111;
	
	return xm;
}

int main(){
	double a=0, b= 1;
	setlocale(LC_ALL, "TURKISH");
	cout << "fonksiyonun " << a << " ile " << b << " arasındaki kökü "
	     << KokY(a,b) << " dir\n";		 
	return 0; 
}