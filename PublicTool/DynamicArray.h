//
//  DynamicArray.h
//  算法
//
//  Created by chenfanfang on 2019/8/26.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

////////////////////////////////////// C语言模拟 简单的动态数组(只存放int类型数据)

#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DynamicArray{
    
    unsigned int capacity; //数组的容量，不够可以自动进行扩容
    unsigned int length; //当前数组中拥有数据的个数
    unsigned int elementSize; //每个元素的大小
    void *values;
    
    
}DynamicArray;

DynamicArray *dynamicArrayCreate(int elementSize);

bool dynamicArrayIsEmpty(DynamicArray *array);

int dynamincArrayLength(DynamicArray *array);

void dynamincArrayGetValueOfIndex(DynamicArray *array, unsigned index, void *const data);

void dynamincArrayGetFirstValue(DynamicArray *array, void *const data);

void dynamincArrayGetLastValue(DynamicArray *array, void *const data);

void dynamicArrayAddValue(DynamicArray *array, void *const data);

void dynamicArrayAddValueAtIndex(DynamicArray *array, int index, void *const data);

void dynamicArrayRemoveAtIndex(DynamicArray *array, int index);

void deallocDynamicArray(DynamicArray *array);


#endif /* DynamicArray_h */
