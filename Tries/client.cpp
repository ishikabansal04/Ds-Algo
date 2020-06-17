#include<iostream>
#include<string>
using namespace std;
#include"Trie.cpp"

int main(){
    Trie obj;
    obj.insertWord("ans");
    obj.insertWord("and");
    obj.insertWord("that");
    obj.insertWord("not");
    obj.insertWord("note");
    obj.insertWord("as");
    cout<<obj.search("not")<<endl;
    obj.removeWord("and");
    cout<<obj.search("and")<<endl;
    return 0;
}