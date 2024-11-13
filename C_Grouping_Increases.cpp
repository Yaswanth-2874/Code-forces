#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

// needed to write extra conditions when the current number is equal to top element(s)

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> v(n);
        input(v);
        // I need to insert every single element in either the first or second subseq
        // Use greedy

        vector<int> first, second;
        int ans = 0;
        first.push_back(LLONG_MAX);
        second.push_back(LLONG_MAX);

        for(int& num : v) {
           int firstTop = first.back();
           int secondTop = second.back();

            if((num > firstTop && num > secondTop) || (num < firstTop && num < secondTop)) {
                if(firstTop > secondTop) {
                    second.push_back(num);
                    // cout<<"Inserted "<<num << " in second"<<endl;
                }
                else {
                    first.push_back(num);
                    // cout<<"Inserted "<<num <<" in first"<<endl;
                }
                ans += (num > firstTop && num > secondTop);
                continue;
            }
            // if control reached here, it means num is smaller than either first or second
            if(num == firstTop) {
                first.push_back(num);
                continue;
            }

            if(num == secondTop) {
                second.push_back(num);
                continue;
            }

            if(num > firstTop) {
                second.push_back(num);
                // cout<<"Inserted "<<num << " in second"<<endl;
            }
            else {
                first.push_back(num);
                // cout<<"Inserted "<<num <<" in first"<<endl;
            }
        }
        // print(first);
        // print(second);

        pn(ans)
        

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
