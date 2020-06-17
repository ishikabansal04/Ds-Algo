// we r keeping val v as generic but key of string type for now...
#include<iostream>
#include<string>
using namespace std;

template<typename V>  //creating our own return type using template!!
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;
    MapNode(string key,V value){
         this->key=key;
         this->value=value;
         this->next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};

// template<typename V>
class ourMap{
    MapNode<V>** buckets;   ///we need to keep a bucket array.. this is double pointer coz: linklist head is denoted by Node<int>* and since we r referring the address(basically storing address of head of linklist in our array) therefore one more star .
    int size;
    int numBuckets;
    public:
    ourMap(){
        count=0;
        numBuckets=0;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~ourMap(){
         for(int i=0;i<numBuckets;i++){
             delete buckets[i];    //first deleting linklists
        }
        delete []buckets;        //then deletingfinal array else address would be lost.
    }

    int size(){
        return count;
    }

    
    private:
    int getBucketIndex(string key){
        int hashcode=0;     //calculate hashcode
        int currcoeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashcode+=key[i]*currcoeff;
            hashcode=hashcode%numBuckets;
            currcoeff*=37;     //any prime no====
            currcoeff=currcoeff % numBuckets;
        }
        return hashcode % numBuckets;  //hashcode compression
    }

    public:
    V getValue(string key){
       int bucketIndex=getBucketIndex(string key);
         MapNode<V>* head=buckets[bucketIndex];
         while(head!=NULL){
             if(head->key==value){
                 return head->value;
             }
             head=head->next;
         }
         return 0;   
    }

    void insert(string key,V value){
         int bucketIndex=getBucketIndex(string key);
         MapNode<V>* head=buckets[bucketIndex];
         while(head!=NULL){
             if(head->key==value){
                 head->value=value;
                 return;
             }
             head=head->next;
         }
         head=buckets[bucketIndex];
         MapNode<V>* node=new MapNode<V>(key,value); 
         node->next=head;
         buckets[bucketIndex]=node;    // we r inserting at beg in a link list therefore head should be changed in buckets as well.
         count++;   //increased when a new node in actually inserted.
    }

    V remove(string key){
         int bucketIndex=getBucketIndex(string key);
         MapNode<V>* head=buckets[bucketIndex];
         MapNode<V>* prev=NULL;
         while(head!=NULL){
             if(head->key==key){
                 if(prev==NULL){
                    buckets[bucketIndex]=head->next;   //simply sklipped first node of linklist(case when prev = null)
                 }
                 else{
                 prev->next=head->next;
                 }
                 V->val=head->value;
                  head->next=NULL;   //since our destructor is recursive so firse free *next of the node to be deleted else complete list will be deleted 
                  delete head;
                  count--;
                  return val
             }
             prev=head;
             head=head->next;
         }
         return 0;
    }
};

int main(){
    ourMap obj=new ourMap;
    obj.insert("abc", 1);
    obj.insert("def", 2);
    obj.insert("ghi", 3);
    obj.insert("jkl", 4);
    obj.insert("mno", 5);
    V res=obj.getValue("def");
    cout<<res;
    return 0;
}