#include<bits/stdc++.h>
using namespace std;
int log2(int n) {
    if(n == 1) {
        return 0;
    }
    return 1 + log2(n/2);
}
int maxMinAlgo(int dept, int idx, bool isMax, int A[], int h) {
    if(dept == h) {
        return A[idx];
    }
    if(isMax) {
        int ans1 = maxMinAlgo(dept+1, idx*2, false, A, h);
        int ans2 = maxMinAlgo(dept+1, idx*2+1, false,A, h);
        return max(ans1, ans2);
    }
    else {
        int ans1 = maxMinAlgo(dept+1, idx*2, true, A, h);
        int ans2 = maxMinAlgo(dept+1, idx*2+1, true, A, h);
        return min(ans1, ans2);
    }
    return -1;
}
int main() {
    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(scores)/sizeof(scores[0]);
    int h = log2(n);
    int res = maxMinAlgo(0, 0, true, scores, h);
    cout << "The optimal value is : " << res << endl;
    return 0;
}