#include<bits/stdc++.h>
using namespace std;
#define point pair<int,int>
int orientation(point p1, point p2, point p3) {
    int ans = (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
    if(ans < 0) {
        return 1;
    }
    else if(ans > 0) {
        return 2;
    }
    return 0;
}

bool onSeg(point p1, point p2, point p3) {
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    int x3 = p3.first;
    int y3 = p3.second;
    if(x3<=max(x1,x3) && x3>=min(x1,x2) && y3<=max(y1,y2) && y3>=min(y1,y2)) {
        return true;
    } 
    return false;
}

bool isIntersect(point p1,point p2, point p3, point p4) {
    int o1 = orientation(p1,p2,p3);
    int o2 = orientation(p1,p2,p4);
    int o3 = orientation(p3,p4,p1);
    int o4 = orientation(p3,p4,p2);
    if(o1!=o2 && o3!=o4) {
        return true;
    }
    return false;
}

void solve(vector<point> &v, vector<point> &u) {
    int count = 0;
    bool boundary = false;
    int n = v.size();
    for(auto cp : u) {
        point infinity = make_pair(cp.first,INT16_MAX);
        for(int i=0;i<n;i++) {
            point a = v[i];
            point b = v[(i+1)%n];
            if(orientation(a,b,cp) == 0 && onSeg(a,b,cp)) {
                boundary = true;
                break;
            }
            if(isIntersect(a,b,cp,infinity)) {
                count++;
            }
        }
        if(boundary) {
            cout<<"BOUNDARY"<<endl;
        }
        else if(count&1) {
            cout<<"INSIDE"<<endl;
        }
        else {
            cout<<"OUTSIDE"<<endl;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<point> v;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    vector<point> u;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        u.push_back(make_pair(x,y));
    }
    solve(v,u);
    return 0;
}