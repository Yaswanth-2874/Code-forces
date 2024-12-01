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

// First question after i reached specialist :)

// Code is so messy, resubmit it again later
// Seems easy, hope no silly mistakes
// DAMN IT DONT ERASE FROM A MAP.. EVEN IF MY LOGIC IS CORRECT IT COULD POTENTIALLY CAUSE ISSUES

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        map<int, int> freq;
        vector<int> v(n);
        input(v);
        for(int& num : v)
            freq[num]++;
        map<int, int> freqOfFreq;

        for(auto& [num, f] : freq) {
            freqOfFreq[f]++;
        }

        int ans = 0;
        set<int> availableFreq;
        for(int i = 1; i <= n+1; i++) {
            availableFreq.insert(i);
        }

        for(auto& [num, f] : freqOfFreq) {
            // cout<<"Freq : "<<num<<" and freq of freq is "<<f<<endl;
            f--;
            ans += num;
            availableFreq.erase(num);
            // if(f == 0)
            //     freqOfFreq.erase(num);
        }

        for(auto& [num, f] : freqOfFreq) {
            
            while(f--) {
                auto lowerBoundIterator = availableFreq.lower_bound(num);
                // cout<<"Lower bound of "<<num<<" is "<<*lowerBoundIterator<<endl;
                if(*lowerBoundIterator > num) {
                    if(lowerBoundIterator == availableFreq.begin())
                        break;
                    lowerBoundIterator = prev(lowerBoundIterator);
                    // cout<<"New Lower Bound : "<<*lowerBoundIterator<<endl;
                    int val = *lowerBoundIterator;
                    ans += val;
                    availableFreq.erase(val);
                } else {
                    ans += num;
                    availableFreq.erase(num);
                }
            }
        }
        pn(ans);
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
