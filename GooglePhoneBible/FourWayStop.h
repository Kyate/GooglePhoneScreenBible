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
