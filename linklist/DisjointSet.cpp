#include<iostream>
#include<vector>
using namespace std;


class Node {
    public:
    int data=0;
    Node *repr=NULL;
    Node *next=NULL;
    Node(){

    }
    Node(int data){
        this->data=data;
    }
};
vector<Node*> set;
/*
Node* insertelement(Node *root,Node *temp){
    if(root==NULL){
       root=temp;
    }
    Node *ptr=root;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return root;
}
*/

Node *makeSet(int val){
    Node *temp=new Node(val);
    temp->next=NULL;
    temp->repr=temp;
    // root=insertelement(root,temp);
    return temp;
}

Node* FindSet(int val){
    // for(int i=0;i<set.size();i++){
    //     if(val==set[i]->data){
    //         return set[i]->repr;
    //     }
    // }
    return set[val-1]->repr;
}

int size(Node *root){
    int count=0;
    Node*ptr=root;
    while(ptr->next!=NULL){
        count++;
    }
    return count;
}
Node* Union(Node* root1,Node* root2){
    int s1=size(root1);
    int s2=size(root2);
    int i;
    for(i=0;i<set.size();i++){
        if(set[i]->data==root1->data || set[i]->data==root2->data){
            set.erase(set.begin()+i);
        }
    }
    Node* root=NULL;
    Node *ptr1=root1;
    Node *ptr2=root2;

    if(s1<s2){
        while(ptr2->next!=NULL){
            ptr2=ptr2->next;
        }        
        ptr2->next=root1;
        while(ptr1->next!=NULL){
            ptr1->repr=root2;
            ptr1=ptr1->next;
        }
        root=root2;
    }
    else{
        while(ptr1->next!=NULL){
            ptr1=ptr1->next;
        }        
        ptr1->next=root2;
        while(ptr2->next!=NULL){
            ptr2->repr=root1;
            ptr2=ptr2->next;
        }
        root=root1;
    }
    set.push_back(root);
    return root;
}

void display(){
   for(int i=0;i<set.size();i++){
       cout<<set[i]->data;
       if(set[i]->next==NULL) {
           cout<<endl;
           continue;
       }
       else{
           cout<<"->";
           Node *ptr=set[i];
           while(ptr->next!=NULL){
              
               ptr=ptr->next;
                cout<<ptr->data<<"->";
           }
           cout<<endl;
       }
   }
}

int main(){
    Node *root=NULL;
    
    for(int i=0;i<5;i++){
        root=makeSet(i+1);
        set.push_back(root);
    } 
    display();
    cout<<endl;
    Node* representative1=FindSet(2);
    cout<<representative1->data<<endl;
    Node* representative2=FindSet(5);
    cout<<representative2->data<<endl;
    cout<<endl<<endl;
    Node* join=Union(representative1,representative2);
    display();
    return 0;
}