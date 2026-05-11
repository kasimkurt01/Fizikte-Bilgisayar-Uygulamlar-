#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<functional>

using namespace std;

struct Diff{
	double y;
	double dy;
};

Diff Fsystem(const Diff& s, double , double k22){
	return {s.dy, -k22*s.y};
}

Diff RK4(const Diff& s, double x, double h, double k22){
	auto f=[&](const Diff& st, double xi){
		return Fsystem(st, xi, k22);
	};
	Diff k1,k2,k3,k4;
	
	k1= f(s,x);
	k2= f({s.y + 0.5*h*k1.y, s.dy + 0.5*h*k1.dy}, x + 0.5*h);
	k3= f({s.y + 0.5*h*k2.y, s.dy + 0.5*h*k2.dy}, x + 0.5*h);
	k4= f({s.y + h*k3.y, s.dy + h*k3.dy}, x + h);
	
	return {
	s.y + (h/6)*(k1.y+2*(k2.y+k3.y)+ k4.y),
	s.dy + (h/6)*(k1.dy+2*(k2.dy+k3.dy)+ k4.dy)
	};
}

double Atis(double k, int N=1000){
	double h = 1.0/N;
	double k22=k*k;
	Diff s={0.0,1.0}; // sýndýr deðerleri (0.0, 1.0)
	double x=0.0;
	for(int i=0;i < N; i++ ){
		s=RK4(s,x,h,k22);
		x+=h;
	}
	return s.y; // y(1) özdeðerde sýfýr olmalý
}

double OzdegerBul(double ka, double kb, double t=1e-6){
	double fa = Atis(ka), 
	       fb = Atis(kb);
	       
	if(fa*fb>0 ) return -1; // kök yok
	double c=ka, fc =fa;
	bool mf=true;
	double sv, d=0;
	
	for(int iter=0; iter<200; iter++){
		if(abs(fb-fa)> t && abs(fb-fc)>t)
	       sv=kb - fb*(kb-ka)/(fb-fa); 	
		else
		   sv= (ka+kb)*0.5;
	bool cn = !((sv> (3*ka+kb)/4 && sv<kb) || 
	            (sv> (3*ka+kb)/4 && sv>kb)) ||
				(mf && fabs(sv-kb)>= fabs(kb-c)*0.5) ||
				(!mf && fabs(sv-kb)>= fabs(c-d)*0.5) ||
				(mf && fabs(kb-c)<t)||
				(!mf && fabs(c-d)<t);
		if (cn){
			sv =(ka+kb)*0.5;
			mf=true;
		}
		else 
		  mf= false;
		  
		double fs = Atis(sv);
		d=c; c= kb; fc = fb;
		
		if(fa*fs < 0 ) {
			kb=sv; fb=fs;
			}
		else 
			{
			ka=sv; fa=fs;
		}
			
		if(fabs(fa)< fabs(fb)){
		    swap(ka,kb);
			swap(fa,fb);
		}	
		
		if(fabs(fb)< t ||fabs(kb-ka)<t)
		  return kb;		
	}
	return kb;
}

void kayitOzdeger(double k, int n, int N=500){
	string DosyaAdi="Ozdeger"+to_string(n)+".txt";
	ofstream fout(DosyaAdi);
	fout << "x,y_rk4, y_analtik\n";
	
	double h=1.0/N;
	double k22= k*k;
	Diff s={0.0, 1.0};
	double x=0.0;
	
	double norm=1.0/k; // sin(kx)/k 
	
	for(int i=0; i<N ;i++){
		double ya=sin(k*x)/k;
	fout << fixed << setprecision(6)
	     << x << "," << s.y*norm << "," << ya<< "\n";
	    
	}
}

int main(){
}