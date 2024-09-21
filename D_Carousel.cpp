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

        int prev = -1;
        vector<int> nums(n);
        input(nums);

        set<int> uniqueNumbers(full(nums));
        vector<int> colors(n, 1);
        if(uniqueNumbers.size() == 1) {
            cout<<1<<endl;
            print(colors);
            return;
        }

        if(n % 2 == 0) {
            cout<<2<<endl;
            for(int i = 0; i < n; i++)
                cout<<(i % 2) + 1<<" ";
            return;
        }

        int equalPairs = 0;

        for(int i = 1; i < n; i += 2) {
            if(nums[i] == nums[i-1])
                equalPairs++;
        }

        if(equalPairs % 2) {
            cout<<2<<endl;
            int prev = 1;
            for(int i = 1; i < n; i += 2) {
                if(nums[i] == nums[i-1]) {
                    cout<<(prev+1)%2<<(prev+1)%2<<" ";
                }
            }
        }





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
