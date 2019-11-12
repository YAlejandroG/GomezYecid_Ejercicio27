#include <fstream>
#include <iostream>
using namespace std;

int explicitScheme(double w,double dt,double t,string nombre);
int implicitScheme(double w,double dt,double t,string nombre);

int main(){
    double w = 0.1;
    double t = 4.0/w;
    double dt1 = 0.1/w;
    double dt2 = 0.01/w;
    double dt3 = 1.0/w;
    string n1 = "implicit0.1.dat";
    string n2 = "implicit0.01.dat";
    string n3 = "implicit1.dat";
    string n4 = "explicit0.1.dat";
    string n5 = "explicit0.01.dat";
    string n6 = "explicit1.dat";
    
    implicitScheme(w,dt1,t,n1);
    implicitScheme(w,dt2,t,n2);
    implicitScheme(w,dt3,t,n3);
    
    explicitScheme(w,dt1,t,n4);
    explicitScheme(w,dt2,t,n5);
    explicitScheme(w,dt3,t,n6);
    
    return 0;
}

int explicitScheme(double w,double dt,double t,string nombre){
    ofstream outfile;
    outfile.open(nombre);
    double integral = 1.0;
    for(double i=0;i<=t;i+=dt){
        integral -= w*dt*integral;
        outfile<<i<<" "<<integral<<endl;
    }
    outfile.close();
    
    return 0;
}

int implicitScheme(double w,double dt,double t,string nombre){
    ofstream outfile;
    outfile.open(nombre);
    double integral = 1.0;
    for(double i=0;i<=t;i+=dt){
        integral = integral/(1.0+w*dt);
        outfile<<i<<" "<<integral<<endl;
    }
    outfile.close();
    
    return 0;
}
