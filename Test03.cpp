#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const float PI=3.141593;
int main(){
	setlocale(LC_ALL,"TURKISH");
	double h=1;
	double  t;
	double tt;
	double x=PI/6;
	t=(sin(x+h)-sin(x))/h;
	tt= cos(x);
	cout << setw(15)<<"h deðeri"<<setw(15)<<"turev" 
	<< setw(15)<<"Tam Türev "<<setw(15)<<"Hata\n";
	
	cout <<  setw(15)<<h << setw(15) <<t << 
	 setw(15)<< tt<< setw(15)<< tt-t<< "\n";
	 
	 for(int i=1;i<=10;i++){
	 	h=h/10;
	 	t=(sin(x+h)-sin(x))/h;
	 	cout <<  setw(15)<<h << setw(15) <<t << 
	 setw(15)<< tt<< setw(15)<< tt-t<< "\n";
	 	
	 }
	
	

	return 0;
}