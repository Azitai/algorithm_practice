//solution:
//1、负数、非法字符（只能是数字）、非法数字（由正负号和数字组成，但顺序不同），专写校验函数。
//2、使用stl栈数据结构，先整体写入栈，随后*10n。
//3、符号标识位。
//4、通过抽象、合并，尽可能的让循环结构少，是程序精简的一个重要路线。
//5、进行INT_MAX判断，是该函数的一个重点。另外，累乘的方法也是一个思维突破点，以及累加的代码处理。


//BUG
//1、0、9边界条件错误。
//
//

#include <stdio.h>
#include <string.h>
#include <limits.h>

class Solution {
    public:
        bool atoi(const char *str, int *number) {
            int temp_number = 0;
            int len = strlen(str);
            int flag = 1;
            char *temp = (char *)str;
            // flag
            if (*temp == '+') {
                temp++;
            } else if (*temp == '-') {
                flag = -1;
                temp++;
            }
            if (*temp == '0') {
                return false;
            }
            while (*temp != '\0') {
                if (*temp >= '0' && *temp <= '9') {
                    temp_number = temp_number * 10 + (*temp - '0');
                    // INT_MAX 判断，在快要接近INT_MAX时进行处理。
                    if (temp_number > INT_MAX/10 || 
                        (temp_number == INT_MAX/10 &&
                         (*(temp+1) - '0') > INT_MAX%10)) {
                        //return flag == -1 ? INT_MIN : INT_MAX; 
                        return false;
                    }
                    temp++;
                } else {
                    return false;
                }
            }

            *number = flag * temp_number;
            return true;
        }
};

int main(int argv, char **argc)
{
    char *test_str = "434554432624";
    Solution solution;
    int number = 0;
    bool flag = solution.atoi(test_str, &number);
    if (flag == false) {
        printf("input illegal\n");
    } else {
        printf("input number is %d\n", number);
    }
}
