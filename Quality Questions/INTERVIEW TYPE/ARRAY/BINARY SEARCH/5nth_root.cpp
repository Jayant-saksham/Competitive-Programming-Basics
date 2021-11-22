#include<bits/stdc++.h>
using namespace std;
double multiply(double num, int n) {
    double ans = 1.0;
    for(int i=1;i<=n;i++) {
        ans = ans*num;
    }
    return ans;
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double limit = 1e-6;
    while((high - low) > limit) {
        double mid = (low+high)/2;
        if(multiply(mid, n) < m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<getNthRoot(n, m)<<endl;
    return 0;
}