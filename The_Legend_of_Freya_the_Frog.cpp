#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array, size) for(int i = 0; i < size; i++)cin>>array[i];

void solve() {
    int a, b, c;
    cin>>a>>b>>c;

    ll stepsForX = ((ll)(a + c - 1) /c);
    ll stepsForY =((ll)(b + c - 1)/c);
    ll ans = stepsForX + stepsForY;
    ll extraSteps = stepsForX - stepsForY;
    if(extraSteps > 0)
        ans += extraSteps - 1;
    else 
        ans += abs(extraSteps);
    
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
