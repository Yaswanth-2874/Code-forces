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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        int limit = (n * (n - 1))/2;

        if(k > limit)
            pn(-1);
        
        int toRemove = limit - k;
        int currentSum = limit;



    }
};

vector<int> generatePrimes(int count) {
    int l = 1299710;
    vector<bool> primeNumbers(l, true);
    vector<int> primes;
    primeNumbers[0] = primeNumbers[1] = false;
    for (int i = 2; i < l && primes.size() < count; ++i) {
        if (primeNumbers[i]) {
            primes.push_back(i);
            for (int j = i * i; j < l; j += i) {
                primeNumbers[j] = false;
            }
        }
    }
    return primes;
}

int32_t main() {
    vector<int> primes = generatePrimes(1e5);
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
