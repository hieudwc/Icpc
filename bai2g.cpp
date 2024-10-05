#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> b;
    for(int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]){
            int x = a[i] + a[i+1];
            a[i+1] = x;
            b.push_back(x);
        }
        else b.push_back(a[i]);
    }
    for(auto i : b){
        cout << i << ' ';
    }
}