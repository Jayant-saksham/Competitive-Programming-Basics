#include<bits/stdc++.h>
using namespace std;
int count_zero(int  n) {
    int count = 0;
    while(n > 0) {
        n /=5;
        count += n;
    }
    return count;
}
int main() {
    int n;
    cin>>n;
    cout<<count_zero(n)<<endl;
    return 0;
}