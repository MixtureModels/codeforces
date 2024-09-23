#define _print(prv, nxt) cout << "prev found: " << prv << " next found: " << nxt << "\n";
#define _print_src_dest(src, dest) cout << "new src: " << src << " new dest: " << dest << "\n";

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int main() {

    int t; cin >> t;

    int n, m, q, c;
    int src, dest;

    while (t--) {
        cin >> n;
        
        vector<int> cts(n);
        FOR(i, n) cin >> cts[i];
        
        cin >> q;
        while (q--) {

            cin >> src >> dest;
            --src;--dest;
            // ensure src always <= dest
            if (src > dest) {
                int tmp = src;
                src = dest;
                dest = tmp;
            }
            _print_src_dest(src, dest);

            c = 0;
            for (int i = src; i < dest; ++i) {
                int prv = i != 0 ? abs(cts[i] - cts[i-1]) : INT_MAX;
                int nxt = abs(cts[i] - cts[i+1]);

                if (nxt < prv) ++c; 
                else c += nxt;
            }

            std::cout << c << "\n";
        }

    }
}