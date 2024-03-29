//
//  main.c
//  150. 逆波兰表达式求值
//
//  Created by chenfanfang on 2019/8/21.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 ====================================题目====================================

 根据逆波兰表示法，求表达式的值。
 
 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 
 说明：
 
 整数除法只保留整数部分。
 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 示例 1：
 
 输入: ["2", "1", "+", "3", "*"]
 输出: 9
 解释: ((2 + 1) * 3) = 9
 示例 2：
 
 输入: ["4", "13", "5", "/", "+"]
 输出: 6
 解释: (4 + (13 / 5)) = 6
 示例 3：
 
 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 输出: 22
 解释:
 ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 = ((10 * (6 / (12 * -11))) + 17) + 5
 = ((10 * (6 / -132)) + 17) + 5
 = ((10 * 0) + 17) + 5
 = (0 + 17) + 5
 = 17 + 5
 = 22
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


//解题思路：使用 栈作为辅助工具


int evalRPN(char ** tokens, int tokensSize){
    
    if (tokensSize == 0) {
        return 0;
    }
    
    int stack[tokensSize];
    int stackIndexFlag = -1;
    int value_left = 0;
    int value_right = 0;
    
    for (int i = 0; i < tokensSize; i++) {
        char *currentChar = tokens[i];
        if (strcmp(currentChar, "+") == 0) {
            value_right = stack[stackIndexFlag];
            stackIndexFlag--;
            value_left = stack[stackIndexFlag];
            stack[stackIndexFlag] = value_left + value_right;
            
        } else if (strcmp(currentChar, "-")  == 0) {
            value_right = stack[stackIndexFlag];
            stackIndexFlag--;
            value_left = stack[stackIndexFlag];
            stack[stackIndexFlag] = value_left - value_right;
            
        } else if (strcmp(currentChar, "*")  == 0 ) {
            value_right = stack[stackIndexFlag];
            stackIndexFlag--;
            value_left = stack[stackIndexFlag];
            stack[stackIndexFlag] = value_left * value_right;
            
        } else if (strcmp(currentChar, "/")  == 0 ) {
            value_right = stack[stackIndexFlag];
            stackIndexFlag--;
            value_left = stack[stackIndexFlag];
            stack[stackIndexFlag] = value_left / value_right;
            
        }
        else { //入栈
            stackIndexFlag++;
            stack[stackIndexFlag] = atoi(currentChar); //字符串转int
        }
    }
    return stack[0];
}



int main(int argc, const char * argv[]) {

    int tokensSize = 13;
    char *tokens[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result = evalRPN(tokens, tokensSize);
    printf("result:%d\n\n",result);
    
    return 0;
}
