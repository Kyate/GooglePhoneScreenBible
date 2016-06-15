//
//  MaxDepthOfBinaryTree.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MaxDepthOfBinaryTree_h
#define MaxDepthOfBinaryTree_h

#include "DataStructure.h"

using namespace std;

/*
 
 1. maxDepth of a tree:recursion
 
 http://www.1point3acres.com/bbs/thread-188200-1-1.html
 
 */

int MaxDepthOfTree(TreeNode * root) {
    if (root==nullptr) return 0;
    return max(MaxDepthOfTree(root->left), MaxDepthOfTree(root->right)) + 1;
}

#endif /* MaxDepthOfBinaryTree_h */
