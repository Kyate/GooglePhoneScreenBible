//
//  BestTimeToBuyAndSellStock.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/12/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef BestTimeToBuyAndSellStock_h
#define BestTimeToBuyAndSellStock_h

#include "DataStructure.h"

using namespace std;

/*
 
 5月5号进行了Google的电话面试，是一个老印。题目简单到自己都无法相信，回报地里攒RP！Leetcode的Buy Stock的1和2……速秒之…… 就一轮，今天收到
 onsite通知，希望onsite有好运
 
 链接: https://instant.1point3acres.com/thread/178142
 来源: 一亩三分地
 
 */

/*
 
 121. Best Time to Buy and Sell Stock
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an 
 algorithm to find the maximum profit.
 
 */


int maxProfitOneTransaction(vector<int>& prices) {
    vector<int> dpresult(prices.size(), 0);
    for (int i = 1; i < prices.size(); i++) {
        dpresult[i] = dpresult[i-1] + (prices[i]-prices[i-1]);
        if (dpresult[i]<0) dpresult[i] = 0;
    }
    int result = 0;
    for (int i = 0; i < dpresult.size(); i++) {
        result = max(result, dpresult[i]);
    }
    return result;
}


/*
 
 122. Best Time to Buy and Sell Stock II
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell 
 one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you 
 must sell the stock before you buy again).
 
 */

int maxProfitMultipleTransactions(vector<int>& prices) {
    int result = 0;
    if (prices.size()==0) return result;
    int buy = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i]>buy) {
            result += prices[i]-buy;
            buy = prices[i];
        }
        else buy = prices[i];
    }
    
    return result;
}

#endif /* BestTimeToBuyAndSellStock_h */
