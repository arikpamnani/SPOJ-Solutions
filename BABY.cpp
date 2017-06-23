// Arik Pamnani
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sd(x) scanf("%d", &x);
#define slld(x) scanf("%lld", &x);
#define pd(x) printf("%d\n", x);
#define plld(x) printf("%lld\n", x);

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pllll pair<ll, ll>
#define f first
#define s second
#define REP(i, a) for(int i=0; i<a; ++i)
#define REPB(i, a, b) for(int i=a; i<b; ++i)
#define FILL(a, x) memset(a, x, sizeof(a))
#define CLEAR(x) memset(x, 0, sizeof(x))
#define mp make_pair
#define pb push_back

const int mod = 1e9+7;
const ll INF = 1e18;

const int N = 17;

int dp[N][N];

int n;

int d_func(pii d, pii e)	{
	return abs(e.s-d.s) + abs(e.f - d.f);
}

ll DP[N][1 << N];

void solve(int k, int mask)	{
	REP(i, n)	{
		if((mask & (1 << i)) > 0)	{
			int x = (1 << i) ^ ((1 << n)-1);
			int mask_ = mask & x;
			// pd(mask_);
			if(DP[k-1][mask_] == INF)	{
				solve(k-1, mask_);
				// cout << mask << " " << mask_ << " " << (1<<n)-1 << endl;
			}
			DP[k][mask] = min(DP[k][mask], DP[k-1][mask_] + dp[k-1][i]);
		}
	}
}	

int main()	{
	while(true)	{
		sd(n);
		vector<pii> B(n);
		vector<pii> C(n);
		if(n == 0)
			return 0;
		// vector<pii> B(n);
		REP(i, n)	{
			int c;
			sd(c);
			B[i] = mp(i+1, c);
			B.pb(mp(i+1, c));
		}
		// vector<pii> C(n);
		REP(i, n)	{
			int c;
			sd(c);
			C[i] = mp(i+1, c);
			C.pb(mp(i+1, c));
		}
		REP(i, n)	{
			REP(j, n)	{
				dp[i][j] = d_func(B[i], C[j]);
			}
		}
		REP(i, n+1)	{
			REP(j, (1 << n)+1)	{
				DP[i][j] = INF;
			}
		}
		DP[0][0] = 0;	
		solve(n, (1 << n)-1);
		plld(DP[n][(1 << n)-1]);
	}
	return 0;
}












