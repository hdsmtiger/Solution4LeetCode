/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m == n)
            return head;
        
        ListNode *Nnode = head;
        ListNode *prevNode = NULL;
        if(m == 1)
        {
            prevNode == NULL;
        }else
        {
            for(int i=1; i<n-1; i++)
                Nnode = Nnode->next;
            prevNode = Nnode;
            Nnode = Nnode->next;
        }
        
        ListNode *Mnode = head;
        ListNode *nextNode = NULL;
        for(int i=1; i<=m-1; i++)
            Mnode = Mnode->next;
        nextNode = Mnode->next;
        
        ListNode *tempNode = Nnode;
        ListNode *tempPrev = nextNode;
        ListNode *tempNext = Nnode->next;
        for(int i=0; i<n-m; i++)
        {
            ListNode *temp = tempNext->next;
            tempNext->next = tempNode;
            tempNode->next = tempPrev;
            
            tempPrev = tempNode;
            tempNode = tempNext;
            tempNext = temp;
        }
        
        if(m == 1)
        {
            head = tempNode;
        }else
        {
            prevNode->next = tempNode;
        }
        
        return head;
        
    }
};
