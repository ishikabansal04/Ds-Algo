// pseudo code (mock interview ques) to add two numbers given in form of link lists 
// eg 1->2->3->4->5->6 + 4->7->2->1->8
/*
insert at beg(separate function);
int carry=0
head3!
if head1==NULL && head2==NULL return NULL
head1==NULL && head2!=NULL?head3=head2:head3=head1
if(head1!=NULL || head2!=NULL){
   head3=recursive_fun(head1->next,head2->next)
   int num= carry+head1->data+head2->data
   head3=insert_at_beg_fun(head3,num%10);
   carry=num/10;
}
return head3;
*/

// .
// .
// .
// .
// .

//psuedo code to ques to merge common elements of two link lists such that even members come after odd members====
//eg ll1= 1 2 3 4 5 7 8, ll2= 2 4 4 7 8 10 , ans= 7 2 4 8  

/*ListNode* AlterList(ListNode* head1,ListNode* head2){
    if(head1==NULL || head2==NULL) return NULL;
    ListNode* oddhead=NULL, *evenhead=NULL, *oddtail=NULL, *eventail=NULL;
    ListNode* temp1=head1;
    ListNode* temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data==temp2->data){
            if(temp1->data%2==0){
                if(evenhead==NULL){
                    evenhead = temp1;
                    eventemp = temp1;
                }
                else{
                    eventemp->next=temp1;
                    eventemp=eventemp->next;
                }
            }
            else{
                if(oddhead==NULL){
                    oddhead=temp2;
                    oddtail=temp2;
                }
                else{
                    oddtemp->next=temp2;
                    oddtemp=oddtemp->next;
                }
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data>temp2->data){
            temp1=temp1->next;
        }
        else{
            temp2=temp2->next;
        }
        if(eventemp!=NULL){
            eventemp->next=NULL;
        }
        if(oddhead==NULL){
            return evenhead;
        }
        oddtemp->next=evenhead;
        return oddhead;
    }

}
*/
//merging two sorted link lists=================

Node* merge_two_sorted_ll(Node* head1, Node* head2){
    // final head and tail are the head and tail of merged ll
        Node* final_head = head1;
        Node* final_tail = head1;
    
    if(head1->data < head2-> data){
         head1 = head1-> next;
    }
    else{
        Node* final_head = head2;
        Node* final_tail = head2;
         head2 = head2-> next;
    }
    while(head1!=NULL && head2!=NULL){    
        if(head1->data < head2->data){
            final_tail-> next = head1;
            final_tail = head1;
            head1 = head1-> next;
        }
        else{
            final_tail-> next = head2;
            final_tail = head2;
            head2 = head2-> next;
        }
    }
      // if one of the list ends then we move the final tail to the other list
    if(head1 == NULL){
        final_tail-> next = head2;
    }
    else{
        final_tail->next = head1;
    }
    return final_head;
}