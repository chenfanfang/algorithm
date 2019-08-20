//
//  main.c
//  20. 有效的括号
//
//  Created by chenfanfang on 2019/8/20.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/valid-parentheses/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//解题思路：使用栈
bool isValid(char * s){
    int length = (int)strlen(s);
    if (length == 0) {
        return true;
    }
    char stack[length];
    int stackIndexFlag = -1; //-1代表数组没值
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (c == '[' || c == '(' || c == '{') {
            stackIndexFlag++;
            stack[stackIndexFlag] = c;
            
        }
        else {
            
            if (stackIndexFlag < 0) {
                return false;
            }
            else {
                char left_char = stack[stackIndexFlag];
                if ((left_char == '[' && c == ']') ||
                    (left_char == '(' && c == ')') ||
                    (left_char == '{' && c == '}')) {
                    stackIndexFlag --;
                }
                else {
                    return false;
                }
            }
        }
    }
    
    return stackIndexFlag < 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "";
    bool valid = isValid(str);
    printf("%d\n\n",valid);
    return 0;
}
