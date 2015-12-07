//
//  test_carbon.cpp
//  project4
//
//  Created by Arslan Memon on 11/27/15.
//  Copyright © 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include "matrix.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"
double carbon(const double x, const double t, const double T,
              const double rtol, const double atol);
double erf(const double y, const double rtol, const double atol);

int main(int argc, char* argv[]) {
    Matrix T=Linspace(800, 1200, 400, 1);//matrix of 400 evenly spaced temperatures between 800K and 1200K
    Matrix t=Linspace(1, 48*3600,600,1 );//matrix of 600 evenly spaced time values in seconds between 1sec and 48 hrs
    //tolerances
    double const atol=1e-15;
    double const rtol=1e-11;
    //400x600 matrices to store carbon concentrations based on time and temp stored above and tolerances
    Matrix C2mm(400,600);//depth of .002m
    Matrix C4mm(400,600);//depth of .004m
    for (int j=0;j<600;j++)
    {
        for (int i=0; i<400; i++) {
            C2mm(i,j)=carbon(.002, t(j), T(i), rtol, atol);//use  carbon() to calculate concentrations
            C4mm(i,j)=carbon(.004, t(j), T(i), rtol, atol);
            
        }
    }
    //matrices to store carbon concentration at 2mm at a constant temp over the 600 time intervals
    Matrix C2mm_800K(600);
    Matrix C2mm_900K(600);
    Matrix C2mm_1000K(600);
    Matrix C2mm_1100K(600);
    Matrix C2mm_1200K(600);
    //same as above except 4mm
    Matrix C4mm_800K(600);
    Matrix C4mm_900K(600);
    Matrix C4mm_1000K(600);
    Matrix C4mm_1100K(600);
    Matrix C4mm_1200K(600);
    for (int j=0;j<600;j++)//fill arrays using carbon and specified temperatures
    {
        
        C2mm_800K(j)=carbon(.002, t(j), 800, rtol, atol);
        C2mm_900K(j)=carbon(.002, t(j), 900, rtol, atol);
        C2mm_1000K(j)=carbon(.002, t(j), 1000, rtol, atol);
        C2mm_1100K(j)=carbon(.002, t(j), 1100, rtol, atol);
        C2mm_1200K(j)=carbon(.002, t(j), 1200, rtol, atol);
        C4mm_800K(j)=carbon(.004, t(j), 800, rtol, atol);
        C4mm_900K(j)=carbon(.004, t(j), 900, rtol, atol);
        C4mm_1000K(j)=carbon(.004, t(j), 1000, rtol, atol);
        C4mm_1100K(j)=carbon(.004, t(j), 1100, rtol, atol);
        C4mm_1200K(j)=carbon(.004, t(j), 1200, rtol, atol);
        
    }
    //write to disk
    T.Write("Temp.txt");
    t.Write("time.txt");
    C2mm.Write("C2mm.txt");
    C2mm_800K.Write("C2mm_800K.txt");
    C2mm_900K.Write("C2mm_900K.txt");
    C2mm_1000K.Write("C2mm_1000K.txt");
    C2mm_1100K.Write("C2mm_1100K.txt");
    C2mm_1200K.Write("C2mm_1200K.txt");
    C4mm.Write("C4mm.txt");
    C4mm_800K.Write("C4mm_800K.txt");
    C4mm_900K.Write("C4mm_900K.txt");
    C4mm_1000K.Write("C4mm_1000K.txt");
    C4mm_1100K.Write("C4mm_1100K.txt");
    C4mm_1200K.Write("C4mm_1200K.txt");
}