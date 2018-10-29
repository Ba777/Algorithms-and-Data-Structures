//
//  main.cpp
//  linearSearch
//
//  Created by Balachandhar on 2018-10-29.
//  Copyright © 2018 Balachandhar. All rights reserved.
//
// Time complexity is O(n).

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,200,300, 48922,4022,44333,2222};
    int a = 300;
    bool switch_ = false;
    for(int i = 0; i < sizeof(arr); i++) {
        if(arr[i] == a) {
            switch_ = true;
            std::cout<<"Index of the element: "<<i<<std::endl;
        }
    }
    if(switch_ == false) {
        std::cout<<"Element is not present in the array"<<std::endl;
    }
        return 0;
}
