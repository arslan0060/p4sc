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
    Ntot=16;
    double npk=n+8;
    R=composite_int(f, a, b, n);
    double Rnpk=composite_int(f, a, b, npk);
    while (Ntot<=200) {
    if(fabs(Rnpk-R)<rtol*fabs(Rnpk)+atol)
    {
        return 0;
    }
        else
        {
            
           if (rtol>=1e-4)
            {
                n+=8;
            Ntot+=n;
            npk=n+4;
            }
           else if (rtol>=1e-8)
            {
                n=n+24;
                npk=n+4;
                Ntot+=n;
            }
            else if(rtol>=1e-10)
            {n=n+36;
                npk=n+4;
                Ntot+=n;
            }
            else
            {
                n=n+64;
                npk=n+4;
                Ntot+=n;
            }
            R=composite_int(f, a, b, n);
            Rnpk=composite_int(f, a, b, npk);
            
        }
}

    return 1;
}