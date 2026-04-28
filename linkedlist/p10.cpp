// Delete the Middle Node of a Linked List

#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* deleteMiddle(Node* head){
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    // Node* prev = nullptr;
    fast = fast->next->next;
    while(fast!= nullptr && fast->next != nullptr){
        // prev = slow;
        slow=slow->next;
        fast = fast->next->next;
    }
    // prev->next = slow->next;
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    // delete slow;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = deleteMiddle(head);
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
}