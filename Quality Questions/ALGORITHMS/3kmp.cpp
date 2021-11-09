#include<bits/stdc++.h>
using namespace std;
vector<int> KMP(string s, string pattern) {
    int n = s.length();
    int m = pattern.length();
    int *pie = new int[n];
    for(int i=0;i<m;i++) {
        pie[i] = 0;
    }
    int i = 0;
    int j = 1;
    while(j<m) {
        if(pattern[i] == pattern[j]) {
            pie[j] = i+1;
            i++;
        }
        else {
            if(i==0) {
                pie[j] = 0;
            }
            else {
                i = pie[i-1];
            }
        }
        j++;
    }
    i=0;
    j=0;
    vector<int> v;
    while(i<n) {
        if(s[i] == pattern[j]) {
            i++;
            j++;
        }
        if(j == m) {
            v.push_back(i-m);
            j = pie[j-1];
        }
        else if(s[i]!=pattern[j] && i<n){
            if(j==0) {
                i++;
            }
            else {
                j = pie[j-1];
            }
        }
    }
    delete pie;
    return v;
}
int main() {
    string s;
    cin>>s;
    string pattern;
    cin>>pattern;
    vector<int> v = KMP(s, pattern);
    for(int i : v) {
        cout<<i<<" ";
    }
    return 0;
}