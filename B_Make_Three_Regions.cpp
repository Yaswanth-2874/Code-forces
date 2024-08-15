#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int size;
    cin>>size;

    string up, down;
    cin>> up>>down;

    ll ans = 0;

    for(int i = 1; i < size - 1; i++) {
        if(up[i] == '.' && up[i + 1] == '.' && up[i - 1] == '.') {
            if(down[i-1] == 'x' && down[i+1] == 'x' && down[i] == '.')
                ans++;
        }
        if(down[i] == '.' && down[i + 1] == '.' && down[i - 1] == '.') {
            if(up[i-1] == up[i+1] && up[i-1] == 'x' && up[i] == '.')
                ans++;
        }
    }
    cout<<ans<<endl;
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
