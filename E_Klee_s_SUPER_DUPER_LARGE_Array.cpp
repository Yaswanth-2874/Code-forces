#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array, size) for(int i = 0; i < size; i++)cin>>array[i];

ll calculateFunction(ll x, ll n, ll k) {
    return (2 * x * x + x * (4 * k - 2) + (n - n * n - 2 * k * n)) / 2;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll discriminant = 4 * k * k + 4 * k * (n - 1) + (2 * n * n - 2 * n + 1);
    ll index = (floor(sqrt(discriminant)) - (2 * k - 1)) / 2;

    ll result = min(abs(calculateFunction(index, n, k)), abs(calculateFunction(index + 1, n, k)));
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
