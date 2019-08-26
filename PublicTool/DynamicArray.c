//
//  DynamicArray.c
//  算法
//
//  Created by chenfanfang on 2019/8/26.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "DynamicArray.h"
#include <assert.h>
#include <stdbool.h>

void dynamicArrayJudgeCapacityIsEnough(DynamicArray *array) {
    if (array->length == array->capacity) {
        array->capacity = array->capacity * 1.5;
        array->values = realloc(array->values, array->capacity * sizeof(int));
    }
}

void dynamicArrayCheckIndex(DynamicArray *array, int index) {
    
    if (index < 0 || index > array->length - 1) {
        if (array->length == 0) {
            printf("\n\n空数组越界:index:%d\n\n",index);
        }
        else {
            printf("\n\n数组越界 index:%d  range:[0  %d]\n\n",index, array->length - 1);
        }
        
        assert(false);
    }
}

DynamicArray *dynamicArrayCreate() {
    DynamicArray *array = calloc(1, sizeof(DynamicArray));
    array->capacity = 10;
    array->length = 0;
    array->values = calloc(array->capacity, sizeof(int));
    return array;
}

int dynamincArrayLength(DynamicArray *array) {
    return array->length;
}

int dynamincArrayValueOfIndex(DynamicArray *array, unsigned index) {
    dynamicArrayCheckIndex(array, index);
    return array->values[index];
}

int dynamincArrayFirstValue(DynamicArray *array) {
    return array->values[0];
}

int dynamincArrayLastValue(DynamicArray *array) {
    return array->values[array->length - 1];
}

void dynamicArrayAddValue(DynamicArray *array, int value) {
    
    dynamicArrayAddValueAtIndex(array, value, array->length);
    
}

void dynamicArrayAddValueAtIndex(DynamicArray *array, int value, int index) {
    
    dynamicArrayJudgeCapacityIsEnough(array);
    
    if (index != array->length) {
        dynamincArrayValueOfIndex(array, index);
    }
    
    array->length = array->length + 1;
    for (int i = array->length - 1; i > index; i--) {
        array->values[i] = array->values[i -1];
    }
    
    array->values[index] = value;
}


void dynamicArrayRemoveAtIndex(DynamicArray *array, int index) {
    dynamincArrayValueOfIndex(array, index);
    
    for (int i = index; i < array->length - 1; i++) {
        array->values[i] = array->values[i + 1];
    }
    
    array->length = array->length - 1;
}
