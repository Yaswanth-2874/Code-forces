#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, start, time;
        cin >> n >> start >> time;
        string st;
        cin >> st;

        int point = start;
        int index = 0;
        int total = 0;
        int timePassed = 0;
        
        while(index < n && point != 0) {
            char ch = st[index++];
            if(ch == 'L')
                point--;
            else
                point++;
            timePassed++;
        }

        if(point != 0) {
            /* Print number*/ {
                cout<<0<<endl;
                return;
            }
        }
        total = 1;
        time -= timePassed;
        int duration = 0;

        for(int i = 0; i < n; i++) {
            if(st[i] == 'L')
                point--;
            else
                point++;
            // cout<<point<<endl;
            duration++;
            if(point == 0)
                break;
        }
        // cout<<"Duration left "<<duration<<" and time is "<<time<<endl;
        if(point != 0 || duration > time)
            /* Print number*/ {
                cout<<total<<endl;
                return;
            }
        total += time/duration;
        /* Print number*/ {
            cout<<total<<endl;
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
