#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int N,A,B,C,D,P,Q,Y;
        cin>>N>>A>>B>>C>>D>>P>>Q>>Y;
        int x[N];
        for(int i=0;i<N;i++) {
            cin>>x[i];
        }
        int t1,t2;
        t1 = abs(x[B-1] - x[A-1])*P;
        int time_A_to_C = abs(x[C-1]-x[A-1])*P;
        int time_train = abs(x[D-1] - x[C-1]) * Q;
        int time_D_to_B = abs(x[B-1] - x[D-1]) * P;
        t2 = time_A_to_C + time_train + time_D_to_B;
        int waiting_time = 0;
        if(Y>=time_A_to_C) {
            waiting_time = Y - time_A_to_C;
            t2 += waiting_time;
        }
        else {
            t2 = INT32_MAX;
        }
        cout<<min(t1, t2)<<endl;
    }
    return 0;
}