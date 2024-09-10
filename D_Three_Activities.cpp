#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array, size) for(int i = 0; i < size; i++)cin>>array[i];

void solve() {
    int days;
    cin>>days;
    vector<vector<pair<int, int>>> friends(3, vector<pair<int, int>> (days));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < days; j++) {
            int num;
            cin>>num;
            friends[i][j] = {num, j};
        }
    }

    for(auto& day : friends) {
        sort(full(day), greater<pair<int, int>> ());
    }

    int ans = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(friends[0][i].second != friends[1][j].second && friends[1][j].second != friends[2][k].second && friends[0][i].second != friends[2][k].second) {
                    ans = max(ans , friends[0][i].first + friends[1][j].first + friends[2][k].first);}
            }
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
