// Kök bulma ISING Modeli
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;



double fx(double s , double T){
	return s-tanh(4*s/T);
}

double dfx(double x,double T){
	double dx= 1e-5;
	return (fx(x+dx,T)- fx(x-dx,T))/(2*dx);
}

double NR(double x, double T){
	double dx, xk;
	int i=1;
	xk=x-fx(x,T)/dfx(x,T);
	dx=abs(x-xk);
	x=xk;
	while(dx>1e-5 && i<50){
		xk=x-fx(x,T)/dfx(x,T);
		i++;
		dx=abs(x-xk);
		x=xk;		
	}
	if(i>=50) {
		cout << "Kök bulunmadi";
		return -11111;
	}
	return xk;
}



int main(){
	double T=1e-6;
	double dT=1e-2;
	double s=1e-3,s1;
	ofstream dsy("ising.txt");
	while (T<7){
	   s1=NR(s,T);
	//   cout << T << "  " << s1<< endl;
	   dsy << T << " " << s1 << endl;
	   T=T+dT;
	   s=s1;	
	}
	dsy.close();
	// Gnuplot komut dosyası oluştur
    std::ofstream GnuPlot("ising.plt");
    GnuPlot << "set title 'Ising Model'\n";
    GnuPlot << "set xlabel 'Sicaklik(T) Kelvin'\n";
    GnuPlot << "set ylabel 'Mannetizasyon (s) a.u'\n";
    GnuPlot << "plot 'ising.txt' using 1:2 with linespoints linewidth 0.5 pointtype 2 title " << " 'Magnet (m)' \n";
   
    GnuPlot << "pause -1\n"; // pencereyi kapatma
    GnuPlot.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" ising.plt");

}