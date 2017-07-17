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
#define print(a) cout << a << endl

const int mod = 1e9+7;
const ll INF = 1e18;

ll ETF(ll n)	{
	ll result = n;	
	for(ll i=2; i*i<=n; i++)	{
		if(n%i==0)	{
			result*=(i-1);
			result/=i;
			// result -= result/i;
		}
		while(n%i==0)	{
			n/=i;
		}
	}
	if(n>1)	{
		result*=(n-1);
		result/=n;
		// result-=result/n;
	}
	return result;
}

int main()	{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	int t;
	sd(t);
	while(t)	{
		t--;
		ll n;
		slld(n);	
		printf("%lld\n",ETF(n));
	}
	return 0;
}
