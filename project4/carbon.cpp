//
//  carbon.cpp
//  project4
//
//  Created by Arslan Memon on 11/27/15.
//  Copyright © 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"
class fcn : public Fcn {
public:
    double operator()(double x) {   // function evaluation
        return (exp(-(x*x)));//e^-(x^2)
    }};
//prototype
int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                const double atol, double& R, int& n, int& Ntot);
//
double erf(const double y, const double rtol, const double atol)
{
    fcn f;//function object
    double erf=0.0;//variable to store result
    int ntot=0;//ntot place holder
    int n=0;// n placeholder
    adaptive_int(f, 0, y, rtol, atol, erf, n, ntot);//estimate integral 0 to y of f
    return 2.0/sqrt(M_PI)*erf;//return 2erf/sqrt(pi)
}
double carbon(const double x, const double t, const double T,
              const double rtol, const double atol)
{

    double Cs=.02;//init carbon concentration
    double c0=.001;//carbon concentration in gas
    double dt=6.2e-7*exp(-8.0e4/(T*8.31));// temperature-dependent diffusion coefficient of the steel
    double y=x/sqrt(4.0*t*dt);//calculate y
    return Cs-((Cs-c0)*erf(y,  rtol, atol));//return CC in steal, C(x,t,T)
}