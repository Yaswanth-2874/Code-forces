#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    int n;
    int midPerson;
    

    bool shouldRobinVisit(int totalWealth, int x, vector<int>& wealth) {
        totalWealth += x;
        double averageWealth = totalWealth / (double)n;
        if((double)(wealth[midPerson]) < averageWealth/2.0)
            return true;
        return false;
    }
    public:
    void solve() {
        cin >> n;
        midPerson = n/2;
        int totalWealth = 0;
        vector<int> wealth(n);

        for(int i = 0; i < n; i++) {
            cin>>wealth[i];
            totalWealth += wealth[i];
        }

        if(n == 1 || n == 2) {
            cout<<-1<<endl;
            return;
        }

        sort(all(wealth));
        int left = 0, right = LLONG_MAX;
        while(left <= right) {
            int mid = left + (right - left)/2;
            // cout<<mid<<" ";
            if(shouldRobinVisit(totalWealth, mid, wealth)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout<<right+1<<endl;

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

