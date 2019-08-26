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

typedef struct DynamicArray{
    
    unsigned int capacity; //数组的容量，不够可以自动进行扩容
    unsigned int length; //当前数组中拥有数据的个数
    int *values;
    
    
}DynamicArray;

DynamicArray *dynamicArrayCreate(void);

int dynamincArrayLength(DynamicArray *array);

int dynamincArrayValueOfIndex(DynamicArray *array, unsigned index);

int dynamincArrayFirstValue(DynamicArray *array);

int dynamincArrayLastValue(DynamicArray *array);

//返回值代表是否添加成功
void dynamicArrayAddValue(DynamicArray *array, int value);

//返回值代表是否添加成功
void dynamicArrayAddValueAtIndex(DynamicArray *array, int value, int index);

//返回值代表是否删除成功
void dynamicArrayRemoveAtIndex(DynamicArray *array, int index);

//销毁动态数组
void deallocDynamicArray(DynamicArray *array);


#endif /* DynamicArray_h */
