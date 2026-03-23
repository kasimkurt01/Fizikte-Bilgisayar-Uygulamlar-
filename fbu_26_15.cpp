// Runga-Kutta yöntemi ile Diffransiyel deneklem çözümü
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
float dif(float x, float y){
	return (x+y);
}
float fx(double x){
	return 2*exp(x)-x-1;
}
int main(){
	float x1=0,y1=1;
	float dx=1e-1;
	float x2=2,y2;
	float k1,k2,k3,k4;
	ofstream file;
	file.open("rungekutta.csv");
	cout <<setw(10)<< "x1" <<setw(10)<< "y1" <<setw(10)<< "fx"<< endl;
	file <<setw(10)<< "x1" <<setw(10)<< "y1" <<setw(10)<< "fx"<< endl;

	while(abs(x2-x1)>1e-4){
		k1=dif(x1,y1);
		k2=dif(x1+0.5*dx,y1+0.5*dx*k1);
		k3=dif(x1+0.5*dx,y1+0.5*dx*k2);
		k4=dif(x1+dx,y1+dx*k3);
		y2=y1+dx*(k1+2*k2+2*k3+k4)/6;
		cout <<setw(10)<< x1 <<"-" <<setw(10)<< y1<<"-"  <<setw(10)<< fx(x1)<< endl;
		file <<setw(10)<< x1 <<"-" <<setw(10)<< y1<<"-"  <<setw(10)<< fx(x1)<< endl;
	
		y1=y2;
		x1=x1+dx;
	}
	file.close();
	return 0;
}