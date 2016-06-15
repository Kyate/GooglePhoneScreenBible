//
//  CircleIntersection.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CircleIntersection_h
#define CircleIntersection_h

#include "DataStructure.h"

using namespace std;

/*
 
 Given (x, y, r) of the circle (x, y is the center of circle, r is the radius), return whether 2 circles have intersection
 
 */

bool CircleIntersection(double x1, double y1, double r1, double x2, double y2, double r2) {
    double rminus = fabs(r1-r2);
    double radd = r1+r2;
    double dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    dist = sqrt(dist);
    if (dist>=rminus && dist<=radd) return true;
    else return false;
}

#endif /* CircleIntersection_h */
