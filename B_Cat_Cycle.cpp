#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

// 5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
// 1 2 4 5 2 3 5 1 3 4 1 2 4 5 2
// Calc total meetings and then print position
// If n is even, never meets

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        if(n % 2 == 0) {
            if(k % n == 0)
                cout<<n<<endl;
            else
                cout<<(k % n)<<endl;
            return;
        }

        int meetingGap = (n+1)/2;
        int totalMeetings = 0;

        if(meetingGap == 1) {
            totalMeetings = k;
        } else if(k >= meetingGap) {
            totalMeetings =  1 + (k-meetingGap)/(meetingGap - 1);
        }

        k += totalMeetings;
        if(k % n == 0)
            cout<<n<<endl;
        else
            cout<<k % n<<endl;
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
