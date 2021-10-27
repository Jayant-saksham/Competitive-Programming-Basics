#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1;
        cin>>s1;
        string s2;
        cin>>s2;
        int A[3] = {0};
        for(int i=0;i<s1.size();i++) {
            if(s1[i] == 'b' || s2[i] == 'b') {
                A[i] = 1;
            }
        }
        int count_b = 0;
        for(int i=0;i<3;i++) {
            if(A[i]) {
                count_b++;
            }
        }
        if(count_b<=1) {
            cout<<"no"<<endl;
        }
        else if(count_b == 2) {
            int idx;
            for(int i=0;i<3;i++) {
                if(A[i] == 0) {
                    idx = i;
                }
            }
            if(s1[idx] == 'o' || s2[idx] == 'o') {
                cout<<"yes"<<endl;
            }
            else {
                cout<<"no"<<endl;
            }
        }
        else if(count_b == 3) {
            int count_o = 0;
            for(int i=0;i<s2.size();i++) {
                if(s2[i] == 'o') {
                    count_o++;
                }
            }
            if(count_o == 0) {
                cout<<"no"<<endl;
            }
            else {
                cout<<"yes"<<endl;
            }
        }
    }
    return 0;
}