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

int distance(point a, point b) {
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

set<point> convex_hull(vector<point> &v) {
    set<point> hull;
    point start = v[0];
    int n = v.size();
    for(int i=1;i<n;i++) {
        if(start.first > v[i].first) {
            start = v[i];
        }
    }
    
    point current = start;
    vector<point> colinear_pts;
    hull.insert(start);
    while(true) {
        point next = v[0];
        for(int i=1;i<n;i++) {
            if(v[i] == current) {
                continue;
            }
            int o = orientation(current, next, v[i]);
            if(o == 2) {
                next = v[i];
                colinear_pts.clear();
            }
            else if(o == 0) {
                int d1 = distance(current, next);
                int d2 = distance(current, v[i]);
                if(d1 > d2) {
                    colinear_pts.push_back(v[i]);
                }
                else {
                    colinear_pts.push_back(next);
                    next = v[i];
                }
            }
        }
        vector<point>::iterator it;
        for(it = colinear_pts.begin();it!=colinear_pts.end();it++) {
            hull.insert(*it);
        }
        if(next == start) {
            break;
        }
        hull.insert(next);
        current = next;
    }
    return hull;
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
    set<point> hull;
    hull = convex_hull(v);
    cout<<hull.size()<<endl;
    for(point p : hull) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}