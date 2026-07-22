class Solution {
    void newnode(ListNode* head){
        ListNode* newnode = new ListNode(0); 
        head->next=newnode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode*prev=NULL;
        ListNode* l3 = new ListNode(0); 
        ListNode* temp3 = l3;

        int carry=0;
        while(temp1||temp2){
           int x = (temp1 ? temp1->val : 0);
           int y = (temp2 ? temp2->val : 0);
           int sum = x + y + carry;

            temp3->val = sum%10; 
            carry = sum/10;
            newnode(temp3);
            prev=temp3;
            temp3=temp3->next;
            if(temp1)temp1=temp1->next;
            if(temp2)temp2=temp2->next;
        }
        if(carry != 0){
            temp3->val = carry;
        }
        else{
            prev->next = nullptr;
        }
        return l3;
    }
};