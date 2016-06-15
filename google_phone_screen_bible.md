# Google Phone Screen 最新面经

1.	面完一周还没消息催了下hr， 刚通知过了， 可以愉快的准备onsite了。分享下电面题。面试官是个berkeley 本科一路读到phd的黑哥们。

	简化版有向图找环， 给一堆edges， 找到eg. 1->2 , 同时2->1的这种边的个数， 比如上面这个例子， 应该返回2。 秒答以后问了下复杂度。

	有一个double类型的数组， 找满足 [a, a + 1) 的最长序列含有的元素的个数， eg. [ 1.0 ,1.3 ,1.5 ,2.3, 3.5],  最长的是[1.0 1.3 1.5], 应该返回3。这种小学5年级的数学（数组操作）题对我来说是很困难的， 我直接说暴力解法呗， 然后面试官提醒了下用greedy的方法。 然而代码还是写的很艰难。。。大家可以自己写写O(n)的方法练习一下。

	[http://www.1point3acres.com/bbs/thread-192426-1-1.html](http://www.1point3acres.com/bbs/thread-192426-1-1.html)

2.	刚面完，貌似是个欧洲小哥，上来hello完了以后就开始做题，两个题:

	第一个 lc 54 spiral matrix
稍微改动了下成了x,y坐标的image上色，解释题目解释了半天，其实换汤不换药。这个时候加上前面找doc和看小哥演示链接的时间，快磨叽过去十分钟了，但是自己非常sb的紧张的一比，结果半个小时才断断续续写出来，中途还想打开leetcode抄一波，结果居然忘了题目的名字了。。崩盘。。只好默默回去写……而且中间还把x,y坐标搞反了，自己卡了半天，小哥显然非常的无语。。写完了以后竟然过去半个多小时了，感觉还有bug，不过就小哥也没care。。然后是第二题。

	第二题 sorted list 2sum
楼主一看感觉这tm挽回颜面的时间到了！！！解释了下思路然后瞬间秒了，然后walk trough了一下test case。小哥就说没时间了，然后good luck。。
感觉好虚……第一题居然花了那么久，还是自己太不淡定了，现在只求2面。。bless me.... 
大家面试的时候一定要静下心来，不要浮躁。。发挥出自己的正常水平基本就很稳了。祝大家找工顺利。。
	

	[http://www.1point3acres.com/bbs/thread-192578-1-1.html](http://www.1point3acres.com/bbs/thread-192578-1-1.html)

3.	第一次电面很紧张，是个小哥，人不冷不热。貌似是新题，题目很简单一个 binary watch，类似下图![image](http://www.slipperybrick.com/wp-content/uploads/2007/12/led_binary_watch.jpg)

	比如：

		1000 > 8

		000011 > 3

	时间就是08:03. 

	让输出所有亮三个灯的时间。
刚开始感觉可以用backtracking来枚举情况，写了一会小哥不理解，然后提示用最naive的方式，写一个countones的函数，然后从 0000 -> 1111分别调用countones来枚举所有符合条件的情况。需要注意，小时必须小于12，分钟必须小于60.
做完有个小bug在提醒下改了，然后时间不多就问了几个问题。
请问电面是不是都是两道题，我只做了一道是不是没希望了.
bless～


	[http://www.1point3acres.com/bbs/thread-192342-1-1.html](http://www.1point3acres.com/bbs/thread-192342-1-1.html)

4.	本来投的是EE方向，后来recruiter主动联系说你投的已经满了，想不想面SDE，我说当然好了，然后五月初写完了OA，题目很稳定，地里面两道题答案都有今天下午电面，面试官听口音应该是个美国本地大叔，声音很和蔼，是总部的site reliability engineer， 先跟我聊了下简历，然后就开始做题。

	第一题：打印所有的质数（print all prime numbers），我已开始没理解清楚范围，设了个i<Integer.MAX_VALUE，为了第一题秒时间，我没多想就用了俩for loop写出来了，他说可以，这样能保证小范围的质数短时间打出来

	第二题：follow up， what if keep printing to the number that greater than the biginteger by using java, 没想明白,我说java里面有biginteger的library，大于long的长度，他说这样用第一题的方法的话越到最后时间越长，两个数间隔好很久（假设n到正无穷..）. From 1point 3acres bbs
因为是个O(N*N)的解法，有没有更好的解法，大叔很有耐心，一直在等我想，也给了些hint，我最后没想出来，后来时间到了，感觉药丸。

	后来他推荐说经常上project euler上面刷刷题，我说好的，估计是暗示我刷的不够吧，本来专业就不一样，EE出身半路出家转CS，最后一学期发现EE工作很难找于是赚了CS，还是挺吃力的，anyway，先写出来给地里的兄弟姐妹们看看面经吧，攒个人品

	[http://www.1point3acres.com/bbs/thread-192458-1-1.html](http://www.1point3acres.com/bbs/thread-192458-1-1.html)

5.	直接上题

		write a grid class. 
	
		1. set the height and width
		2. set value at arbitrary point
		3. get max value of the grid

	一开始问我用什么结构存这个grid， 我说vector，他问为什么，我说可以random access。

	然后做题，先直接brute-force， 2问O(1), 3问O(n^2)。他说取最大值太慢了，我就用了个priority_queue（他还问了我priority_queue<int, vector<int>, less<int>>参数的意思，说他不太清楚。。），2问变O(n^2)，3问变O(1)。他说不行，set value太慢了，我说创建一个vector<int> maxVallue(m, 0)，记录每行的最大值，这样2问复杂度是O(n), 3问是O(m)。

	他又否了我的想法，说如果是一个1*1000的grid复杂度还是很高。我说binary search tree可以都O(logn)，他说有duplicate怎么办，后来我说用multiset，这样都是O(logn)并且可以重复。

	（PS: 因为太久没用multiset+时间太赶，用法写错了。。。multiset是不能改变值的，只能找到了然后删了再加新的，当时没时间了就跟set一样直接ms[grid[i][j]] = newValue了。。。应该是ms.erase(ms.find(grid[i][j])); ms.insert(newValue)。悲剧）. 

	这一道题就把时间用光了，前前后后写了4种方法，最后那个也不知道达到他的要求没

	> 这题是经典的operation tradeoff。

	> 假设矩阵大小N＊M，那么（至少）有如下做法：

	> 1. 维护一个正常的grid。set value O(1)，取最大值O(NM)，空间复杂度O(NM)。

	
	> 2. 二维线段树维护最大值。set value O(logNlogM)，取最大值O(1)，空间复杂度O(NM)。
	> 3. 自己建heap，然后建立一个从grid cell和heap index的双向映射，然后每次更新值的时候先从grid到heap的映射中找到heap对应的index，然后根据改大还是改小决定shift up或者shift down并且维护所有变更的index。set value O(log(NM))，取最大值O(1)，空间复杂度O(NM)。	
	
	> 4. 记录最大值和最大值坐标，每次修改到最大值所在坐标的时候更新最大值。set value 最好情况O(1)，最差情况O(NM)，取最大值O(1)，空间复杂度O(NM)。
	
	
	> 之后就是考虑如何tradeoff。如果set数量远远大于query数量，那么set的复杂度就要尽量低，于是方法1是最好的；如果query数量远远大于set数量，或者说set数量远远低于矩阵大小，那么方法4是最好的，因为最大值被修改的可能性不高；如果query和set数量基本相同，而且和矩阵大小是一个数量级，那么方法3应该是首选。如果这是一个实际问题，那么可能所有的情况都会出现，所以可以根据现在query和set的比例情况自适应的选择最好的处理方式。
	
	[http://www.1point3acres.com/bbs/thread-192195-1-1.html](http://www.1point3acres.com/bbs/thread-192195-1-1.html)

6.	上周GOOGLE 店面， 一个题 , 一直标准的系统函数read， 有一个功能 每次就读一个字节， 然后要经常读，在一个loop 里， 问如何优化。 结果就是一次点用read多读一些，放在缓存里，用没了再读。

	[http://www.1point3acres.com/bbs/thread-191880-1-1.html](http://www.1point3acres.com/bbs/thread-191880-1-1.html)

7.	给一堆nodes有，每个里面有 id，有parent_id

	function 1 实现获取当某点的子节点 

	function 2  实现获取当某点的后代点 

	follow up：

	先用O(n)做了，然后问如何做到O(1)

	取后代的时候注意什么问题？
	
	1. 自己是自己的父节点

	
	2. nodes里面有环（如何防范？）

	
	[http://www.1point3acres.com/bbs/thread-192591-1-1.html](http://www.1point3acres.com/bbs/thread-192591-1-1.html)

8.	Google 技术店面，4月份面的，楼主太懒，一直拖到现在。 

	听口音应该是白人小哥，上来寒暄一番，说说自己在google 做什么，然后问了些关于项目的东西，然后做题。

	题目很简单，就是leetcode 346 题，moving average from datastreaming。但楼主做的时候这道题还没post 出来。目测只要将time complexity 降到O（1） 就行，楼主就是维护一个window size 大小的List，和一个window size 内所有数的和。但要注意corner case。 

	还有两个简单的follow up，如果是多线程怎么办，以及写一下test case。下周onsite，攒一下RP。祝各位找工作顺利。

	链接: [https://instant.1point3acres.com/thread/178618](https://instant.1point3acres.com/thread/178618) 来源: 一亩三分地

9.	美国小哥。上来先问我自我介绍和最challenge的project。聊了大概七八分钟， 然后上题。很简单。 

	1. 给一个字符串里面只包含0-9的数字和＊，＊可以被0或者1代替，求出input字符串中的＊代替成0或者1的所有结果。100*11 结果是 100011，100111 

	2. 一个整数一数组形势给出，给这个数作加1。 

	链接: [https://instant.1point3acres.com/thread/176414](https://instant.1point3acres.com/thread/176414) 来源: 一亩三分地

10.	5/6 google 电面 

	首先给一个字典，比如：{apple, people,...} 再给一个misspelling word，比如：adple，返回它的正确拼写，即 apple 还知道一个限制条件，misspelling word只跟原单词有一个字母的区别**（且长度相同）**。如果输入是addle，返回null。如果字数不同，也返回null 还是比较简单的一个题，一开始以为是warm up。结果发现这种简单题也是能扯出很多东西的，主要在问题的理解和交流上。比如：是不是需要返回所有的correction，如何降低一些时间复杂度。

	写完代码，又问了下我怎么测试。一共用了30分钟在这道题上。剩下的15分钟就是聊我过去的项目和她现在的team。45分钟准时挂电话。。 上周五电面，今天就给了onsite通知，还是很有效率的。 

	链接: [https://instant.1point3acres.com/thread/178030](https://instant.1point3acres.com/thread/178030) 来源: 一亩三分地

11.	上周三面试的，今天接到电话说已经挂了。 

	Google的面试给我留下了很好的印象，因为做的比较规范，最后反馈也都是电话告知结果，非常正规的感觉。 

	我当时面试的时候运气不错，是一个美国小哥，题目也蛮简单的。第一题是给两个string,其中一个string比另外一个多了个字母，返回这个字母。 第一题就用了最简单的比较，比较每一个字母（按照顺序就可以了），注意一下边界条件，最后一个的边界条件。 

	Follow up是如果字母顺序打乱了怎么找。我先说了HashMap，要写的时候想起来另外一个方法，就是把所有的ASICII加起来，减一下，得到的就是多出来的那个。 我就直接说了这个，然后写了这个。写完之后小哥问了一下时间空间复杂度，然后说你已经把本来要提升的东西做了。

	然后给了个第三题，是说如果说要实现一个数据结构，要有insert()， delete()，medium()，mode()方法，怎么写。 这题感觉是我最后被拒的原因，因为我感觉我没正确理解他的意思。因为这里你用LinkedList()也好，ArrayList（）也好，总会有一个时间复杂度会很高，后面结束的时候想想可能是想让我比较每种结构的优缺点。 我当时是写了一个Arraylist的，他问如果找中位数怎么办，是不是会time complexity很高，然后我说每个结构都会有缺点，是个trade off。 最后时间也不够，因为是额外加的，草草结束了这题。 其实答完感觉还可以，不过最后还是挂了。 

	Move on了，不过HR还是很nice，今天电话告知我挂了之后问我要不要点学习资料，还发了学习资料，然后说8到12个月以后再见。 整体对google的招聘印象很好 

	链接: [https://instant.1point3acres.com/thread/175542](https://instant.1point3acres.com/thread/175542) 来源: 一亩三分地

12.	第一轮，国人小哥。 给我一堆unsorted数字，问我可不可以等分成若干组，每组由五个连续的整数组成。 

	eg: 

	 - 1,2,3,4,5,4,5 -> false 

	 - 1,2,3,4,5,2,3,4,5,6 ->true 

	follow up: 问我可不可以等分成若干组，每组由五个重复数组成。 

	follow up 2: 每组由k个连续数组成。 k>=3 

	第二轮： 本地小哥 地里的encode decode aaaa->4xa 

	这里楼主作死了，我就说那 4xa 和aaaa 结果都是4xa 怎么区别？ 对面蒙了，我也傻了，天哪就你嘴贱，我是在给自己出题吗？ 

	果然对面就回了既然你这么diao，你来解决这个问题吧。。。。。。 

	楼主想了想：

	1. 全部做成 2x a的形式，但是在不重复字母多的时候perform很差 

	2. 参照编译器用转义符， 变成2\xa， 如果是\输入就变成 \\\\

	对方好像自己在嘟囔一些东西，说转义符是可以，但是会有问题，但是也觉得没啥其他办法。 跟amazon那哥们不一样，这个小哥很爱笑，楼主瞅准机会就是讲段子，然后黑c++。小哥听的很开心，好像不打算问我问题了，我就继续跟他吹谷歌多好，把谷歌三宝拿出来跪舔。 整套下来讲了快一个小时，都是吹水，第一次遇见这种面试，不知道好事坏事，不过我挺喜欢的，我也直接跟他说了这不像是面试，更像是捞家常。 

	国人小哥最后一题follow up 有点卡住，不够时间没写完，不知道会不会给同胞面子。第二轮这个我就不知道他会怎么报上去了，不过感觉交了个朋友，还是不错的。

	链接: [https://instant.1point3acres.com/thread/160931](https://instant.1point3acres.com/thread/160931) 来源: 一亩三分地

13.	5月5号进行了Google的电话面试，是一个老印。题目简单到自己都无法相信，回报地里攒RP！

	Leetcode的Buy Stock的1和2……速秒之…… 就一轮，今天收到onsite通知，希望onsite有好运 

	链接: [https://instant.1point3acres.com/thread/178142](https://instant.1point3acres.com/thread/178142) 来源: 一亩三分地

14.	一个小时前的面经，就问了一个问题，回头想想很简单，不过答得不咋好。 :-(
	面试官小哥特别好，很轻松，前面瞎扯扯，让我先问问题，说后面写算法的时候会耽误点时间，所以先问问题，（满善解人意的）。

	废话不多说，上题：


		Give you an array of integers: A
	 
		Goal is to find three indexes (i,j,k) such that A[i] + A[j] == A[k]

		For Example:
		A = [ -5, 10, 1, 8, -2 ]
	
		10 + -2 == 8
	
		Good answer: i=1, j=4, k=3


	也不知道那时候脑子怎么抽了，一直在回想刷过的题目，搞复杂了，好可惜。

	希望将来面试的人好好审题。
	Good Luck Everyone!
	
	[http://www.1point3acres.com/bbs/thread-190302-1-1.html](http://www.1point3acres.com/bbs/thread-190302-1-1.html)

15.	美国小哥挺友好的，一直在肯定我说的话，题目不难，气氛还算不错，希望能顺利onsite。 

	第一题：给一个 sorted Integer array, 返回square后的array.主要是要考虑负数的情况，很多trick的地方比如全都是negative或者全都是positive 

	第二题： serialize a string array, then deserialize it. 祝大家猴年大吉！！加油加油！！ 

	链接: [https://instant.1point3acres.com/thread/157007](https://instant.1point3acres.com/thread/157007) 来源: 一亩三分地

16.	上周一（2/29/2016）的google电面，今天刚刚收到通过的通知电面通过，赶快过来发面经。 

	面我的是个白人小哥，人非常nice，只问了一个问题：moving window average for double value。楼主用了类似LRU的double linkedlist 和 sum 解的， 但是感觉这个应该不是最好的办法。 follow up 1） 如果input data stream非常大的话会不会有error 2） linkedlist会有会有经常delete／create node，有没有什么改进。 楼主从电面到收到通知之间用了一个星期，不知道是不是答得一般，committee意见有分歧。onsite求bless！ 
	

	不好意思，这个题没有说明白。 题目是有一个data stream， find the average of latest k numbers。 data 是 double parameter。这就类似于array 的moving window average 

	链接: [https://instant.1point3acres.com/thread/164302](https://instant.1point3acres.com/thread/164302) 来源: 一亩三分地

	这两个follow up是根据我的回答问的。 

	1. 我用了一个sum 来记录window值的总和， window 里每次加入／剔除一个树时就update一下sum，这样求average是O（1）的时间。但是如果data stream太大，每次求sum的error会累积，最后就不准确了。 我当时回答如果data stream太大就不用sum记录了，但是这样求average 就是O（k）。 现在想，其实可以每一定量数（e.g 1000）后refresh一下sum，这样还是可以keep O（1）in time 2） 

	2. 这个面试小哥是想说每次create list node 和delete list node不太好，可以保持list node 不变，每次改node value 就可以了。

	链接: [https://instant.1point3acres.com/thread/164302](https://instant.1point3acres.com/thread/164302) 来源: 一亩三分地

17.	分分钟刚面完。。赶紧写个面经赞一波人品。。
	一个不知道是不是国人的女生声音挺甜的accent不太像local，如果是还求国人妹子给过啊。。

	上来大概问了5分钟background然后直接上题，一个string decompression的题。。不知道是不是原题反正没见过。。题目如下.

		2[abc]3[a]c => abcabcaaac;

		2[ab3[d]]2[cc] => abdddabdddcc
     		
	一开始用了一个栈，写着写着嵌套的逻辑卡住了，最后用俩stack解决。。

	然后follow-up问的是不要输出string而是输出解压后的K-th character，主要也还是嵌套情况就从内到外把疙瘩解开以后再算。。然后我问俩问题就结束了。整体感觉妹子面试官人很nice 反应很快而且不是特别picky的那种。
	

	求好运~，求onsite
	
	[http://www.1point3acres.com/bbs/thread-189365-1-1.html](http://www.1point3acres.com/bbs/thread-189365-1-1.html)
	

18.	打过来电话后人家先让我自我介绍一下，并且给她讲一个project，完后就是google doc做题。

	我就只有一道题，是string decompression.
		

		example
		3[ab]2[abc]e ==> ababababcabce
		3[2[de]f]==>  dedefdedefdedef
		
	[http://www.1point3acres.com/bbs/thread-189938-1-1.html](http://www.1point3acres.com/bbs/thread-189938-1-1.html)

19.	上次电面之后，Recruiter给我打电话说是“好消息”，然后给我加了一轮电面。_(:з)∠)_ 

	今天下午做的加面，面试官是个烙印。_(:з)∠)_ 
	还是两个题： 

	1. 大整数加法，追问如何用并行计算优化。我说按8位切片，在每个片里转成整数做加法，然后等更低位传过来进位。不过听烙印的反应似乎不太好。_(:з)∠)_ 
	2. 一个整数数组，找sum最接近0的一对数。2Sum Closest Pair。 求onsite。_(:з)∠)_ 烙印全程不怎么说话，搞得我心里很虚。是福不是祸，是祸躲不过。_(:з)∠)_ 

	补充内容 (2016-3-19 13:54): 3/16 接到onsite通知

	链接: [https://instant.1point3acres.com/thread/165509](https://instant.1point3acres.com/thread/165509) 来源: 一亩三分地

	> 第一题 实际上你的并行策略并没起作用。如果有carry in 你的MSB得重新算。等于说整个MSB的计算都depend on LSB的计算的结果。 我觉得应该用个类似carry selection adder的方法。 suppose你分2个进程， 你的MSB要计算有carry in的， 也要计算没有carry in的 最后根据是有还是没有把预测错误的那个结果抛弃就行。 补充内容 (2016-3-15 13:43): suppose 你把整个数字断分成MSB和LSB。 你需要3＊个进程

	链接: [https://instant.1point3acres.com/thread/165509
](https://instant.1point3acres.com/thread/165509) 来源: 一亩三分地

	> 同意LS，因为高位在等低位的carry，如果真的有carry还得再算一遍，既然这样不如在等的过程中算一遍没有carry的和carry是1的，最后选择对的一个。

	链接: [https://instant.1point3acres.com/thread/165509](https://instant.1point3acres.com/thread/165509)
	来源: 一亩三分地


20.	新鲜出炉的GG电面。面试官应该是美国大叔，面试两道题。 

	第一题Random Walk，因为不经常写random函数，网上查花了点时间。查到了以后分分钟搞定。 

	第二题Skyline类似的问题，似乎不是用的最优解法但是面试官还算满意。 后面聊了一些工作环境以及他们组的工作内容。今天下午面试的，希望能过！ 

	链接: [https://instant.1point3acres.com/thread/154428](https://instant.1point3acres.com/thread/154428)
	来源: 一亩三分地

21.	动作比较晚，到寒假才开始找实习，结果Google差不多成了我的处女面，之前都没面试经验（我知道要先拿小公司试水，但小公司网投都没回音＝＝！），所以没抱太大希望，权当积累经验了。

	一面：国男-google
	
	上来先谈简历，做过的一些项目，大概扯了十分钟左右。
	
	然后做题：

		encoder and decoder

		Example: aaaabbbbcc5555->4xa4xbcc4x5->aaaabbbbcc5555

	我直接用naive方法做了，Two Pointers。这个方法的局限是只能做连续字母个数小于10的那种，比如21a，decoder就不知道是21a还是21个a。
	写程序后，让跑个test case，像debug一样一步步讲，途中问了一个pointer的问题。
	然后让分析算法复杂度。

	接着是一堆OOD的问题：
	什么是virtual function，什么时候用？
	什么时候用virtual deconstrutor ?
	这些都在CC150中有。

	
	最后还有时间，就让我提问，我就问了intern都干些什么，小公司还是大公司对个人发展更有帮助，还有就是对于interview有什么建议？.他最后说我除了边界条件没处理，其他都做的挺好的，他会给我good feedback。（这里真的很感谢这些前辈！！！给了我很大信心！）

	二面：白男

	上来直接问我做过的一个Android项目，问的挺细致的，让我讲扫描二维码登陆的具体实现原理。。。
	然后做题：

	
		A: 34567
		B: 45678
		C: 67345
		交换A中的数字位置，得到一个新的数C，使得C大于B。

	我的想法是，每次挑出最大的那个digit跟前面的swap，直到找大于B的，时间复杂度是O(n*n);corner case：当A、B的digits个数不等时，直接返回结果。

	
	这时候小哥给了hint说这本质上是一个sort问题，那么sort问题你ideal复杂度应该是多少呢？sort我就直接想到了quicksort，我就说找最大digit的那个过程可以用quick select，这样就是O(nlogn)了。然后让用test case跑一边quick select，让分析复杂度。

	Follow up: 存在很多这样的C，返回其中最小的那个。
	因为要把integer的digits一个个拿出来，弄成array，比较麻烦，就只让讲了下想法，然后用test case跑一边. 
	最小的就是离B最近的那个，所以我的想法是，从B开始找。因为B中可能存在A没有digits，所以先作差集A-B={3}，把B中的8替换成3，得到45673.
	然后从B的尾巴开始，保持一个递减的序列B[i - 1] > B[i]，直到碰到一个B[i - 1] < B[i]， 则B[i - 1]跟B[i...n]中第一个比B[i - 1]大的那个交换，得到45763，然后使B[i...n]递增，得到45736。
	感觉我是弄的太复杂，消耗了很多时间，最后小哥感觉不耐烦了，到了45分钟，就直接说了thanks for your time就挂了，我都还没缓过神了。

	总体来说，一面encoder、deconder之前见过，但没有去实现，OOD问题CC150中见过；二面的题目没见过，所以感觉很虚。。。
	Anyway，权当积累经验，攒RP了！

	[http://www.1point3acres.com/bbs/thread-166600-1-1.html](http://www.1point3acres.com/bbs/thread-166600-1-1.html)
	
22.	发个google 跪经， 一个三哥面的。感觉他人应该不错，有试着提示我，可是那英语好难理解呀。。。



	好了，上题：

	
		Find the total number of patterns of the Android lock screen. The number of key used has to be at least 4, and max 9.
		Example:
		If the keyboard is
	
		| 1 | 2 | 3 |
		| 4 | 5 | 6 |
		| 7 | 8 | 9 |
	
		use 5 keys:
		
		OAB
		OOC
		OED
		which means 2->3->6->9->8
		
		OAB
		OCD
		OOE
		which means 2->3->5->6->9

		Same thing goes with 4, 6, 7, 8, 9 keys. Count the total possible pattern. The order of keys used matters.

	看到这个题一点想法都没有。。。

	[http://www.1point3acres.com/bbs/thread-186774-1-1.html](http://www.1point3acres.com/bbs/thread-186774-1-1.html)

23. 两道题

		1. maxDepth of a tree:recursion
	
		2. Design a interface for find the running mode in a stream of values: 随时返回most frequent word
	
	先写函数
	
		get();
		add(String input); 

	再问怎么实现这个两个函数：先说了Heap, get()--O(1),add()--O(n) 

	然后她说优化add(),我说用HashMap+ counter，这样get()-->O(1),add()--->O(1)   然后开始写代码。。   

	写完了问你觉得这个代码有什么问题，我说multi-threading可能有错，一个在get(), 一个在add(),她说 是的，如果这是single thread

	 - 我说可能space太大了,因为有些hot词频会被频繁输入，但是冷门的词语也会一直保存，她说对的 怎么优化？

	 - 我说用Tritree，减少HashMap key的存放空间，她说这个key不一定是string，可能是object，

	 - 我说group input searching，比如 google， google.inc 表示的可能是一样的意思，只用一个key保存，这样插入时判断similarity，小于一个threshold就认定match，把当前位置+1；
   

	 - 我说用cache。大概说了说，时间就到了，她说you are in the right track，但是我们没时间了。

	 
	[http://www.1point3acres.com/bbs/thread-188200-1-1.html](http://www.1point3acres.com/bbs/thread-188200-1-1.html)


24.	一上来就直接贴题目做。面试官是个口音不重的印度小哥，不过给我的感觉他还比较nice。 

	让设计一个机器人，实现前进，向右转以及输出当前位置的功能（面经题，之前是乌龟来着），一开始在原点坐标，不能去负的坐标，去的话报错。 

	follow1：输入指令，如 FFRRF3R，F就是前进，R就是向右转，2R就是RRR。输出这个指令之后所处的位置。

	follow2：在指令里面会出现2（FFR）这种情况，就是FFRFFR。 就问了这个就没了，在写follow2的时候感觉和小哥的作法有出入，他让我怎么怎么写，但是我不太理解，改来改去消耗了些时间。最后还是按着我的代码写完了……

	40分钟结束问问题。 在google doc上面，感觉撤销有点诡异。不知道是不是同步的问题，当时想回到之前的代码，怎么也回不去了。 感觉自己写的有点慢，题目挺简单的，但也没让面试官很满意。感觉直接给onsite希望不大了……诶，不过还是求个人品吧~ 

	链接: [https://instant.1point3acres.com/thread/176255](https://instant.1point3acres.com/thread/176255)
	来源: 一亩三分地

	
25.	面的是某个multimedia组，打电话的听上去是一个白人小哥，只是介绍了自己的名字便开始出题。 

	专业题（专业码农同学请忽略）： 

	1. 说说perceptual audio coding的基本要素？ 

	2. 如果在audio coding中用fixed frame size会有什么问题？应该如何改进？ 

	coding题： 

	1. Given (x, y, r) of the circle (x, y is the center of circle, r is the radius), return whether 2 circles have intersection 

	2. 求BCD编码 + 1的值，例如：35的BCD编码是0011 | 0101，给一个BCD的值，输出这个值 + 1的BCD，比如input为0011 | 0101，输出则为0011 | 0110 

	3. filter out the given char. 如：给“abcdefg”，需要filter掉的是“a“，则给出的char *应该是“bcdefg”，要做到in place 

	之前HR跟我说找SWE的人来面试，导致我专业题都没复习=，=，coding题巨简单，可是专业题是乱答的，哎。。 

	今天HR给我打电话说跪了，搞得特别郁闷，这么简单的题都能跪，我这水平是有多烂啊！总结了一下可能有如下原因吧：

	1. 电话声音不清楚，导致全程跟小哥都没什么交流。就是他出题，我答题，聊的不high 

	2. 每次写完一道题，我都心想：这么简单的code不用多加解释了吧，就没手动跑test case，简单解释了下code算完，可能不够专业 

	3. 本来2月份就联系HR了，因为coding水平有限，拖到了3月底，可能那个组已经有很好的candidate了 

	4. 背景确实不match，没有做audio coding的经验，也是一个短板 从今天开始关小黑屋6个月，anyway，move on了，继续修炼吧。 

	链接: [https://instant.1point3acres.com/thread/171473](https://instant.1point3acres.com/thread/171473)
	来源: 一亩三分地

	
26.	新鲜热辣的谷歌面筋。估计炮灰了。答得很放，面试官也都心不在焉。但是是时候回馈广大同胞了。 

	设计查询系统(最大值，最小值，最新加入值) 

		class System { 

			int getMax(); 

			int getMin(); 

			int getRecent(); 

			void add(long time, int price);

			void update(long time, int price); 

			void remove(long time); 

		} 

	例子如下

		add(1,4) max:4, min:4, recent:4

		add(4,7) max:7, min:4, recent:7 

		add(2,5) max:7, min:4, recent:7

		etc.. 

	能帮大家的就到这里了。祝未来好运:)

	链接: [https://instant.1point3acres.com/thread/166460](https://instant.1point3acres.com/thread/166460)
	来源: 一亩三分地
	
26.	刷题刷累了，上来攒人品！
	搞了两次电面，可能是第一次面的不好又给了第二次机会。还好后来过了，明天onsite。。。Finger crossed！

	第一次电面：假设除了用1和0表示数字的binary方式，还可以用2来表示，给一个数字，求有多少种表达方式。
        
        例子：
        4 = 100, 20, 12 所以答案是3。 
        8 = 1000, 200, 120, 112 所以答案是4。这题想了半天没想出来，后来给了提示用dp写出来了。

	第二次电面：两题都是lc原题，lc298 (Longest consecutive sequence in BT) 和lc128 (longest consecutive sequence in array)。各位自己去看解法吧！

	祝大家找工作顺利！！！

	[http://www.1point3acres.com/bbs/thread-192677-1-1.html](http://www.1point3acres.com/bbs/thread-192677-1-1.html)

27. recruitor email找到我。问我有没有兴趣面谷歌。由于Lz自己确实在准备跳槽。只是没准备好。于是想面一个试试。电话接通了没有废话，直接做题。

   给一个tree，每一个treeNode多2个指针pre next但是是空的。要求按inorder的顺序把指针连起来。
   Lz用recursion。写的不好。
   
   followup是怎么实现insert方法。还问了时间复杂度和空间复杂度。
   
   第一次面试太紧张，已跪。
   
   祝大家早日找到工作。
   
   [http://www.1point3acres.com/bbs/thread-192582-1-1.html](http://www.1point3acres.com/bbs/thread-192582-1-1.html)

27.	面试官一美国小哥，简单闲聊后甩题：


	给一个 array of words，和favorite letters， 让重新排序array，使得按照favorite letters的priority 排列。 没有包含 favorite letters 的 words 则继续按照原本字母表排序

	举个栗子：

		array：['animal','duck','snake','zebra','horse','mouse']
		favorite letter:'zh'
		output--->['zebra','horse','animal','duck','mouse','snake']
		
		array：['aab','baa','caa','aaa','aaaa']
		favorite letter:'ab'
		output--->['aaa','aaaa','aab','baa','caa']

	算是半个水题。用随便一种sorting自己定义一个 comparator就ok。也可以用类似radix sort 来逐层比较每一个位置的letter。但是本人脑抽，一紧张把quicksort的pivot index搞错被interviewer发现了。估计难逃一死了。

	发个贴给大家看一看本人的死相多难看之余，希望大家别犯同样的傻叉错误。。	

	补充内容 (2016-2-24 07:39):
	

	刚接到电话，居然过了。。美国小哥人好啊，放生积德啊！！继续准备onsite去了。大家也都加油好运！

	
	[http://www.1point3acres.com/bbs/thread-173016-1-1.html](http://www.1point3acres.com/bbs/thread-173016-1-1.html)

28. Leetcode 原题， missing range 。因为没有做过 电面也很紧张，所以45分钟只有时间做一道题。

	所以说 leetcode 收费题目还是应该去花钱做一做的。
	
	[http://www.1point3acres.com/bbs/thread-190925-1-1.html](http://www.1point3acres.com/bbs/thread-190925-1-1.html)

28.	上周五面的，上来直接做题~

	判断一个数是不是rotation symmetric，就是把一个数旋转180度，是不是还是原来的那个数，例如“619”，旋转180度还是“619”；followup：给一个数n，输出所有小于n的rotation symmetric number。 

	链接: [https://instant.1point3acres.com/thread/176815](https://instant.1point3acres.com/thread/176815)
	来源: 一亩三分地

	
29.	面试官也不知道是个东欧人还是印度人，叫做桑杰，在map组工作了五年。一上来先是介绍最有意思的proj，基本没有问问题。接下来接下来就是在gg doc上做题。

	我的gg doc上还存着，直接贴上来给大家 

	补充内容 (2016-4-3 12:24): 

	题1. A string consists of ‘0’, ‘1’ and ‘?’. The question mark can be either ‘0’ or ‘1’. Find all possible combinations for a string. 01?0 –>0100, 0110 
	
	补充内容 (2016-4-3 12:26): 
	
	题2 Suppose we have a method “getLongestSubstring(String s, int m)” which finds the longest substring with exactly M distinct characters. Examples: “ABACAAAB” M=2 -> “ACAAA” 
	
	补充内容 (2016-4-3 12:26): 
	
	There are now new requirements for getLongestSubstring! The string doesn't fit into memory. Instead you get an object of type BigString: 
	
		interface BigString { 
			public boolean hasNextChar(); 
			public char getNextChar(); 
		} 
	
	补充内容 (2016-4-3 12:28): onsite求人品TAT….虽然拿到onsite就已经是赚了….

	链接: [https://instant.1point3acres.com/thread/171729](https://instant.1point3acres.com/thread/171729)
	来源: 一亩三分地

30. 一位阿三PHD面的，问了简单的背景问题和两个技术问题。看完问题之后我就知道和Google今年缘尽于此了。

		Q) Write a program to count the total number of pages reachable from a website.
		For example, given "nytimes.com", count the number of pages reachable from there.
		You can assume you are given a function to fetch the page and extract the inner links, e.g.:
		List<String> fetchPageAndExtractUrls(String url);

		Q) Given a tiny computer with a 1 MHz CPU and 1 KiB of RAM memory;
		no input;
		only output is an LED light that says “I am done”.
		(1 MHz == 1 million instructions per second)
		I load an arbitrary unknown program onto this computer.
		How long do we have to wait in wall-clock time before we can prove the program has an infinite loop?
		
	[http://www.1point3acres.com/bbs/thread-134847-1-1.html](http://www.1point3acres.com/bbs/thread-134847-1-1.html)
	
30.	刚刚结束的Google电面，在google呆了8年的貌似国人大哥。 

	1. 判断一个树是不是另一个的subTree. 

	2. shortest palindrome. 求个onsite 

	链接: [https://instant.1point3acres.com/thread/176963](https://instant.1point3acres.com/thread/176963)
	来源: 一亩三分地

31.	这周二面的Google，太紧张了 脑袋木木的开始聊了聊简历. 
	然后问了很多关于C++的知识，继承多态虚函数之类的，简单提了提虚函数表以及一些hash table的实现

	coding题目是这样的，一个字典，里面很多单词，例如

	
		google, leg, about, lemma, apple, time

	找这样的pair <A, B>，有两个条件, (1) A单词的后两个字母和B单词的前两个字母一样 （2）A单词的第一个字母和B单词的最后一个字母一样，例如<google, leg>就是一个合格的pair，<apple, lemma>也是一个合格的pair， <about, time>不可以，然后求这样的pair的最长长度，<google, leg>的长度=6+3


	我开始没听见他说这个dict是sorted，太紧张了唉。


	我只好用了个很sb的方法，用每个单词的最后两个字母建了一个map，然后再扫一遍寻找所有的pair
分析了复杂度，要分析的很准确， 

	后来他提醒了一下是sorted，有吭哧写了个带binary search的版本，BinSearch的函数没来得及写

	后来又问could we do better 已经没有时间了， 唉 感觉挺简单一题，写的太慢。 

	不知道有没有其他很简洁的办法。。LZ弱的跟猪一样

	然后三天之后HR打电话来，说did well，被proceed到Youtube了。	求问有没有类似经历的小伙伴，Youtube和Google貌似在不同的location，难度有什么不一样么

	Anyway，已经做好move on的准备了。。总比直接挂了好。。


32.	给定一个棵树，树的节点是一个的值是一对pair， 树可能有很多children，然后要做的就是给定一个pair<x, y>查看是不是能在一个树的同一高度上，找到这两个值，并且x只能在第一个位置，y只能在第二个位置。

	第一问：写算法，楼主写了BFS的算法，也说DFS可以实现

	
	follow up: time and space complexity.

	
	follow up: if I want to get space O(logn)的算法，怎么做。 楼主说如果树不是balanced话，dfs也要O(n), 然后面试官说假定树是balanced，就是说高度为O(logn), 这里纠结了一小会，因为没有确定面试官说的话，以为要求O(1)的解法，并且不能用dfs去做。 后来make sure了一下需求，就说dfs很可以解决。
	

	follow up: 找树的规律，每对节点都是一个interval，并且每个子节点将父亲节点的interval进行划分 和interval tree一样。

	follow up: 改一开始的code，是不是提高效率，加上interval的剪枝，写了代码。

	PS: 快10天了，hr一直没有消息。。。是不是挂了－－楼主的oa也是10多天才有消息，中间一周的时候催了一下hr，现在急需发邮件问的话，会不会太aggressive了。

	[http://www.1point3acres.com/bbs/thread-179798-1-1.html](http://www.1point3acres.com/bbs/thread-179798-1-1.html)

33.	是个印度小哥，打电话的时间就晚了五分钟，跟我聊了十分钟，最后还提前结束了，做题的时间就很少了。

	最后只做了一道题：自己实现一个hashtable的insert，delete，search，getRandom，全部都要O（1）


	时间紧迫，而且一开始没明白他的意思，边问边写~就写了这一道，小哥全程比较冷淡，但是还是有回答我的问题的！
	

	也不多想了，应该是要挂了~. 

	[http://www.1point3acres.com/bbs/thread-178900-1-1.html](http://www.1point3acres.com/bbs/thread-178900-1-1.html)

34.	發一下之前一月底Google的電面，一開始打來就是簡單的自我介紹聊聊project之後就開始給題了。

	題目是： 

		Given a set S of 10^6 doubles. Find a number X so that the [X, X+1) half-open real interval contains as many elements of S as possible.

		For example, given this subset: 2.7, 0.23, 8.32, 9.65, -6.55, 1.55, 1.98, 7.11, 0.49, 2.75, 2.95, -96.023, 0.14, 8.60.

		The value X desired is 1.98 because there are 4 values in the range 1.98 to 2.97999 (1.98, 2.7, 2.75, 2.95) 

	這題我的解法是先sort過一遍之後再使用two pointers找，那時面完就覺得沒有說得很順，後來結果也是掛了～～ 希望可以幫我加點分！！

	链接: [https://instant.1point3acres.com/thread/162322](https://instant.1point3acres.com/thread/162322)
	来源: 一亩三分地

	
35.	星期一电话面试。是一个印度哥哥。之前觉得印度哥哥没什么，因为学校印度人很多，工作地方也是印度人，口音不是那么难以理解啊。但是这次，我晕。不知道是我理解有问题还是怎么着。anyway，上题。

	给一个integer array，让你求比array  (where i is from 0 to array.length() - 1) 大的maximum number of element
	i.e 就是求每个integer右边比它大的个数，求最大值。

	
		e.g. 
		A = [2 3 0 1 5 7 4]
		     4 3 4 3 1 0 0   
		answer is 4

	不知道是楼主理解能力差还是他表达不好，弄明白题意就整了好长时间。写码也磕磕绊绊。

	
	印度哥哥提示Divide and conquer... 楼主做的不好，已经挂了。

	
	和这个题很类似，大家可以看看。祝你们好运！求大米！

	补充内容 (2016-3-17 00:21):

	
	老印可能想要的是这个解法。merge sort 大家可以去看看。
	

	https://leetcode.com/discuss/73256/mergesort-solution
	

	祝你们好运

	
	[http://www.1point3acres.com/bbs/thread-178983-1-1.html](http://www.1point3acres.com/bbs/thread-178983-1-1.html)

36.	电面一面的面经在这里. 

	[http://www.1point3acres.com/bbs/thread-183067-1-1.html](http://www.1point3acres.com/bbs/thread-183067-1-1.html)

	
	这次是第二面，第一面题好难LZ没答好，二面题目就超简单我也是被这个差距给惊狗带。不求offer，求个onsite体验一把啊哈哈哈

	大概就是取一个array里的任意n个不同的值,得到一个随机的组合，不能取同一个index的数，但是可以取数值相同的不同index的数

		给一个array：[5,1,3,3],
		再给一个数字n：2，
		求这个array里的任意num个数：比如可以得到[5,1] or [5,3] or [1,3] or [3,3] ，但是不能得到[5,5]

		再比如[5,1,3,3], 1 ===> [5] or [1] or [3]

	LZ就是先判断如果n>array.length或者n<=0或者array是空,返回一个空array，否则就是一个loop，每一次生成一个random的index数字，还用了一个hashset来存之前访问过的index，如果生成的random index之前已经get了，就再继续生成一个random index。
	

	loop n次，每次取到的值放进新的结果array里。


	然后说了说也可以用一个boolean array存每个值有没有已经取到。。

	写完后再写了写unit test什么的，还有问道怎么检测得到的结果比如[5,1]确实是[5,1,3,3]里的.. 

	问问大家有没有更优的方法啊
	

	[http://www.1point3acres.com/bbs/thread-188731-1-1.html](http://www.1point3acres.com/bbs/thread-188731-1-1.html)

37.	1个小时前结束的电面，开始时问了两次他的名字，仍然没有听清，只能作罢。

	就问了句：你是PhD是吧，我说是ECE的PhD，然后就直接开始coding

	题目是：

	
	给你两个文件f1和f2，f1是10M的量级，f2是10G的量级。f1的每一行有三个东西：str1, str2, ratio，ratio代表str1和str2的比值，示例：

	
		1.	A, B, 0.5         // 解释：A / B = 0.5
		2.	A, E, 2.3         // 解释：A / E = 2.3
		3.	C, E, 1.5         // 解释：C / E = 1.5. From 1point 3acres bbs
		4.	C, D, 1.0         // 解释：C / D = 1.0
		5.	...

		
	f2的每一行只存了str1, str2，示例：

	
		1.	C, B   
		2.	A, D
		3.	...

		
	需要返回一个新的文件叫f3，f3是在f2的基础上更新，并且和f1的格式一样，即你需要算出f2中每一行两个string的ratio，比如上面的例子的话，就是返回下面这样：

	
		1.	C, B, 0.33     // 即：C / B = C/E * E/A * A/B = 1.5*1/2.3*0.5 = 0.33
		2.	A, D, 1.53     // 即：A / D = A/E * E/C * C/D = 2.3*1/1.5*1 = 1.53

	电面具体结果：

	
	他出完题目后，问我有什么想法，我说用`Map<Key1, Map<Key2, Ratio>>`来存遍历f1后的关系。然后他想了会，给出了一个反例，说你后来求ratio的时候会进入死循环，就好比 A -> B -> C -> A这样。我说这种情况下可以backtrack。他好像有些听不下去了，说你有没有想到什么data structure。我才反应过来是f1遍历后实际形成了一个类似于weighted graph，每个node存他的邻居和他与邻居间的ratio。

	
	然后他问：那怎么求两个node之间的ratio呢？我说类似于shortest path。然后他说用什么algorithm呢？我说用DFS，BFS应该都可以。然后告诉他BFS的思路：从sourceNode开始每层每层地走，更新对每个邻居的ratio，直到抵达targetNode。然后他说你可以写代码了。
	
	然后就是最悲剧的事情了：先想着怎么定义这个Graph的Node就想了半天，后来才想到每个Node有一个name和adj的Map，adj的Map存的是邻居Node -> ratio的映射

	然后思路和他说了：
	

	 - 先遍历f1，创建这个graph // 这个方法思路说了下，代码写完了，但肯定有错。。。

	
	 - 然后遍历f2，对每一行的两个node（一个是sourceNode，另一个是targetNode）进行一个bfs找到ratio，加到f3里面。但这里写代码完全卡壳。直到时间到了也没有理顺。。。

	目测肯定是挂了，但想问下，这种情况怎么样向HR要求加面会增加被电面的可能性呢？

	真诚感各位！

	补充内容 (2016-3-29 08:15):

	更准确地说不是weighted graph，只不过node的adj里面除了存node外，还要存一个ratio而以，所以为什么BFS就行，而不需要用bellman ford / dijkstra 之类的东西

	补充内容 (2016-4-2 04:26):	

	今天HR告诉我加面，可能面试官没有fail我

	
38.	刚刚面完：本人已经工作了一年了，公司很多印度同事，跟他们交流完全没什么问题，但是今天这个印度哥哥真心口音重，而且开免提有回声我跟他说能不能关免提他说他没带耳机。。。然后我就听了45分钟自己的回声。。。

	这位小哥一来先介绍自己的组，然后完全没问我任何东西直接上题：

	第一题：给一个array,找出最长的连续片段   比如：[5,2,3,4,5,8,9]   就是2，3，4，5，返回4
	

	我觉得这道题很眼熟，但是忘了最优解了，所以最开始写了一个看似两层循环但是time O(n)，space O(n)的。但是小哥觉得还可以优化，所以开始提示我了，然后我在自己代码的基础上改了改最后改成了time:O(n),space:O(1)最优解

	第二题：还是找最长连续片段，但是是在树里面。因为第一天调到最优解就已经花了35分钟了，第二题讲了一下思路，准备用pre-order traver加stack来做，小哥说这个解不是最优但是勉强还行。就没有写代码了，写了一下步骤就结束了

	祝愿能来个onsite吧。。。Amazon和Bloomberg onsite全跪了。。。纽约没剩下几家可以面的了。。。

	要是还有哪位看到这个帖子的仁兄在纽约工作，公司对一年工作经验的base能上11W的同志帮忙内推一下吧。。。本人的公司工资实在是有点不好谈。。。但是又不想离开纽约。。。

	补充内容 (2016-4-1 23:56):

	第一题“不是”leetcode上面的longest consecutive sequence，同志们不要搞混了，要是那道题我也不敢大言不惭说是最优解了。。。请看清楚例子。。。后一个元素必须是前一个元素+1。。

	
	[http://www.1point3acres.com/bbs/thread-183713-1-1.html](http://www.1point3acres.com/bbs/thread-183713-1-1.html)

39.	第二轮电面跪经，面试官迟到7-8分钟。 说是手机找不到了。 大概聊了一下以前做的project，开始做题。

	题目是给你一个board，里面存储user的信息，user有id和socre。
	

	board有adduser(id, score)(返回add进去的user当前的rank), findByRank(k) (这个返回id)。
	

	Add如果本身已经有id在board中，需要对这个id的score进行update。

	开始想的是用map加binary search中，中途脑子短路，写到一半发现似乎做不出来了。。。。(面完之后想想，这个方法应该是做的出来的。)

	
	面试官说应该要用binary search tree做，听到这里 基本就知道gg了。
	

	然后就是悲剧的开始，只会做binary search tree的添加点的操作，update和delete 操作基本忘干净了，不记得具体的步骤了。


	写代码的时候 struggle在了 delete 操作上，还有10分钟左右面试官说不用写了，就这样了。最后就是问一些问题了。

	
	还是基本功不够扎实，发个面经，攒点rp。。。顺便求内推！！！！！

	
	[http://www.1point3acres.com/bbs/thread-183346-1-1.html](http://www.1point3acres.com/bbs/thread-183346-1-1.html)


40.	今天下午二面，西班牙哥们儿（入职一年），两题：

	1. 找到一个数组中递增子串的最长序列的长度。 就像［2，1，3，4，5］递增子串就是［3，4，5］
	2. 找到一个二叉树中递增的sub tree的某分支最长序列长度。 
	

	例如

			   0
			  / \
			 1   3
			/ \   \
		   2   8   4
					\		   
					 5

	这样返回的就是3， 因为有3， 4， 5。
	这两题算简单了啊。

	上次面试的题目是给你一个collection 要求对collection里面的元素进行添加（object）， 删除（object）， 随机取（object）这三个操作，要求常数时间复杂度

	求加米～～～
	

	[http://www.1point3acres.com/bbs/thread-178080-1-1.html](http://www.1point3acres.com/bbs/thread-178080-1-1.html)

41.	刚刚电话面试结束，一直看帖子，没怎么发过，来回馈下地里的朋友。


	我的面试是上午十点的，小哥准时打来电话。上来小哥简单来了个自我介绍，是做chrome security做了五年的，吧啦吧啦。废话不多讲，上题。

	第一题：

		Print elements of a tree in level order. E.g., given the tree:

					A
				   / \
				  B   C
				 /   / \
				D   E   F
			   /
			  G
		The program should print out:
		A
		BC
		DEF
		G
					
	没错，你没有看错，就是level order travers binary tree, 没有任何的变形，leetcode的easy的原题。上来跟小哥讲了下思路，用queue实现，然后就噼啪代码敲完了，小哥就问了一下queue.poll()是什么作用（他长时间没有用java编程了）。之后我就缕着代码给他讲了一遍，讨论了一下corner case，本身这个基本上也没啥corner case， 然后小哥说，比我想象中的完成的快好多。

	第二题：

		Football:
		{2, 3, 6, 7, 8}
		9 = { 7 + 2, 6 + 3, 3 + 3 + 3, ... }
		don’t need both 6+3 and 3+6


	其实就是leetcode combination sum的原题，给你一个数组，一个target，求所有的组合方式。 上来先和小哥讨论了下输入项的可能性，然后噼啪一顿代码又出来了。小哥给了个case，然后我就把代码的执行过程给写了出来，小哥还比较满意。然后就问我可能出现的一些corner case，然后我就讲可能空数组啊，target value可能是0啊，可能有负数啊，等等。

	关于这个几个corener case的输出，跟小哥探讨了一番，关于返回{}还是{{}}讨论了一下，结果就是根据实际的要求来做，小哥表示认可。讨论到负数的可能性，发现代码会进入死循环，果断表示不能允许duplicate的存在，小哥也恩恩表示赞同了。


	最后一题：

		Input:

		BB
		BBE
		BAD
		BACE
		BED
		DAD
		ABBC
		ABBA

		(Known lexicographically sorted, under unknown alphabet order.)

		Output: B<D<C<A<E.


	其实就是给你一个String的数组，这个数组不是按照字母的顺序来排的，让你找出他们的排序规则。 因为时间没有多少，所以让我讲下思路，不需要编码。我就吧啦吧啦讲遍历第一个字符，找出最开始的第一个字符的顺序（我说这应该不是最优解，但是现在思路就是这样的）。然后周而复始的继续往后得出BDA   BAE  DC  CA，最后小哥讲没时间了，我觉得你是在正确的track上，然后就让我提问题了，我就问了俩问题，what's the best part wokring in Google / what's the biggest challenge in you daily work，小哥吧啦吧啦讲了一下，我就cool cool的，然后就愉快的say goodbye了。


	虽然现在依然水的不行，但是还是求有个好结果咯，也祝各位拿到好offer，顺利抽中身份。
	

	[http://www.1point3acres.com/bbs/thread-177259-1-1.html](http://www.1point3acres.com/bbs/thread-177259-1-1.html)

42.	Google 电面是和fremont office的印度小哥， 做了一道题目15分钟，然后聊了30分钟，过了。


	题目是， 一个string, 有空格，有引号，sparse string, 两个引号中间的部分的空格不处理, 引号外面的空格将前后划成两个String。

	
	做法就是traverse一遍就搞定了，细节处理一下。

	
	然后问了test case, 时间复杂度空间复杂度。

	[http://www.1point3acres.com/bbs/thread-188226-1-1.html](http://www.1point3acres.com/bbs/thread-188226-1-1.html)

43.	给一个sorted int array 定义popular item的frequency/occurerence 大于N/4
	

	求item 值最小的frequency.

	写了个O(N)
	
	说不行。。（第一次没看清题 写了个return popular item value的。。。。）
	
	要更快(<O(N))

	想了半天没想出来，，，，然后把frequency的threshold改成N/2
	
	提出了把array切成2份看
	
	然后就卡这了
	期间给了我个例子要我找pattern 
	整个面试45分钟就一道题，可能是没解出来就不让进下一题

	面试结束后 想到了。。。。用binary search 在切好的两个array里找到canditate 的index 两个index减一下得出frequency，应该是个O(lgN)的解法。
	

	基本走远了。。。但还是祈祷给我个机会。
	

	[http://www.1point3acres.com/bbs/thread-181863-1-1.html](http://www.1point3acres.com/bbs/thread-181863-1-1.html)

44.	Range maximum query

	一开始扯了20分钟楼主做过得project,问了一下最challenging的part.

	
	然后直接 就是range maximum query, 给一个array, 求[start,end]中的最大。

	
	反正他就一直要求优化，写了三种方法（从最简单的开始）之后，楼主无能为力了，然后就谈谈time和space。
	我看wiki有O(1)time, O(n)space的，但是表示不懂。

	
	[http://www.1point3acres.com/bbs/thread-177692-1-1.html](http://www.1point3acres.com/bbs/thread-177692-1-1.html)

45.	上来聊了下debug中遇到的挑战和怎么解决的， 聊了10min。

	第一题 atoi 只考虑正数，写了一些test case，没啥问题。

	
	第二题 没见过，有一个4-way stop的路口，4条lane， 给两个function getNextCar（）， arriveCar（Car car， Lane lane），要求实现这两个方法。

	
	就是生活中一个intersection有4个stop sign，然后看看哪条lane的车应该先走。理解完题只剩10min，写了一会儿发现好烦，最后没时间了，说了下思路，还有好多核心code没写。。
	估计挂了。。。

	
	[http://www.1point3acres.com/bbs/thread-188010-1-1.html](http://www.1point3acres.com/bbs/thread-188010-1-1.html)

46.	LZ选的Seattle position，准时收到电话，听声音像是个很nice的白人小哥。

	开场让我自我介绍，聊了个project，然后出题。

	题目：

	
		input 是一个游戏的后台log (可以自己定义结构)：
		（1） update log，每条记录是 (time, player, role)，比如 (2016 March 11 13:10 UTC, 'mark', 'knight')
		（2） play log，没条记录是（time，player），比如 (2016 March 12 12:10 UTC, 'mark')

		output是每个role出现的次数。

	面试过程：

	
	问清楚input&output，说input结构可以自己定义。我的回答是把所有update建一个 per-user map，update list按序存成数组。每次读play log，按player找到update list，然后binary search。时间NlogL， N是play log长度，L是per-user update list 的最大长度。
	

	快写完的时候，小哥说可以先不写binary search 容易错，我们先linear scan。。。小哥一直很nice应该不是BS我。。。写完给我提了一个小bug然后问了下test case。

	总结：

	
	自我介绍加聊project大概六七分钟的样子，clear question和说解法也是六七分钟，十五分钟边说边写完了之后，说完test cases就只有七八分钟了，小哥说差不多还是留几分钟那我们就进入提问环节吧。
	

	感觉写的速度一般，不快不慢，说话不够简洁浪费了点时间，都需要多练啊。。。求过！

	补充内容 (2016-4-10 00:05):

	补充一下，output是要用play log去找每个role的 登陆次数

	
	[http://www.1point3acres.com/bbs/thread-179863-1-1.html](http://www.1point3acres.com/bbs/thread-179863-1-1.html)

47.	印度大哥，不太友善，上来聊了两句就开始做题。


	不贴题目，然后带着印度口音口述了题目，我没怎么听懂，然后问他有没有example给我一个，如下：

		大意是有一个办公室，in代表进入办公室的时间，out表示出办公室的时间， 每一个event都有in和out两个参数
		A in:5 out:10 
		C in:12 out: 15
		D in: 25 out:30
		B in:7 out:13

		求最长的办公室被连续占用的区间
		上面连续占用为 [5, 15], [25, 30]。因为要求最长的，所以返回[5,15]。

	我的方法是按照 in 的时间进行排序，然后就维护最长区间的两个变量就行了。复杂度 nlogn

	
	但是印度大哥一定要我优化，我实在想不出怎么优化复杂度了，印度大哥一点提示也没有然后也不说话，我无奈之下随便扯了一点数据比较大什么的。

	
	[http://www.1point3acres.com/bbs/thread-164790-1-1.html](http://www.1point3acres.com/bbs/thread-164790-1-1.html)

48.	先聊了一下research然后就开始做题


	第一题是random generator的题，比如给100*100的matrix，初始为全零，让随机把其中p（比如百分之六十）的值设为1

	
	第二题是tree level order traversal，按层输出，只用打印出来就可以了

	
	然后就让我问问题了


	求人品啊希望大家都好运

	
	[http://www.1point3acres.com/bbs/thread-188230-1-1.html](http://www.1point3acres.com/bbs/thread-188230-1-1.html)

49.	今天面试非常简单


	给你一个数字 拆成个位数相乘 一直重复 知道那个数不能再拆

	
	http://www.1point3acres.com/bbs/thread-185885-1-1.html

50.	刚面完一波google，速度来发帖赞人品。


	面试官是老美，Android组的，声音好沙哑，刚开始一直听不清他说啥。讲道理应该先聊聊简历寒暄寒暄，问候完他直接上题。题并不难，只不过我刚开始有点懵逼，有点犯傻，没进入状态。

	1. Binary tree lowest common ancester. lowest common ancester他是定义为longest path from a leaf to the root，貌似和leetcode那个题不太一样。找最长路径上的那个叶子节点。

	
		我一上来用的方法写到一半觉得写不下去。果断说我换个更直白的方法，把所有path都记录下来，然后返回最长path的最后一个node。写的过程中，他说我的第一个方法对着呢为啥不写完呢，我说先把这个写完再写那个。第一个方法就是不断更新path的长度，然后更新相对应的那个node。最后两种方法都写了，他说perfect，我们来下一个。

	2. 你有 10^12个short integer，然后找出largest top100。最直白的方法就是用heap，分分钟完成。然后我想当然的说可以用hashmap，因为short integer 大概范围是-32000~32000，差不多64000个数，然后怎么弄key-value我不太清楚。他说heap is perfect enough，hashmap这个key-value pair不太好搞 - -。第二题就这么结束了。

	感觉老美面试还是稳，题比三哥简单。但是自己刚开始有点懵逼，表现的不太好，希望不要受到影响，求Onsite

	[http://www.1point3acres.com/bbs/thread-187850-1-1.html](http://www.1point3acres.com/bbs/thread-187850-1-1.html)

51.	本人小白，这次电面对本人来说挺难的，很紧张。对面是个白人小哥，感觉是第一次当面试官，听得出他也挺紧张。我是一路跟着小哥的提示走的，最后写了伪代码，还不一定对。目测已跪。

		给出一个 list of int, the target, 输出这个 list 中所用的数能否通过4则运算 得到 target。
		boolean EvaluatesTo(list numbers, int target)
		[2 3 6 9] -> 75
		(2+3)*(6+9) = 75 return true
		[2 3 6 9] －> 11 return false

	顺便求米，谢谢

	[http://www.1point3acres.com/bbs/thread-186172-1-1.html](http://www.1point3acres.com/bbs/thread-186172-1-1.html)

52.	今天google 小哥一上来直接问题目 用google doc写的

	一锅汤，有胡萝卜和汤，各50份。然后有一堆人会来接汤，有四种人
	a. 接一份里面有75%的胡萝卜，25%的汤
	b. 接一份里面有50%的胡萝卜，50%的汤
	c. 接一份里面有25%的胡萝卜，75%的汤
	d. 接一份里面有0%的胡萝卜，100%的汤

	请问 当没有汤的时候，还剩下胡萝卜的这种情况的概率。

	我一开始很紧张，想不到，一脸懵。然后我就先写recursion的，写出base step和recursive step。然后他说很好，没有问题，然后他就问complexity。我说因为每一种可能都要算所以是N permutation。然后他让我在doc上写。我一开始还不懂什么意思，然后我写了O（N！）。他说对，我就是想看你会不会写permutation。0_0 接着就问能不能improve。我这个时候已经想到是dp了，于是就说可以，用一个2dmatrix。最后complexity是O(胡萝卜+汤)。他很满意。然后剩下15分钟。扯问题。最后byebye。求过！ 

	新人求大米!!!! 

	求好运！！！ 

	
	[http://www.1point3acres.com/bbs/thread-183037-1-1.html](http://www.1point3acres.com/bbs/thread-183037-1-1.html)

53.	第一次DOC写代码的体验给了google.全程都很紧张。 听口音小哥像是欧洲人，但是非常NICE，说如果没听明白一定要和他确定。


	前两分钟自我介绍了一下在哪个组我其实没听出来说的太快然后没问任何简历上的问题就直接开始了。

		1. Given two number a and b, find all the binary representations with length a and has b number of 1's and output in decimal in sorted order
		Example:
		input: a = 3, b = 1
		[001, 010, 100]
		output: [1, 2, 4]
		Explain time and space complexity. 

		2. Determine if two int array is permutation. 

		
	刚开始觉得这个题太简单了还跟他确定了一下不是next permutation, 只要判断是不是permutation就好。

	
		input: [1, 1, 0] and [0, 1, 1] 
		output: true.
		Explain time and space complexity.

	两道题都非常简单，大概不到三十分钟就写完了然后愉快地聊了一会天。 小哥一直在说自己很喜欢在Google 工作什么的，讲啦一下最近在用GO做的项目。 感觉小哥和我一样紧张，然后没有很多follow up的问题。发面经攒人品希望on site。

	补充内容 (2016-3-18 02:26):


	可以去onsite啦开心。


	[http://www.1point3acres.com/bbs/thread-179135-1-1.html](http://www.1point3acres.com/bbs/thread-179135-1-1.html)

54.	两周前约的电话面试，今天中午面的，希望不要跪，发发面经攒人品。

	一如既往的google作风，非常准时在给我打了电话，感觉是一个白人小哥，人还是比较nice的。一开始介绍了一下他所在的小组情况，是Google Play的内部数据统计等等，然后让我介绍一下我最喜欢的project等等，然后遇到的challenge等等，这些差不多用了10分钟左右吧。然后就是coding了，在Google Doc里面进行

	
	1） 一个binary tree，如果对其进行inorder traverse，但要求是iteratively。听到题目，心中暗喜，太便宜我了吧，然后balabala的把代码写出来，虽然中间也停顿几回，不是太确定细节了，然后在脑子里推敲了几下，觉得答案就是这个。（所以说熟记代码，包括细节，还是很有好处的）

	写完之后，也讨论一下时间和空间的复杂度。时间O（N）， 空间O（depth）

	
	2）  第二题，我没见过，表面看着也非常简单，但因为太简单，反而让我有些慌乱。

	
		Given:
		int[] F of size k, with numbers in [0, k)
		int a_init, within [0, k)
		int N
		A_0 = a_init
		A_1 = F[A_0]
		A_2 = F[A_1]
		...
		A_i = F[A_i-1]

		
		Find A_N.

		
	其实题目本身，特别简单，一个N次的循环，就能找到最后的答案。当时我压根就没把这三行代码当成solution，就一个劲的想优化算法。

	
	当时我犯了两个错误：1. 怎么样我都要把暴力解法给出来，但是我居然傻乎乎的避开了，他还以为我这个最简单的solution都没想出来。 2. 我当时想要的优化结果太aggressive了，想着优化到O（1）时间，导致自己陷入自己的思维陷阱出不来。
	

	后来他看我半天没琢磨出什么来，就说先不要想优化算法，把最简单的写出来。我当时有些慌乱，简单的代码，我自己的声明的变量忘了写类型，还提醒了我两次，我居然都没看出来（丢死人了）。
	

	然后他就说有什么优化算法，又重新回到之前自己的陷阱中（无语），然后他就提示说，中间是不是会出现重复，然后我就立马想到了要记录之前index，然后一旦发现有重复，就进行用数学求余的方式得到答案。（太笨了，自责一下，其实也不难想到，当时就不清楚为啥想不出来）由于中间耗费了一些时间，然后我匆匆忙忙就把自己的思路写完代码，思维未必缜密，估计有bug，然后他看时间差不多，就说这个代码未必通过得了test case，不过思路应该是对了的。（希望他这句不是美国的礼貌用语而已，只要有对我一些肯定，我就感激了）参考答案我就不发了，未必对，大家可以琢磨一下，有没更好的solution！

	求过！！求人品！！！求Onsite！！！！

	
	[http://www.1point3acres.com/bbs/thread-184340-1-1.html](http://www.1point3acres.com/bbs/thread-184340-1-1.html)

55.	面试就考了一道题， 整数加1. 比如 【1，2，3】 加一就变成 【1，2，4】。 很简单，一会就做出来了，然后他随便问了几个其他问题，就完了。也不知道到底结果如何


	[http://www.1point3acres.com/bbs/thread-182643-1-1.html](http://www.1point3acres.com/bbs/thread-182643-1-1.html)

56.	  

		Suppose you have a list of prime numbers in order, but not consecutive. 
		For example [3,7,13] Find the N smallest integers in order which have only these primes as factors. 
		For example [3,7,9,13,21,...
	
	[http://www.1point3acres.com/bbs/thread-186161-1-1.html](http://www.1point3acres.com/bbs/thread-186161-1-1.html)

57.	4月5号电面的google。 面我的是个白人大哥，说是在google已经工作了五年， 一上来问我有什么问题问一个在google工作了五年的engineer（囧 这不应该结束时在问吗）， 我就把我准备好的general question 问了下， 然后简单的说了下做过的project。 然后就是在google doc上题。。。


	题目是： 写一个function 求 一个数（可以是任意数） 的 root of squre。。。。 当时我就懵了，但感觉是用divide and conquer， 然后我想了一下，说了下自己的想法，然后写code

	我的code是

		public double findRoot(double n){
		  int x = n;
		  int y = 1;
		  while(x >y){
		    x = (x+y)/2;
		    y = n/x;
		  }
		  return x;
		}

	然后他说要我演示一下， 然后给我100让我演示， 然后我一步步演示了，证明这是可行的。

	然后他要我分析下time complexity， 然后我当时挺纠结的， 纠结是不是logn，然后我说了下我的怎么想的，然后他说他觉得是logn，然后我说我不确定，我觉得可能是loglogn，然后他就没说话了。

	
	然后他让我给几个test cases， 然后我发现我忽略了input 小于1的情况。 然后我有想了下并没有想出来， 结束后一想，发现只要把while里的condition 改成 Math.abs(x-y)>0就可以handle输入数小于1的情况了，反正当时死活没想出来。

	
	后来在网上搜了下，好像还要考虑精度的，反正我是没考虑到这么多。然后时间就到了，互相说了thank you。。。。。。。我觉得我这情况应该是没戏了。。。。。。 哎，感觉这题五花八门啊，和平时刷leetcode的题都不太一样。。。。囧。。。结果还没出来，但已经不报希望了，只能说积累了些经验。大家如果有什么疑问可以问我。.1point3acres缃_


	补充内容 (2016-4-13 03:53):

	
	刚刚收到google的电话， 进入onsite了， 好好准备吧












