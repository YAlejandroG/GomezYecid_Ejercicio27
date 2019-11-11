#include <iostream>
#include <stdlib.h>
#include <math.h>

double integral(double t);
double explicitScheme(double wdt,double t);
double implicitScheme(double wdt,double t);
double calcerror(double real,double calc);

int main(){
    double wdt;
    double t;
    
    std::cout<<"Ingresar wdt:"<<std::endl;
    std::cin>>wdt;
    std::cout<<"Ingresar t:"<<std::endl;
    std::cin>>t;
    
    double int1 = integral(t);
    std::cout<<"Integral real con wdt = "<<wdt<<" : "<<int1<<std::endl;
    double int2 = explicitScheme(wdt,t);
    double e1 = calcerror(int1,int2);
    std::cout<<"Integral explicita con wdt = "<<wdt<<" : "<<int2<<std::endl;
    std::cout<<"Error integral explicita: "<<e1<<"%"<<std::endl;
    double int3 = implicitScheme(wdt,t);
    double e2 = calcerror(int1,int3);
    std::cout<<"Integral implicita con wdt = "<<wdt<<" : "<<int3<<std::endl;
    std::cout<<"Error integral implicita: "<<e2<<"%"<<std::endl;
}

double integral(double t){
    double integral = exp(-t);
    return integral;
}

double explicitScheme(double wdt,double t){
    double integral = 1.0;
    for(double i=0;i<=t;i+=wdt){
        integral -= wdt*integral;
    }
    return integral;
}

double implicitScheme(double wdt,double t){
    double integral = 1.0;
    for(double i=0;i<=t;i+=wdt){
        integral = integral/(1.0+wdt);
    }
    return integral;
}

double calcerror(double real,double calc){
    double error = 100*abs(real-calc)/real;
    return error;
}