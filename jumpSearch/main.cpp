//
//  main.cpp
//  jumpSearch
//
//  Created by Balachandhar on 2018-10-29.
//  Copyright © 2018 Balachandhar. All rights reserved.
//

/* This algorithm is jump search and it has time complexity of O(sqrt(n)). number_to_check is supposed to be changed to test the algorithm.
 */
#include <iostream>
#include <math.h>

static int index_counter = 0;

void linearSearch(int arr[], int jump_n, int number_to_check) {
    int start_index = index_counter - jump_n;
    for(int i = start_index; i <= index_counter; i++) {
        if(arr[i] == number_to_check) {
            std::cout<<"Number found"<<std::endl;
        }
}
}



void jumpSearch(int arr[], int jump_n, int number_to_check) {
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    index_counter = index_counter + jump_n;
    if(number_to_check == arr[index_counter]) {
        std::cout<<"Number found"<<std::endl;
    }
    if(number_to_check < arr[index_counter]) {
        linearSearch(arr, jump_n, number_to_check);
    }
    if(number_to_check > arr[index_counter]) {
        jumpSearch(arr, jump_n, number_to_check);
    }
    
    
}

int main(int argc, const char * argv[]) {

    int arr[] = {2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20};
    int number_to_check = 11;
    int jump_n = sqrt(sizeof(arr)/sizeof(arr[0]));
    jumpSearch(arr, jump_n, number_to_check);
    return 0;
}
