#include<bits/stdc++.h>
using namespace std;

/*
Each node should store:

Children nodes (26 for lowercase English letters).
A boolean flag indicating if a word ends at that node.*/

class TrieNode{
    public:
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode(){
            isEndOfWord = false;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
};

/*
The Trie class should contain:

Insert() → To insert a word.
Search() → To check if a word exists.
StartsWith() → To check if any word starts with a given prefix.*/

class Trie{
    private:
        TrieNode* root;
    
    public:
        Trie(){
            root = new TrieNode();
        }
        
        //insertion of a word into trieNode
        void insert(string word){
            TrieNode* node = root;
            for(char ch : word){
                int index = ch - 'a';
                if(node->children[index] == NULL){
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->isEndOfWord = true;
        }

        //searching for a word - returning true of it exists and false otherwise
        bool search(string word){
            TrieNode* node = root;
            for(char ch : word){
                int index = ch - 'a';
                if(node->children[index] == NULL){
                    return false;
                }
                node = node->children[index];
            }
            return node->isEndOfWord;
        }

        //checking if any word starts with a given prefix
        bool startsWith(string prefix){
            TrieNode* node= root;
            for(char ch : prefix){
                int index = ch - 'a';
                if(node->children[index] == NULL){
                    return false;
                }
                node = node->children[index];
            }

            return true;
        }
};


int main(){

    Trie trie;
    //insertion
    trie.insert("cat");
    trie.insert("cap");
    trie.insert("bat");

    //searching
    cout << "searching 'cat'->" << trie.search("cat") <<endl;
    cout << "searching 'cap'->" << trie.search("cap") <<endl;
    cout << "searching 'bat'->" << trie.search("bat") << endl;

    //startswith
    cout << "'cat' startswith 'ca'->" << trie.startsWith("ca") << endl;
    cout << "'cap' startswith 'ca'->" << trie.startsWith("ca") << endl;
    cout << "'bat' startswith 'ca'->" << trie.startsWith("da") << endl;

    return 0;
}