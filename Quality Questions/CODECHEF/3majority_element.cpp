#include<bits/stdc++.h>
using namespace std;
vector<int> majority_element_n3(int A[], int n) {
    vector<int> v;
    int element1 = A[0];
    int count1 = 0;
    int element2 = 0;
    int count2 = 0;
    for(int i=0;i<n;i++) {
        if(A[i] == element1) {
            count1++;
        }
        else if(A[i] == element2) {
            count2++;
        }
        else if(count1 == 0) {
            element1 = A[i];
            count1 = 1;
        }
        else if(count2 == 0) {
            element2 = A[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i=0;i<n;i++) {
        if(A[i] == element1) {
            count1++;
        }
        else if(A[i] == element2) {
            count2++;
        }
    }
    if(count1 > n/3) {
        v.push_back(element1);
    }
    if(count2 > n/3) {
        v.push_back(element2);
    }
    return v;
}
int majority_element_n2(int A[], int n) {
    int element = A[0];
    int count = 1;
    for(int i=1;i<n;i++) {
        if(A[i] == element) {
            count++;
        }
        else if(count == 0) {
            element = A[i];
        }
        else {
            count--;
        }
    }
    count = 0;
    for(int i=0;i<n;i++) {
        if(A[i] == element) {
            count++;
        }
    }
    if(count>n/2) {
        return element;
    }
    return -1;    
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    vector<int> v = majority_element_n3(A, n);
    for(auto i : v) {
        cout<<i<<" ";
    }
    return 0;
}