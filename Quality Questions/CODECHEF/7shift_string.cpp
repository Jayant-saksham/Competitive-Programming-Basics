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

int main() {
    string a;
    cin>>a;
    string b;
    cin>>b;
    string newPattern = a + "#" + b + b;
    int n = newPattern.size();
    int PIE[n];
    pie_table(PIE, n, newPattern);
    int idx = 0;
    int maxKMP = -1;
    for(int i=a.size()+1;i<n;i++) {
        if(PIE[i]>maxKMP) {
            idx = i;
            maxKMP = PIE[i];
        }
    }
    cout<<idx - maxKMP - a.size()<<endl;
    return 0;
}