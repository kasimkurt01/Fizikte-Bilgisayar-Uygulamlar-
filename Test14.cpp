// Runga-Kutta yöntemi ile Diffransiyel deneklem çözümü
// Av Avcý
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
float a=0.25,b=1e-2,c=1.0,d=1e-2;
float h=1e-1;

struct Nufus{
  float Tavsan;
  float Tilki;	
};
float dif1(float y1, float y2){
	return (a*y1-b*y1*y2);
}

float dif2(float y1, float y2){
	return (-c*y2+d*y1*y2);
}
Nufus RK4(Nufus &y){
	float k1,k2,k3,k4;
	float l1,l2,l3,l4;
	float y1,y2;
	y1=y.Tavsan;
	y2=y.Tilki;
	k1=dif1(y1,y2);
	l1=dif2(y1,y2);
	
	k2=dif1(y1+0.5*h*k1,y2+0.5*h*l1);
	l2=dif2(y1+0.5*h*k1,y2+0.5*h*l1);
	
	k3=dif1(y1+0.5*h*k2,y2+0.5*h*l2);
	l3=dif2(y1+0.5*h*k2,y2+0.5*h*l2);
	
	k4=dif1(y1+h*k3,y2+h*l3);
	l4=dif2(y1+h*k3,y2+h*l3);
	
	y1 += h/6*(k1+2*(k2+k3)+ k4);
	y2 += h/6*(l1+2*(l2+l3)+ l4);
	return {
		y.Tavsan=(y1),
		y.Tilki=(y2)
	
	};
	
}

int main(){
	
	int tv1=80;
	int tl1=30;
	int N=200;
	float t=0;
	Nufus n;
	ofstream File("Av.txt");
	n.Tavsan=tv1;
	n.Tilki =tl1;
	 while (t< N) {
	 	
	 	n = RK4(n);
	 	File << fixed << setprecision(4) 
		     << t << " " << n.Tavsan << " " << n.Tilki<< "\n";
	 	
	 	t +=h;
	 	
	 }
		
	File.close();
	// Gnuplot komut dosyasý oluþtur
    std::ofstream GnuPlot("Av.plt");
    GnuPlot << "set title 'Tavsan Tilki'\n";
    GnuPlot << "set xlabel 'Zaman '\n";
    GnuPlot << "set ylabel 'Tavsan Tilki '\n";
    GnuPlot << "plot 'Av.txt' using 1:2 with linespoints linewidth 0.5 pointtype 0 title"
	<<" 'Y ', '' using 1:3 with linespoints linewidth 0.5 pointtype 0 title ' (X)'\n";
   
    GnuPlot << "pause -1\n"; // pencereyi kapatma
    GnuPlot.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" Av.plt");	
	
	
}