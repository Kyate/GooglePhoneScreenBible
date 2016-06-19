//
//  LongestPathLeaf.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/19/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestPathLeaf_h
#define LongestPathLeaf_h

#include "DataStructure.h"

using namespace std;

TreeNode * LongestHelper(TreeNode * node, int & depth);

TreeNode * LongestPathLeaf(TreeNode * root) {
    int depth = 0;
    TreeNode * leaf = LongestHelper(root, depth);
    return leaf;
}

TreeNode * LongestHelper(TreeNode * node, int & depth) {
    if (node==nullptr) { depth = 0; return nullptr; };
    int leftdepth = 0, rightdepth = 0;
    TreeNode * leftside = LongestHelper(node->left, leftdepth);
    TreeNode * rightside = LongestHelper(node->right, rightdepth);
    depth = max(leftdepth, rightdepth) + 1;
    
    if (leftside > rightside) return leftside;
    else {
        if (leftside==nullptr && rightside==nullptr) return node;
        else return rightside;
    }
}


#endif /* LongestPathLeaf_h */
