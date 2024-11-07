#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;
        vector<int> p(n + 1); // Use 1-based indexing
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        vector<bool> visited(n + 1, false);
        int operations = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                // Start a new cycle
                int cycle_length = 0;
                int current = i;
                bool can_form_pair = false;

                while (!visited[current]) {
                    visited[current] = true;
                    cycle_length++;
                    
                    if (p[p[current]] == current) {
                        can_form_pair = true; // Found a pair that can swap
                    }
                    
                    current = p[current];
                }

                if (cycle_length > 1) {
                    operations += (cycle_length - 1); // To fix the cycle
                    if (can_form_pair) {
                        operations--; // One less operation if a pair can be swapped
                    }
                }
            }
        }

        cout << operations << endl;
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
