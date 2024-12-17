#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; continue;}
#define no {cout<<"NO\n"; continue;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

//seems like i cant afford n*m
// very good question

class Solution {
    multiset<int> availableRow, availableCol;
    bool check(int num) {
        bool isNeg = num < 0;
        if(num < 0)
            num *= -1;
        
        for(int i = 1; i*i <= num; i++) {
            if(num % i == 0 && !isNeg) {
                // cout<<"Factors of target "<<num<<" are "<<i<<" , "<<(num/i)<<endl;
                int other = num/i;
                //both positive
                if((exists(availableRow, i) && exists(availableCol, other)) || (exists(availableCol, i) && exists(availableRow, other))) {
                    return true;
                }
                // both negative
                if((exists(availableRow, -i) && exists(availableCol, -other)) || (exists(availableCol, -i) && exists(availableRow, -other))) {
                    return true;
                }
            }
            else if(num % i == 0 && isNeg) {
                // cout<<"Factors of target "<<num<<" are "<<i<<" , "<<(num/i)<<endl;
                int other = num/i;
                //first negative
                if((exists(availableRow, -i) && exists(availableCol, other)) || (exists(availableCol, -i) && exists(availableRow, other))) {
                    return true;
                }
                //second negative
                if((exists(availableRow, i) && exists(availableCol, -other)) || (exists(availableCol, i) && exists(availableRow, -other))) {
                    return true;
                }
            }
        }
        return false;
    }
    public:
    void solve() {
        int n, m, q;
        cin >> n >> m >> q;
        array(int, a, n);
        array(int, b, m);
        int bTotal = accumulate(all(b), 0ll);
        int aTotal = accumulate(all(a), 0ll);
        int totalSum = aTotal*bTotal;
        // cout<<"Rows : ";
        for(int i = 0; i < n; i++) {
            int currA = aTotal - a[i];
            availableRow.insert(currA);
            // cout<<currA<<" ";
        }
        // cout<<endl<<"Cols : ";
        for(int i = 0; i < m; i++) {
            int currB = bTotal - b[i];
            availableCol.insert(currB);
            // cout<<currB<<" ";
        }
        cout<<endl;

        while(q--) {
            int query;
            cin >> query;
            if(query == 0) {
                if(exists(availableRow, 0) || exists(availableCol, 0))
                    yes;
                no;
            }

            if(check(query))
                yes;
            no;
        }
        // pn(totalSum)
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
