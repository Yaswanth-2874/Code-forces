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

class Solution {
    public:
    void solve() {
        int extraMoves = 0;
        int erased = 0;
        map<int, int> freq;
        int n, k;
        cin >> n >> k;
        int size = n;
        vector<int> nums(n);
        input(nums);
        for(int num : nums)
            freq[num]++;
        int ok = k;
       
       while(!freq.empty()) {
            auto minFreq = freq.begin();
            freq.erase(minFreq);
            
            int mini = minFreq->first - erased;
            int frequ = minFreq->second;
            
            

            if(mini != 0 && size > INT_MAX/mini)
                break;

            int total = mini * size;
            // maybe total overflows

            if(total >= k)
                break;
            // cout<<"got total "<<total<<endl;
            size -= frequ;
            // cout<<"extra moves : "<<frequ<<endl;
            extraMoves += frequ;
            // cout<<"need extra : "<<(k-total)<<" in size : "<<size<<endl;
            erased += mini;
            k -= total;
       }

       cout<<ok + extraMoves<<endl;
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

