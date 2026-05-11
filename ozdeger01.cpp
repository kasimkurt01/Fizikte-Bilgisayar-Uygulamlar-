#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<functional>
#include <vector>

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
	Diff s={0.0,1.0}; // s?nd?r de?erleri (0.0, 1.0)
	double x=0.0;
	for(int i=0;i < N; i++ ){
		s=RK4(s,x,h,k22);
		x+=h;
	}
	return s.y; // y(1) ?zde?erde s?f?r olmal?
}

double OzdegerBul(double ka, double kb, double t=1e-6){
	double fa = Atis(ka), 
	       fb = Atis(kb);
	       
	if(fa*fb>0 ) return -1; // k?k yok
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
	    if (i < N) {
            s = RK4(s, x, h, k22);
            x += h;
        }
    }
    fout.close();
    cout << "  › " << DosyaAdi << " dosyasina yazildi.\n";
	
}

int main(){
	
	const int    OZDEGER_SAY   = 5;
    const double Adim_Uz       = 0.05;   // tarama adýmý
    const double Kmaks         = 20.0;
    
      vector<double> ozdeger;
    cout << fixed << setprecision(8);
    cout << left
    	 << setw(5) << "n"
    	 << setw(18) << "k_n(sayýsal)"
    	 << setw(18) << "k_n(Analtik)"
    	 << setw(18) << "Hata \n" ;
    cout << string(60, '-') << "\n";
     // k aralýðýný tara, iþaret deðiþimi ara › kök bul
    double kp = Adim_Uz;
    double fp = Atis(kp);
    
     for (double k = 2*Adim_Uz; k <= Kmaks && (int)ozdeger.size() < OZDEGER_SAY; k += Adim_Uz) {
        double fcrr = Atis(k);
        if (fp * fcrr < 0) {
            // Ýþaret deðiþimi: bu aralýkta özdeðer var
            double ev = OzdegerBul(kp, k);
            if (ev > 0) {
                ozdeger.push_back(ev);
                int    n         = (int)ozdeger.size();
                double analtik  = n * M_PI;
                double hata     = fabs(ev - analtik);

                cout << left
                     << setw(5)  << n
                     << setw(18) << ev
                     << setw(18) << analtik
                     << setw(18) << hata
                     << "\n";

                kayitOzdeger(ev, n);
            }
        }
        kp = k;
        fp = fcrr;
    }

    cout << "\n";

    // ¦¦¦ Detaylý RK4 çözümü tablosu (n=1 için) ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦
    if (!ozdeger.empty()) {
        double k1 = ozdeger[0];
        cout << "\n--- n=1 icin RK4 cozumu ornegi (k=" << k1 << ") ---\n";
        cout << setw(10) << "x"
             << setw(18) << "y_RK4"
             << setw(18) << "y_analitik"
             << setw(15) << "Fark\n";
        cout << string(58, '-') << "\n";

        int    N  = 1000;
        double h  = 1.0 / N;
        double k2 = k1 * k1;
        Diff  s  = {0.0, 1.0};
        double x  = 0.0;
        double norm = 1.0 / k1;

        for (int i = 0; i <= N; i += 100) {
            double y_an   = sin(k1 * x) / k1;
            double y_num  = s.y * norm;
            cout << setw(10) << x
                 << setw(18) << y_num
                 << setw(18) << y_an
                 << setw(15) << fabs(y_num - y_an) << "\n";
            // adým ilerlet (100 adým)
            if (i < N) {
                for (int j = 0; j < 100 && i+j < N; j++) {
                    s = RK4(s, x, h, k2);
                    x += h;
                }
            }
        }
    }

    cout << "\nProgram tamamlandi.\n";
    return 0;
    	 
    	 
    
}