#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int ones, twos;
    cin>>ones>>twos;

    if(ones % 2 == 0 && twos % 2 == 0) {
        cout<<"YES"<<endl;
        return;
    }
    if(twos % 2 != 0) {
        if(ones >= 2 && ones % 2 == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        return;
    }
    if(ones % 2 != 0)
        cout<<"NO"<<endl;

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
