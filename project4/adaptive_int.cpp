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
double composite_int(Fcn& f, const double a,
                     const double b, const int n);

int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                 const double atol, double& R, int& n, int& Ntot)
{
    
    n=16;
    int npk=n+10;
     Ntot=n+npk;
    R=composite_int(f, a, b, n);
    double Rnpk=composite_int(f, a, b, npk);
    while (Ntot<=1000) {
    if(fabs(Rnpk-R)<rtol*fabs(Rnpk)+atol)
    {
        return 0;
    }
        else
        {
            if (rtol>=1e-4)
            {
            n+=8;
            npk=n+4;
                Ntot+=n+npk;
            }
           else if (rtol>=1e-8)
            {
                n=n+24;
                npk=n+4;
                Ntot+=n+npk;
            }
            else
            {
                n=n+9;
                npk=n+4;
                Ntot+=n+npk;
            }
            R=composite_int(f, a, b, n);
            Rnpk=composite_int(f, a, b, npk);
            
        }
}

    return 1;
}