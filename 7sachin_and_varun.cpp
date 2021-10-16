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
int findy1(int a, int b, int d) {
    return d * modInverse(b,a);
}
int number_of_pairs(int a, int b, int d) {
    int y1 = findy1(a, b, d);
    int ans = ((d/b) - y1)/a;
    return 1+ans;
}
int main(){
    cout<<number_of_pairs(2,3,5);
    return 0;
}