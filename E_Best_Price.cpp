#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_multiset tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long

using namespace std;
using namespace __gnu_pbds;

class Solution {
    ordered_multiset s1, s2;
    int n, k;
    int findSales(int sellingPrice) {
        auto upperIt = s1.lower_bound({sellingPrice, -69});
        int positiveReviews = 0;
        // cout<<"Selling price is "<<sellingPrice<<endl;

        if(upperIt != s1.end()) {
            positiveReviews = n - s1.order_of_key(*upperIt);
        } else {
            positiveReviews = 0;
        }

        auto upperIt2 = s2.lower_bound({sellingPrice, -69});
        int negativeReviews = 0;
        
        if(upperIt2 != s2.end()) {
            // cout<<"Next price is "<<upperIt2->first<<endl;
            int maxSales = n - s2.order_of_key(*upperIt2); // number of people who are going to buy this product for given price
            negativeReviews = maxSales - positiveReviews;
        } else {
            negativeReviews = 0;
        }

        // cout<<positiveReviews<<" and "<<negativeReviews<<endl;

        if(negativeReviews > k)
            return -1;

        int currSales = sellingPrice * (positiveReviews + negativeReviews);
        return currSales;
    }
    public:
    void solve() {
        cin >> n >> k;

        vector<int> a(n), b(n);
        int index = 0;

        for(auto& input : a) {
            cin >> input;
            s1.insert({input, index++});
        }
        index = 0;

        for(auto& input : b) {
            cin >> input;
            s2.insert({input, index++});
        }

        int maxSales = 0;

        for(int i = 0; i < n; i++) {
           maxSales = max(maxSales, findSales(a[i]));
           maxSales = max(maxSales, findSales(b[i]-1));
           maxSales = max(maxSales, findSales(b[i]));
        }
        {
            cout<<maxSales<<endl;
            return;
        }
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
