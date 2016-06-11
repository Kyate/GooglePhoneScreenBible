//
//  MovingAverageDataStream.j.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/10/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MovingAverageDataStream_j_h
#define MovingAverageDataStream_j_h

/*
 
 Google 技术店面，4月份面的，楼主太懒，一直拖到现在。 听口音应该是白人小哥，上来寒暄一番，说说自己在google 做什么，然后问了些关于项目的东西，然
 后做题，题目很简单，就是leetcode 346 题，moving average from datastreaming。但楼主做的时候这道题还没post 出来。目测只要将time 
 complexity 降到O（1） 就行，楼主就是维护一个window size 大小的List，和一个window size 内所有数的和。但要注意corner case。 还有两个简单
 的follow up，如果是多线程怎么办，以及写一下test case。下周onsite，攒一下RP。祝各位找工作顺利。
 
 链接: https://instant.1point3acres.com/thread/178618
 来源: 一亩三分地
 
 */

class MovingAverage {
public:
    MovingAverage(int n) : wsize(n) {
    };
    
    double next(int val) {
        sum += val;
        myqueue.push_back(val);
        if (myqueue.size()>wsize) {
            sum -= myqueue.front();
            myqueue.pop_front();
        }
        return static_cast<double>(sum)/ myqueue.size();
    };
    
    int wsize = 0;
    int sum = 0;
    deque<int> myqueue;
};

#endif /* MovingAverageDataStream_j_h */
