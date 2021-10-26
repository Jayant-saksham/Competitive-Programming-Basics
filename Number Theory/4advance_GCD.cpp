#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    if(a>b) {
        return gcd(b, a%b);
    }
    return gcd(b , a);
}
int advance_GCD(int a, string s) {
    int ans = 0;
    for(int i=0;s[i]!='\0';i++) {
        ans = (ans*10 + (s[i] -'0'))%a;
    }
    return ans;
}
int main() {
    
    return 0;
}