//
//  LongestPair.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/16/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestPair_h
#define LongestPair_h

#include "DataStructure.h"

using namespace std;

string longestStr(list<string> & ls);

int LongestPair(vector<string> & dict) {
    unordered_map<string, list<string>> mymapA;
    unordered_map<string, list<string>> mymapB;
    for (auto str : dict) {
        int len = str.length();
        string first = str.substr(0,1);
        string lasttwo = str.substr(len-2,2);
        string f = first + "#" + lasttwo;
        mymapA[f].push_back(str);
        string lastone = str.substr(len-1,1);
        string firsttwo = str.substr(0,2);
        string g = lastone + "#" + firsttwo;
        mymapB[g].push_back(str);
    }
    int result = 0;
    for (auto m : mymapA) {
        string keyA = m.first;
        if (mymapB.find(keyA)!=mymapB.end()){
            string strA = longestStr(m.second);
            string strB = longestStr(mymapB[keyA]);
            result = max(result, static_cast<int>(strA.length()+strB.length()));
        }
    }
    
    return result;
}

string longestStr(list<string> & ls) {
    string result;
    int len = 0;
    for (auto s : ls) {
        if (s.length()>len) {
            len = static_cast<int>(s.length());
            result = s;
        }
    }
    return result;
}

/*
 
 Since the original dict is sorted in alphabet order
 we can use binary search to save space
 
 */

int binarySearch(int start, int end, string & str, vector<string> & dict, bool left) {
    string target = str.substr(str.length()-2,2);
    int mid = start + (end-start)/2;
    int result = -1;
    while(start<=end) {
        string midstr = dict[mid];
        string firsttwo = midstr.substr(0,2);
        if (firsttwo == target) {
            result = mid;
            if (left) end = mid-1;
            else start = mid+1;
        }
        if (firsttwo < target) {
            start = mid+1;
        }
        else if (firsttwo > target) {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return result;
}

int LongestPairBinraySearch(vector<string> & dict) {
    int result = 0;
    for (int i = 0; i < dict.size(); i++) {
        string str = dict[i];
        int start = 0, end = static_cast<int>(dict.size()-1);
        int left = binarySearch(start, end, str, dict, true);
        int right = binarySearch(start, end, str, dict, false);
        if (left==-1 || right==-1) continue;
        for (int j = left; j <= right; j++) {
            string strj = dict[j];
            if (str[0]==strj.back()) {
                result = max(result, static_cast<int>(str.length()+strj.length()));
            }
        }
    }
    return result;
}


#endif /* LongestPair_h */
