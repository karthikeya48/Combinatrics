// Approach: 
// counting of dearrangmenets
// consider the case 

// A B C D E

// A has n - 1 ways to give the gifts.
// if A have given the gift to be B then 
// two cases:

// either B can give the gift of it to A which creates new subproblem f(n - 2);
// if B gives to someother than A then new subproblem f(n - 1) as there are still n - 1 participants;

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    const int mod = 1e9 + 7;
    vector<int>dp(n + 1, -1);
    auto f = [&](int index, auto &&self) -> int {
        if(index == 1) return 0;
        if(index == 2) return 1;
        if(dp[index] != -1) return dp[index];
        return dp[index] = ((index - 1) * (self(index - 2, self) + self(index - 1, self)) % mod)  % mod;
    };
    cout << f(n, f) << endl;
}
