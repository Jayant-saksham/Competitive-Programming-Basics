#include<bits/stdc++.h>
using namespace std;
void pie_table(int *PIE, int n, string pattern) {
    for(int i=0;i<n;i++) {
        PIE[i] = 0;
    }
    int i = 0;
    int j = 1;
    while(j<n) {
        if(pattern[i] == pattern[j]) {
            PIE[j] = i+1;
            i++;
            j++;
        }
        else {
            if(i==0) {
                PIE[j] = 0;
                j++;
            }
            else {
                i = PIE[i-1];
            }
        }
    }
}
vector<int> KMP(string s, string pattern, int PIE[]) {
    int n = s.size();
    int m = pattern.size();
    vector<int> v;
    int i = 0;
    int j = 0;
    while(i<n) {
        if(s[i] == pattern[j]) {
            i++;
            j++;
        }
        if(j==m) {
            v.push_back(i-m);
            j = PIE[j-1];
        }
        else if(i<n && pattern[j]!=s[i]) {
            if(j==0) {
                i++;
            }
            else {
                j = PIE[j-1];
            }
        }
    }
    return v;
}
int main() {
    string s;
    cin>>s;
    string pattern;
    cin>>pattern;
    int m = pattern.size();
    int PIE[m];
    pie_table(PIE, m, pattern);
    vector<int> v = KMP(s, pattern, PIE);
    for(int i : v) {
        cout<<i<<" ";
    }
    return 0;
}