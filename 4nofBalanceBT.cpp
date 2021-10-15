#include<bits/stdc++.h>
using namespace std;
int balanceBT(int h) {
    if(h == 0 || h == 1) {
        return 1;
    }
    int x = balanceBT(h-1);
    int y = balanceBT(h-2);
    long res1 = (long)x*x;
    long res2 = (long)x*y*2;
    int m = pow(10,9) + 7;
    int ans1 = (int)(res1%m);
    int ans2 = (int)(res2%m);
    return (ans1 + ans2)%m;
}
int main(){
    cout<<balanceBT(4)<<endl;
    return 0;
}