#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        int v = x%8;
        if(v==0) {
            cout<<(x-1)<<"SL"<<endl;
        }
        else if(v == 7) {
            cout<<(x+1)<<"SU"<<endl;
        }
        else if(v == 1) {
            cout<<(x+3)<<"LB"<<endl;
        }
        else if(v == 4) {
            cout<<(x-3)<<"LB"<<endl;
        }
        else if(v == 2) {
            cout<<(x+3)<<"MB"<<endl;
        }
        else if(v == 5) {
            cout<<(x-3)<<"MB"<<endl;
        }
        else if(v == 3) {
            cout<<(x+3)<<"UB"<<endl;
        }
        else if(v == 6) {
            cout<<(x-3)<<"UB"<<endl;
        }
    }
    return 0;
}