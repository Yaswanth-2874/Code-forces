#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define num(n) {cout<<n<<endl; return;}

// LOGIC WAS SO FREAKING EASY BUT I DIDNT COME UP WITH THIS :(
class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        input(nums);

        int maxi = *max_element(all(nums));
        int sum = accumulate(all(nums), k);

        for(int i = n; i >= 1; i--) {
            int groups = sum / i;
            int extraCards = sum % i;
            // EXTRA MEMBERS ARE THE ONES THAT ARE LEFT OVER
            // cout<<"GROUPS : "<<groups<<endl;
            // SKIP CASE WHEN MAX OCCURANCE OF ONE PARTICULAR CARD IS GREATER THAN NUMBER OF SPLIT GROUPS
            //  SKIP WHEN MORE THAN K EXTRA CARDS ARE LEFT BCS IT MEANS WE ARE NOT USING ALL OUR CARDS
            if(maxi > groups || extraCards > k)
                continue;
            num(i);
        }
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

