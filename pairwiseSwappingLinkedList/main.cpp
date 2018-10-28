//
//  main.cpp
//  pairwiseSwappingLinkedList
//
//  Created by Balachandhar on 2018-07-23.
//  Copyright © 2018 Balachandhar. All rights reserved.
//

#include <iostream>

class LinkedList {
public:
    
    struct Node {
        int value;
        Node *nextAddress;
    };
    
    LinkedList() {
        head = NULL;
    }
    
    ~LinkedList() {
        Node *deleteNode, *tempAddress;
        deleteNode = head;
        while(deleteNode != NULL) {
            tempAddress = deleteNode->nextAddress;
            delete deleteNode;
            deleteNode = tempAddress;
        }
    }
    
    void addElement(int n) {
        Node *newNode = new Node();
        newNode->value = n;
        newNode->nextAddress = head;
        head = newNode;
    }
    
    void swapPairwiseByValue() {
        Node *leftNode, *rightNode;
        int temp;
        leftNode = head;
        rightNode = leftNode->nextAddress;

        while(rightNode != NULL) {
            temp = leftNode->value;
            leftNode->value = rightNode->value;
            rightNode->value = temp;
            leftNode = leftNode->nextAddress->nextAddress;
            rightNode = rightNode->nextAddress->nextAddress;
        }
    }
    
    void printList() {
        Node *printNode;
        printNode = head;
        while(printNode != NULL) {
            std::cout<<printNode->value<<std::endl;
            printNode = printNode->nextAddress;
        }
    }
    
private:
    Node *head;
};

int main() {

    LinkedList ListObj;
    
    ListObj.addElement(1);
    ListObj.addElement(2);
    ListObj.addElement(3);
    ListObj.addElement(4);
    ListObj.addElement(5);
    ListObj.addElement(6);
    ListObj.addElement(7);
    ListObj.addElement(8);
    ListObj.addElement(9);
    ListObj.addElement(10);
    ListObj.addElement(11);
    ListObj.addElement(12);
    ListObj.addElement(13);
    ListObj.addElement(14);
    ListObj.addElement(15);
    
    std::cout<<"Before Swapping:"<<std::endl;

    ListObj.printList();

    ListObj.swapPairwiseByValue();
    
    std::cout<<"After Swapping:"<<std::endl;

    ListObj.printList();
    
    return 0;
}
