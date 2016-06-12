//
//  DifferentChar.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/11/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DifferentChar_h
#define DifferentChar_h

#include "DataStructure.h"

using namespace std;

/*
 
 上周三面试的，今天接到电话说已经挂了。 Google的面试给我留下了很好的印象，因为做的比较规范，最后反馈也都是电话告知结果，非常正规的感觉。 我当时面
 试的时候运气不错，是一个美国小哥，题目也蛮简单的。
 
 第一题是给两个string,其中一个string比另外一个多了个字母，返回这个字母。 第一题就用了最简单的
 比较，比较每一个字母（按照顺序就可以了），注意一下边界条件，最后一个的边界条件。 Follow up是如果字母顺序打乱了怎么找。我先说了HashMap，要写的
 时候想起来另外一个方法，就是把所有的ASICII加起来，减一下，得到的就是多出来的那个。 我就直接说了这个，然后写了这个。写完之后小哥问了一下时间空间复
 杂度，然后说你已经把本来要提升的东西做了
 
 */

char DifferentChar(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    for (int i = 0; i < min(l1,l2); i++) {
        if (s1[i]!=s2[i]) {
            return l1>l2 ? s1[i] : s2[i];
        }
    }
    return l1>l2 ? s1.back() : s2.back();
}

char DifferentCharUnordered(string s1, string s2) {
    s1 += s2;
    int x = 0;
    for (auto c : s1) {
        x = x ^ c;
    }
    return static_cast<char>(x);
}

#endif /* DifferentChar_h */
