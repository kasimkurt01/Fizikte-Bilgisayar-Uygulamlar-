//Euler dif denklem çözümü 
#include<iostream>
#include<cmath>
#include<fstream>
#include <cstdlib>
using namespace std;
double dx=1e-2;
double dydx(double x, double y){
	return x+y;
}

double Euler(double x,double y){
	return y+dx*dydx(x,y);
}
double yt(double x){
	return 2*exp(x)-x-1;
}
int main(){
	ofstream f;
	f.open("Euler.txt");
	double x1,x2,y1,y2;
	x1=0; y1=1;
	cout <<  "x1 \t " << " y1 \t " << "ytam "<<endl;
//	f <<  "x1 \t-"<< " y1 \t-"<< "\ ytam "<<endl;
	while (x1<10){
		cout << x1<< "\t"<< y1 << "\t"<< yt(x1)<<endl;
		f << x1<< " " << y1 << " " << yt(x1)<<endl;
		y2=Euler(x1,y1);
		x2=x1+dx;
		x1=x2;
		y1=y2;
	}
	f.close();
// Gnuplot komut dosyası oluştur 
    ofstream gnuplotScript("plot.plt");
    gnuplotScript << "set title 'Euler'\n";
    gnuplotScript << "plot 'Euler.txt' with lines\n";
    gnuplotScript << "pause -1\n"; // pencereyi kapatma
    gnuplotScript.close();

    // Gnuplot'u çalıştır
    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot.plt");

	
}
