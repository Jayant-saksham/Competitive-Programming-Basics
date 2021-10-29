#include<bits/stdc++.h>
using namespace std;
int findMex(unordered_set<int> s) {
    int mex = 0;
    while(s.find(mex)!=s.end()) {
        mex++;
    }
    return mex;
} 
int grundy(int n) {
    if(n == 0 || n == 1 || n == 2 || n==3) {
        return n;
    }
    unordered_set<int> s;
    for(int i=1;i<=3;i++) {
        s.insert(grundy(n-i));
    }
    return findMex(s);
}
string pridiction(int A[], int n) {
    int XOR = grundy(A[0]);
    for(int i=1;i<n;i++) {
        XOR = XOR^grundy(A[i]);
    }
    if(XOR!=0) {
        return "Player1";
    }
    return "Player2";

}
int main() {
    int A[] = {3,4,5};
    cout<<pridiction(A, 3)<<endl;
    return 0;
}