#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int left , right;
    cin>>left>>right;
    int size = 0;
    int difference = 1;
    while(left <= right) {
        size++;
        left += difference++;
    }
    cout<<size<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
