class Solution
{
    public:

    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if (head==NULL) return head;
        
        struct node* curr = head, *pre=NULL, *next=NULL;
        
        int count=0;
        
        while (curr!=NULL && count<k) {
            next=curr->next;
            curr->next=pre;
            pre=curr; curr=next;
            count++;
        }
        
        if (next!=NULL) head->next=reverse(next, k);
        
        return pre;
        
        
    }
};