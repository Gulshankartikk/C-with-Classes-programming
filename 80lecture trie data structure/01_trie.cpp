#include<iostream>
using namespace std;

class TrieNode
{
    public:
    TrieNode *child[26];
    bool isEndofWord;

    TrieNode()
    {
        isEndofWord =false;
        for(int i=0;i<26;i++)
        child[i]=NULL;
    }

};
class Trie
{
    TrieNode *root;
    public:
    Trie()
    {
        root = new TrieNode();
    };

    //insert
    void insert(string word)
    {
       TrieNode *node=root;
       for(char c: word)
       {
        int index =c-'a';
        if(node->child[index]==NULL)
        {
            node->child[index]=new TrieNode();
            node =node->child[index];
        }
        else{
            node =node->child[index];
        }
       }
       node->isEndofWord=true;
    }
    //search
    bool search(string word)
    {
      TrieNode *node=root;
      for(char c:word)
      {
          int index =c-'a';
          if(node->child[index]==NULL)
          return false;
          else
          node=node->child[index];
      } 
      return (node!=NULL && node->isEndofWord);    
    }
    bool isEmpty(TrieNode *node)
    {
        for(int i=0;i<26;i++)
        {
            if(node->child[i])
            return false;
        }
        return true;
    }   

    //delete
    bool Delete(TrieNode *node,string word,int depth)
    {
       // base condition
       if(depth==word.size())
       {
        //it is not the ed of word
          if(node->isEndofWord==0)
          {
            return false;
          }
        //it is  the ed of word
        node->isEndofWord=0;
        //child exist or not
        return isEmpty(node);
       }
       int index =word[depth]-'a';
       //char doesn't exist
       if(node->child[index]==NULL)
         return false;
         //char exist

         //Recursive call to delete the char in tree
         bool shouldDeleteChild=Delete(node->child[index],word,depth+1);

         if(shouldDeleteChild)
            {
                delete node->child[index];
                node->child[index]=NULL;
                return !node->isEndofWord && isEmpty(node);
            };
            return false;

    }
    void Deleteword(string word)
    {
        Delete(root,word,0);
    }
};

int main()
{
    Trie *tree =new Trie();
     tree->insert("apple");
     tree->insert("appex");
     tree->insert("almond");
     tree->Deleteword("apple");
     cout<<tree->search("appex")<<endl;
     cout <<"does it exist"<<tree->search("apple")<<endl;
    return 0;
}