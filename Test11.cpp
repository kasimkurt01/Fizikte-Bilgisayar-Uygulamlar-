#include<cmath>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
const float PI=3.141593;

double fx(double x){
	return x*x-exp(-x)-exp(1);
}

double dfx(double x){
	double h=1e-4;
	return (fx(x+h)-fx(x-h))/(2*h);
}

double KokY(double a, double b){
	double dx;
	double xm;
	
	dx = abs(a-b);
	if(fx(a)*fx(b)<0){
		xm=(a+b)/2;
		while (dx > 1e-6 ) {
		   if(fx(xm)*fx(a)<=0) b=xm;
		   else
		   if(fx(xm)*fx(b)<=0) a=xm;
		   	xm=(a+b)/2; 
		   	dx = abs(a-b);
		}
	} else return -1111;
	
	return xm;
}

double Kiris(double a, double b){
	double x1,x2,xk,dx;
	int i=1;
	x1=a; x2=b;
	dx=abs(x1-x2);
	while (dx>1e-4 && i<50){
		xk=x2-(x2-x1)*fx(x2)/(fx(x2)-fx(x1));
		x1=x2;
		x2=xk;
		dx=abs(x1-x2);
		i++;
	}
	if(i<50) return xk;
	else 
	{
		cout << "Kok bulunamadý ";
		return -1111;
	}
	 
}


double NR(double a){
	double x,xk,dx;
	int i=1;
	x=a;
	xk=x-fx(x)/dfx(x);
	dx=abs(x-xk);
	
	while(dx>1e-4 && i<50){
		x=xk;
		xk=x-fx(x)/dfx(x);
		dx=abs(x-xk);
		i++;
	}
	if(i<50) return xk;
	else 
	{
		cout << "iterayon yeterli deðil Kok bulunamadý ";
		return -1111;
	}
	
}

int main(){
	double a=-3, b= 4;
	setlocale(LC_ALL, "TURKISH");
	cout << "fonksiyonun " << a << " ile " << b << " arasýndaki Yarýla \t\t"
	     << KokY(a,b) << " dir\n";	
		 
	cout << "fonksiyonun " << a << " ile " << b << " arasýndaki kökü Kiriþ\t"
	     << Kiris(a,b) << " dir\n";		
	cout << "fonksiyonun " << a << " ile " << b << " arasýndaki kökü NR \t\t"
	     << Kiris(a,b) << " dir\n";		  
	return 0; 
}