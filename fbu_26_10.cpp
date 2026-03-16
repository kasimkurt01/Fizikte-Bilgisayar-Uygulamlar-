// Kök bulma Kriş yöntemi
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;



double fx(double x){
	return exp(x)*log(x)- pow(x,2);
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
	double a=1;
	double b=5;
	cout << "Denklemin kokleri : "<< KokK(a,b) << "\n";
}
