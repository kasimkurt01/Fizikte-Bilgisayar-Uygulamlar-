// Kök bulma Newton Raphson yöntemi
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;



double fx(double x){
	return x*x-4;
}

double dfx(double x){
	double dx= 1e-5;
	return (fx(x+dx)- fx(x-dx))/(2*dx);
}

double NR(double x){
	double dx, xk;
	int i=1;
	xk=x-fx(x)/dfx(x);
	dx=abs(x-xk);
	x=xk;
	while(dx>1e-5 && i<50){
		xk=x-fx(x)/dfx(x);
		i++;
		dx=abs(x-xk);
		x=xk;		
	}
	if(i>=50) {
		cout << "Kök bulunmadi";
		return -11111;
	}
	return xk;
}
double KokK(double a, double b){
	double x,x1,x2,dx;
	int i=1;
	x1=a; x2=b;
	x=x1-fx(x1)*(x2-x1)/(fx(x2)-fx(x1));
	x1=x2;
	x2=x;
	dx=abs(x2-x1);
	while(dx>1e-6 && i<50 ){
		x=x2-(x2-x1)*fx(x2)/(fx(x2)-fx(x1));
		x1=x2;
		x2=x;
		dx=abs(x2-x1);
		i++;
		if (i==50){
			cout << "Kok Bulunmamadi";
			return -111111;
		}		
	}
	return x;
}


int main(){
	double a=-5;
	double b=-1;
	cout << "Denklemin kokleri Kiris    : "<< KokK(a,b) << "\n";
	cout << "Denklemin kokleri N-Raphson: "<< NR(b) << "\n";
}