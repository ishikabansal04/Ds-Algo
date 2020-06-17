class TrieNode{
    public:
    char data;
    TrieNode **children;
    
    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];//contains only small/lower case alphabets
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    bool isterminal=false;
};
