//
//  RandomSet.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/16/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef RandomSet_h
#define RandomSet_h

#include "DataStructure.h"

using namespace std;

/*
 
 电面一面的面经在这里.
 
 http://www.1point3acres.com/bbs/thread-183067-1-1.html
 
 这次是第二面，第一面题好难LZ没答好，二面题目就超简单我也是被这个差距给惊狗带。不求offer，求个onsite体验一把啊哈哈哈
 
 大概就是取一个array里的任意n个不同的值,得到一个随机的组合，不能取同一个index的数，但是可以取数值相同的不同index的数
 
 给一个array：[5,1,3,3],
 再给一个数字n：2，
 求这个array里的任意num个数：比如可以得到[5,1] or [5,3] or [1,3] or [3,3] ，但是不能得到[5,5]
 
 再比如[5,1,3,3], 1 ===> [5] or [1] or [3]
 LZ就是先判断如果n>array.length或者n<=0或者array是空,返回一个空array，否则就是一个loop，每一次生成一个random的index数字，还用了一个hashset来存之前访问过的index，如果生成的random index之前已经get了，就再继续生成一个random index。
 
 loop n次，每次取到的值放进新的结果array里。
 
 然后说了说也可以用一个boolean array存每个值有没有已经取到。。
 
 写完后再写了写unit test什么的，还有问道怎么检测得到的结果比如[5,1]确实是[5,1,3,3]里的..
 
 问问大家有没有更优的方法啊
 
 http://www.1point3acres.com/bbs/thread-188731-1-1.html
 
 */


vector<int> RandomSet(vector<int> & nums, int n) {
    int len = nums.size();
    vector<int> result;
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < n; i++) {
        int idx = rand() % len;
        result.push_back(nums[idx]);
        swap(nums[idx], nums[len-1]);
        len--;
    }
    return result;
}

#endif /* RandomSet_h */
