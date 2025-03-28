#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    class SegmentTree {
        vector<int> segTree, source;
        int n;
    public:
        SegmentTree(vector<int>& source) {
            n = source.size();
            this->source = source;
            segTree.resize(4 * n);
            buildTree(0, 0, n - 1);
        }
    
        int buildTree(int index, int left, int right) {
            if (left == right) {
                return segTree[index] = source[left];
            }
            int mid = left + (right - left) / 2;
            return segTree[index] = min(buildTree(index * 2 + 1, left, mid), buildTree(index * 2 + 2, mid + 1, right));
        }
    
        int findMin(int index, int left, int right, int l, int r) {
            if (left > r || right < l) {
                return INT_MAX;
            }
            if (left >= l && right <= r)
                return segTree[index];
    
            int mid = left + (right - left) / 2;
            return min(findMin(index * 2 + 1, left, mid, l, r), findMin(index * 2 + 2, mid + 1, right, l, r));
        }
    
        void update(int index, int left, int right, int updateIndex, int updateVal) {
            if (left == right) {
                source[left] = segTree[index] = updateVal;
                return;
            }
            int mid = left + (right - left) / 2;
            if (updateIndex <= mid) {
                update(index * 2 + 1, left, mid, updateIndex, updateVal);
            } else {
                update(index * 2 + 2, mid + 1, right, updateIndex, updateVal);
            }
            segTree[index] = min(segTree[index * 2 + 1], segTree[index * 2 + 2]);
        }

        int query(int l, int r) {
            return findMin(0, 0, n - 1, l, r);
        }

        void updateValue(int updateIndex, int updateVal) {
            update(0, 0, n - 1, updateIndex, updateVal);
        }
    };
    public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;

        vector<pair<int, int>> v;
        for(int i = 0; i < fruits.size(); i++) {
            v.push_back({baskets[i], i});
        }
        sort(begin(v), end(v));
        vector<int> segSource;
        unordered_map<int, set<int>> indexMap;

        for(int i = 0; i < n; i++) {
            segSource.push_back(v[i].second);
            indexMap[v[i].second].insert(i);
        }
        
        SegmentTree st(segSource);
        int last = n-1;
        // for(int i = 0; i < n; i++) {
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }

        for(int fruit : fruits) {
            int bestStartIndex = lower_bound(begin(v), end(v), make_pair(fruit, -1)) - begin(v);
            if(bestStartIndex > last) {
                unplaced++;
                continue;
            } 
            int miniIndex = st.query(bestStartIndex, last);
            // cout<<miniIndex<<" will be erased"<<endl;
            
            if(miniIndex == INT_MAX)
                unplaced++;
            else {
                int index = *indexMap[miniIndex].begin();
                st.updateValue(index, INT_MAX);
                
                indexMap[miniIndex].erase(index);
            }
        }
        return unplaced; 
    }
    void solve() {
        set<pair<int, int>> v;

        
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
