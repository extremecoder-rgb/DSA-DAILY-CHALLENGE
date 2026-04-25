// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

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

Node* middleFind(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count ++;
        temp = temp->next;
    }
    int midNode = count/2 + 1;
    temp = head;
    while(temp != nullptr){
        midNode = midNode-1;
        if(midNode == 0) break;
        temp = temp->next;
    } 
    return temp;
}

Node* middleFindTortoiseAndHare(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);

    Node* result = middleFind(head);
    Node* result1 = middleFindTortoiseAndHare(head);

    cout << "Result: ";
    printList(result);
    printList(result1);

    return 0;
}