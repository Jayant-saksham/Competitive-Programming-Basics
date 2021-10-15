#include<bits/stdc++.h>
using namespace std;
class Triplet {
    public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclids(int a, int b) {
    if(b==0) {
        Triplet smallAns;
        smallAns.gcd = a;
        smallAns.x = 1;
        smallAns.y = 0;
        return smallAns;
    }
    Triplet smallAns = extendedEuclids(b, a%b);
    Triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = (smallAns.x - (a/b)*(smallAns.y));
    return ans;
}
int modInverse(int a, int m) {
    if(__gcd(a,m)!=1) {
        return -1;
    }
    return extendedEuclids(a, m).x;
}
int main(){
    cout<<modInverse(3,11);
    return 0;
}