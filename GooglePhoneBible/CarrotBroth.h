//
//  CarrotBroth.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/19/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef CarrotBroth_h
#define CarrotBroth_h

#include "DataStructure.h"

using namespace std;

double CarrotBroth(int carrot, int broth) {
    carrot *= 4;
    broth *= 4;
    vector<vector<double>> dpresult(carrot+1, vector<double>(broth+1, 0));
    dpresult[carrot][broth] = 1;
    vector<pair<int,int>> people{{3,1}, {2,2}, {1,3},{0,4}};
    for (int i = carrot; i>=0; i--) {
        for (int j = broth; j>0; j--) {
            
            double x = dpresult[i][j];
            
            if (x<=0) continue;
            
            int avail = 0;
            
            for (auto p : people) {
                if (i-p.first >=0 && j-p.second>=0) avail++;
            }
            
            if (avail==0) continue;
            
            if (i-3>=0 && j-1>=0)
                dpresult[i-3][j-1] += x * (1.0/avail);
            
            if (i-2>=0 && j-2>=0)
                dpresult[i-2][j-2] += x * (1.0/avail);
            
            if (i-1>=0 && j-3>=0)
                dpresult[i-1][j-3] += x * (1.0/avail);

            if (i-0>=0 && j-4>=0)
                dpresult[i-0][j-4] += x * (1.0/avail);

        }
    }
    
    double total = 0;
    
    for (int j = 0; j <= broth; j++) total += dpresult[0][j];
    total -= dpresult[0][0];
    
    return total;
}

double CarrotBrothRecursion(int carrot, int broth) {
    if (carrot<0 || broth<0) return 0.0;
    if (carrot==0) return 0.0;
    if (carrot>0 && broth==0) return 1.0;
    return (CarrotBrothRecursion(carrot-3, broth-1) + CarrotBrothRecursion(carrot-2, broth-2) + CarrotBrothRecursion(carrot-1, broth-3) + CarrotBrothRecursion(carrot, broth-4)) / 4.0;
}

#endif /* CarrotBroth_h */
