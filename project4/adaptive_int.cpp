//
//  adaptive_int.cpp
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
// function prototype
double composite_int(Fcn& f, const double a,
                     const double b, const int n);

int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                 const double atol, double& R, int& n, int& Ntot)
{
    //start n is based on rtol, as rtol decreases n increases.
    int npk=0;//number of intervals used to estimate the true integral
   if(rtol>=1e-4)//start values are based on trial and error to minimize Ntot
       //because of rapid convergence, as n increases, the number of subintervals added to n to estimate
       //thw true integral can be decreased.
   {
       n=16;
       npk=n+6;
   }
    else if(rtol>=1e-8)
    {
        n=36;
        npk=n+4;
    }
    else
    {
        n=64;
        npk=n+3;
    }
    
     Ntot=n+npk;//add n and npk to Ntot
    R=composite_int(f, a, b, n);//use composite_int to estimate integral
    double Rnpk=composite_int(f, a, b, npk);
    //loop four times, if result is sufficient return 0, otherwise increase intervals and try again
    for(int i=0;i<4;i++)
    {
    if(fabs(Rnpk-R)<rtol*fabs(Rnpk)+atol)
    {
        return 0;
    }
        else
            //since n was based on rtol, I decided that for larger tolerances,
            //n is sufficiently small enough that multiplying by 1.5 wouldn't affect Ntot alot. For smaller tolerances, since n is large to start with increasing n by n/8 should lead to a approximation within a couple of intervals due to the high convergence rate.
        {
            if (rtol>=1e-4)
            {
            n=n*1.5;
            npk=n+6;
                Ntot+=n+npk;
            }
           else if (rtol>=1e-8)
            {
                
                n=n*1.25;
                npk=n+4;
                Ntot+=n+npk;
            }
            else
            {
                n=n*1.125;
                npk=n+3;
                Ntot+=n+npk;
            }
            R=composite_int(f, a, b, n);
            Rnpk=composite_int(f, a, b, npk);
            
        }
}

    return 1;//if condition not met after 4 iterations, return 1/fail
}