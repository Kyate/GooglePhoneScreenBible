//
//  GroupFiveConsecutive.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef GroupFiveConsecutive_h
#define GroupFiveConsecutive_h

/*
 
 给我一堆unsorted数字，问我可不可以等分成若干组，每组由五个连续的整数组成。 
 eg: 
 1,2,3,4,5,4,5 -> false
 1,2,3,4,5,2,3,4,5,6 ->true
 
 */


bool GroupFiveConsecutive(vector<int> & nums) {
    unordered_map<int,int> mymap;
    for (auto n : nums) {
        mymap[n]++;
    }
    while(mymap.size()>0) {
        int x = mymap.begin()->first;
        int nextMin = 0;
        while (mymap.find(x)!=mymap.end()) {
            if (mymap[x]>1) nextMin = x;
            x--;
        }
        x++;
        nextMin = (mymap[x]>1) ? x : nextMin;
        int num = 0;
        while(num<5 && mymap.find(x)!=mymap.end()) {
            mymap[x]--;
            if (mymap[x]==0) mymap.erase(x);
            num++;
            x++;
            if (num==5) {
                num=0;
                x = nextMin;
            }
        }
        if (num!=0) return false; 
    }
    
    return true;
}

#endif /* GroupFiveConsecutive_h */
