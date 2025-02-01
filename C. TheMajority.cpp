// The approach to the problem:

// 1) We follow an simple idea, were for each ball of type not 1 is added with ball type 1 and hence {+1, -1} froms equality..
//   (Use stars and bars to find the number of ways to arrange the pairs (i, 1)). 
// 2) To maintain majority of ball of first type we can add one ball to each of the bucket and the left balls are again placed into the buckets.

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

// const int MOD = 1e9 + 7;
const int MOD = 998244353;

template<const int mod>
struct mint {
    int val;
    constexpr mint(long long x = 0) : val((x % mod + mod) % mod) {}
    explicit operator int() const { return val; }
    mint& operator+=(const mint &b) { val += b.val; val -= mod * (val >= mod); return *this; }
    mint& operator-=(const mint &b) { val -= b.val; val += mod * (val < 0); return *this; }
    mint& operator*=(const mint &b) { val = 1ll * val * b.val % mod; return *this; }
    mint& operator/=(const mint &b) { return *this *= b.inv(); }
    mint inv() const { int x = 1, y = 0, t; for(int a=val, b=mod; b; swap(a, b), swap(x, y)) t = a/b, a -= t * b, x -= t * y; return mint(x); }
    mint power(int b) const { mint a = *this, res(1); for(; b; a *= a, b /= 2)  if(b & 1) res *= a; return res; }
    mint operator-() const { return val == 0 ? 0 : mod - val; }
    mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
    mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
    mint operator++(int32_t) { mint before = *this; ++*this; return before; }
    mint operator--(int32_t) { mint before = *this; --*this; return before; }
    friend mint operator+(const mint &a, const mint &b) {return mint(a) += b;}
    friend mint operator-(const mint &a, const mint &b) {return mint(a) -= b;}
    friend mint operator*(const mint &a, const mint &b) {return mint(a) *= b;}
    friend mint operator/(const mint &a, const mint &b) {return mint(a) /= b;}
    friend bool operator==(const mint &a, const mint &b) {return a.val == b.val;}
    friend bool operator!=(const mint &a, const mint &b) {return a.val != b.val;}
    friend bool operator<(const mint &a, const mint &b) {return a.val < b.val;}
    friend istream& operator>>(istream &in, mint &a) {return in >> a.val;}
    friend ostream& operator<<(ostream &os, const mint &a) {return os << a.val;}
};
using Mint = mint<MOD>;


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin >> n;
    int k; cin >> k;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    Mint ans = 1;

    for(int i = 1; i < n; i++) {
        int r = k - 1;
        int numerator = arr[i] + r;
        for(int j = 0; j < min(r, numerator - r); j++) {
            ans *= (numerator - j);
            ans /= (j + 1);
        }
    } 

    int left = accumulate(arr.begin() + 1, arr.end(), 0ll);

    if(left >= arr[0]) {
        cout << 0 << endl;
        return 0;
    }

    left = arr[0] - left;

    int numerator = left - 1;
    int r = k - 1;

    for(int j = 0; j < min(r, numerator - r); j++) {
        ans *= (numerator - j);
        ans /= (j + 1);
    }

    cout << ans << endl;

}  
