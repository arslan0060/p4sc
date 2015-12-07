//
//  application.cpp
//  project4
//
//  Created by Arslan Memon on 11/28/15.
//  Copyright © 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"
using namespace std;
//prototypes
double erf(const double y, const double rtol, const double atol);
double fd_newton(Fcn& f, double x, int maxit, double tol,double alpha, bool show_iterates);
double carbon(const double x, const double t, const double T,
              const double rtol, const double atol);

class fcnC : public Fcn {//root finding function for concentration of .006
public:
    double operator()(double T)//parameter T
    {
        //initial variables
        double Cs=.02;
        double c0=.001;
        double dt=6.2e-7*exp(-8.0e4/(T*8.31));
        double x=.003;//depth of 3mm
        double t=36*3600;//36 hours
        double y=x/sqrt(4.0*t*dt);
        
        return (carbon(x, t, T, 1e-14, 1e-15)-.006);//C(x,t,T)-.006=0
   
    }};

int main(int argc, char* argv[]) {
     fcnC f;//function object
    double T=fd_newton(f, 1000, 6, 1e-4, pow(2.0, -26), false);//use 1000 as initial guess and an alpha of
    //2^-26 to find root with fd_newton accurate to .0001K. 6 max iterations
    
    //display result
    cout<<"The temperature at which a depth of 3.0 mm in the steel will reach a carbon concentration of 0.6% under carburization at t = 36 hours is ";
   
    printf("%.4f", T); cout<<"K"<<endl;
}