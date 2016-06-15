//
//  TreeInorderConnect.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TreeInorderConnect_h
#define TreeInorderConnect_h

#include "DataStructure.h"

using namespace std;

/*
 
 recruitor email找到我。问我有没有兴趣面谷歌。由于Lz自己确实在准备跳槽。只是没准备好。于是想面一个试试。电话接通了没有废话，直接做题。
 
 给一个tree，每一个treeNode多2个指针pre next但是是空的。要求按inorder的顺序把指针连起来。 Lz用recursion。写的不好。
 
 followup是怎么实现insert方法。还问了时间复杂度和空间复杂度。
 
 第一次面试太紧张，已跪。
 
 祝大家早日找到工作。
 
 http://www.1point3acres.com/bbs/thread-192582-1-1.html
 
 */

void InorderConnect(TreeDoubleLinkNode * root) {
    vector<TreeDoubleLinkNode*> result;
    if (root == nullptr) return;
    stack<TreeDoubleLinkNode*> mystack;
    while(!mystack.empty() || root!=nullptr) {
        if (root!=nullptr) {
            mystack.push(root);
            root = root->left;
        }
        else {
            TreeDoubleLinkNode * node = mystack.top();
            mystack.pop();
            if (result.size()>0) {
                result.back()->next = node;
                node->prev = result.back();
            }
            result.push_back(node);
            root = node->right;
        }
    }
    return;
}

void InorderConnectHelper(TreeDoubleLinkNode * root, TreeDoubleLinkNode *& last);

void InorderConnectRecursive(TreeDoubleLinkNode * root) {
    TreeDoubleLinkNode * last = nullptr;
    InorderConnectHelper(root, last);
}

void InorderConnectHelper(TreeDoubleLinkNode * root, TreeDoubleLinkNode *& last) {
    if (root) {
        InorderConnectHelper(root->left, last);
        if (last) {
            last->next = root;
            root->prev = last;
        }
        
        last = root;
        
        InorderConnectHelper(root->right, last);
    }
}


#endif /* TreeInorderConnect_h */
