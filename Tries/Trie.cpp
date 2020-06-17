// #include<iostream>
#include"TrieNode.cpp"
#include<string>
// using namespace std;
class Trie{
    TrieNode *root;

    public:
    Trie(){
        root=new TrieNode('\0');//null / empty means we r making it terminal node!!!!
    }
    void insertWord(TrieNode*root,string word){  //using recursion.......
        //Base case
        if(word.size()==0){
            root->isterminal=true;
            return;
        }

        //Small calculation part
        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursive call
        insertWord(child,word.substr(1));
    }


    //for user function===============
    void insertWord(string word){
        insertWord(root,word);
    }
   
    bool search(TrieNode* root,string word){
        if(word.size()==0){
           return root->isterminal;
        }
        
        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return search(child,word.substr(1));
    }

    //helper function=======================
    bool search(string word){
        return search(root,word);
    }


    void removeWord(TrieNode*root,string word){  //using recursion.......
        //Base case
        if(word.size()==0){
            root->isterminal=false;
            return;
        }

        //Small calculation part
        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return;
        }

        //Recursive call
        removeWord(child,word.substr(1));

        //remove child if useless====
        if(child->isterminal==false){
            for(int i=0;i<26;i++){
                child->children[i]!=NULL;
                return;
            }
        }
        delete child;
        root->children[index]=NULL;
    }


    //for user function===============
    void removeWord(string word){
        removeWord(root,word);
    }
};