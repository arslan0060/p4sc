//
//  composite_int.cpp
//  project4
//
//  Created by Arslan Memon on 11/21/15.
//  Copyright © 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;


double composite_int(Fcn& f, const double a, const double b, const int n)
{
    if (b < a) {
        cerr << "error: illegal interval, b < a\n";
        return 0.0;
    }
    if (n < 1) {
        cerr << "error: illegal number of subintervals, n < 1\n";
        return 0.0;
    }
    
    // set subinterval width
    double h = (b-a)/n;
    double F=0.0;
    // set nodes/weights defining the quadrature method
    double x1 = -sqrt(1.0/9.0*(5.0-2.0*sqrt(10.0/7.0)));
    double x2 = -sqrt(1.0/9.0*(5.0+2.0*sqrt(10.0/7.0)));
    double x3=0;
    double x4=sqrt(1.0/9.0*(5.0-2.0*sqrt(10.0/7.0)));
    double x5=sqrt(1.0/9.0*(5.0+2.0*sqrt(10.0/7.0)));
    double w1 =  0.3*((-.7+5.0*sqrt(0.7))/(-2+5*sqrt(.7)));
    double w2 =0.3*((.7+5.0*sqrt(0.7))/(2+5*sqrt(.7)));
    double w3=128.0/225.0;
    double w4=0.3*((-.7+5.0*sqrt(0.7))/(-2+5*sqrt(.7)));
    double w5=0.3*((.7+5.0*sqrt(0.7))/(2+5*sqrt(.7)));
    double xmid, node1, node2, node3,node4,node5;
    for (int i=0; i<n; i++) {
        
        // determine evaluation points within subinterval
        xmid  = a + (i+0.5)*h;
        node1 = xmid + 0.5*h*x1;
        node2 = xmid + 0.5*h*x2;
        node3 = xmid + 0.5*h*x3;
        node4 = xmid + 0.5*h*x4;
        node5 = xmid + 0.5*h*x5;
        
        // add Gauss2 approximation on this subinterval to result
        F += w1*f(node1) + w2*f(node2)+w3*f(node3)+w4*f(node4)+w5*f(node5);
        
    } // end loop

return (0.5*h*F);    


}