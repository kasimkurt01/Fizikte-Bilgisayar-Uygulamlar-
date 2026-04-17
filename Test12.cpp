// Euler
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double h=1e-2;

double dydx(double x, double y){
	return x+y;
}

double Euler(double x, double y){
	return y+h*dydx(x,y);
}
double fx(double x){
	return 2*exp(x)-x-1;
}
int main(){
	double  y1,x1,y2,x2,end;
	y1=1;
	x1=1e-3;
	end=10;
	ofstream dsy("euler.txt");
	while(x1<end){
		y2=Euler(x1,y1);
	//	cout << " x :" << x1 <<"\t y:" <<y1 << " \ttmde :" <<fx(x1)<< endl;
		dsy << x1 << " " << y1 << endl;
		y1=y2;
		x1+=h;
	}
	dsy.close();
	// Gnuplot komut dosyasý oluþtur
    std::ofstream GnuPlot("euler.plt");
    GnuPlot << "set title 'Euler'\n";
    GnuPlot << "set xlabel 'X'\n";
    GnuPlot << "set ylabel 'Y '\n";
    GnuPlot << "plot 'euler.txt' using 1:2 with linespoints linewidth 0.5 pointtype 0 title " << " 'Euler ' \n";
   
    GnuPlot << "pause -1\n"; // pencereyi kapatma
    GnuPlot.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" euler.plt");

}