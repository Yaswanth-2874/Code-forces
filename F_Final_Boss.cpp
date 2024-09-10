#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()


bool canKillBoss(ll hp, ll time, vector<int>& dmg, vector<int>& cooldown) {
    ll damage = 0;
    for(int i = 0; i < dmg.size(); i++) {
        ll attacks = (ll)(time + cooldown[i] - 1) / cooldown[i];
        if(attacks > INT_MAX/dmg[i])
            return true;
        if(damage > INT_MAX- (attacks*dmg[i]))
            return true;
        damage += attacks * dmg[i];
        
        if(damage >= hp)
            return true;
    }
    return false;
}

void solve() {
    int health, attacks;
    cin>>health>>attacks;

    vector<int> damage(attacks), cooldown(attacks);
    for(int i = 0; i < attacks; i++)
        cin>>damage[i];
    for(int i = 0; i < attacks; i++)
        cin>>cooldown[i];

    ll left = 1, right = LLONG_MAX - 1, turns = 0;

    while(left <= right) {
        ll mid = left + (right - left)/2;
        if(canKillBoss(health, mid, damage, cooldown)) {
            turns = mid;
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }

    cout<<turns<<endl;
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
