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
Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

bool isPalindromeV2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr ){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverse(slow->next);
    Node* first = head;
    while(second != nullptr){
        if(first->data != second->data){
            reverse(second);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(second);
    return true;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);   
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if(isPalindromeV2(head)) cout << "Palidrome List";
    else cout << "Not a Palindrome List";
}