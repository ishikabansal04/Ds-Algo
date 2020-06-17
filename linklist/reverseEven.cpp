//HACKERRANK QUES==============

//in a given link list we have to reverse even parts of link list in O(n)!!!!
//for eg  2->18->24->3->5->7->9->6->12 should give ans 24->18->2->3->5->7->9->12->6
#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
struct Node {
    int data;
    Node *next;
};
Node *ptr;
Node *head1 = NULL;
Node *head2 = NULL;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        Node *tmp = new Node;
        tmp->data = x;
        tmp->next = NULL;
        if(head1 == NULL) {
            head1 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
    while(head1 != NULL) {   //traversing across original list
        if(head1->data % 2 == 0) {  //checking if data is even or odd
            stk.push(head1->data);  //reversing even list using stack in O(1)
        } else {
            bool flag = 1;  //when data is odd
            while(!stk.empty() || flag) {  //either we have inserted even elements already or we have got odd elements only till now
                if(stk.empty())
                    flag = 0;  //no more even elements
                Node *tmp = new Node;
                tmp->data = flag ? stk.top() : head1->data;  //if flag=1 then we have even elements in our stack so we pop them
                tmp->next = NULL;
                if(head2 == NULL) {  //making a new link list i.e final ans list
                    head2 = tmp;
                    ptr = tmp;
                } else {
                    ptr->next = tmp;
                    ptr = ptr->next;
                }
                if(!stk.empty())
                    stk.pop();
            }
        }
        head1 = head1->next;
    }
    while(!stk.empty()) {   //if at last still any even elements are left we pop them out with same method!
        Node *tmp = new Node;
        tmp->data = stk.top();
        tmp->next = NULL;
        if(head2 == NULL) {
            head2 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
        stk.pop();
    }
    while(head2 != NULL) {  //display of final list
        cout << head2->data << ' ';
        head2 = head2->next;
    }
    cout << '\n';
    return 0;
}