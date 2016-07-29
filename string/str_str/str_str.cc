//strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。

// eg. str1 = "abc";  str2 = "fsdabcldi";

//solution:
//1、双指针，相同，指针同时++。子串指针，str2非指针，采用标记的方法即可。
//2、要返回起始位置。
//

#include <assert.h>
#include <stdio.h>

class Solution {
    public:
        // 暴力解决方案
        char * strstr_1(const char *str1, const char str2[]) {
            if (str1 == NULL) {
                printf("str1 is NULL\n");
                return NULL;
            }
            const char *temp_str1 = str1;
            const char *temp_str2 = str2;
            char *start_index = (char *)str2;
            int count = 1;
            while (*temp_str1 != '\0' && *temp_str2 != '\0') {
                printf("%d: \n", count);
                count++;
                printf("temp_str1 is %c\n", *temp_str1);
                printf("temp_str2 is %c\n", *temp_str2);
                if (*temp_str1 == *temp_str2) {
                    printf("equal is %c\n", *temp_str1);
                    temp_str1++;
                    temp_str2++;
                } else {
                    temp_str1 = str1;
                    start_index++;
                    temp_str2 = start_index;
                }
            }
            if (*temp_str1 == '\0') {
                return start_index;
            } else {
                return NULL;
            }
        }
        char * strstr_2(const char *str1, const char str2[]) {
            return NULL;
        }
};

int main(int argv, char ** argc)
{
    char *str1 = "abcd";
    char *str2 = "fsdabcldi";
    char *index = NULL;
    
    Solution s;
    index = s.strstr_1(str1, str2);
    //assert(index == NULL);
    if (index == NULL) {
        printf("str1 is not a handler str in str2\n");
    } else {
        printf("str1 is a handler str in str2, start index is: %c\n", *index);
    }
}

