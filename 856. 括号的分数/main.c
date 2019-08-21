//
//  main.c
//  856. 括号的分数
//
//  Created by chenfanfang on 2019/8/21.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/score-of-parentheses/solution/gua-hao-de-fen-shu-by-leetcode/

#include <stdio.h>
#include <string.h>
/*
 【题解】-----------------------
 栈
 字符串 S 中的每一个位置都有一个“深度”，即该位置外侧嵌套的括号数目。例如，字符串 (()(.())) 中的 . 的深度为 2，因为它外侧嵌套了 2 层括号：(__(.__))。
 
 我们用一个栈来维护当前所在的深度，以及每一层深度的得分。当我们遇到一个左括号 ( 时，我们将深度加一，并且新的深度的得分置为 0。当我们遇到一个右括号 ) 时，我们将当前深度的得分乘二并加到上一层的深度。这里有一种例外情况，如果遇到的是 ()，那么只将得分加一。
 
 下面给出了字符串 (()(())) 每次对应的栈的情况：
 
 [0, 0] (
 [0, 0, 0] ((
 [0, 1] (()
 [0, 1, 0] (()(
 [0, 1, 0, 0] (()((
 [0, 1, 1] (()(()
 [0, 3] (()(())
 [6] (()(()))
 
 */

int scoreOfParentheses(char *S){
    int length = (int)strlen(S);
    int scoreStack[length];
    scoreStack[0] = 0; //当前分数设置为0   index=0 代表的是最终的分数
    int stackIndexFlag = 0;
    
    
    int rightScore = 0;
    int leftScore = 0;
    for (int i = 0; i < length; i++) {
        char c = S[i];
        if (c == '(') { // (
            stackIndexFlag++;
            scoreStack[stackIndexFlag] = 0;
            
        }
        else { // )
            rightScore = scoreStack[stackIndexFlag] * 2;
            if (rightScore == 0) {
                rightScore = 1;
            }
            stackIndexFlag--;
            leftScore = scoreStack[stackIndexFlag];
            scoreStack[stackIndexFlag] = leftScore + rightScore;
        }
    }
    
    return scoreStack[0];
}


int main(int argc, const char * argv[]) {
    
    char *string = "(()(()))"; //最终得分为6
    int score = scoreOfParentheses(string);
    printf("得分为:%d\n\n",score);
    
    
    return 0;
}
