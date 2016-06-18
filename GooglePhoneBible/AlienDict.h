//
//  AlienDict.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AlienDict_h
#define AlienDict_h

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
