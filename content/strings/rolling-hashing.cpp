#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

// Obtenido de: https://github.com/ProgramacionCompetitivaUTFSM/Handbook-USM/blob/master/content/strings/rolling-hashing.cpp
/*
 *Description:* Rolling hash for fast substring comparison, single hash function
 *Status:* Tested
*/
template<class T>
struct rolling_hashing {
  int base, mod; 
  vector<long long> p, H;
  int n;
  rolling_hashing(const T &s, int b, int m): base(b), mod(m), n(s.size()) {
    p.assign(n+1, 1);
    H.assign(n+1, 0);
    for (int i = 0; i < n; ++i) {
      H[i+1] = (H[i] * base + s[i]) % mod;
      p[i+1] = (p[i] * base) % mod;
    }
  }
  // get obtiene el hash de s[l..r], es decir, el hash
  // del substring de s desde l hasta r, inclusive.
  int get(int l, int r) {
    int res = (H[r+1] - H[l]*p[r-l+1]) % mod;
    if (res < 0) res += mod;
    return res;
  }
};


int main () {
	int n, m, sp; cin >> n >> m;
	string p; cin >> p; sp = p.size();
	rolling_hashing rh(p, 67, 998244353);
	int last = -1;
	for (int i = 0; i<m; i++) {
		int xi; cin >> xi; xi--;
		n -= sp;
		if (xi <= last) {
			int c = last-xi+1;
			ll left = rh.get(sp - c, sp-1);
			ll right = rh.get(0, c-1);
			// cout << left << " is equal to " << right << endl;

			// cout << "left " << p.substr(sp - c, sp-1) << endl;			
			// cout << "right " << p.substr(0, c-1) << endl;
			bool a = right == left;
			if (a) n += c;
			else {
				cout << 0 << endl;
				return 0;
			}
		} 
		
		last = xi + sp-1;
		// cout << "last is " << last << endl;
	}
	// cout << "n is " << n << endl;
	ll ans = 1;
	for (int i = 0; i<n; i++) {
		ans = (ans * 26) % mod;
	}
	//if (n == 0) ans = 0;
	
	cout << ans << endl; 
	
	return 0;
}
