#include<iostream>
using namespace std;

int main(){
	setlocale(LC_ALL,"TURKISH");
	int i,t=0;
	for(i=0;i<=10;i+=3) t=t+i;	
	cout << "Toplam = " << t << "\n";	
	return 0;
}