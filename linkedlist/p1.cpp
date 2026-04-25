// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* addTwoLL(Node* L1, Node* L2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* t1 = L1;
    Node* t2 = L2;
    int carry = 0;
    while(t1 != nullptr || t2 != nullptr){
        int sum = carry;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;
        //simple addition
        Node* newNode = new Node(sum%10);  //storing the last digit
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* L1 = new Node(2);
    L1->next = new Node(4);
    L1->next->next = new Node(3);
    Node* L2 = new Node(5);
    L2->next = new Node(6);
    L2->next->next = new Node(4);


    cout << "L1: ";
    printList(L1);

    cout << "L2: ";
    printList(L2);

 
    Node* result = addTwoLL(L1, L2);

    cout << "Result: ";
    printList(result);

    return 0;
}