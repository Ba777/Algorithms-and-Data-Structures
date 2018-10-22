//
//  main.cpp
//  reverseLinkedList
//
//  Created by Balachandhar on 2018-07-27.
//  Copyright © 2018 Balachandhar. All rights reserved.
//

#include <iostream>

class LinkedList {
   
    struct Node {
        int value;
        Node* nextAddress;
    };
    
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }
    
    void addElement(int n) {
        Node *addNode = new Node();
        addNode->value = n;
        addNode->nextAddress = head;
        head = addNode;
    }
    
    void reverseLinkedList() {
        Node *previousNode, *currentNode, *nextNode;
        previousNode = NULL;
        nextNode = NULL;
        currentNode = head;
        
        while(currentNode != NULL) {
            nextNode = currentNode->nextAddress;
            
            currentNode->nextAddress = previousNode;
            
            if(nextNode == NULL) {
                head = currentNode;
            }
            
            previousNode = currentNode;
            
            currentNode = nextNode;
        }
      
    }
    void printNode() {
        Node *printElement;
        printElement = head;
        while(printElement != NULL) {
            std::cout<<printElement->value<<std::endl;
            printElement = printElement->nextAddress;
        }
    }
    


private:
};


int main() {
    
    LinkedList a;
    
    a.addElement(10);
    a.addElement(9);
    a.addElement(8);
    a.addElement(7);
    a.addElement(6);
    a.addElement(5);
    a.addElement(4);
    a.addElement(3);
    a.addElement(2);
    a.addElement(1);
    
    a.reverseLinkedList();
    std::cout<<"Linked List:" <<std::endl;
    a.printNode();
    return 0;
}
