/**
 * Given a sorted array, remove the duplicates in place such that 
 * each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do 
 * this in place with constant memory.
 *
 * For example,Given input array array = [1,1,2],
 * Your function should return length = 2, and array is now [1,2].
 *
 **/

#include <stdio.h>

// case 1
// 最初设计：认为对每一个数字，判断和移动的过程都是一样的，所以设计了两个for循环，第一个用来遍历
// 每个去重数，第二遍跑完剩余的数字进行比对。发现第二遍的下标并非每次都是与第一次有关的，于是又
// 设计了一个全局的前向指针下标。最终实现了去重，但是统计个数时又遇到了麻烦，没有能够解决。
//
// 参考了最优解后：实现如下。
// 
// 分析：首先为每个去重数字建立一遍循环的思路就是打错特错，因为这里仅仅是为了记录去重数的下标，
// 并且该下标是随着数字覆盖连续递增的，完全不需要进行循环，增加了循环后，后续根本没有办法进行处理。
// 实际这里违背了之前总结的算法思路。应该先用最简单的方式描述思路，描述之前，可以定义必要的变量。
// 随后不断的进行推进，如果在这之前，能够首先定义出去重数字当前下标这个变量，后续思路就非常清晰了。
class RemoveDupicate1 {
public:
    int remove_duplicates(int array[], int n) {
        if (n == 0) {
            return 0;
        }
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (array[index] != array[i]) {
                array[++index] = array[i];
            } 
        }
        return index+1;
	}
};

#include <algorithm>
using namespace std;
// case 2
// 借用stl算法实现:直接使用去重方法unique来实现。
class RemoveDupicate2 {
public:
    int remove_duplicates(int array[], int n) {
        return distance(array, unique(array, array + n));
	}
};

// case 3
// 使用STL中的upper_bound函数
// ???????
class RemoveDupicate3 {
public:
    int remove_duplicates(int array[], int n) {
        return removeDuplicates(array, array + n, array) - array;
	}
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
        while (first != last) {
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        return output;
    }
};

// test 
int main(int argv, char **argc)
{
    RemoveDupicate3 rem;
    int array[]={1,1,2,2,3,3};
    int num = rem.remove_duplicates(array, 6);
    printf("num:%d \n", num);
    for (int i = 0; i < 6; ++i) {
        printf("%d  ", array[i]);
    }
}
