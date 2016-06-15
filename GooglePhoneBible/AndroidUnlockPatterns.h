//
//  AndroidUnlockPatterns.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AndroidUnlockPatterns_h
#define AndroidUnlockPatterns_h

#include "DataStructure.h"

using namespace std;

/*
 
 发个google 跪经， 一个三哥面的。感觉他人应该不错，有试着提示我，可是那英语好难理解呀。。。
 
 好了，上题：
 
 Find the total number of patterns of the Android lock screen. The number of key used has to be at least 4, and max 9.
 Example:
 If the keyboard is
 
 | 1 | 2 | 3 |
 | 4 | 5 | 6 |
 | 7 | 8 | 9 |
 
 use 5 keys:
 
 OAB
 OOC
 OED
 which means 2->3->6->9->8
 
 OAB
 OCD
 OOE
 which means 2->3->5->6->9
 
 Same thing goes with 4, 6, 7, 8, 9 keys. Count the total possible pattern. The order of keys used matters.
 看到这个题一点想法都没有。。。
 
 http://www.1point3acres.com/bbs/thread-186774-1-1.html
 
 */

bool canGo(int from, int to, vector<bool> & visited) {
    from--, to--;
    if (from/3 == to/3) {
        if (abs(from-to)==1) return true;
        else return visited[min(from,to)+2];
    }
    if (from%3 == to%3) {
        if (abs(from-to)==3) return true;
        else return visited[min(from,to)+4];
    }
    int minm = min(from, to) + 1, maxm = max(from, to) + 1;
    if ((minm==1 && maxm == 9) || (minm==3 && maxm == 7))
        return visited[5];
    
    return true;
}


void unlockHelper(int & result, int m, int n, vector<bool> & visited, int step, int prev) {
    if (step > n) return;
    if (step==n) { result++; return; }
    if (step >= m) result++;
    for (int i = 1; i <= 9; i++) {
        if (!visited[i] && canGo(prev, i, visited)) {
            visited[i] = true;
            unlockHelper(result, m, n, visited, step+1, i);
            visited[i] = false;
        }
    }
    
}

int AndroidUnlockPatterns(int m, int n) {
    vector<bool> visited(10, false);
    int result = 0;
    for (int i = 1; i <= 9; i++) {
        int current = 0;
        visited[i] = true;
        unlockHelper(result, m, n, visited, 1, i);
        visited[i] = false;
    }
    return result;
}

#endif /* AndroidUnlockPatterns_h */
