//
//  SortStringsFavorite.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef SortStringsFavorite_h
#define SortStringsFavorite_h

#include "DataStructure.h"

using namespace std;

/*
 
 面试官一美国小哥，简单闲聊后甩题：
 
 给一个 array of words，和favorite letters， 让重新排序array，使得按照favorite letters的priority 排列。 没有包含 favorite letters 的 words 则继续按照 原本字母表 排序
 
 举个栗子：
 
 array：['animal','duck','snake','zebra','horse','mouse']
 favorite letter:'zh'
 output--->['zebra','horse','animal','duck','mouse','snake']
 
 array：['aab','baa','caa','aaa','aaaa']
 favorite letter:'ab'
 output--->['aaa','aaaa','aab','baa','caa']
 算是半个水题。用随便一种sorting自己定义一个 comparator就ok。也可以用类似radix sort 来逐层比较每一个位置的letter。但是本人脑抽，一紧张把quicksort的pivot index搞错被interviewer发现了。估计难逃一死了。
 
 发个贴给大家看一看本人的死相多难看之余，希望大家别犯同样的傻叉错误。。
 
 补充内容 (2016-2-24 07:39):
 
 刚接到电话，居然过了。。美国小哥人好啊，放生积德啊！！继续准备onsite去了。大家也都加油好运！
 
 http://www.1point3acres.com/bbs/thread-173016-1-1.html
 
 */

class myComparator{
public:
    myComparator(string fav) {
        for (int i = 0; i < fav.length(); i++) {
            order[fav[i]] = i;
        }
    }
    
    bool operator()(string const & s1, string const & s2) {
        int i = 0;
        for (; i < min(s1.length(), s2.length()); i++) {
            char c1 = s1[i], c2 = s2[i];
            if (c1==c2) continue;
            if (order.find(c1)!=order.end() && order.find(c2)!=order.end()) {
                if (order[c1]<order[c2]) return true;
                else return false;
            }
            else {
                if (order.find(c1)!=order.end()) return true;
                if (order.find(c2)!=order.end()) return false;
                return c1 < c2;
            }
        }
        if (i==s1.length()) return true;
        else return false;
    }
    
    unordered_map<char, int> order;
};



void SortWithFavorite(vector<string> & strs, string favorite) {
    sort(strs.begin(), strs.end(), myComparator(favorite));
    return;
}

#endif /* SortStringsFavorite_h */
