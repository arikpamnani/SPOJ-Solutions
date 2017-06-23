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

const int N = 21;

ll dp[N][(1 << N) - 1];

int match[N][N];

void solve(int k, ll mask, int n)	{
	ll put = 0;
	REP(i, n)	{
		if( match[k-1][i] && ((mask & (1 << i)) > 0) )	{
			ll x = (1 << i) ^ ((1 << n)-1);
			ll mask_ = mask & x;
			// plld(mask_);
			if(dp[k-1][mask_] == -1)	{
				solve(k-1, mask_, n);
			}			
			put += (dp[k-1][mask_]);
		}
	}
	dp[k][mask] = put;
}

int main()	{
	int t;
	sd(t);
	while(t)	{
		t--;
		int n;
		sd(n);
		REP(i, n)	{
			REP(j, (1 << n))	{
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 1;
		REP(i, n)	{
			REP(j, n)	{
				int x;
				sd(x);
				// pd(x);
				match[i][j] = x;
			}
		}
		solve(n, (1<<n)-1, n);
		plld(dp[n][(1 << n)-1]);
	}
	return 0;
}
