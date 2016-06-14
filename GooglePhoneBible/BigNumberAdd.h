//
//  BigNumberAdd.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BigNumberAdd_h
#define BigNumberAdd_h

#include "DataStructure.h"

using namespace std;

/*
 
 上次电面之后，Recruiter给我打电话说是“好消息”，然后给我加了一轮电面。(:з)∠)
 
 今天下午做的加面，面试官是个烙印。(:з)∠) 还是两个题：
 
 大整数加法，追问如何用并行计算优化。我说按8位切片，在每个片里转成整数做加法，然后等更低位传过来进位。不过听烙印的反应似乎不太好。(:з)∠)
 
 链接: https://instant.1point3acres.com/thread/165509 来源: 一亩三分地
 
 */

vector<int> BigNumberAdd(vector<int> & n1, vector<int> & n2) {
    int l1 = n1.size(), l2 = n2.size();
    vector<int> result(max(l1,l2), 0);
    int add = 0;
    int i = l1-1, j = l2-1;
    for (; i>=0 && j>=0; i--,j--) {
        int sum = n1[i]+n2[j] + add;
        add = sum / 10;
        result[max(i,j)] = sum % 10;
    }
    
    int f = (i>=0) ? i : j;
    if (f==0) {
        if (add>0) result.insert(result.begin(), add);
        return result;
    }
    else {
        vector<int> longer = (i>=0) ? n1 : n2;
        while(f>=0) {
            int sum = longer[f]+add;
            add = sum/10;
            result[f] = sum%10;
            f--;
        }
        if (add>0) result.insert(result.begin(), add);
        return result;
    }
}


/*
 
 第一题 实际上你的并行策略并没起作用。如果有carry in 你的MSB得重新算。等于说整个MSB的计算都depend on LSB的计算的结果。 我觉得应该用个类似
 carry selection adder的方法。 suppose你分2个进程， 你的MSB要计算有carry in的， 也要计算没有carry in的 最后根据是有还是没有把预测错误的
 那个结果抛弃就行。 补充内容 (2016-3-15 13:43): suppose 你把整个数字断分成MSB和LSB。 你需要3＊个进程
 链接: https://instant.1point3acres.com/thread/165509 来源: 一亩三分地
 
 同意LS，因为高位在等低位的carry，如果真的有carry还得再算一遍，既然这样不如在等的过程中算一遍没有carry的和carry是1的，最后选择对的一个。
 链接: https://instant.1point3acres.com/thread/165509 来源: 一亩三分地
 

 
 */


#endif /* BigNumberAdd_h */
