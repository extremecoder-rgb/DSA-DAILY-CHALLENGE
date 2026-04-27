// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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

bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(temp->data != st.top()) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);   
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if(isPalindrome(head)) cout << "Palidrome List";
    else cout << "Not a Palindrome List";
}