#include<bits/stdc++.h>
using namespace std;
vector<int> makeFactors(int a, int b) {
    int gcd = __gcd(a,b);
    vector<int> v;
    for(int i=1;i*i<=gcd;i++) {
        if(gcd%i==0) {
            v.push_back(i);
            if(i*i!=gcd) {
                v.push_back(gcd/i);
            }
        }   
    }
    return v;
}
int main() {
    int a,b;
    cin>>a>>b;
    int t;
    vector<int> v = makeFactors(a, b);
    cin>>t;
    while(t--) {
        int low, high;
        cin>>low;
        cin>>high;
        int ans = -1;
        for(auto i : v) {
            if(i>=low && i<=high) {
                ans = max(ans, i);
            }
        }
        cout<<ans<<endl;
    }    
    return 0;
}