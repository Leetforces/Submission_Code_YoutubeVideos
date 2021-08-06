const int ALPHABET_SIZE = 26;
struct TrieNode{
    TrieNode* child[ALPHABET_SIZE];
    bool isEnd;
    TrieNode()
    {
       isEnd=false;
       for(int i=0;i<ALPHABET_SIZE;i++)
       child[i]=NULL;
    }
  };
  // global trieroot
  TrieNode* root;


  //insert a string
  void insertKey(string& key)
  {
      TrieNode* curr=root;
      for(int i=0;i<key.size();i++)
      {
         int index=key[i]-'a';
         if(curr->child[index]==NULL)
         curr->child[index]=new TrieNode();
         curr=curr->child[index];
      }
      curr->isEnd=true;
  }
  // search a string 
  bool searchKey(string& key)
  {
      TrieNode* curr=root;
      for(int i=0;i<key.size();i++)
      {
          int index=key[i]-'a';
          if(curr->child[index]==NULL)
          return false;
          curr=curr->child[index];
      }
      return curr->isEnd;
  }
  // check trie is empty or not
  bool isEmpty(TrieNode* curr)
  {
      for(int i=0;i<ALPHABET_SIZE;i++)
      if(curr->child[i]!=NULL)
      return false;
      return true;
  }
  // delete a string from trie
  TrieNode* deleteKey(TrieNode* curr,string& key,int i)
  {
     if(curr==NULL) return NULL;
     if(i==key.size())
     {
         curr->isEnd=false;
         if(isEmpty(curr))
         {
             delete(curr);
             curr=NULL;
         }
         return curr;
     }
     int index=key[i]-'a';
     curr->child[index]=deleteKey(curr->child[index],key,i+1);
     if(isEmpty(curr) && curr->isEnd==false)
     {
         delete(root);
         curr=NULL;
     }
     return curr;
  }
int longestPrefix(string& key)
{
    TrieNode* curr=root;
    int len=0;
    for(int i=0;i<key.size();i++)
    {
        int index=key[i]-'a';
        if(curr->child[index]==NULL)
        return len;
        len++;
        curr=curr->child[index];
    }
    return len;
}


// root=new TrieNode(); // do this to make trie
// void insertKey(string);
//bool searchKey(string);
//TrieNode* deleteKey(TrieNode* ,string, int=0);
//int longestPrefix(string)

