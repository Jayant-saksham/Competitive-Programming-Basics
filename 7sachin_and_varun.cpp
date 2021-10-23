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

int findy1(int b, int a, int d) {
    int modIn = modInverse(b, a);
    int y1 = (d%a * modIn)%a;
    return y1;
}
int main() {
    int a,b,d;
    cin>>a>>b>>d;
    if(d == 0) {
        cout<<1<<endl;
    }
    int g = __gcd(a, b);
    if(d%g == 1) {
        cout<<0<<endl;
    }
    else {
        a/=g;
        b/=g;
        d/=g;
        int y1 = findy1(b, a, d);
        if(d>y1*a) {
            int n = ((d/b - y1)/a);
            cout<<1+n<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }
    return 0;
}