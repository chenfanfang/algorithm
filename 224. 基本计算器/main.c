//
//  main.c
//  224. 基本计算器
//
//  Created by chenfanfang on 2019/8/21.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include <string.h>

/*
 【题目】
 
 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 
 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
 
 示例 1:
 
 输入: "1 + 1"
 输出: 2
 示例 2:
 
 输入: " 2-1 + 2 "
 输出: 3
 示例 3:
 
 输入: "(1+(4+5+2)-3)+(6+8)"
 输出: 23
 说明：
 
 你可以假设所给定的表达式都是有效的。
 请不要使用内置的库函数 eval。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/basic-calculator
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */



//解题思路：栈  未解出
int calculate(char *s){
//
//    int length = (int)strlen(s);
//    char *arr[length]; //给个最大可能的空间
//    int arrIndexFlag = 0;
//    char preString[length];
//    char operatorString[2];
//    for (int i = 0; i < length; i++) {
//        char c = s[i];
//
//        if (c >= '1' && c <= '9') {
//            sprintf(preString, "%s%c",preString,c);
//        }
//
//        else {
//            if (c == '+' || c == '-') {
//                arr[arrIndexFlag] = preString;
//                arrIndexFlag++;
//                sprintf(operatorString, "%c",c);
//                arr[arrIndexFlag] = operatorString;
//                arrIndexFlag++;
//                sprintf(preString, "");
//            }
//        }
//
//    }
//
//    for (int i = 0; i < arrIndexFlag; i++) {
//        printf("%s\n",arr[i]);
//    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    
    char *string = "(1+(4+5+2)-3)+(6+8)";
    int result = calculate(string);
    
    printf("result:%d\n\n\n",result);
    
    return 0;
}
