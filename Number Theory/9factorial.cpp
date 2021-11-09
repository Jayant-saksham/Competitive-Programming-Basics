#include<bits/stdc++.h>
using namespace std;
int factorial(int a, int m) {
    int f = 1;
    for(int i=a;i>=1;i--) {
        f *= i;
        f %= m;
    }
    return f;
}
int main() {
    int a;
    cin>>a;
    int m;
    cin>>m;
    cout<<factorial(a, m)<<endl;
    return 0;
}