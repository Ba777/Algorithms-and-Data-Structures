//
//  main.cpp
//  exponentialSearch
//
//  Created by Balachandhar on 2018-10-31.
//  Copyright © 2018 Balachandhar. All rights reserved.
//

#include <iostream>
#include <cmath>

static int k = 0;
static int s,e;
static int arr_size;

void binarySearch(int arr[], int number_to_find, int start, int end) {
    if(end >= start) {
        int middle_index = start + ((end-start)/2);
        if(number_to_find == arr[middle_index]) {
            std::cout<<"Number found in the array"<<std::endl;
            return;
        }
        
        if(number_to_find < arr[middle_index]) {
            end = middle_index - 1;
            binarySearch(arr, number_to_find, start, end);
        }
        if(number_to_find > arr[middle_index]) {
            start = middle_index+1;
            binarySearch(arr, number_to_find, start, end);
        }
        return;
    }
}



void exponentialSearch(int arr[], int number_to_find) {
    int end_index = pow(2,k);
        if(number_to_find < arr[end_index]) {
            int start = pow(2, k-1)-1;
            int end = pow(2,k);
            s = start;
            e = end;
            
            binarySearch(arr, number_to_find, start, end);
            return;
        } else {
            k = k+1;
            exponentialSearch(arr, number_to_find);
        }
    }




int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    arr_size = sizeof(arr)/sizeof(arr[0]);
    int number_to_find = 90;
    exponentialSearch(arr, number_to_find);
    return 0;
}
