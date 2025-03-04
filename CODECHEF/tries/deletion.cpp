#include<bits/stdc++.h>
using namespace std;

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

class Trie{
    private:
        TrieNode* root;

        bool isEmpty(TrieNode* node)
        {
            for(int i=0; i < 26; i++){
                if(node->children[i] != NULL){
                    return false;
                }
            return true;
            }
        }

        //deletion of a word from trieNode
        // recurrsion method se delete krenge
        TrieNode* deleteWord(TrieNode* node, string word, int depth = 0){
            //base cases
            if(node == NULL){
                return NULL;
            }
            
            if(depth == word.size()){
                if(node->isEndOfWord){
                    node->isEndOfWord = false;
                }

                //agar node has no children then delete the node
                if(isEmpty(node)){
                    delete node;
                    return NULL;
                }
                return node;
            }

            int index = word[depth]  - 'a';
            node->children[index] = deleteWord(node->children[index], word, depth + 1);

            if(isEmpty(node) && !node->isEndOfWord){
                delete node;
                return NULL;

            }
            return node;
        }
};

int main(){



    return 0;
}