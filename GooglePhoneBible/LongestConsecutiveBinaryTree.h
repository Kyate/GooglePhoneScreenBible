//
//  LongestConsecutiveBinaryTree.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/15/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestConsecutiveBinaryTree_h
#define LongestConsecutiveBinaryTree_h

#include "DataStructure.h"

using namespace std;

/*
 
 第二次电面：两题都是lc原题，lc298 (Longest consecutive sequence in BT) 和lc128 (longest consecutive sequence in array)。各位自己去看解法吧！
 
 祝大家找工作顺利！！！
 
 http://www.1point3acres.com/bbs/thread-192677-1-1.html
 
 */


int longestConsecutive(TreeNode* root) {
    int result = 1;
    if (root==nullptr) return 0;
    longestHelper(root, result);
    return result;
}

int longestHelper(TreeNode * root, int & result) {
    if (root->left==nullptr && root->right==nullptr) return 1;
    int leftside = INT_MIN, rightside = INT_MIN;
    if (root->left) {
        leftside = longestHelper(root->left, result);
        if(root->left->val != root->val+1) leftside = 0;
    }
    if (root->right) {
        rightside = longestHelper(root->right, result);
        if(root->right->val != root->val+1) rightside = 0;
    }
    result = max(result, max(leftside, rightside) + 1);
    return max(leftside, rightside) + 1;
}

#endif /* LongestConsecutiveBinaryTree_h */
