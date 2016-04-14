/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 *     "A man, a plan, a canal: Panama" is a palindrome.
 *     "race a car" is not a palindrome.
 * 
 *     Note:
 *     Have you consider that the string might be empty? This is a good question to ask during an interview.
 * 
 *     For the purpose of this problem, we define empty string as valid palindrome.
 **/

// 思路：
// 1、头尾比对，双指针。具体非指针。
// 2、重点在结束条件，指针<=则结束。一个循环，指针向中间靠拢，比对两个是否相等，若不等，则直接退出，且
//    说明非回文。设置状态标志。
// 3、边界异常情况，为空：直接返回。
// 4、如何忽略：分隔符。如何解决大小写，不能仅仅是简单的对比。如果为分隔符，则一针移动，另一针不动。
//    如何设计比较好的语法。直接continue，如果两个都非分隔符，再做比较，且要考虑大小写。
// 5、字符的范围，从'a'~'Z' '0'~'9'
//

#include <stdio.h>
#include <string.h>

bool is_alphanumeric(char temp) {
    return (temp >= 'A' && temp <= 'Z') ||
           (temp >= 'a' && temp <= 'z') ||
           (temp >= '0' && temp <= '9') ?
           true : false;
}

class Solution {
public:
    bool is_palindrome(char* str, int str_len) {
        if (str_len == 0) return true;

        int front_index = 0;
        int post_index = str_len - 1;
        bool is_palindrome = true;

        while(front_index < post_index) {
            if(!is_alphanumeric(str[front_index])) {
                front_index++;
                continue;
            }
            if(!is_alphanumeric(str[post_index])) {
                post_index--;
                continue;
            }
            if(str[front_index] != str[post_index] && str[front_index] != str[post_index] - ('a' - 'A') &&
                    str[front_index] != str[post_index] + ('a' - 'A')) {
                is_palindrome = false;
                break;
            } else {
                front_index++;
                post_index--;
            }
        }
        return is_palindrome;
    }
};

int main(int argv, char** argc)
{
    // test is_alphanumeric()
    char temp = '8';
    int a = is_alphanumeric(temp);
    printf("a :%d\n", a);

    // test is_palindrome()
    Solution solution;
    char* test_str= "A man, a plan, a canal: Panama";
    int str_len = strlen(test_str);
    bool is_pa = solution.is_palindrome(test_str, str_len);
    printf("is_pa : %d\n", is_pa);
}
