#include<bits/stdc++.h>
using namespace std;
int number_of_triangle(int a1, int a2, int a3, int a4, int a5, int a6) {
    return (a1+a2+a3)*(a1+a2+a3) - (a1*a1+a3*a3+a5*a5);
}
int main() {
    int a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    cout<<number_of_triangle(a1,a2,a3,a4,a5,a6);
    return 0;
}