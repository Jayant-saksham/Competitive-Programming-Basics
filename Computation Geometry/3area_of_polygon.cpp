#include<bits/stdc++.h>
using namespace std;
#define point pair<int,int>
int cross_product(point a, point b) {
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    return (y2*x1 - x2*y1);
}
int area(vector<point> &v) {
    int ans = 0;
    int n = v.size();
    for(int i=0;i<n;i++) {
        point a = v[i];
        point b = v[(i+1)%n];
        int crs = cross_product(a, b);
        ans += crs;
    }
    return abs(ans/2);
}
int main() {
    int n;
    cin>>n;
    vector<point> v;
    while(n--) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    cout<<2*area(v)<<endl;
    return 0;
}