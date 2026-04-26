// Reverse Linked List
#include<iostream>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

stack<int> s;

Node*reverse(Node*head){
    Node*temp = head;
    while(temp != nullptr){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
}

Node* reverseAlgo2(Node* head){
    Node* prev = nullptr;
    Node* temp = head;

    while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* reverseRecAlgo(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* newHead = reverseRecAlgo(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);   
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Node* result = reverse(head);
    // Node* result2 = reverseAlgo2(head);
    Node* result3 = reverseRecAlgo(head);
    // while(result != nullptr){
    //     cout << result->data << " -> ";
    //     result = result->next;
    // }

    while(result3 != nullptr){
        cout << result3->data << " -> ";
        result3 = result3->next;
    }

    cout << "NULL\n";
}