//
//  fd_newton.cpp
//  Newton
//
//  Created by Arslan Memon on 9/28/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

double fd_newton(Fcn& f, double x, int maxit, double tol,
                 double alpha, bool show_iterates)//same as newton except use alpha to calculate f' using
//finite difference, so no f' needed as parameter
{


    if (maxit<1)
    {
        std::cerr<<"not enough iterations, returning input value"<<std::endl;
        return x;
    }
    if (tol<1e-15)
    {
        std::cerr<<"tol<1e-15, resetting to to 1e-15"<<std::endl;
        tol=1e-15;
        
    }
    double fx=f(x);
    if (show_iterates)
    {
        std::cout<<"Initial guess, x="<<x<<", |fx|="<<fabs(fx)<<", tolerance= "<<tol<<std::endl;
        
    }
    for (int n=0;n<maxit;n++)
    {
        double sdpf=(f(x+alpha)-f(x))/alpha;//f'(x) is approximately (f(x+alpha)-f(x))/alpha
        double d=fx/sdpf;
        x=x-d;
        fx=f(x);
        if( show_iterates)
        {
            
            std::cout<<"iteration="<<n<<", x="<<x<<", |d|="<<fabs(d)<<", |fx|= "<<fabs(fx)<<std::endl;
        }
        if (fabs(d)<tol)
        {
            return x;
            
        }
    }
    return x;



}