#include <bits/stdc++.h>
#define int long long
using namespace std;


vector<int> primes;
vector<int> sieve(int n) {
    vector<bool> prime(n+1, true);
    prime[1] = false;
    for(int i = 2; i*i <= n; i++) {
        for(int j = 2*i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(prime[i])
            primes.push_back(i);
    }

    return primes;
}

class Solution {
    vector<int> mexp;
    void dfs(int start, vector<vector<int>>& tree, vector<bool>& visited, int mini, int& cost) {
        if(visited[start])
            return;
        visited[start] = true;
        cost += mini;

        for(int child : tree[start]) {
            dfs(child, tree, visited, min(mini, mexp[child - 1]), cost);
        }

    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        mexp.resize(n);
        for(int index = 0; index < n; index++) {
            for(int i = 0; i < primes.size(); i++) {
                if(v[index] % primes[i]) {
                    mexp[index] = primes[i];
                    break; 
                }
            }
        }

        // for everynumber i have its mexp

        vector<vector<int>> tree(n+1);
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int cost = 0;

        for(int i = 1; i <= n; i++) {
            vector<bool> visited(n, false);
            int ans = 0;
            dfs(i, tree, visited, mexp[i-1], ans);
            cout<<ans<<" ";
        }
        cout<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int testCases = 1;
    cin >> testCases;

    primes = sieve(1e5);

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
