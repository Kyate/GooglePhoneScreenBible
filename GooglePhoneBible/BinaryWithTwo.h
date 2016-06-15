//
//  BinaryWithTwo.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BinaryWithTwo_h
#define BinaryWithTwo_h

#include "DataStructure.h"

using namespace std;

//刷题刷累了，上来攒人品！ 搞了两次电面，可能是第一次面的不好又给了第二次机会。还好后来过了，明天onsite。。。Finger crossed！
//
//第一次电面：假设除了用1和0表示数字的binary方式，还可以用2来表示，给一个数字，求有多少种表达方式。
//
//例子：
//4 = 100, 20, 12 所以答案是3。
//8 = 1000, 200, 120, 112 所以答案是4。这题想了半天没想出来，后来给了提示用dp写出来了。


int BinaryWithTwo(int num) {
    vector<int> dpresult(num+1, 0);
    dpresult[0] = 1;
    dpresult[1] = 1;
    for (int i = 2; i <= num; i++) {
        if (i%2!=0) dpresult[i] = dpresult[(i-1)/2];
        else dpresult[i] = dpresult[i/2]+dpresult[(i-2)/2];
    }
    return dpresult[num];
}

#endif /* BinaryWithTwo_h */
