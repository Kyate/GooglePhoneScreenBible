//
//  AlienDict.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AlienDict_h
#define AlienDict_h

#include "DataStructure.h"

using namespace std;

/*
 
 最后一题：
 
 Input:
 
 BB
 BBE
 BAD
 BACE
 BED
 DAD
 ABBC
 ABBA
 
 (Known lexicographically sorted, under unknown alphabet order.)
 
 Output: B<D<C<A<E.
 其实就是给你一个String的数组，这个数组不是按照字母的顺序来排的，让你找出他们的排序规则。 因为时间没有多少，所以让我讲下思路，不需要编码。我就吧啦吧啦讲遍历第一个字符，找出最开始的第一个字符的顺序（我说这应该不是最优解，但是现在思路就是这样的）。然后周而复始的继续往后得出BDA   BAE  DC  CA，最后小哥讲没时间了，我觉得你是在正确的track上，然后就让我提问题了，我就问了俩问题，what's the best part wokring in Google / what's the biggest challenge in you daily work，小哥吧啦吧啦讲了一下，我就cool cool的，然后就愉快的say goodbye了。
 
 虽然现在依然水的不行，但是还是求有个好结果咯，也祝各位拿到好offer，顺利抽中身份。
 
 http://www.1point3acres.com/bbs/thread-177259-1-1.html
 
 */


bool dfsOrder(list<char> & result, unordered_set<char> & path, vector<unordered_set<char>> & graph, unordered_set<char> & allChar, char node) {
    allChar.erase(node);
    path.insert(node);
    for (auto next : graph[node-'A']) {
        if (path.count(next)>0) return false;
        if (allChar.count(next)>0) {
            bool cyclic = dfsOrder(result, path, graph, allChar, next);
            if (!cyclic) return false;
        }
    }
    result.insert(result.begin(), node);
    return true;
}

string AlienDictionary(vector<string> & words) {
    unordered_set<char> allChar;
    vector<unordered_set<char>> graph(26);
    for (auto word : words) {
        for (auto c : word) allChar.insert(c);
    }
    
    for (int i = 0; i < words.size()-1; i++) {
        string curr = words[i];
        string next = words[i+1];
        int j = 0;
        int cl = curr.length(), nl = next.length();
        while(j<min(cl, nl) && curr[j]==next[j]) j++;
        if (j<min(cl,nl)) {
            graph[curr[j]-'A'].insert(next[j]);
        }
    }
    
    list<char> result;
    for (int i = 0; i < 26; i++) {
        unordered_set<char> path;
        if (allChar.count(i+'A')>0) {
            bool cyclic = dfsOrder(result, path, graph, allChar, i+'A');
            if (!cyclic) return "";
        }
    }
    if (allChar.size()>0) result.insert(result.end(), allChar.begin(), allChar.end());
    string order;
    for (auto c : result) order.push_back(c);
    return order;
}

#endif /* AlienDict_h */
