// Find the length of the Loop in LinkedList

#include<iostream>
#include<map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

int lengthLoopHashing(Node* head){
    map<Node*, int> visited;
    Node* temp = head;
    int count = 1;
    while(temp != nullptr){
        if(visited.find(temp) != visited.end()){
            int val = visited[temp];
            return (count-val);
        }
        visited[temp] = count;
        count ++;
        temp = temp->next;
    }
    return 0;
}

int findLength(Node* slow, Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow != fast){
        count ++;
        fast = fast->next;
    }
    return count;
}

int lengthLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
        if(slow == fast) return findLength(slow,fast);
    }
}

int main(){
     Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    int res = lengthLoop(head);

    cout << res;
}