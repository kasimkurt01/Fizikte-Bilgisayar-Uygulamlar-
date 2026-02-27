#include<cmath>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
const float PI=3.141593;

double N=200;
double h=4*PI/N;
double ivme(double x){
	return -x;
}

double Hiz(double x, double v){
	return v+ivme(x)*h;
}

double Konum(double x, double v){
	return x+ v*h;
}

int main(){
	double t=0;
	int i;
	double v1=0,v2,x1=1,x2;
	ofstream dosya("veri.txt");
	for(i=0; i<N;i++){
		t=i*h;
		v2=Hiz(x1,v1);
		x2=Konum(x1,v1);
		cout <<t<< " " << x2 << " " << v2 << "\n";
		dosya <<t<< " " << x2 << " " << v2 << "\n";
		x1=x2;
		v1=v2; 
		
	}
	dosya.close();
	
}