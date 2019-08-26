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
#include <assert.h>

typedef struct CustomType {
    int val;
} CustomType;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("请选择target运行你想运行的算法\n\n");
    
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
    
    return 0;
}
