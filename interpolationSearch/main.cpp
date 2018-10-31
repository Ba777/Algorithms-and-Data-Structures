//
//  main.cpp
//  interpolationSearch
//
//  Created by Balachandhar on 2018-10-31.
//  Copyright © 2018 Balachandhar. All rights reserved.
//

// Interpolation search is faster than any other search algorithms if the input is sorted and uniformly distributed.
/*
 
 Step 1: A - Array of elements. e - element to be searched. pos - current position.
 Step 2: Make start = 0 and end = n-1
 Step 3: Calculate the current position pos by, pos = Start + [(end - start) / A[end] - A[Start])] * (e - A[Start]).
 Step 4: If A[pos] = e then report the pos value.
 Step 5: If e < A[pos] then, end = pos-1
 Step 6: If e > A[pos] then, start = pos+1
 Step 7: Do stpes 3, 4, 5, 6 While : start <= end && e >= A[start] && e =< A[end]
            1. start <= end - that is untill we have elements in the sub-array.
            2. e >= A[start] - element we are looking for is greater than or equal to the starting element of sub-array we are looking in.
            3. e =< A[end] - element we are looking for is less than or equal to the last element of sub-array we are looking in.
 */

#include <iostream>

void interpolateSearch(int arr[], int start, int end, int arr_size, int value_to_find) {
    int pos = start + (((end - start) / (arr[end] - arr[start]))) * (value_to_find - arr[start]);
    
    if(arr[pos] == value_to_find) {
        std::cout<<"Value found"<<std::endl;
        return;
    }
    else if(value_to_find < arr[pos]) {
        end = pos-1;
        if(start <= end && value_to_find >= arr[start] && value_to_find <= arr[end]) {
            interpolateSearch(arr, start, end, arr_size, value_to_find);
        } else {
            std::cout<<"Value not found"<<std::endl;
        }
    }
    else if(value_to_find > arr[pos]) {
        start = pos+1;
        if(start <= end && value_to_find >= arr[start] && value_to_find <= arr[end]) {
            interpolateSearch(arr, start, end, arr_size, value_to_find);
        } else {
            std::cout<<"Value not found"<<std::endl;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int arr[] = {1,1,2,2,3,3,4,4,5,5,6,6};
    int value_to_find = 7;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = arr_size-1;
    interpolateSearch(arr, start, end, arr_size, value_to_find);
    
    return 0;
}
