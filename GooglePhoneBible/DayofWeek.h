//
//  DayOfWeekForDate.h
//  LeetCode
//
//  Created by Jerome on 6/19/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DayOfWeekForDate_h
#define DayOfWeekForDate_h

#include "DataStructure.h"

using namespace std;

int DayOfWeek(int date, int mon, int year) {
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, r, s = 0 ;
    
    year -= mon<3;
    
    for(i = 0 ; i < mon - 1 ; i++)
        s = s + month[i] ;
    
    s = s + (date + year + (year / 4) - 2) ;
    s = s % 7 ;
    
    return s;
}

#endif /* DayOfWeekForDate_h */