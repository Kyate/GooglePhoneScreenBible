//
//  MovingAverageStream.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MovingAverageStream_h
#define MovingAverageStream_h

#include "DataStructure.h"

using namespace std;


/*
 
 上周一（2/29/2016）的google电面，今天刚刚收到通过的通知电面通过，赶快过来发面经。
 
 面我的是个白人小哥，人非常nice，只问了一个问题：moving window average for double value。楼主用了类似LRU的double linkedlist 和 sum 解
 的， 但是感觉这个应该不是最好的办法。 follow up 1） 如果input data stream非常大的话会不会有error 2） linkedlist会有会有经常delete／
 create node，有没有什么改进。 楼主从电面到收到通知之间用了一个星期，不知道是不是答得一般，committee意见有分歧。onsite求bless！
 
 不好意思，这个题没有说明白。 题目是有一个data stream， find the average of latest k numbers。 data 是 double parameter。这就类似于
 array 的moving window average
 
 链接: https://instant.1point3acres.com/thread/164302 来源: 一亩三分地
 
 这两个follow up是根据我的回答问的。
 
 我用了一个sum 来记录window值的总和， window 里每次加入／剔除一个树时就update一下sum，这样求average是O（1）的时间。但是如果data stream太
 大，每次求sum的error会累积，最后就不准确了。 我当时回答如果data stream太大就不用sum记录了，但是这样求average 就是O（k）。 现在想，其实可以
 每一定量数（e.g 1000）后refresh一下sum，这样还是可以keep O（1）in time 2）
 
 这个面试小哥是想说每次create list node 和delete list node不太好，可以保持list node 不变，每次改node value 就可以了。
 
 链接: https://instant.1point3acres.com/thread/164302 来源: 一亩三分地
 
 */

class MovingAverageStream {
public:
    MovingAverageStream(int k) {
        w = k;
    }
    
    double next(double val) {
        num++;
        mydeque.push_back(val);
        sum += val;
        if (mydeque.size()>w) {
            if (num>=1000) {
                mydeque.pop_front();
                sum = 0;
                for (auto n : mydeque) {
                    sum += n;
                }
                num = 0;
            }
            else {
                double f = mydeque.front();
                sum -= f;
                mydeque.pop_front();
            }
        }
        else {
            if (num>=1000) {
                sum = 0;
                for (auto n : mydeque) {
                    sum += n;
                }
                num = 0;
            }
        }
        return sum / static_cast<double>(mydeque.size());
    }
    
private:
    int w = 0;
    deque<double> mydeque;
    double sum;
    int num = 0;
}


#endif /* MovingAverageStream_h */
