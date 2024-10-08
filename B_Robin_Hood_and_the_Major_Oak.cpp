#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        int firstYear = n - k + 1;
        int lastYear = n;
        int totalOdds = 0;


        if(firstYear == lastYear) {
            if(n % 2 == 0){
                yes;}
            else{
            no;}
        }

        if(firstYear % 2) {
            totalOdds++;
            firstYear++;
        }
        if(lastYear % 2 && firstYear < lastYear) {
            totalOdds++;
            lastYear--;
        }
        int diffYears = max(lastYear - firstYear, 0);
        totalOdds += diffYears / 2;

        

        if(totalOdds % 2){
            no;}
        yes;

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

