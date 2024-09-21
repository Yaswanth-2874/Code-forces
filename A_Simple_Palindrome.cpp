#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n;
        cin>>n;

        vector<char> vowels = {'a', 'e', 'i', 'o' ,'u'};
        int index = 0;

        int repeats = n/5;
        int remaining = n % 5;

        while(n) {
            int moves = repeats;
            if(remaining > 0) {
                remaining--;
                moves += 1;
            }
            n -= moves;
            while(moves--) {
                cout<<vowels[index];
            }
            index++;
        }
        cout<<endl;
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}
