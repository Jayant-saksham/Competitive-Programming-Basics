#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int ans = (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
        if(ans == 0) {
            cout<<"TOUCH"<<endl;
        }
        else if(ans > 0) {
            cout<<"LEFT"<<endl;
        }
        else {
            cout<<"RIGHT"<<endl;
        }
    }
    return 0;
}