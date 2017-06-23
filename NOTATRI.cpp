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

int main()	{
	while(true)	{
		int n;
		sd(n);
		if(n == 0)
			break;
		vi Array(n);
		REP(i, n)	{
			sd(Array[i]);
		}
		sort(Array.begin(), Array.end());
		vi Plus;
		REP(i, n)	{
			REPB(j, i+1, n)	{
				Plus.pb(Array[i] + Array[j]);
			}
		}
		sort(Plus.begin(), Plus.end());
		int t = 0;
		REP(i, n)	{
			int x = lower_bound(Plus.begin(), Plus.end(), Array[i]) - Plus.begin();
			// cout << x << " ";	
			t += x;
		}
		pd(t);
	}
	return 0;
}
