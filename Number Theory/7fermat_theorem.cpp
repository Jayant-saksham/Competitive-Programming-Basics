#include<bits/stdc++.h>
using namespace std;

int power(int x, int y, int m) {
    if(y==0) {
        return 1;
    }
    int smallPower = power(x, y/2, m)%m;
    smallPower = (smallPower*smallPower)%m;
    if(y&1) {
        return (x*smallPower)%m;
    }
    return smallPower%m;
}

int fermats_theorem(int a, int p) {
    if(p<=a) {
        return -1;
    }
    if(__gcd(a,p)!=1) {
        return -1;
    }
    return power(a, p-2,p);
}
int main() {
    int a,p;
    cin>>a>>p;
    cout<<fermats_theorem(a,p)<<endl;
    return 0;
}