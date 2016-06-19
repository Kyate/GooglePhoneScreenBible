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

/*
 
 今天google 小哥一上来直接问题目 用google doc写的
 
 一锅汤，有胡萝卜和汤，各50份。然后有一堆人会来接汤，有四种人 a. 接一份里面有75%的胡萝卜，25%的汤 b. 接一份里面有50%的胡萝卜，50%的汤 c. 接一份里面有25%的胡萝卜，75%的汤 d. 接一份里面有0%的胡萝卜，100%的汤
 
 请问 当没有汤的时候，还剩下胡萝卜的这种情况的概率。
 
 我一开始很紧张，想不到，一脸懵。然后我就先写recursion的，写出base step和recursive step。然后他说很好，没有问题，然后他就问complexity。我说因为每一种可能都要算所以是N permutation。然后他让我在doc上写。我一开始还不懂什么意思，然后我写了O（N！）。他说对，我就是想看你会不会写permutation。0_0 接着就问能不能improve。我这个时候已经想到是dp了，于是就说可以，用一个2dmatrix。最后complexity是O(胡萝卜+汤)。他很满意。然后剩下15分钟。扯问题。最后byebye。求过！
 
 新人求大米!!!!
 
 求好运！！！
 
 http://www.1point3acres.com/bbs/thread-183037-1-1.html
 
 */


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
