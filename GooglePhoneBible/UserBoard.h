//
//  UserBoard.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/17/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef UserBoard_h
#define UserBoard_h

#include "DataStructure.h"

using namespace std;

/*
 
 第二轮电面跪经，面试官迟到7-8分钟。 说是手机找不到了。 大概聊了一下以前做的project，开始做题。
 
 题目是给你一个board，里面存储user的信息，user有id和socre。
 
 board有adduser(id, score)(返回add进去的user当前的rank), findByRank(k) (这个返回id)。
 
 Add如果本身已经有id在board中，需要对这个id的score进行update。
 
 开始想的是用map加binary search中，中途脑子短路，写到一半发现似乎做不出来了。。。。(面完之后想想，这个方法应该是做的出来的。)
 
 面试官说应该要用binary search tree做，听到这里 基本就知道gg了。
 
 然后就是悲剧的开始，只会做binary search tree的添加点的操作，update和delete 操作基本忘干净了，不记得具体的步骤了。
 
 写代码的时候 struggle在了 delete 操作上，还有10分钟左右面试官说不用写了，就这样了。最后就是问一些问题了。
 
 还是基本功不够扎实，发个面经，攒点rp。。。顺便求内推！！！！！
 
 http://www.1point3acres.com/bbs/thread-183346-1-1.html
 
 */

struct RankNode {
    RankNode(int r, int v) {
        lcount = r;
        score = v;
        left = nullptr;
        right = nullptr;
    }
    int lcount, score;
    unordered_set<int> idset;
    RankNode * left, * right;
};

class UserBoard {
public:
    UserBoard(){
        root = nullptr;
    };
    
    int add(int userid, int score) {
        if (root==nullptr) {
            root = new RankNode(0, score);
            root->idset.insert(userid);
            idMap[userid] = root;
            return 1;
        }
        if (idMap.find(userid)!=idMap.end()) {
            RankNode * node = idMap[userid];
            if (node->idset.size()==1) {
                deleteNode(node);
            }
            else {
                node->idset.erase(userid);
            }
            insertNode(userid, score);
        }
        else {
            insertNode(userid, score);
        }
        
        return 0;
    }
    
    void insertNode(int userid, int score) {
        RankNode * prev = root;
        RankNode * currParent = root;
        bool found = false;
        while(prev) {
            currParent = prev;
            if (prev->score == score) {
                prev->idset.insert(userid);
                found = true;
                break;
            }
            else if (score < prev->score) {
                prev->lcount++;
                prev = prev->left;
            }
            else {
                prev = prev->right;
            }
        }
        if (!found) {
            RankNode * node = new RankNode(0, score);
            node->idset.insert(userid);
            idMap[userid] = node;
            if (node->score < currParent->score) {
                currParent->left = node;
            }
            else {
                currParent->right = node;
            }
        }
    }
    
    
    RankNode * findParent(RankNode * node) {
        if (node==root) return nullptr;
        RankNode * curr = root;
        RankNode * prev = root;
        while(curr!=node) {
            if (node->score < curr->score) {
                curr->lcount--;
                prev = curr;
                curr = curr->left;
            }
            else {
                prev = curr;
                curr = curr->right;
            }
        }
        return prev;
    }
    
    RankNode * findLeftMost(RankNode * node) {
        if (node->left==nullptr) return node;
        node->lcount--;
        return findLeftMost(node->left);
    }
    
    void deleteNode(RankNode * node) {
        RankNode * parent = findParent(node);
        if (parent==nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                root = nullptr;
            }
            else if (node->left == nullptr) {
                root = node->right;
            }
            else if (node->right == nullptr) {
                root = node->left;
            }
            else {
                RankNode * leftmost = findLeftMost(root->right);
                leftmost->left = root->left;
                leftmost->right = root->right;
                leftmost->lcount = root->lcount;
            }
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                if (parent->left == node) parent->left = nullptr;
                else parent->right = nullptr;
            }
            else if (node->left == nullptr) {
                if (parent->left == node) parent->left = node->right;
                else parent->right = node->right;
            }
            else if (node->right == nullptr) {
                if (parent->left == node) parent->left = node->left;
                else parent->right = node->left;
            }
            else {
                RankNode * leftmost = findLeftMost(node->right);
                leftmost->left = node->left;
                leftmost->lcount = node->lcount;
                leftmost->right = node->right;
                if (parent->right == node) parent->right = leftmost;
                else parent->left = leftmost;
            }
        }
    }
    
    vector<int> findByRank(int k) {
        vector<int> result;
        RankNode * node = root;
        while(node) {
            if (node->lcount +1 == k) {
                result = vector<int>(node->idset.begin(), node->idset.end());
                break;
            }
            else if (k > node->lcount) {
                k -= node->lcount + 1;
                node = node->right;
            }
            else {
                node = node->left;
            }
            
        }
        return result;
    }
    
    
    unordered_map<int, RankNode*> idMap;
    
    RankNode * root;
};

#endif /* UserBoard_h */
