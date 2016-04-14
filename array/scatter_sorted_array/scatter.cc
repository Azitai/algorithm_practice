/**
 *  struct A {
 *      int provider_id;
 *      char bc;
 *  };
 *  Given a vector which each elem is A. The vector has sorted. Now, scatter the vector to promise that adjacent
 *  elem is not equal provider_id and as far as possible to ensure before order.
 *  Scatter vector by provider_id, the interval of two equal provider is N.
 *
 *  For example:
 *  N = 5.
 *  Input: {{1,a},{1,b},{2,c},{1,c},{3,c},{2,b}}
 *  Output: {{1,a},{2,c},{3,c},{1,b},{2,b},{1,c}}
 *
 **/

// 思路：
// 1、将数组导为链表，方便插入，因为一遍N过后，要从前开始，所以，直接采用链表插入的方式。比回去重新开始
//    遍历要方便，这种需要标记，不可行。注意：是中插法。
// 2、维护一个set存放本次N循环中已经压入的provider，如果出现，则不插入（留一个指针，标记当前插入位置）。
//    每次N循环过后，清空Set。
// 3、注：考虑N大于整个vec长度的情况，提前结束。
//
// 细节：
// 1、链表上双指针，第一个指向插入的位置，
//
//**该题目类似于之前的数组去重，本质上是一样的，只不过数组去重直接可以覆盖，所以在数组上操作，不用开辟
//其他空间，而该需求不能覆盖，所以要借助链表。在数组去重的基础上，不仅判断与当前相邻的是否相等，还要判断
//之前N个是否相等，所以要额外有一个set记录N次的elem。另外一个不同，在于它没有按照provider排序，而是score排序。
//

#include <vector>
#include <iostream>

typedef struct A {
    int provider_id;
    char bc;
};

class Solution {
public:
    void scatter_by_provider(std::vector<A *> & vec) {
    }
};
