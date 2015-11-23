//
//  test_adapt.cpp
//  project4
//
//  Created by Arslan Memon on 11/22/15.
//  Copyright © 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"

using namespace std;

// function prototypes
int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                 const double atol, double& R, int& n, int& Ntot);

// Integrand
class fcn : public Fcn {
public:
    double c, d;
    double operator()(double x) {   // function evaluation
        return (exp(c*x) + sin(d*x));
    }
    double antiderivative(double x) { // function evaluation
        return (exp(c*x)/c - cos(d*x)/d);
    }
};


// This routine tests the Gauss-2 method on a simple integral
int main(int argc, char* argv[]) {
    
    // limits of integration
    double a = -3.0;
    double b = 5.0;
    
    // integrand
    fcn f;
    f.c = 0.5;
    f.d = 25.0;
    
    // true integral value
    double Itrue = f.antiderivative(b) - f.antiderivative(a);
    printf("\n True Integral = %22.16e\n", Itrue);
    double R=0.0;
    int n=0;
    int Ntot=0;
    vector<double> rtol={1e-2,1e-4,1e-6,1e-8,1e-10,1e-12};
    vector<double> atol={1e-4,1e-6,1e-8,1e-10,1e-12,1e-14};
    cout << "     n    Ntot  rtol     atol     rtol |I(f)| + atol         |I(f)-R(f)|\n";
    cout << "  -----------------------------------------------------------------------------\n";
    for(int i=0;i<rtol.size();i++)
    {
        adaptive_int(f, a, b, rtol[i], atol[i], R, n, Ntot);
       printf("   %4i  %4i  %7.1e  %7.1e  %21.16e  %23.16e\n", n,Ntot,rtol[i], atol[i],rtol[i]*fabs(Itrue)+atol[i],fabs(Itrue-R));
    }
    
}
