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
#include <string.h>

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


DynamicArray *dynamicArrayCreate(int elementSize) {
    
    DynamicArray *array = calloc(1, sizeof(DynamicArray));
    array->capacity = 10;
    array->length = 0;
    array->values = calloc(array->capacity, elementSize);
    array->elementSize = elementSize;
    return array;
}


bool dynamicArrayIsEmpty(DynamicArray *array) {
    return array->length == 0;
}

int dynamincArrayLength(DynamicArray *array) {
    return array->length;
}

void dynamincArrayGetValueOfIndex(DynamicArray *array, unsigned index, void *const data) {
    dynamicArrayCheckIndex(array, index);
    memcpy(data, array->values + index * array->elementSize, array->elementSize);
}



void dynamincArrayGetFirstValue(DynamicArray *array, void *const data) {
    dynamicArrayAddValueAtIndex(array, 0, data);
}


void dynamincArrayGetLastValue(DynamicArray *array, void *const data) {
    
    dynamicArrayAddValueAtIndex(array, array->length - 1, data);
}



void dynamicArrayAddValue(DynamicArray *array, void *const data) {
    
    dynamicArrayAddValueAtIndex(array, array->length, data);
    
}



void dynamicArrayAddValueAtIndex(DynamicArray *array, int index, void *const data) {
    
    dynamicArrayJudgeCapacityIsEnough(array);
    
    if (index != array->length) {
        dynamicArrayCheckIndex(array, index);
    }
    
    array->length = array->length + 1;
    for (int i = array->length - 1; i > index; i--) {
        memcpy(array->values + i * array->elementSize, array->values + (i - 1) * array->elementSize, array->elementSize);
    }
    
    memcpy(array->values + index * array->elementSize, data, array->elementSize);
    
}


void dynamicArrayRemoveAtIndex(DynamicArray *array, int index) {
    
    
    dynamicArrayCheckIndex(array, index);
    
    for (int i = index; i < array->length - 1; i++) {
        memcpy(array->values + i * array->elementSize, array->values + (i - 1) * array->elementSize, array->elementSize);
    }
    
    array->length = array->length - 1;

}


void deallocDynamicArray(DynamicArray *array) {
    
}
