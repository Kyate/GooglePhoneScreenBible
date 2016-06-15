//
//  AndroidUnlockPatterns.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AndroidUnlockPatterns_h
#define AndroidUnlockPatterns_h


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
