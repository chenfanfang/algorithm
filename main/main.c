//
//  main.c
//  算法
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
#include "StackTool.h"
#include <assert.h>

typedef struct CustomType {
    int val;
} CustomType;

int main(int argc, const char * argv[]) {
    
    // insert code here...
    printf("请选择target运行你想运行的算法\n\n");
    
    
    //动态数组测试用例
    /*
    DynamicArray *array = dynamicArrayCreate(sizeof(CustomType));
    for (int i = 0; i < 20; i++) {
        CustomType *value = calloc(1, sizeof(CustomType));
        value->val = i;
        dynamicArrayAddValue(array, value);
    }
    
    CustomType *value = calloc(1, sizeof(CustomType));
    value->val = 55;
    dynamicArrayAddValueAtIndex(array, 19, value);
    
    for (int i = 0; i < array->length; i++) {
        CustomType *value = malloc(sizeof(CustomType));
        dynamincArrayGetValueOfIndex(array, i, value);
        printf("%d   ",value->val);
    }
    
    
    printf("\n");
     
     */
    
    /*
    //栈 测试用例
    Stack *stack = stackCreate(sizeof(CustomType));
    for (int i = 0; i < 20; i++) {
        CustomType *data = malloc(stack->dataSize);
        data->val = i;
        stackPush(stack, data);
    }
    
    
    while (stack->top != NULL) {
        CustomType *data = stackPop(stack);
        printf("%d  ",data->val);
        free(data);
        
    }
    
    printf("\n\n");
    
    */
    
    
    return 0;
}
