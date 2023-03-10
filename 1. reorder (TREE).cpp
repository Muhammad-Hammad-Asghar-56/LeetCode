/**
 * Definition for singly-linked list.
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
    void reorderList(ListNode* head) {
        ListNode* pointer=head;
        while (pointer->next != 0)
        {
            ListNode* nextItem=pointer->next;
            // get the last element
            ListNode* lastNode=getLastElementAndRemove(pointer);
            // adjust the pointers next to current pointer
            lastNode->next=pointer->next;
            // adjust the current pointer's next
            pointer->next=lastNode;
            pointer=nextItem;      
        }
    }
    ListNode* getLastElementAndRemove(ListNode* head){
        ListNode *pointer=head;
        ListNode *prevPointer= 0 ;
        while(pointer->next!=0){
            prevPointer=pointer;
            pointer=pointer->next;
        }
        if(prevPointer!=nullptr){
            prevPointer->next=0;
        }
        return pointer;
    }
};

