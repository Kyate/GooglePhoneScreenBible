//
//  FourWayStop.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef FourWayStop_h
#define FourWayStop_h

#include "DataStructure.h"

using namespace std;

/*
 
 上来聊了下debug中遇到的挑战和怎么解决的， 聊了10min。
 
 第一题 atoi 只考虑正数，写了一些test case，没啥问题。
 
 第二题 没见过，有一个4-way stop的路口，4条lane， 给两个function getNextCar（）， arriveCar（Car car， Lane lane），要求实现这两个方法。
 
 就是生活中一个intersection有4个stop sign，然后看看哪条lane的车应该先走。理解完题只剩10min，写了一会儿发现好烦，最后没时间了，说了下思路，还有好多核心code没写。。 估计挂了。。。
 
 http://www.1point3acres.com/bbs/thread-188010-1-1.html
 
 */

struct Car {
    Car(int id):carid(id) {};
    int carid;
};

struct Lane {
    Lane() {};
    queue<Car*> carQueue;
};

struct Pair {
    Pair(Car * c, Lane * l) : car(c), lane(l) {};
    Car * car;
    Lane * lane;
};

class FourWayStop {
    
public:
    queue<Pair*> mainQueue;
    
    FourWayStop(){
//        m_lane1 = lane1;
//        m_lane2 = lane1;
//        m_lane3 = lane1;
//        m_lane4 = lane1;
    };
    
    void arriveCar(Car * car, Lane * lane) {
        if (lane->carQueue.empty()) {
            Pair * newp = new Pair(car, lane);
            mainQueue.push(newp);
        }
        lane->carQueue.push(car);
    };
    
    Car * getNextCar() {
        if (mainQueue.empty()) return nullptr;
        Pair * next = mainQueue.front();
        mainQueue.pop();
        next->lane->carQueue.pop();
        if (! next->lane->carQueue.empty()) {
            Pair * newp = new Pair(next->lane->carQueue.front(), next->lane);
            mainQueue.push(newp);
        }
        return next->car;
    }
private:
//    Lane * m_lane1;
//    Lane * m_lane2;
//    Lane * m_lane3;
//    Lane * m_lane4;
};

#endif /* FourWayStop_h */
