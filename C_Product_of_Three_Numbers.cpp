#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n";}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end() 

// Find all the prime factors of n;
// generate three unique numbers using these prime factors
// Seems easy enough, lets see for edge cases

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        map<int, int> factors;
        int numCopy = n;
        int count = 0;

        for(int i = 2; i*i <= numCopy; i++) {
            while(n % i == 0) {
                n /= i;
                factors[i]++;
                count++;
            }
        }
        if(n > 1) {
            factors[n]++;
            count++;
        }

        if(factors.size() >= 3) {
            yes;
            int numA = factors.begin()->first;
            factors.erase(numA);
            int numB = factors.begin()->first;
            cout<<numA<<" "<<numB;
            numCopy /= numA;
            numCopy /= numB;
            cout<<" "<<numCopy<<endl;
            return;
        }

        if(factors.size() == 2) {
            if(count < 4)
                no;
            yes;
            int numA = factors.begin()->first;
            factors.erase(numA);
            int numB = factors.begin()->first;
            cout<<numA<<" "<<numB;
            numCopy /= numA;
            numCopy /= numB;
            cout<<" "<<numCopy<<endl;
            return;
        }

        if(count < 6)
            no;
        yes;
        int numA = factors.begin()->first;
        int numB = numA * numA;
        cout<<numA<<" "<<numB;
        numCopy /= numA;
        numCopy /= numB;
        cout<<" "<<numCopy<<endl;
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