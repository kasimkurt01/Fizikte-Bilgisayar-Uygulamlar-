#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double const PI=3.141593;
int main(){
long double h=1.0;
long double x=PI/6;
long double t,tt;
	setlocale(LC_ALL,"TURKISH");
	tt=cos(x);	
	t=(sin(x+h)-sin(x))/h; //ileri türev
	cout << setw(15)<<"h deðeri"<<setw(15)<<"turev" 
	<< setw(15)<<"Tam Türev "<<setw(15)<<"Hata\n";
	
	cout <<  setw(15)<<h << setw(15) <<t << 
	 setw(15)<< tt<< setw(15)<< tt-t<< "\n";
	 
	 while (h>1e-20){
	 	h=h/10;
	 	t=(sin(x+h)-sin(x))/h;
	 	cout <<  setw(15)<<h << setw(15) <<t << 
	 setw(15)<< tt<< setw(15)<< tt-t<< "\n";
	 	
	 }
	
}
