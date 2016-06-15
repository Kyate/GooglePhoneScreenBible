//
//  MinMaxRecentSystem.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MinMaxRecentSystem_h
#define MinMaxRecentSystem_h

#include "DataStructure.h"

using namespace std;


/*
 
 新鲜热辣的谷歌面筋。估计炮灰了。答得很放，面试官也都心不在焉。但是是时候回馈广大同胞了。
 
 设计查询系统(最大值，最小值，最新加入值)
 
 class System {
 
 int getMax();
 
 int getMin();
 
 int getRecent();
 
 void add(long time, int price);
 
 void update(long time, int price);
 
 void remove(long time);
 
 }
 例子如下
 
 add(1,4) max:4, min:4, recent:4
 
 add(4,7) max:7, min:4, recent:7
 
 add(2,5) max:7, min:4, recent:7
 
 etc..
 能帮大家的就到这里了。祝未来好运:)
 
 链接: https://instant.1point3acres.com/thread/166460 来源: 一亩三分地
 
 */


class MinMaxRecentSystem{
public:
    
    int getMax() {
        return PriceIndex.rbegin()->first;
    };
    
    int getMin() {
        return PriceIndex.begin()->first;
    };
    
    int getRecent() {
        return TimeIndex.rbegin()->second;
    };
    
    void add(long time, int price){
        TimeIndex[time] = price;
        PriceIndex[price].insert(time);
    };
    
    void update(long time, int price){
        int oldPrice = TimeIndex[time];
        TimeIndex[time] = price;
        PriceIndex[oldPrice].erase(time);
        PriceIndex[price].insert(time);
    };
    
    void remove(long time) {
        int oldPrice = TimeIndex[time];
        TimeIndex.erase(time);
        PriceIndex[oldPrice].erase(time);
        if (PriceIndex[oldPrice].size()==0) {
            PriceIndex.erase(oldPrice);
        }
    };
    
    map<long, int> TimeIndex;
    map<int, unordered_set<long>> PriceIndex;
};

#endif /* MinMaxRecentSystem_h */
