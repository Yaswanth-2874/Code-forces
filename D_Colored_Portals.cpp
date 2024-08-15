#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

vector<ll> dijkstra(const vector<vector<ll>>& graph, int start, int n) {
    vector<ll> dist(n + 1, LLONG_MAX); 
    vector<bool> visited(n + 1, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        ll current = pq.top().second;
        ll currentDist = pq.top().first;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (ll neighbor : graph[current]) {
            ll newDist = currentDist + abs(current - neighbor);
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }

    return dist;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> graph(n + 1);
    map<char, vector<ll>> mp;

    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        
        for (char ch : st) {
            if (mp.find(ch) != mp.end()) {
                for (ll num : mp[ch]) {
                    graph[i + 1].push_back(num);
                    graph[num].push_back(i + 1);
                }
            }
            mp[ch].push_back(i + 1);
        }
    }

    vector<vector<ll>> distanceMatrix(n + 1);

    for (int i = 1; i <= n; ++i) {
        distanceMatrix[i] = dijkstra(graph, i, n);
    }

    while (q--) {
        int city1, city2;
        cin >> city1 >> city2;
        if (distanceMatrix[city1][city2] == LLONG_MAX) {
            cout << -1 << endl; // If the city is not reachable
        } else {
            cout << distanceMatrix[city1][city2] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}