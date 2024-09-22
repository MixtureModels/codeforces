#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int n; int k; int mx_len;
    int cnt; int l;

    while (t--) {

        cin >> n; cin >> k;

        vector<long long> fr(n); vector<long long> ht(n);

        // store the fruits and the heights
        for (int i = 0; i < n; ++i) cin >> fr[i];
        for (int i = 0; i < n; ++i) cin >> ht[i];
        
        // two-pointer sliding window
        cnt = fr[0];
        mx_len = cnt <= k ? 1 : 0;

        l = 0;
        for (int r = 1; r < n; ++r) {
            
            // check the height constraint
            if (ht[r - 1] % ht[r] != 0) {
                cnt = 0;
                l = r;
            }

            cnt += fr[r];

            while (l < r && cnt > k) {
                cnt -= fr[l]; ++l;
            }

            if (cnt <= k)
                mx_len = max(mx_len, r - l + 1);
        }

        std::cout << mx_len << "\n";
    }
}