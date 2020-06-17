#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:        //compulsory to make public.......
    int data=0;
    Node *left=NULL;
    Node *right=NULL;
    int freq=1;
    Node(int data){
        this->data=data;
    }

    Node(int data,Node *left,Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

//creating a bst using an array!===============
Node* create(vector<int>& arr,int si,int ei){
    if(si>ei) return NULL;

    int mid=(si + ei) >> 1;  //right shift by one divides a no by 2!
  
    Node *node=new Node(arr[mid]);
  
    node->left=create(arr,si,mid-1);
    node->right=create(arr,mid+1,ei);

    return node;
}
//display=========================
void display(Node *node){
    if(node==NULL) return;
     
    string str="";
    str+=node->left!=NULL?to_string(node->left->data):".";
    str+="=>" +to_string(node->data)+"<=";
    str+=node->right!=NULL?to_string(node->right->data):".";
    cout<<str<<endl;

    display(node->left);
    display(node->right);
}

//maximum===========================
int maximum(Node *node){
    if(node==NULL) return INT_MIN;
    return max(maximum(node->left),max(node->data,maximum(node->right)));
}

//method no 2 of maximum=====================

int maximum_01(Node *node){
    Node *curr=node;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr->data;
}


//minimum===========================
int minimum(Node *node){
    if(node==NULL) return INT_MAX;
    return min(minimum(node->left),min(node->data,minimum(node->right)));
}


//method no 2 of minimum==============================

int minimum_01(Node *node){
    Node *curr=node;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr->data;
}


//height=============================
int height(Node *node){
    if(node==NULL) return 0;
    return max(height(node->left),height(node->right))+1;
}

//size of function======================
int size(Node *node){
    return (node==NULL)? 0: size(node->left)+size(node->right)+1;
}

//finding an element=======================
bool find(Node *node,int val){
    if(node==NULL) return false;
    if(node->data==val) return true;
    
    return find(node->left,val) ||find(node->right,val);
}

//method  no 2=============================
 bool find_01(Node *node,int data,int level){
     if(node==NULL) return false;

     if(node->data==data) {
         cout<<"Height of data in tree: "<<level<<endl;
         return true;}
     
     else if(node->data<data) return find_01(node->right,data,level+1);
     
     else
         return find_01(node->left,data,level+1);
 }


//method 3 to find an element and print its path=======================
bool find_02(Node *node,int data,int level,string ans){
     if(node==NULL) return false;

     if(node->data==data) {
         cout<<"Height of data in tree: "<<level<<endl;
         cout<<ans;
         return true;}
     
     else if(node->data<data) return find_02(node->right,data,level+1,ans+to_string(node->data)+" ");
     
     else
         return find_02(node->left,data,level+1,ans+to_string(node->data)+" ");
 }

//LCA=========================
int LCA_01(Node *node,int data1,int data2){
    if(data1>data2){          //sending data1 and data2 in sorted order else swapping it.!
        int temp=data1;
        data1=data2;
        data2=temp; 
    }
    if(node==NULL)return -1;

    if(data2<node->data){
        return LCA_01(node->left,data1,data2); 
    }

    else if(node->data<data1){
        return LCA_01(node->right,data1,data2);
    }

    else 
        return node->data;
}

//predecessor and successor of a data===================

 Node *pred=NULL;
 Node *pre=NULL;
 Node *succ=NULL;

void predSucc(Node *node,int data){
    if(node==NULL) return;
    predSucc(node->left,data);
    if(node->data==data){
       pred=pre;
    }
    if(pre!=NULL && pre->data==data)
         succ=node;      
    pre=node;

    predSucc(node->right,data);     
}

//adding new node!==================================== 
 void addNode_01(Node *node,Node *par,int data,bool isLeft){
     if(node==NULL){
         Node *child=new Node(data);
         if(isLeft) par->left=child;
         else par->right=child;
         return;
     }
     if(node->data==data){
         //freq++;
     }
     if(node->data<data){
         addNode_01(node->right,node,data,false);
     }
     else if(node->data>data){
         addNode_01(node->left,node,data,true);
     }
 }
/*
 Node *addNode_02(Node *node,int data){
     if(node==NULL){
         return newNode(data);
     }
     if(node->data<data){
         node->right=addNode_02(node->right,data);
         else
         node->left=addNode_02(node->left,data);
         return node;
     }
 }
*/
 Node* deletenode(Node *node,int val){
    if(node->left==NULL && node->right==NULL && node->data==val){
        return node ;
    }
    else if((node->left==NULL || node->right==NULL)&&node->data==val){
        if(node->left!=NULL)
        node=node->left;
        else
        node=node->right;

    }
    else if(node->left!=NULL && node->right!=NULL && node->data==val){
        Node *temp=temp->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        node->data=temp->data;
        delete temp;

    }
    deletenode(node->left,val);
    deletenode(node->right,val);
 }

 Node *delete_01(Node *node,int data){
     if(node->data<data){
         node->right=delete_01(node->right,data);

     }
     else if(node->data>data){
         node->left=delete_01(node->left,data);
     }
     else{
         if(node->freq>1){
             node->freq--;
         }
         else{
             if(node->left==NULL&& node->right==NULL ){
                 delete node;
                 return nullptr;
                 }
              if(node->left==NULL || node->right==NULL){
                  Node *n =node->left!=NULL?node->left:node->right;
                  delete node;
                  return n;
              }   
              int max_=maximum(node->left);
              node->data=max_;
              node->left=delete_01(node->left,data);
         }
     }
 }
 //======================================

void solve(){
     vector<int>arr={10,20,30,40,50,60,70,80,90,100,110,120};
     Node *root=create(arr,0,arr.size()-1);
     
     //display(root);
     /*
     cout<<maximum(root)<<"\n";
     cout<<maximum_01(root)<<"\n";
     cout<<minimum(root)<<"\n";
     cout<<minimum_01(root)<<"\n";
     cout<<height(root)<<"\n";
     cout<<size(root)<<"\n";
     cout<<(boolalpha)<<find(root,60)<<"\n";  //boolalpha prints ans in true and false form and not in 1 or 0 form!
     cout<<(boolalpha)<<find_01(root,80,0)<<"\n";
     cout<<(boolalpha)<<find_02(root,80,0,"")<<"\n";   
     cout<<LCA_01(root,120,40)<<"\n";
     */
     
     predSucc(root,70);
     cout<<(pred!=NULL?pred->data:-1)<<" -> "<<" 70 "<<" - >"<<(succ!=NULL?succ->data:-1);
     
     //Node *temp=insertelement(root,11);
     //addNode_01(root,root,11,false);
    /* deletenode(root,30);
     display(root);*/
   //   delete_01(root,30);
     //display(root);
}


int main(){
    solve();
}