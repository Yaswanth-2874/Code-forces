#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int l, r, L, R;
    cin>>l>>r;
    cin>>L>>R;

    int commonRooms = max(0, min(r, R) - max(l, L) + 1);
    if(!commonRooms)
        cout<<1<<endl;
    else {
        if(l == L && r == R) {
            cout<<(commonRooms - 1)<<endl;
        }
        else if(l == L || r == R) {
            cout<<commonRooms<<endl;
        }
        else {
            cout<<(commonRooms + 1)<<endl;
        }
    } 
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
