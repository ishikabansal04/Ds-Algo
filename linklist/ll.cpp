#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data=0;
    Node *next=NULL;
    Node(int data){
        this->data=data;
    }
    Node(){
    }
};

Node* head=NULL;
Node* tail=NULL;

int size(){
    if(head==NULL) return 0;
    else{
        int count=0;
        Node*temp=new Node;
        temp=head;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
}

bool isEmpty(){
    if(head==NULL) return true;
    else return false;
}

void addFirst(int data){
    Node *ptr=new Node(data);
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
        tail=ptr;
    }
    else{
        ptr->next=head;
        head=ptr;
        
    }
}


void addLast(int data){
    Node *ptr=new Node(data);
    ptr->next=NULL;
    if(head==NULL){
        
        head=ptr;
        tail=ptr;
    }
    else{
        tail->next=ptr;
        tail=ptr;
    }
}

int removeFirst(){
    if(head==NULL) return -1;
    else{
        if(head->next==NULL){
            tail=NULL;
        }
        Node *temp=new Node;
        temp=head;
        head=head->next;
        int val=temp->data;
        delete temp;
        return val;
    }
}

Node* getNode(int idx){
    Node *temp=new Node;
    temp=head;
    while((idx-1)!=0){
        temp=temp->next;
        idx--;
    }
    //cout<<temp->data;
    return temp;
}

int removeLast(){
    if(head==NULL) return -1;
    else{
        int idx=size()-1;
        Node *gn=getNode(idx);
        if(head->next==NULL){
            head=NULL;
        }
        int val=tail->data;
        Node *last=tail;
       
        gn->next=NULL;
         tail=gn;
        delete last;
        return val;
    }
}

int getFirst(){
    if(head==NULL){
        return -1;
    }
    else{
        int val=head->data;
        return val;
    }
}

int getLast(){
    if(head==NULL){
        return -1;
    }
    else{
        int val=tail->data;
        return val;
    }
}

