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
    else if(o1 == 0 && onSeg(p1,p2,p3)) {
        return true;
    }
    else if(o2 == 0 && onSeg(p1,p2,p4)) {
        return true;
    }
    else if(o3 == 0 && onSeg(p3,p4,p1)) {
        return true;
    }
    else if(o4 == 0 && onSeg(p3,p4,p2)) {
        return true;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        point a = make_pair(x1,y1);
        point b = make_pair(x2,y2);
        point c = make_pair(x3,y3);
        point d = make_pair(x4,y4);
        if(isIntersect(a,b,c,d)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}