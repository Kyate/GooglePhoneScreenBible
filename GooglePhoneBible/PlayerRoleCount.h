//
//  PlayerRoleCount.h
//  GooglePhoneBible
//
//  Created by Jerome on 6/18/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PlayerRoleCount_h
#define PlayerRoleCount_h

#include "RangeMaximumQuery.h"

using namespace std;

/*
 
 LZ选的Seattle position，准时收到电话，听声音像是个很nice的白人小哥。
 
 开场让我自我介绍，聊了个project，然后出题。
 
 题目：
 
 input 是一个游戏的后台log (可以自己定义结构)：
 （1） update log，每条记录是 (time, player, role)，比如 (2016 March 11 13:10 UTC, 'mark', 'knight')
 （2） play log，没条记录是（time，player），比如 (2016 March 12 12:10 UTC, 'mark')
 
 output是每个role出现的次数。
 面试过程：
 
 问清楚input&output，说input结构可以自己定义。我的回答是把所有update建一个 per-user map，update list按序存成数组。每次读play log，按player找到update list，然后binary search。时间
 NlogL， N是play log长度，L是per-user update list 的最大长度。
 
 快写完的时候，小哥说可以先不写binary search 容易错，我们先linear scan。。。小哥一直很nice应该不是BS我。。。写完给我提了一个小bug然后问了下test case。
 
 总结：
 
 自我介绍加聊project大概六七分钟的样子，clear question和说解法也是六七分钟，十五分钟边说边写完了之后，说完test cases就只有七八分钟了，小哥说差不多还是留几分钟那我们就进入提问环节吧。
 
 感觉写的速度一般，不快不慢，说话不够简洁浪费了点时间，都需要多练啊。。。求过！
 
 补充内容 (2016-4-10 00:05):
 
 补充一下，output是要用play log去找每个role的 登陆次数
 
 避免引起歧义解释下。。update表示某个时刻某个玩家切换了角色，play log表示某个时刻某个玩家登陆了游戏，也就是要用play log的时间找该玩家play 的role，然后统计次数，登陆一次就算一次
 
 再举个例：play log里有4条记录，mark 3条，jack 1条，mark玩过两次wizard一次knight (切换角色反应在update log里)，jack玩过一次wizard，所以wizard一共3次，knight一次
 
 实际上，需要按照play log来找在当前这个时间，玩家的role是什么（因为在这个play发生之前，玩家可能换过很多种role）。因此，首先将update log建成key为user，value为按时间排序的pair<时间，role>。搜索
 play log的过程中，用Binary search搜索该用户对应的所有update条目，找到当前play时间之前的最后一条update记录，就是目前该用户的role。
 
 http://www.1point3acres.com/bbs/thread-179863-1-1.html
 
 */


struct UpdateLog {
    UpdateLog(long t, string u, string r) : time(t), user(u), role(r) {};
    UpdateLog():time(0),user(""),role(""){};
    long time;
    string user;
    string role;
};

struct PlayLog {
    PlayLog(long t, string u) : time(t), user(u){};
    PlayLog():time(0),user(""){};
    long time;
    string user;
};

vector<pair<string, int>> CountRoleNumber(vector<UpdateLog> & updates, vector<PlayLog> & plays) {
    unordered_map<string, map<long, string>> userMap;
    for (auto ul : updates) {
        userMap[ul.user][ul.time] = ul.role;
    }
    unordered_map<string, int> roleCount;
    for (auto p : plays) {
        string user = p.user;
        auto it = userMap[user].lower_bound(p.time);
        if (it!=userMap[user].begin()) it--;
        roleCount[it->second]++;
    }
    vector<pair<string, int>> result;
    for (auto rc : roleCount) {
        result.push_back(make_pair(rc.first, rc.second));
    }
    
    return result;
}

#endif /* PlayerRoleCount_h */
