/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

*/

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