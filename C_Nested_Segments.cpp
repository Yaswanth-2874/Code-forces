#include <bits/stdc++.h>
#define int long long
using namespace std;

// lmao i dont need to think that much, simply use seg trees

class Solution {
    class SegmentTree {
        vector<int> segTree, source;
        int n;
        public:
        SegmentTree(vector<int>& source) {
            n = source.size();
            this->source = source;
            segTree.resize(4 * n);
            build(0, 0, n-1);
        }
        int build(int index, int left, int right) {
            if(left == right) {
                return segTree[index] = source[left];
            }
            int mid = left + (right - left)/2;
            return segTree[index] = min(build(index * 2 + 1, left, mid), build(index * 2 + 2, mid+1, right));
        }
        int query(int index, int left, int right, int l, int r) {
            if(left > r || right < l)
                return LLONG_MAX;
            if(left >= l && right <= r)
                return segTree[index];
            int mid = left + (right - left)/2;
            return min(query(index * 2 + 1, left, mid, l, r), query(index * 2 + 2, mid+1, right, l, r));
        }
    };
    // bool comp(pair<int, int>& v1, pair<int, int>& v2) {
    //     if (v1.first != v2.first)
    //         return v1.first < v2.first; 
    //     return v1.second > v2.second;
    // }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> ranges;
        vector<int> endPoints;
        map<pair<int, int>, int> reverseMap;
        
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            ranges.push_back({l, r});
            if(reverseMap.find({l, r}) != reverseMap.end()) {
                cout<<i+1<<" "<<reverseMap[{l, r}];
                return;
            }
            reverseMap[{l, r}] = i+1;

        }

        sort(ranges.begin(), ranges.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        for(int i = 0; i < n; i++)
            endPoints.push_back(ranges[i].second);
        SegmentTree st(endPoints);

        for(int i = 0; i < n; i++) {
            auto [currStart, currEnd] = ranges[i];
            int endIndex = upper_bound(begin(ranges), end(ranges), make_pair(currEnd+1, -69ll)) - begin(ranges) - 1ll;
            int minVal = st.query(0, 0, n-1, i+1, endIndex);
            if(minVal <= currEnd) {
                for(int j = i+1; j < n; j++) {
                    if(ranges[j].second == minVal) {
                        cout<<reverseMap[{ranges[j].first, ranges[j].second}]<<" "<<reverseMap[{currStart, currEnd}]<<endl;
                        return;
                    }
                }
            }
        }

        cout<<"-1 -1"<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}