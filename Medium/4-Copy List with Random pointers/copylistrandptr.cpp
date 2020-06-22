#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    class triplet{
  public:
  Node*a;
  Node*b;
  Node*c;
};
    Node* copyRandomList(Node* A) {
            if(!A) return NULL;
    
    std::unordered_map<Node*,triplet> mp;
    
    Node*temp = A;
    while(temp){
        Node* newnode = new Node(temp->val);
        mp[temp].a = newnode;
        mp[temp].b = temp->next;
        mp[temp].c = temp->random;
        temp=temp->next;
    }
    for(auto i:mp){
        
        Node * next_ptr= i.second.b;
        Node * random_ptr = i.second.c;
        if(next_ptr){
         i.second.a->next = mp[i.second.b].a;   
        }
        else{
            i.second.a->next = NULL;
        }
        if(random_ptr){
            i.second.a->random = mp[i.second.c].a;
        }
        else{
            i.second.a->random = NULL;
        }
    }
    return mp[A].a;
  }
};