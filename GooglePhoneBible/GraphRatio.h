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
