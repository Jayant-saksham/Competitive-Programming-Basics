#include<bits/stdc++.h>
using namespace std;
#define point pair<int,int>
int cross_product(point a, point b) {
    int x1 = a.first;
    int x2 = b.first;
    int y1 = a.second;
    int y2 = b.second;
    return (y2*x1 - x2*y1);
}

int area(vector<point> &v) {
    int ans = 0;
    int n = v.size();
    for(int i=0;i<n;i++) {
        point a = v.at(i);
        point b = v.at((i+1)%n);
        ans += cross_product(a,b);
    }
    return abs(ans) / 2;
}

int latticPointOnSegment(point a, point b) {
    int x1 = a.first;
    int x2 = b.first;
    int y1 = a.second;
    int y2 = b.second;
    int fiValue = abs(y2-y1);
    int seValue = abs(x2-x1);
    return __gcd(fiValue, seValue) - 1;
}

point solve(vector<point> &v) {
    point ans;
    int _area = area(v);
    int latticOnSeg = 0;
    int n = v.size();
    for(int i=0;i<n;i++) {
        point a = v[i];
        point b = v[(i+1)%n];
        latticOnSeg += latticPointOnSegment(a,b);
    }
    latticOnSeg += n;
    int latticInside = (_area + 1 - (latticOnSeg>>1));
    ans.first = latticInside;
    ans.second = latticOnSeg;
    return ans;    
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
    point ans = solve(v);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}

// Pick's theorem 
// A = i + (b/2) - 1 
