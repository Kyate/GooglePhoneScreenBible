//
//  MovingAverageDataStream.j.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/10/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MovingAverageDataStream_j_h
#define MovingAverageDataStream_j_h

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
