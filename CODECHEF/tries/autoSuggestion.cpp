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

        void collectSuggestions(TrieNode* node, string prefix, vector<string>& results){
            //yaha 'node' ka mtlb samjo
            //suppose prefix = "app"
            //aur root ke under hamare pass "apple krkr hoga"
            // toh iss case mei 'node' joh hai "app" ke last 'p' node hoga
            // waha se suggestion collection start krega yeh function
            if(node->isEndOfWord){
                results.push_back(prefix);  //store the word in the results vector
            }

            for(char ch = 'a' ; ch <= 'z'; ch++){
                if(node->children[ch - 'a'] != NULL){
                    //means -> ki 'p' ke koi child hai ki nahi
                    // agar hai toh aaje bdo

                    // ch - 'a' -> p ke child ka index hoga
                    // prefix "app" mei 'child' = ch ko add kr denge
                    collectSuggestions(node->children[ch - 'a'], prefix + ch, results);
                }
            }

        }

        /*yeh function hai joh hume "app" prefix agar exist krta hai toh 'p' return krenga
        usko hum upr collectionSugestions ke 'node' mei use krenge
        */
        TrieNode* searchPrefix(string prefix){
            TrieNode* node = root;
            for(char ch : prefix){
                int index = ch - 'a';
                if(node->children[index] == NULL){
                    return NULL;
                }
                node = node->children[index];
            }
            return node;
        }
    
    public:

        Trie(){
            root = new TrieNode();
        }

        void insert(string word){
            TrieNode* node= root;
            for(char ch : word){
                int index = ch - 'a';
                if(!node->children[index]){
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }

            node->isEndOfWord = true;
        }

        vector<string> getAutoSuggestions(string prefix){
            vector<string> suggestions;
            TrieNode* node= searchPrefix(prefix);
            if(!node) return suggestions;


            collectSuggestions(node, prefix, suggestions);
            return suggestions;
        }
};

int main(){

    Trie trie;

    trie.insert("apple");
    trie.insert("apex");

    vector<string> suggestions = trie.getAutoSuggestions("app");
    for(string x : suggestions){
        cout << x<<endl;
    }
    // cout << endl;

    return 0;
}