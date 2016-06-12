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

/*
 
 Two methods:
 
 (1) O(nlogn) Solution: using a multiset, put all numbers in this set, and then
 iterating from the smallest one, delete the next 4 consecutive numbers
 If you can't find any of the four consecutive numbers, then return false;
 
 (2) O(n) Solution: using a hashmap where key is the number and the value is frequency.
 Get any of the numbers and find the minimum one in the consecutive interval
 From the minimum number, delete every five numbers until we can't find the next consecutive one
 (we processed a whole consecutive interval)
 If the length consecutive interval can be divided by 5, this interval is good
 If not, return false
 
 Since every element is visited twice at most, this solution is O(n).
 
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

bool GroupFiveSame(vector<int> & nums) {
    unordered_map<int,int> mymap;
    for (auto n : nums) {
        mymap[n]++;
    }
    
    for (auto m : mymap) {
        if (m.second % 5 != 0) return false;
    }
    return true;
}

bool GroupKConsecutive(vector<int> & nums, int k) {
    unordered_map<int,int> mymap;
    for (auto n : nums) {
        mymap[n]++;
    }
    while(mymap.size()>0) {
        int x = mymap.begin()->first;
        while (mymap.find(x)!=mymap.end()) x--;
        x++;
        int num = 0;
        while(num<k && mymap.find(x)!=mymap.end()) {
            mymap[x]--;
            if (mymap[x]==0) mymap.erase(x);
            num++;
            x++;
            if (num==k) num=0;
        }
        if (num!=0) return false; 
    }
    
    return true;
}

#endif /* GroupFiveConsecutive_h */
