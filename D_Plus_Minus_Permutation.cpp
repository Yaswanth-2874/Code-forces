#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array, size) for(int i = 0; i < size; i++)cin>>array[i];


ll sum(ll n) {
    return n * (n+1) / 2;
}
void solve() {
    ll n, x, y;
    cin>>n>>x>>y;

    ll count1 = 0, count2 = 0; 

    count1 = n / x;
    count2 = n / y;
    ll common = n/lcm(x, y);
    count1 -= common;
    count2 -= common;
    
    ll maxNumber = sum(n) - sum(n - count1);
    ll minNumber = sum(count2);

    cout<<maxNumber - minNumber<<endl;
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

// 12 + 11 - 1 - 2- 3- 4
// 23 - 10