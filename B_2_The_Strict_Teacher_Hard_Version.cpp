#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

class Solution {

    pair<int, int> findClosestTeachers(vector<int>& teacherPos, int davidPos) {
        int l = 0;
        int r = teacherPos.size() - 1;
        if(teacherPos[0] > davidPos) {
            return {teacherPos[0], teacherPos[0]};
        }
        if(teacherPos[r] < davidPos) {
            return {teacherPos[r], teacherPos[r]};
        }

        int left = 0, right = teacherPos.size() - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(teacherPos[mid] < davidPos) {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return {teacherPos[right],teacherPos[right+1]};
    }
    public:
    void solve() {
        int n, m, q;
        cin>>n>>m>>q;

        vector<int> teachers(m);
        input(teachers);
        sort(full(teachers));

        while(q--) {
            int davidPos;
            cin>>davidPos;

            auto [t1, t2] = findClosestTeachers(teachers, davidPos);
            vector<int> teacherPos(2);
            teacherPos[1] = t2;
            teacherPos[0] = t1;
            // cout<<t1<<" "<<t2<<endl;

            if(davidPos > teacherPos[1]) {
                int distance = n - teacherPos[1] ;
                cout<<distance<<endl;
                continue;
            }
            if(davidPos < teacherPos[0]) {
                int distance = teacherPos[0] - 1;
                cout<<distance<<endl;
                continue;
            }

            int leftDistance = davidPos - teacherPos[0];
            int rightDistance = teacherPos[1] - davidPos;

            if(leftDistance == rightDistance) {
                cout<<leftDistance<<endl;
                continue;
            }

            if(leftDistance > rightDistance)
                swap(leftDistance, rightDistance);

            int changes = rightDistance - leftDistance;
            int moves = (changes + 1) / 2;
            rightDistance -= moves * 2;
            cout<<moves + min(leftDistance, rightDistance)<<endl;
        }
      
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
