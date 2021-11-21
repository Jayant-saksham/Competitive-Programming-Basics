#include<bits/stdc++.h>
using namespace std;
int max_water_container(int height[], int n) {
    int area = 0;
    int left = 0;
    int right = n-1;
    while(right > left) {
        area = max(area, min(height[left], height[right]) * (right - left));
        if(height[left] > height[right]) {
            right--;
        }
        else {
            left++;
        }
    }
    return area;
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    cout<<max_water_container(A, n)<<endl;
    return 0;
}