//
//  IsSubtree.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/16/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef IsSubtree_h
#define IsSubtree_h

#include "DataStructure.h"

using namespace std;

/*
 
 刚刚结束的Google电面，在google呆了8年的貌似国人大哥。
 
 判断一个树是不是另一个的subTree.
 
 shortest palindrome. 求个onsite
 
 链接: https://instant.1point3acres.com/thread/176963 来源: 一亩三分地
 
 
 */

bool IsSubtree(TreeNode * t1, TreeNode * t2) {
    if (t1==nullptr && t2==nullptr) return true;
    if (t1==nullptr || t2==nullptr) return false;
    if (t1->val==t2->val) {
        if (IsSubtree(t1->left, t2->left) && IsSubtree(t1->right, t2->right))
            return true;
        else return false;
    }
            
    return IsSubtree(t1->left, t2) || IsSubtree(t1->right, t2);
}

#endif /* IsSubtree_h */
