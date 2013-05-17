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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newHeader = NULL, *lessPrev = NULL, *grtPrev = NULL, *grtHeader = NULL;
        if(head == NULL)
            return head;
        
        while(head!=NULL)
        {
            ListNode* node = new ListNode(head->val);
            if(node->val < x)
            {
                if(lessPrev == NULL)
                {
                    lessPrev = node;
                    newHeader = node;
                }else
                {
                    lessPrev->next = node;
                    lessPrev = lessPrev->next;
                }
            }else
            {
                if(grtPrev == NULL)
                {
                    grtPrev = node;
                    grtHeader = node;
                }else
                {
                    grtPrev->next = node;
                    grtPrev = grtPrev->next;
                }
            }
            
            head = head->next;
        }
        
        if(lessPrev != NULL)
            lessPrev->next = grtHeader;
        
        if(newHeader == NULL)
            newHeader = grtHeader;
            
        return newHeader;
    }
};
