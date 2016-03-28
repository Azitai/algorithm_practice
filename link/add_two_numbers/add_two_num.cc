/**
 * Add Two Numbers
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 **/

#include <stdio.h> // 不加，error NULL为定义。

struct ListNode {
    short int value;
    ListNode * p_next;
};

class List {
private:
    ListNode * head;
public:
    List() {
        head = NULL;
    }
    ListNode* begin() {
        return head;
    }
    bool add_node(short int value) {
        ListNode* p_node = new ListNode();
        p_node->value = value;
        p_node->p_next = NULL;

        if (head == NULL) {
            head = p_node;
            return true;
        }
        ListNode* p_temp = head;

        while (p_temp->p_next != NULL) {
            p_temp = p_temp->p_next;
        }
        p_temp->p_next = p_node;
        
        return true;
    }
};

// 思路：
// 1、设置进位信息，从地位到高位增加，从链表头到链表尾。进位标志根据node的value是否大于10判断，
//    默认为0，设为全局（while外）。else 设置为0.
// 2、三个链表在一个循环结构中，保持对其。条件为两个中任意一个链表指针不为NULL。
// 3、若一个链表到达尾部，则视为0.if(list1的p不为NULL) node->value + p->value;list2同理。
//    node初始为0、NULL。最终增加node到list3.注：该步一定不要忘记加进位。另注：大于10，则要取余。
//
// 在实际实现以及跑测试代码时出现以下问题：
// 1、大于10，取余，及时发现。
// 2、运行测试代码出core，原因，之前在while的末尾统一移动指针，没有考虑到其中一个可能已经到头，无法再
//    进行移动，放到if判断中，问题解决。
// 3、进一步又出core，原因在于add方法没有将result_list返回。
// 4、进一步又发现一个较为隐蔽的严重bug，当进位为1，而两个链表都到尾时，进位1被丢弃。
//
// 最终参考最优解，对语法进一步的进行优化，优化的点如下：
// 1、将循环变量赋初值的操作放在循环提的判断条件中。
// 2、将函数中的简单if语句全部用条件表达式代替，减少代码行数。
// 3、在接口设计上，直接传入两个ListNode，代表链表的头节点。返回同样是结果链表的头节点。
//    在函数内部，完成链表的尾插。
//

class Solution {
public:
    List* add_two_link(List* ln_1, List* ln_2) {
        List* result_list = new List();
        bool carry_bit = 0;
        ListNode* p_temp_1 = ln_1->begin();
        ListNode* p_temp_2 = ln_2->begin();

        while (p_temp_1 != NULL || p_temp_2 != NULL) {
            short int temp = 0; 
            if (p_temp_1 != NULL) {
                temp += p_temp_1->value;
                p_temp_1 = p_temp_1->p_next;
            }
            if (p_temp_2 != NULL) {
                temp += p_temp_2->value;
                p_temp_2 = p_temp_2->p_next;
            }
            temp += carry_bit;
            if (temp >= 10) {
                carry_bit = 1;
                temp = temp % 10;
            } else {
                carry_bit = 0;
            }
            result_list->add_node(temp);
        }
        // 之前的一个严重bug。最后一次的进位被丢弃。
        if (carry_bit == 1) {
            result_list->add_node(carry_bit);
        }
        return result_list;
    }
};

int main(int argv, char** argc) {
    List list_1;
    List list_2;
    List* list_3;
    Solution solu;
    {
        // 数字为321，1->2->3
        for (short int i = 7; i <9 ; ++i) {
            list_1.add_node(i);
        }
        // 打印结果，随后加入google gtest库，并用cmake方式进行编译。
        ListNode* p_temp = list_1.begin();
        while (p_temp != NULL) {
            printf("%d ", p_temp->value);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
    {
        // 数字为65，5->6
        for (short int i = 5; i < 7; ++i) {
            list_2.add_node(i);
        }
        // 打印结果，随后加入google gtest库，并用cmake方式进行编译。
        ListNode* p_temp = list_2.begin();
        while (p_temp != NULL) {
            printf("%d ", p_temp->value);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }

    list_3 = solu.add_two_link(&list_1, &list_2);
    {
        ListNode* p_temp = list_3->begin();
        while (p_temp != NULL) {
            printf("%d ", p_temp->value);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
}
