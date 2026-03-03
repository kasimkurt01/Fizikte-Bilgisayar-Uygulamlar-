// Kök bulma
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;



double fx(double x){
	return exp(x)*log(x)-pow(x,2);
}

double KokY(double a, double b){
	double xm, x1,x2,dx;
	x1=a; x2=b;
	if(fx(x1)*fx(x2) <0) {
		xm=(x1+x2)/2;
		dx=abs(xm-x1);
		while(dx>1e-6){
			if(fx(xm)*fx(x2)<0){
				x1=xm;
				xm=(x1+x2)/2;
				dx=abs(xm-x1);
			}
			else 
			if(fx(xm)*fx(x1)<0){
				x2=xm;
				xm=(x1+x2)/2;
				dx=abs(xm-x1);	
			}			
		}
		return xm;		
	}
	else {
		cout<< x1 << " --- " << x2 << "Bu aralýklarda Kok Yok\n";
		return -111111;
	}
}
int main(){
	double a=1;
	double b=3;
	cout << "Denklemin kokleri :"<< KokY(a,b) << "\n";
}
