// Av Avcı Runga Kutta
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
	
	float a=0.25;
	float b=1e-2;
	float c=1;
	float d=1e-2;
	float dt=1e-1;
using namespace std;
float dif1(float t, float x, float y){
	return (a*x-b*x*y);
}
float dif2(float t,float x, float y){
	return (d*x*y-c*y);
}
double RK4(float t,float x, float y, bool b){
	float k1,k2,k3,k4;
	if(b) {
		k1=dif1(t,x,y);
		k2=dif1(t+0.5*dt,x+0.5*dt*k1,y);
		k3=dif1(t+0.5*dt,x+0.5*dt*k2,y);
		k4=dif1(t+dt,x+dt*k3,y);
		return x+dt*(k1+2*k2+2*k3+k4)/6;		
	} else {
		k1=dif2(t,x,y);
		k2=dif2(t+0.5*dt,x,y+0.5*dt*k1);
		k3=dif2(t+0.5*dt,x,y+0.5*dt*k2);
		k4=dif2(t+dt,x,y+dt*k3);
		return y+dt*(k1+2*k2+2*k3+k4)/6;	
		
	}
	
}
int main(){
	float x1=80;
    float  y1=30;
	
	float x2,y2;
	float t=0;

	
	ofstream file;
	file.open("RK4Av.txt");
//	cout <<setw(10)<< "t" <<setw(10)<<  "tv" <<setw(10)<< "tl" << endl;
//	file <<setw(10)<< "t" <<"/" <<setw(10)<<  "tv" << "/" <<setw(10)<< "tl"<< endl;
	while(t< 40){
		
	    y2=RK4(t,x1,y1,0);
	    
		x2= RK4(t,x1,y1,1);
			
//		cout <<setw(10)<< t<< setw(10)<< x1 <<"-" <<setw(10)<< y1<< endl;
		file << t<< " "  <<  x1 <<" " << y1<< endl;
		y1=y2;
		x1=x2;	
		
		t=t+ dt;
	}
	file.close();
	
// Gnuplot komut dosyası oluştur
    std::ofstream GnuPlot("RK4AV.plt");
    GnuPlot << "set title 'Tavşan Tilki'\n";
    GnuPlot << "set xlabel 'Zaman(t) Ay '\n";
    GnuPlot << "set ylabel 'Nufus (Av ve Avcı)'\n";
    GnuPlot << "plot 'RK4Av.txt' using 1:2 with linespoints linewidth 0.5 pointtype 0 title"
	<<" 'Av (Tavşan)', '' using 1:3 with linespoints linewidth 0.5 pointtype 0 title 'Avci (Tilki)'\n";
   
    GnuPlot << "pause -1\n"; // pencereyi kapatma
    GnuPlot.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"RK4AV.plt");
	return 0;
}
