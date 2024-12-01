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

class Solution {
    int count = 0;
    int generateNumbers(int l, int r) {
        int conse = 1;
        while(conse < 17) {
            // cout<<conse<<endl;
            int bitIndex = 0;
            bool bit = true;
            set<int> foundValues;
            int number = 0;

            while(bitIndex < 32) {
                int copyConse = conse;
                // cout<<"Value before is "<<number<<endl;
                number <<= conse;
                while(copyConse--) {
                    if(bit)
                        number += 1ll << (bitIndex % conse);
                    bitIndex++;
    
                }

                cout<<"Value is "<<number<<" and consecutive is "<<conse<<endl;
            
                if(exists(foundValues, number) == false && number >= l && number <= r) {
                    count++;
                    // cout<<"Valid : "<<number<<endl;
                    foundValues.insert(number);
                }
                
                bit = !bit;
            }
            conse++;
        }

        cout<<count<<endl;
        return count;
    }
    public:
    void solve() {
        int l, r;
        cin >> l >> r;

        // First consider something like 1, 11, 111, 111 -> 32 atmost
        // Then consider something like 10, 101, 1010, 10101 ...
        // Then consider something like 1100, 110011 ...
        // Then 111000,111000111 ... 
        generateNumbers(l, r);
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
