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

/*
 刚面完一波google，速度来发帖赞人品。
 
 面试官是老美，Android组的，声音好沙哑，刚开始一直听不清他说啥。讲道理应该先聊聊简历寒暄寒暄，问候完他直接上题。题并不难，只不过我刚开始有点懵逼，有点犯傻，没进入状态。
 
 Binary tree lowest common ancester. lowest common ancester他是定义为longest path from a leaf to the root，貌似和leetcode那个题不太一样。找最长路径上的那个叶子节点。
 
 我一上来用的方法写到一半觉得写不下去。果断说我换个更直白的方法，把所有path都记录下来，然后返回最长path的最后一个node。写的过程中，他说我的第一个方法对着呢为啥不写完呢，我说先把这个写完再写那个。第一个方法就是不断更新path的长度，然后更新相对应的那个node。最后两种方法都写了，他说perfect，我们来下一个。
 
 你有 10^12个short integer，然后找出largest top100。最直白的方法就是用heap，分分钟完成。然后我想当然的说可以用hashmap，因为short integer 大概范围是-32000~32000，差不多64000个数，然后怎么
 弄key-value我不太清楚。他说heap is perfect enough，hashmap这个key-value pair不太好搞 - -。第二题就这么结束了。
 
 感觉老美面试还是稳，题比三哥简单。但是自己刚开始有点懵逼，表现的不太好，希望不要受到影响，求Onsite
 
 http://www.1point3acres.com/bbs/thread-187850-1-1.html
 
 
 */

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
