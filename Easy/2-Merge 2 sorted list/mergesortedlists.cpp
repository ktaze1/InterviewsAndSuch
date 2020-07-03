/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2 == nullptr)
            return l1;
        if(l1 == nullptr)
            return l2;
        
        ListNode * dummy = new ListNode(0);
        ListNode * curr = dummy;
        
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val == l2->val)
            {
                ListNode * n = new ListNode(l1->val);
                curr->next = n;
                curr = curr->next;
                l1 = l1->next;
            }
            else if(l1->val > l2->val)
            {
                ListNode * n = new ListNode(l2->val);
                curr->next = n;
                curr = curr->next;
                l2 = l2->next;
            }
            else if(l1->val < l2->val)
            {
                ListNode * n = new ListNode(l1->val);
                curr->next = n;
                curr = curr->next;
                l1 = l1->next;
            }
        }
    
        
        if(l2 == nullptr && l1!=nullptr)
        {
            
            while(l1!=nullptr)
            {
                ListNode * n = new ListNode(l1->val);
                curr->next = n;
                curr = curr->next;
                l1 = l1->next;
            }
        }
        if(l2!=nullptr && l1 == nullptr)
        {
            while(l2!=nullptr)
           {
            ListNode * n = new ListNode(l2->val);
            curr->next = n;
            curr = curr->next;
            l2 = l2-> next;
            }
        }
            
        
        return dummy->next;  
    }
   
};


int main(){
    return 0;
}