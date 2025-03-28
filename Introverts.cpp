#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, i;
    cin >> n;
    vector<int> p(n);
    for(i=0; i<n; i++) cin >> p[i];
    
    if(n < 3) return true;
    
    if(!(p[0]==1 && p.back()==2) && !(p[0]==2 && p.back()==1)) return false;
    
    vector<int> idxs(n);
    for(i=0; i<n; i++) {
        idxs[p[i]-1] = i;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({n-1, {0, n-1}});
    
    for(i=2; i<n; i++) {
        int diff = pq.top().first;
        if(diff <= 3) break;
        bool flag = false;
        queue<pair<int, pair<int, int>>> q;
        while(!pq.empty() && pq.top().first==diff) {
            q.push(pq.top());
            pq.pop();
        }
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.second.first, y = it.second.second;
            if((x+diff/2) == idxs[i]) {
                flag = true;
                pq.push({diff/2, {x, x+diff/2}});
                pq.push({y-x-diff/2, {x+diff/2, y}});
            } else if((y-diff/2) == idxs[i]) {
                flag = true;
                pq.push({y-x-diff/2, {x, y-diff/2}});
                pq.push({diff/2, {y-diff/2, y}});
            } else {
                pq.push(it);
            }
        }
        if(!flag) return false;
    }
    return true;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}

// 1 6 7 4 8 9 3 10 5 11 12 2Sy