#include<bits/stdc++.h>
using namespace std;
const int SIZE = 26;
struct node {
    struct node *children[SIZE];
    bool isEnd;
}; 
struct node *createNode() {
    struct node *ptr = new node;
    ptr->isEnd = false;
    for(int i=0;i<SIZE;i++) {
        ptr->children[i] = NULL;
    }
    return ptr;
}

void insert(struct node *root, string word) {
    struct node *current = root;
    int n = word.length();
    for(int i=0;i<n;i++) {
        int idx = word[i] - 'a';
        if(current->children[idx] == NULL) {
            current->children[idx] = createNode();
        }
        current = current->children[idx];
    }
    current->isEnd = true;
}

bool search(struct node *root, string key) {
    struct node *current = root;
    int n = key.length();
    for(int i=0;i<n;i++) {
        int idx = key[i] - 'a';
        if(current->children[idx] == NULL) {
            return false;
        }
        current = current->children[idx];
    }
    if(current->isEnd) {
        return true;
    }
    return false;
}

bool startswith(struct node *root, string key) {
    struct node *current = root;
    int n = key.length();
    for(int i=0;i<n;i++) {
        int idx = key[i] - 'a';
        if(current->children[idx] == NULL) {
            return false;
        }
        current = current->children[idx];
    }
    return true;
}

int brute_force(string s[], string prefix, int n) {
    int count = 0;
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<prefix.length();j++) {
            if(s[i][j] == prefix[j]) {
                count++;
            }
        }
        if(count == prefix.length()) {
            ans += 1;
        }
        count = 0;
    }
    return ans;
}

int main() {
    string s[] = {"apple", "app", "application", "the", "this", "hello", "hull", "his", "her", "android"};
    int n = 10;
    struct node *root = createNode();
    for(int i=0;i<n;i++) {
        insert(root, s[i]);
    }
    cout<<search(root, "appli")<<endl;
    cout<<startswith(root, "appli");
    return 0;
}