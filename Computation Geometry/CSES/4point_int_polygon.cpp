#include<bits/stdc++.h>
using namespace std;
#define point pair<int,int>
int orientation(point a, point b, point c) {
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int x3 = c.first;
    int y3 = c.second;
    int ans = (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    if(ans == 0) {
        return 0;
    }
    else if(ans > 0) {
        return 1;
    }
    return 2;
}
bool onSeg(point a, point b, point c) {
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int x3 = c.first;
    int y3 = c.second;
    if(x3<=max(x1,x2) && x3>=min(x1,x2) && y3<=max(y1,y2) && y3<=min(y1,y2)) {
        return true;
    }
    return false;
}
bool isIntersect(point p1, point p2, point p3, point p4) {
    int o1 = orientation(p1,p2,p3);
    int o2 = orientation(p1, p2,p4);
    int o3 = orientation(p3, p4,p1);
    int o4 = orientation(p3, p4,p2);
    if(o1!=o2 && o3!=o4) {
        return true;
    }
    return false;
}
void solve(vector<point> &poly, vector<point> &poi) {
    int count = 0;
    int n = poly.size();
    for(auto cp : poi) {
        bool isBoundary = false;
        point infinity = make_pair(cp.first, INT16_MAX);
        for(int i=0;i<n;i++) {
            point a = poly[i];
            point b = poly[(i+1)%n];
            if(orientation(a,b,cp) == 0 && onSeg(a,b,cp)) {
                isBoundary = true;
                break;
            }
            else if(isIntersect(a, b, cp, infinity)) {
                count++;
            }
        }
        if(isBoundary) {
            cout<<"BOUNDARY"<<endl;
        }
        else {
            if(count&1) {
                cout<<"INSIDE"<<endl;
            }
            else {
                cout<<"OUTSIDE"<<endl;
            }
        }
    }  
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<point> poly;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        poly.push_back(make_pair(x,y));
    }
    vector<point> poi;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        poi.push_back(make_pair(x,y));
    }
    solve(poly, poi);
    return 0;
}