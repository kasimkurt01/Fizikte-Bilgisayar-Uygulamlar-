#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;
int N= 6;
double E=1.2;
double k=8.617e-5;
double s=1e10;
double w[6]={0.17132449,0.17132449,0.36076157,0.36076157,0.46791393,0.46791393};
double x[6]={0.93246951,-0.93246951,0.66120939,-0.66120939,0.23861919,-0.23861919};
double fnk(double x){
	return s*exp(-E/(k*x));
}


double GaussInt(double a, double b){
	double integral=0;
	for(int i=0; i < N; i++){
		integral =integral + w[i]*fnk(((b-a)*x[i]+(b+a))/2);
	}
	return (b-a)/2*integral;
}

int main(){
	double x1=300;
	double x2=600;
	cout << "G integral :" << GaussInt(x1,x2) << endl;
	
}