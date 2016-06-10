//
//  BinaryWatchThreeBits.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/9/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BinaryWatchThreeBits_h
#define BinaryWatchThreeBits_h

#include "DataStructure.h"

using namespace std;

/*第一次电面很紧张，是个小哥，人不冷不热。貌似是新题，题目很简单一个 binary watch，类似下图的http://www.slipperybrick.com/wp- ... ed_binary_watch.jpg. from: 1point3acres.com/bbs
 . From 1point 3acres bbs
 比如：
 1000 >
 8
 000011 >-google 1point3acres
 3
 
 时间就是08:03.
 让输出所有亮三个灯的时间。
 刚开始感觉可以用backtracking来枚举情况，写了一会小哥不理解，然后提示用最naive的方式，写一个countones的函数，然后从 0000 -> 1111分别调用countones来枚举所有符合条件的情况。需要注意，小时必须小于12，分钟必须小于60.
 做完有个小bug在提醒下改了，然后时间不多就问了几个问题。
 请问电面是不是都是两道题，我只做了一道是不是没希望了.
 bless～
 http://www.1point3acres.com/bbs/thread-192342-1-1.html

 */

/*bruteforce and naive method: using countones()*/

int countones(int x) {
    int count = 0;
    while(x>0) {
        count ++;
        x = x & (x-1);
    }
    return count;
}

vector<vector<int>> BinaryWatch() {
    vector<vector<int>> result;
    for (int i = 0; i < 12; i++) { // hour
        for (int j = 0; j < 60; j++) { // minite
            if (countones(i) + countones(j) == 3) {
                result.push_back({i,j});
            }
        }
    }
    return result;
}

#endif /* BinaryWatchThreeBits_h */
