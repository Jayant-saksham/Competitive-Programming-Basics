#include<bits/stdc++.h>
using namespace std;
int sunny_building(int height[], int n) {
    int count = 0;
    int maxH = INT16_MIN;
    for(int i=0;i<n;i++) {
        if(maxH < height[i]) {
            maxH = height[i];
            count++;
        }
    }
    return count;
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    cout<<sunny_building(A, n)<<endl;
    return 0;
}