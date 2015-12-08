#include <iostream>
#include <cmath>

using namespace std;

void machmirk(double*, double*, const int, const int, const double);

int main(void){

const double dt=0.1;
const int L=100;
const int N=L/dt;
double y[3];
y[0]=1;
y[1]=1;
y[2]=1;
const int a=10;
const int b=28;
const double c=8/3.0;
const double b1=1/6;
const double b2=1/3;
const double b3=1/3;
const double b4=1/6;
double k1[3];
double k2[3];
double k3[3];
double k4[3];
double temp[3];

	for(int i=0; i<N; i++){

	machmirk(k1, y, a, b, c);

	temp[0]=y[0]+dt/2*k1[0];
	temp[1]=y[1]+dt/2*k1[1];
	temp[2]=y[2]+dt/2*k1[2];
	machmirk(k2, temp, a, b, c);

	temp[0]=y[0]+dt/2*k2[0];
	temp[1]=y[1]+dt/2*k2[1];
	temp[2]=y[2]+dt/2*k2[2];
	machmirk(k3, temp, a, b, c);

	temp[0]=y[0]+dt*k3[0];
	temp[1]=y[1]+dt*k3[1];
	temp[2]=y[2]+dt*k3[2];
	machmirk(k4, temp, a, b, c);



	y[0]=y[0]+dt*(b1*k1[0]+b2*k2[0]+b3*k3[0]+b4*k4[0]);
	y[1]=y[1]+dt*(b1*k1[1]+b2*k2[1]+b3*k3[1]+b4*k4[1]);
	y[2]=y[2]+dt*(b1*k1[2]+b2*k2[2]+b3*k3[2]+b4*k4[2]);	


cout<< i*dt<<"\t"<<y[0]<<"\t"<<y[1]<<"\t"<<y[2]<<endl;

	}



}

void machmirk(double k[2], double y[2], const int a, const int b, const double c){
k[0]=a*(y[1]-y[0]);
k[1]=y[0]*(b-y[2])-y[1];
k[2]=y[0]*y[1]-c*y[2];
}
