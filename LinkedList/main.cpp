/*
 Linked List Implementation
 */


#include <iostream>
using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };
    
    // public member
public:
    // constructor
    LinkedList(){
        std::cout<<"Constructor"<<std::endl;
        head = NULL; // set head to NULL
        std::cout<<"Head_Constructor:"<<head<<std::endl;
    }
    
    
    
     //destructor
    ~LinkedList(){
       Node *next = head;
        std::cout<<"Destructor"<<std::endl;
        while(next) {              // iterate over all elements
            Node *deleteMe = next;
            next = next->next;     // save pointer to the next element
            delete deleteMe;       // delete the current entry
        }
    }
    
    
    
    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node. First time this pointsto NULL.
        //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
        std::cout<<"n->x:" << n->x << std::endl;
        std::cout<<"n->next:" << n->next << std::endl;
        std::cout<<"head:" << head << std::endl;
    }
    
    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    int popValue(){
        Node *n = head;
        int ret = n->x;
        
        head = head->next;
        delete n;
        return ret;
    }
    
    // private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
};

int main() {
    LinkedList list;
    
    list.addValue(5);
    list.addValue(10);
    //list.addValue(20);
    
    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    //cout << list.popValue() << endl;
    // because there is no error checking in popValue(), the following
    // is undefined behavior. Probably the program will crash, because
    // there are no more values in the list.
    // cout << list.popValue() << endl;
    return 0;
}
