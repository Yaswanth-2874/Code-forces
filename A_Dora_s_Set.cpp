#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int l, r;
    cin>>l>>r;
    if(l % 2 == 0)
        l++;
    if(r % 2 == 0)
        r--;
    int count = r-l+1;
    count = ceil(count/2.0);
    count /= 2;
    cout<<count<<endl; 
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

