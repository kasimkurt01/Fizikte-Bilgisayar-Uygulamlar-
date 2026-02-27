#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const float PI=3.141593;
double h=1e-3;
double Fnk(double x){
	return sin(x);
}
double TurevI(double x){
	return (Fnk(x+h)-Fnk(x))/h;
}

double TurevG(double x){
	return (Fnk(x)-Fnk(x-h))/h;
}

double TurevS(double x){
	return (Fnk(x+h/2)-Fnk(x-h/2))/(h);
}
int main(){
	setlocale(LC_ALL,"TURKISH"); // Türkçe karakterlerin yazýlmasý için
	cout << "Ýleri    Türev :" << TurevI(PI/3) << endl;
	cout << "Geri     Türev :" << TurevG(PI/3) << endl;
	cout << "Simetik  Türev :" << TurevS(PI/3) << endl;
	
}