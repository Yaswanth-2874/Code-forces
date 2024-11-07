#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

// 0 1 0 0 1 0
// Select the largest Gap
// Any gap can be filled in 2 days and 1 person gets the virus(if gap >= 1)
// In the mean while(in those 2 days), at every place, 4 new people get infected


class Solution {
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        vector<int> nums(m);
        input(nums);
        // N value is min 5, if there is one person, then infection will spread to atleast 1 more
        if(m == 1)
            pn(min(n, 2LL))

        sort(all(nums));
        priority_queue<int> gaps;

        for(int i = 0; i < m; i++) {
            if(i == m-1) 
                gaps.push(n - nums[i] + nums[0] - 1);
            else
                gaps.push(nums[i+1] - nums[i] -  1);
        }
        int reduceGapSize = 0;
        int savedPeople = 0;

        while(!gaps.empty()) {
            int biggestGap = gaps.top();
            gaps.pop();
            int canSave =  (biggestGap - reduceGapSize - 1);
            if(!canSave)
                canSave = 1;

            if(canSave <= 0)
                break;
            savedPeople += canSave;
            reduceGapSize += 4;
        }
        pn(n - savedPeople)

    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

