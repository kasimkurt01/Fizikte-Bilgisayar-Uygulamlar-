#include<iostream>
#include<cmath>
using namespace std;
float fnk(float x)
{
	return (5-x)-5*exp(-x);
}

float turevS(float x)
{
	float h=1e-4;
	return (fnk(x+h)-fnk(x-h))/(2*h);
}
float newtonR(float x)
{
	float dx,x2;
	float dxm=1e-4;
	int itrsy=0;
	x2=x-fnk(x)/turevS(x);
	
	dx=abs(x2-x);

	while((dx>dxm) && (itrsy < 50))
	{
		itrsy++;
		x=x2;
		x2=x-fnk(x)/turevS(x);
	    dx=abs(x2-x);
	   
	}
	if (itrsy < 50 ) return x2;
	else 
	  {
	  	cout << " kok bulunmadý, iterasyonu " << itrsy<<" \n";
	  	return 0;
	  }
	
}

int main()
{
	double c=3e8;
	double h=6.63e-34;
	double k= 1.38e-23;
	double x,lm;
	double T=300;// oda sýcalýðý
	x=newtonR(5);
	lm=(h*c)/(k*x*T);
	cout << "denkelemin koku  " << x<< "\n dalga boyu :" << lm << endl;
	return 0;
}
