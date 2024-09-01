#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n, m;
    cin>>n>>m;

    set<ll> pq;

    for(int i = 0; i < n; i++) {
        int num;
        cin>>num;
        pq.insert(num);
    }

    while(m--) {
        char ch;
        int l, r;
        cin>>ch>>l>>r;
        ll highest = *(--pq.end());
        if(highest >= l && highest <= r) {
            int operation = ch == '+' ? 1 : -1;
            pq.erase(highest);
            pq.insert(highest + operation);
        }
        cout<<*(--pq.end())<<" ";
    }
    cout<<endl;
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
