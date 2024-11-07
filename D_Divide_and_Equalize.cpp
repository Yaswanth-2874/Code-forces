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

// 100 2 50 10 1 can  be written as
// 100 = 2 * 2 * 5 * 5
// 2 = 2
// 50 = 2 * 5 * 5
// 10 = 2 * 5
// 1 = 1

// now if i store all factors in map, i get 5 2's and 5 5's
// I need to check if all these numbers are divisible by rowsize or not

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);

        map<int, int> freq;
        for(int num : nums) {
            int originalNum = num;
            for(int i = 2; i <= sqrtl(originalNum); i++) {
                while(num > 1 && num % i == 0) {
                    num /= i;
                    freq[i]++;
                }
                if(num <= 1)
                    break;
            }
            // Demn i was instantly able to come up with the approach but i could not optimise this part properly
            if(num > 1) //This line is so op
                freq[num]++;
        }
        for(auto& [number, occurances] : freq) {
            if(occurances % n)
                no;
        }
        yes;

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

