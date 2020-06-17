#include<iostream>
using namespace std;

class Node{
    
public:
    int data;
    Node*next;
    // Node constructor
    Node(int data){
        
        this -> data = data;
        this -> next = NULL;
    }
    // Node deconstructor
    ~Node(){
        
    }
};

Node* insert_node_recursively(Node*head , int data , int position){
    Node *temp = head;
    if(temp==NULL && position>0){
        return NULL;
    }
     if(position==0){
        Node *new_node = new Node(data);
        new_node-> next = head;
        head = new_node;
        return head;
    }
   // else if(temp==NULL && position=0)
    Node *recursive_head = insert_node_recursively(temp-> next , data , position - 1);
    if(temp==NULL && position==0){
        temp=recursive_head;
        return temp;
    }
    head-> next = recursive_head;
    return head;
}
// TO DELETE THE WHOLE LIST
Node* get_input(){
    
    int data;
    cin >> data;
    
    Node* head = NULL;
    
    while(data != -1){
        
        Node * new_node = new Node(data);
        if(head == NULL){
            head = new_node;
        }
        else{
            Node * temp = head;
            while(temp->next != NULL ){
                temp = temp->next;
            }
            temp->next = new_node;
        }
        cin >> data;
    }
    return head;
}
void deletion(Node*head){
    
    Node *ptr , *store;
    ptr = head;
    while(ptr!=NULL){
        store = ptr-> next;
        delete ptr;
        ptr = store;
    }
    cout << "All the nodes were deleted" << endl;
}
// TO PRINT ALL THE NODES AND COUNT IT TOO

int print(Node* head){
    int counter = 0;
    cout << "The Printed list is:" << endl;
    while(head!=NULL){
        cout << head-> data << " ";
        head = head-> next;
        counter++;
    }
    cout << endl;
    return counter;
}
int main(){
    cout << "Enter the elements in the linked list:" << endl;
    Node* head = get_input();
    
    int data , position;
    cout << "Enter the data to be stored in the new node: " << endl;
    cin >> data;
    cout << "Enter the position before which the new node is to be inserted: " << endl;
    cin >> position;
    head = insert_node_recursively(head , data , position);
    print(head);
    
    deletion(head);
}