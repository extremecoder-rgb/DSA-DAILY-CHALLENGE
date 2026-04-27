// Odd Even Linked List

// 2-1-3-5-6-4-7

#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* oddEven(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even!=nullptr && even->next!=nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main(){
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
Node* result = oddEven(head);
Node* temp = result;
while(temp != nullptr){
    cout << temp->val << " ";
    temp = temp->next;
}
}