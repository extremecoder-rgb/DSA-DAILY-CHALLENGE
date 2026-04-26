// Given head, the head of a linked list, determine if the linked list has a cycle in it.

#include<iostream>
#include<map>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(Node *head) {
        map<Node*, int> visited;
        Node* temp = head;    
        while(temp != nullptr){
            if(visited.find(temp) != visited.end()) return true;
            visited[temp] = 1;
            temp = temp->next;
        }
        return false;
    }

    bool hasCycleV2(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }   
        return false;
    }
};

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    Solution obj;

    if (obj.hasCycle(head)) {
        cout << "Cycle detected (map method)" << endl;
    } else {
        cout << "No cycle (map method)" << endl;
    }

    if (obj.hasCycleV2(head)) {
        cout << "Cycle detected (two-pointer method)" << endl;
    } else {
        cout << "No cycle (two-pointer method)" << endl;
    }

    return 0;
}