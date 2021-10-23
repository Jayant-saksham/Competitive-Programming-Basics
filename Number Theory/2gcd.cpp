#include<bits/stdc++.h>
using namespace std;
class Triplet {
    public:
    int x;
    int y;
    int gcd;
};
int hcf(int a, int b) {
    for(int i=a>b?b:a;i>=1;i--) {
        if(a%i==0 && b%i==0) {
            return i;
        }
    }
    return 1;
}
int gcd1(int a, int b) {
    if(b==0) {
        return a;
    }
    if(a>b) {
        return gcd1(b, a%b);
    }
    return gcd1(b ,a);
}
Triplet extendedEuclidsAlgo(int a, int b) {
    if(b==0) {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet smallAns;
    smallAns = extendedEuclidsAlgo(b, a%b);
    Triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = (smallAns.x - (a/b)*(smallAns.y));
    return myAns;
}
int main() {
    Triplet ans = extendedEuclidsAlgo(30,20);
    cout<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;    
    return 0;
}