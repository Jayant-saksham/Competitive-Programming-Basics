#include<bits/stdc++.h>
using namespace std;
const int SIZE = 26;
struct node {
    struct node *children[SIZE];
    bool isEnd;
    int word;
};

struct node *createNode() {
    struct node *root = new node;
    root->isEnd = false;
    for(int i=0;i<SIZE;i++) {
        root->children[i] = NULL;
    }
    root->word = 0;
    return root;
}

void insert(struct node *root, string word) {
    int n = word.length();
    struct node *current = root;
    for(int i=0;i<n;i++) {
        int idx = word[i] -'a';
        if(current->children[idx] == NULL) {
            current->children[idx] = createNode();
        }
        current->word += 1;
        current = current->children[idx];
    }
    current->isEnd = true;
}
int prefix_count(struct node *root, string prefix) {
    struct node *current = root;
    for(int i=0;i<prefix.length();i++) {
        int idx = prefix[i] - 'a';
        if(current->children[idx] == NULL) {
            return 0;
        }
        current = current->children[idx];
    }
    return current->word;
}
int main() {
    string s[] = {"ram", "ramlal", "ramdev", "ramdas"};
    int n = sizeof(s)/sizeof(s[0]);
    struct node *root = createNode();
    for(int i=0;i<n;i++) {
        insert(root, s[i]);
    }
    cout<<prefix_count(root, "ram");
    return 0;
}