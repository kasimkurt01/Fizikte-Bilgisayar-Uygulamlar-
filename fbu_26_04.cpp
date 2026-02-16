#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
const double PI=3.141593;
int N= 400;
const double h=4*PI/N;
const double m=1.0;
const double k=1.0;


double kvt(double x, double v){
	return -k/m*x;
}

double hiz(double x, double v){
	return v+h*kvt(x,v);
}

double konum(double x, double v){
	return x+h*hiz(x,v);
}

int main(){
	double xi=1,vi=0, vs,xs;
	int n=0;
	 double t=0;
	 ofstream dosya("kutleyay.txt");
	 cout << t << " " << vi << " " << xi << endl;
	 dosya << t << " " << vi << " " << xi << endl;
	for(n=0;n<=N;n++){
		t=n*h;
		vs=hiz(xi,vi);
		xs=konum(xi,vi);
		cout << t << "   " << vs << "   " << xs << endl;
		dosya << t << " " << vs << " " << xs << endl;
		xi=xs;
		vi=vs;
	}
	dosya.close();
// Gnuplot komut dosyası oluştur
    std::ofstream GnuPlot("ciz.plt");
    GnuPlot << "set title 'Kütle Yay'\n";
    GnuPlot << "set xlabel 'Zaman(t) saniye'\n";
    GnuPlot << "set ylabel 'Genlik (Hız ve Konum)'\n";
    GnuPlot << "plot 'kutleyay.txt' using 1:2 with linespoints linewidth 0.5 pointtype 0 title"
	<<" 'Hiz (V)', '' using 1:3 with linespoints linewidth 0.5 pointtype 0 title 'Konum (X)'\n";
   
    GnuPlot << "pause -1\n"; // pencereyi kapatma
    GnuPlot.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" ciz.plt");
	
}