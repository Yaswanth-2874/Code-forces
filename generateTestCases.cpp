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
#define array(name, size) vector<int> v(size); input(v);
#pragma endregion

class Solution {
    void generateRandom(int n)
{
    vector<int> v(n);

    // Fill the vector with the values
    // 1, 2, 3, ..., n
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
 
    // While vector has elements
    // get a random number from the vector and print it
    while (v.size()) {
        cout << getNum(v) << " ";
    }
}
int getNum(vector<int>& v)
{
 
    // Size of the vector
    int n = v.size();
 
    // Generate a random number
 
    // Make sure the number is within
    // the index range
    int index = rand() % n;
 
    // Get random number from the vector
    int num = v[index];
 
    // Remove the number from the vector
    swap(v[index], v[n - 1]);
    v.pop_back();
 
    // Return the removed number
    return num;
}
    public:
    void solve() {
        int n = rand() % 100 + 1;

        cout<<n<<endl;
        generateRandom(n);
        cout<<endl;

    }
};


int32_t main() {
    srand(static_cast<unsigned int>(time(0)));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 100;
    cin >> t;
    cout<<t<<endl;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
