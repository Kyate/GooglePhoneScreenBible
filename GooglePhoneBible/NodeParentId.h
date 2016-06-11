//
//  NodeParentId.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/10/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef NodeParentId_h
#define NodeParentId_h

#include "DataStructure.h"

using namespace std;

/**********************************************************

 给一堆nodes有，每个里面有id，有parent_id
 function 1 实现获取当某点的子节点
 function 2实现获取当某点的后代点
 follow up：
 先用O(n)做了，然后问如何做到O(1)
 取后代的时候注意什么问题？
 1、自己是自己的父节点
 2、nodes里面有环（如何防范？）
 http://www.1point3acres.com/bbs/thread-192591-1-1.html

 **********************************************************/

/*
 
 Suppose we have n nodes with id 0..n-1
 And the input pair [i, j] means the node i is the parent of node j
 
 Using hash map to store the adjacent list. 
 then the function 1 takes O(1) time.
 function 2 uses BFS taking O(n) time
 */

class GraphParentId {
public:
    GraphParentId(int n) : nodesNum(n) {
        graph.resize(n);
    }
    
    // e.first is the father of e.second
    // but we want to construct the map from father to children
    void addEdge(vector<pair<int,int>> & edges) {
        for (auto e : edges) {
            graph[e.first].insert(e.second);
        }
    };
    
    vector<int> getChildren(int node) {
        unordered_set<int> children = graph[node];
        return vector<int>(children.begin(), children.end());
    }
    
    vector<int> getSuccessors(int node) {
        queue<int> myqueue;
        myqueue.push(node);
        vector<int> result;
        unordered_set<int> visited;
        visited.insert(node);
        while(!myqueue.empty()) {
            int current = myqueue.top();
            result.push_back(current);
            myqueue.pop();
            for (auto neighbor : graph[node]) {
                if (visited.count(neighbor)==0) {
                    myqueue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        
        result.erase(visited.begin());
        return result;
    }
    
    vector<unordered_set<int>> graph;
    int nodesNum = 0;
};

#endif /* NodeParentId_h */
