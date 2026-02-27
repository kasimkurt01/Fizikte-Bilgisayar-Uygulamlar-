#include<cmath>
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
const float PI=3.141593;

double N=1000;
double h=6*PI/N;
double ivme(double x, double v){
	return -x-0.3*v;
}

double Hiz(double x, double v){
	return v+ivme(x,v)*h;
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
		//cout <<t<< " " << x2 << " " << v2 << "\n";
		dosya <<t<< " " << x2 << " " << v2 << "\n";
		x1=x2;
		v1=v2; 
		
	}
	dosya.close();
	// Gnuplot komut dosyasý oluþtur
    std::ofstream gnuplotScript("plot.plt");
    gnuplotScript << "set title 'Kütle Yay'\n";
    gnuplotScript << "set xlabel 'W(t) Zaman'\n";
    gnuplotScript << "set ylabel 'Genlik (Hýz ve Konum)'\n";
    gnuplotScript << "plot 'veri.txt' using 1:2 with linespoints linewidth 0.1 pointtype 0 title"
	<<" 'Hiz (V)', '' using 1:3 with linespoints linewidth 0.1 pointtype 0 title 'Konum (X)'\n";
    //gnuplotScript << "plot 'kutleyay.txt' using 1:3:2 with linespoints linewidth 0.1 pointtype 0 title 'Veri Seti'\n";
    gnuplotScript << "pause -1\n"; // pencereyi kapatma
    gnuplotScript.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot.plt");
}