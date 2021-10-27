#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int b;
        cin>>b;
        if(b&1) {
            b -= 1;
            int ta = 0.5 * b * b;
            int asq = 4;
            int n = (ta - b)/asq;
            cout<<n<<endl;
        }
        else {
            int ta = 0.5 * b * b;
            int asq = 4;
            int n = (ta - b)/asq;
            cout<<n<<endl;
        }
    }
    return 0;
}