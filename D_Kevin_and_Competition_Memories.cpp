#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma region Macros
    #define MOD 1000000007
    #define int long long
    #define yes {cout<<"YES\n"; return;}
    #define no {cout<<"NO\n"; return;}
    #define all(array) array.begin(), array.end()
    #define input(array) for(auto& d : array)cin>>d;
    #define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
    #define pn(num){cout<<num<<endl; return;}
    #define minHeap(var) var, vector<var>, greater<var>
    #define exists(map, num) map.find(num) != map.end()
    #define array(type, name, size) vector<type> name(size); input(name);
    #define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
    #define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
    #define ordered_multiset tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#pragma endregion

// source of resource is https://www.geeksforgeeks.org/iterative-segment-tree-range-maximum-query-with-node-update/

class Solution {

        void construct_segment_tree(vector<int>& segtree,
                                vector<int>& a, int n)
    {
        // assign values to leaves of the segment tree
        for (int i = 0; i < n; i++)
            segtree[n + i] = a[i];
    
        /* assign values to internal nodes
        to compute maximum in a given range */
        for (int i = n - 1; i >= 1; i--)
            segtree[i] = max(segtree[2 * i],
                            segtree[2 * i + 1]);
    }
    
    void update(vector<int>& segtree, int pos, int value,
                int n)
    {
        // change the index to leaf node first
        pos += n;
    
        // update the value at the leaf node
        // at the exact index
        segtree[pos] = value;
    
        while (pos > 1) {
    
            // move up one level at a time in the tree
            pos >>= 1;
    
            // update the values in the nodes in
            // the next higher level
            segtree[pos] = max(segtree[2 * pos],
                            segtree[2 * pos + 1]);
        }
    }
    
    int range_query(vector<int>& segtree, int left, int
                                                        right,
                    int n)
    {
        /* Basically the left and right indices will move
            towards right and left respectively and with
            every each next higher level and compute the 
            maximum at each height. */
        // change the index to leaf node first
        left += n;
        right += n;
    
        // initialize maximum to a very low value
        int ma = INT_MIN;
    
        while (left < right) {
    
            // if left index in odd
            if (left & 1) {
                ma = max(ma, segtree[left]);
    
                // make left index even
                left++;
            }
    
            // if right index in odd
            if (right & 1) {
    
                // make right index even
                right--;
    
                ma = max(ma, segtree[right]);
            }
    
            // move to the next higher level
            left /= 2;
            right /= 2;
        }
        return ma;
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        array(int, rating, n);
        array(int, diff, m);
        vector<int> ans;

        int kevinRating = rating[0];
        vector<int> required;
        ordered_multiset st;

        for(int i = 0; i < n; i++) {
            st.insert({rating[i], i});
        }

        vector<int> solArray;
        solArray.clear();
        for(int& d : diff) {
            if(d <= kevinRating) {
                solArray.push_back(1);
            } else {
                required.push_back(d);
            }
        }

        
        sort(all(required), greater<int> ());
        for(int& r : required) {
            auto it = st.lower_bound({r, -69});
            if(it == st.end()) {
                solArray.push_back(1);
                continue;
            }
            int position = (n -  st.order_of_key(*it)) % n;
            solArray.push_back(position + 1);
        }

        vector<int> segTree(2*solArray.size());
        construct_segment_tree(segTree, solArray, solArray.size());
        // print(segTree);
        
        // print(solArray)
        int increase = 1;
        for(int i = 0; i < m; i++) {
            int sum = 0;
            for(int k = 0; k < m; k+=increase) {
                int kEnd = k+increase-1;
                if(k == kEnd) {
                    sum += solArray[k];
                    continue;
                }
                // cout<<"Range is "<<k<<" "<<kEnd<<endl;
                if(kEnd >= m)
                    break;
                // cout<<"Max is "<<range_query(segTree, k+1, kEnd+1, solArray.size())<<endl;
                sum += range_query(segTree, k+1, kEnd+1, solArray.size());
            }
            if(sum == 0)
                break;
            cout<<sum<<" ";

            increase++;
        }
        cout<<endl;
     
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
