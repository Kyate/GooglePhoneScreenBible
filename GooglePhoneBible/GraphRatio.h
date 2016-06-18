//
//  GraphNodeRatio.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/17/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef GraphNodeRatio_h
#define GraphNodeRatio_h

#include "DataStructure.h"

using namespace std;

/*
 
 1个小时前结束的电面，开始时问了两次他的名字，仍然没有听清，只能作罢。
 
 就问了句：你是PhD是吧，我说是ECE的PhD，然后就直接开始coding
 
 题目是：
 
 给你两个文件f1和f2，f1是10M的量级，f2是10G的量级。f1的每一行有三个东西：str1, str2, ratio，ratio代表str1和str2的比值，示例：
 
 1.  A, B, 0.5         // 解释：A / B = 0.5
 2.  A, E, 2.3         // 解释：A / E = 2.3
 3.  C, E, 1.5         // 解释：C / E = 1.5. From 1point 3acres bbs
 4.  C, D, 1.0         // 解释：C / D = 1.0
 5.  ...
 f2的每一行只存了str1, str2，示例：
 
 1.  C, B
 2.  A, D
 3.  ...
 需要返回一个新的文件叫f3，f3是在f2的基础上更新，并且和f1的格式一样，即你需要算出f2中每一行两个string的ratio，比如上面的例子的话，就是返回下面这样：
 
 1.  C, B, 0.33     // 即：C / B = C/E * E/A * A/B = 1.5*1/2.3*0.5 = 0.33
 2.  A, D, 1.53     // 即：A / D = A/E * E/C * C/D = 2.3*1/1.5*1 = 1.53
 电面具体结果：
 
 他出完题目后，问我有什么想法，我说用Map<Key1, Map<Key2, Ratio>>来存遍历f1后的关系。然后他想了会，给出了一个反例，说你后来求ratio的时候会进入死循环，就好比 A -> B -> C -> A这样。我说这种情况
 下可以backtrack。他好像有些听不下去了，说你有没有想到什么data structure。我才反应过来是f1遍历后实际形成了一个类似于weighted graph，每个node存他的邻居和他与邻居间的ratio。
 
 然后他问：那怎么求两个node之间的ratio呢？我说类似于shortest path。然后他说用什么algorithm呢？我说用DFS，BFS应该都可以。然后告诉他BFS的思路：从sourceNode开始每层每层地走，更新对每个邻居的
 ratio，直到抵达targetNode。然后他说你可以写代码了。
 
 然后就是最悲剧的事情了：先想着怎么定义这个Graph的Node就想了半天，后来才想到每个Node有一个name和adj的Map，adj的Map存的是邻居Node -> ratio的映射
 
 然后思路和他说了：
 
 先遍历f1，创建这个graph // 这个方法思路说了下，代码写完了，但肯定有错。。。
 
 然后遍历f2，对每一行的两个node（一个是sourceNode，另一个是targetNode）进行一个bfs找到ratio，加到f3里面。但这里写代码完全卡壳。直到时间到了也没有理顺。。。
 
 目测肯定是挂了，但想问下，这种情况怎么样向HR要求加面会增加被电面的可能性呢？
 
 真诚感各位！
 
 补充内容 (2016-3-29 08:15):
 
 更准确地说不是weighted graph，只不过node的adj里面除了存node外，还要存一个ratio而以，所以为什么BFS就行，而不需要用bellman ford / dijkstra 之类的东西
 
 补充内容 (2016-4-2 04:26):
 
 今天HR告诉我加面，可能面试官没有fail我
 
 */

struct NodeRatio {
    NodeRatio(char f, char s, double r) : first(f), second(s), m_NodeRatio(r) {};
    char first, second;
    double m_NodeRatio;
};

vector<NodeRatio> computeNodeRatio(vector<NodeRatio> known, vector<pair<char,char>> unknown) {
    unordered_map<char, unordered_map<char, double>> graph;
    for (auto r : known) {
        graph[r.first][r.second] = r.m_NodeRatio;
        graph[r.second][r.first] = 1.0 / r.m_NodeRatio;
    }
    vector<NodeRatio> result;
    for (auto p : unknown) {
        char start = p.first;
        char target = p.second;
        queue<char> myqueue;
        myqueue.push(start);
        unordered_map<char, double> visited;
        visited[start] = 1.0;
        while(!myqueue.empty()) {
            char current = myqueue.front();
            myqueue.pop();
            double prev = 1.0;
            if (visited.find(current)!=visited.end())
                prev = visited[current];
            bool found = false;
            for (auto next : graph[current]) {
                if (visited.find(next.first)==visited.end()) {
                    double nextNodeRatio = prev * next.second;
                    visited[next.first] = nextNodeRatio;
                    myqueue.push(next.first);
                    if (next.first == target) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }
        result.push_back(NodeRatio(start, target, visited[target]));
        for (auto v : visited) graph[start].insert(v);
    }
    
    return result;
}


#endif /* GraphNodeRatio_h */
