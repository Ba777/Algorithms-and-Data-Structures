//
//  main.cpp
//  binarySearch
//
//  Created by Balachandhar on 2018-10-29.
//  Copyright © 2018 Balachandhar. All rights reserved.
//


/*
 Binary search algorithm needs input in sorted order. We need to pass sorted input and compare the number to be found with the middle number of the sorted list. If it matched return the result, if the number is less than the middle number then check the left side of the list and if the number is greater than the middle number then check the right side of the list. Continue the process until we find the number.
 */
#include <iostream>

static int c_last, c_first;
void binarySearch(int arr[], int first_index, int last_index, int number_to_find) {
    
    if(last_index >= first_index) {
        int middle_element_index = first_index+((last_index-first_index)/2);
        
        if(middle_element_index > c_last || middle_element_index < c_first) {
            std::cout<<"Number not found in the array"<<std::endl;
            return;
        }
        if(number_to_find == arr[middle_element_index]) {
            std::cout<<"Number found"<<std::endl;
            return;
        }
        if(number_to_find < arr[middle_element_index]) {
            last_index = middle_element_index - 1;
            binarySearch(arr, first_index, last_index, number_to_find);
        }
        if(number_to_find > arr[middle_element_index]) {
            first_index = middle_element_index + 1;
            binarySearch(arr, first_index, last_index, number_to_find);
        }
        return;
    }
}



int main(int argc, const char * argv[]) {
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int number_to_find = 11;
    int first_index = 0;
    int last_index = sizeof(arr)/sizeof(arr[0]);
    c_first = first_index;
    c_last = last_index;
    binarySearch(arr, first_index, last_index, number_to_find);
    
    return 0;
}