void display(){
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void addAt(int idx,int data){
    if(idx==0){
        addFirst(data);
    }
    else{
    Node *temp=new Node;
    temp->data=data;
    Node *gn=getNode(idx-1);
    temp->next=gn->next;
    gn->next=temp;
    }
}

int removeAt(int idx){
    if(idx==0){
        removeFirst();
    }
    else{
        Node *gn=getNode(idx-1);
        Node *cn=getNode(idx);
        gn->next=cn->next;
        delete cn;
    }
}

Node* getMid(){
    Node *fastptr=NULL;
    Node *slowptr=NULL;
    fastptr=head;
    slowptr=head;
    while(fastptr!=NULL && fastptr->next!=NULL && fastptr->next->next!=NULL){  //no need of first condition
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
   
    return slowptr;
}

//reverse==================================


// method 1=======================using recursion
class pairreve{
   public:
     Node* prevnode=nullptr;
};



void reverselistrec(Node *node,pairreve *prev,int level){

    if(node==nullptr){
        return;
    }
     reverselistrec(node->next,prev,level+1);
     if(level>size()/2){
         int temp=prev->prevnode->data;
         prev->prevnode->data=node->data;
         node->data=temp;
         prev->prevnode=prev->prevnode->next;
     }
}

// method 2==============================using pointers

Node* reversepointer(Node* node){
    if(node==nullptr)
     return node;

     Node* curr=node;
     Node* prev=nullptr;

     while(curr!=nullptr){
          Node* forw=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forw;
}
  return prev;
}

void reversepointer_(){
    Node* prev=reversepointer(head);
    tail=head;
    head=prev;
}


//to check if it has cycle==============
/*
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL)return false;
    Node *slowptr=head;
    Node *fastptr=head->next;
   
    while(slowptr!=fastptr){
        if(fastptr==NULL || fastptr->next==NULL)return false;
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }
    if(fastptr==slowptr && slowptr!=NULL && fastptr!=NULL){
        return true;
    }
    else{
        return false;
    } 
}
*/
//to check if ll is palindromic or not===============================
bool palindromicll(){

    Node* midnode=getMid();
    Node* newhead=midnode->next;
    midnode->next=nullptr;
    Node* leftlist=head;
    Node* rightlist=reversepointer(newhead);
    bool flag=true;
    while(leftlist!=nullptr && rightlist!=nullptr){
        if(leftlist->data!=rightlist->data){
            flag=false;
            break;
        }
        leftlist=leftlist->next;
        rightlist=rightlist->next;
    }
    newhead=reversepointer(rightlist);
    midnode->next=newhead;
    return flag;
}



//folding linked list==========================================
void llfold(){
   
     Node* midnode=getMid();
     Node* nhead=midnode->next;
      midnode->next=nullptr;
     Node* list1=head;
     Node* list2=reversepointer(nhead);
      while(list2!=nullptr){
          Node* c1=list1->next;
          Node* c2=list2->next;
          list1->next=list2;
          list2->next=c1;
          list1=c1;
          list2=c2;
      }
    if(list1==nullptr)
     tail=nhead;
     else 
      tail=list1;
}

//unfolding of ll======================================

Node* addFirst_01(Node* node,Node* nhead,Node* ntail){
        if(nhead==nullptr){
        node->next=nullptr;
        nhead=node;
        ntail=node;
    }
    else{             
        node->next=nhead;
        nhead=node;
        
    }
    return nhead;
}


Node* addLast_01(Node* ptr,Node* nhead,Node* ntail){
        if(nhead==nullptr){
        ptr->next=nullptr;
        nhead=ptr;
        ntail=ptr;
    }
    else{
        ntail->next=ptr;
        ntail=ptr;
    }
    return ntail;
}

Node* removeFirst_01(){
    if(head==nullptr) return nullptr;
    else{
        if(head->next==nullptr){
            tail=nullptr;
        }
        Node *temp=new Node;
        temp=head;
        head=head->next;
        
        return temp;
    }
}

void unfoldll(){

    Node* list1=nullptr;
    Node* list2=nullptr;

    Node* t1=nullptr;
    Node* t2=nullptr;

    while(head!=nullptr && head->next!=nullptr){
        Node* temp1=removeFirst_01();
        Node* temp2=removeFirst_01();

       t1= addLast_01(temp1,list1,t1);
       list2= addFirst_01(temp2,list2,t2);
    }
    if(head!=nullptr) {
        Node *temp=removeFirst_01();
        t1=addLast_01(temp,list1,t1);
    }
    head=list1;
    t1->next=list2;
    tail=t2;
}

int main(){
    // addFirst(5);
    //  addFirst(6);
    //   addFirst(7);
    //    addFirst(8);
    //     addFirst(9);
    //      addFirst(20);
    // display();
    // cout<<endl;

    // addLast(10);
    // display();
    // cout<<endl;

    // cout<<getFirst()<<endl;
    
    // getLast();
    
    // cout<<removeFirst()<<endl;
    // display();
    // cout<<endl;

    // cout<<removeLast()<<endl;
    // display();
    // cout<<endl;
    
    // addAt(3,11);
    // display();
    // cout<<endl;
    
    // addAt(2,15);
    // display();
    // cout<<endl;
    
    // removeAt(2);
    // display();
    // cout<<endl;

   // cout<<getMid()<<endl;
  for(int i=0;i<10;i++)
    addFirst(i*10);
//     for(int i=0;i<10;i++)
//      addLast(i*10);
      display();
//     pairreve* prev=new pairreve();
//     prev->prevnode=head;
//     reverselistrec(head,prev,0);
//    // reversepointer_();
    cout<<endl;
    llfold();
    display();
    cout<<endl;
     unfoldll();
    display();
    cout<<endl;
   // cout<<palindromicll()<<endl;

    
    return 0;
}