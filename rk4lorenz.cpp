#include<iostream>
#include<cmath>
#include<graphics.h>
	float sgm=10;
	float r=28;
	float b=8/3;
	float dt=1e-3;
using namespace std;
float difx(float t,float x, float y,float z){
	return (y-x)*sgm;
}
float dify(float t,float x, float y, float z){
	return (-x*z+r*x-y);
}
float difz(float t, float x, float y, float z){
	return (x*y-b*z);
}
double RK2(float t, float x, float y, float z, char b){
	float k1,k2,k3,k4;

	switch (b)
	 {
	 	case 0:{
	 		k1=dt*difx(t,x,y,z);

			k2=dt*difx(t+0.5*dt,x+0.5*dt*k1,y,z);

			k3=dt*difx(t+0.5*dt,x+0.5*dt*k2,y,z);

			k4=dt*difx(t+dt,x+dt*k3,y,z);
			return x+(k1+2*k2+2*k3+k4)/6;
			break;
		 }
		case 1:{
			k1=dt*dify(t,x,y,z);

			k2=dt*dify(t+0.5*dt,x,y+0.5*dt*k1, z);

			k3=dt*dify(t+0.5*dt,x,y+0.5*dt*k2, z);

			k4=dt*dify(t+dt,x,y+dt*k3,z);
			return y+(k1+2*k2+2*k3+k4)/6;
			break;
		}
		case 2:{
			k1=dt*difz(t,x,y,z);

			k2=dt*difz(t+0.5*dt,x,y,z+0.5*dt*k1);

			k3=dt*difz(t+0.5*dt,x,y,z+0.5*dt*k2);

			k4=dt*difz(t+dt,x,y,z+dt*k3);

			return z+(k1+2*k2+2*k3+k4)/6;
			break;

			break;
		}

	}
	return 0;
}

int main(){
	float x1=1;
    float y1=1;
    float z1=20;

	float x2,y2,z2;
	float t=0;


  initwindow(900, 900, "Kasım KURT Lorenz");
	while(t< 100){

		x2= RK2(t,x1,y1,z1,0);
		y2= RK2(t,x1,y1,z1,1);
	   	z2=	RK2(t,x1,y1,z1,2);
		putpixel( int(700-y1*10), int( 350-x1*10),3 );
		putpixel( int(350-x1*10), int( 450-z1*10),3 );
		putpixel( int(350-y1*10), int( 750-z1*10),3 );
	//delay(1);
	putpixel( int(20+t*25), int( 450-x1*10),5 );
		z1=z2;
		x1=x2;
		y1=y2;

		t=t+ dt;
	}
 while (!kbhit( ))
    {
        delay(20);
    }

	return 0;
}

