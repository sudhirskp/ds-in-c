#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<unordered_map>
#include<string>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord;

    Node() : isEndOfWord(false) {}

    ~Node(){
        for(auto& pair : children) {
            delete pair.second;
        }
    }
};

class Trie{

    private:
    Node* root;
    
    public :

    Trie() {
        root = new Node();
    }

    // Destructor to free memory
    // This will delete all nodes in the trie - not necessary
    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        Node* currentNode = root;
        for(char ch : word) {
            if(currentNode->children.find(ch) == currentNode->children.end()) { // it is for the check to the existence of the character till the end of the child
                currentNode->children[ch] = new Node();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(const string& word) {
        Node* currentNode = root;
        for(char ch : word) {
            if(currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];

        // if(!currentNode->children[ch]) {
        //     return false;
        // } else {
        //   currentNode = currentNode->children[ch];
        // }
    }
     return currentNode->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        Node* current = root;
         for(char ch : prefix) {
            if(!current->children[ch]){
                return false;
            }
            current = current->children[ch];    
        }
        return true;
    }


};

int main(){
    Trie trie;
    trie.insert("coke");
    trie.insert("code");
    trie.insert("cone");
    trie.insert("example");

    trie.search("coke") ? cout << "Found coke" << endl : cout << "Not found coke" << endl;
    trie.search("cod") ? cout << "Found cod" << endl : cout << "Not found cod" << endl;
    trie.startsWith("co") ? cout << "Prefix 'co' exists" << endl : cout << "Prefix 'co' does not exist" << endl;
    trie.startsWith("ex") ? cout << "Prefix 'ex' exists" << endl : cout << "Prefix 'ex' does not exist" << endl;



}