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
	ios_base::sync_with_stdio(false);
	int n;
	sd(n);
	vi T(n);
	vi LHS;
	vi RHS;
	REP(i, n)	{
		sd(T[i]);
	}	
	for(int i=0; i<n; i++)	{
		for(int j=0; j<n; j++)	{
			for(int k=0; k<n; k++)
				LHS.pb(T[i]*T[j]+T[k]);
		}
	}
	sort(LHS.begin(), LHS.end());
	for(int i=0; i<n; i++)	{
		for(int j=0; j<n; j++)	{
			for(int k=0; k<n; k++)	{	
				if(T[k]!=0)
					RHS.pb(T[k]*(T[i]+T[j]));	
			}
		}
	}
	sort(RHS.begin(), RHS.end());
	int total = 0;
	vi::iterator low = lower_bound(RHS.begin(), RHS.end(), LHS[0]);
	vi::iterator high = upper_bound(RHS.begin(), RHS.end(), LHS[0]);
	int currL = 1;
	int currR = high - low;
	// cout << currR << " ";
	int j = 1;
	while(j < LHS.size())	{
		if(LHS[j] == LHS[j-1])	{
			currL ++;
		}
		else	{
			total = total + (currR*currL);
			currL = 1;
			low = lower_bound(RHS.begin(), RHS.end(), LHS[j]);
			high = upper_bound(RHS.begin(), RHS.end(), LHS[j]);
			currR = high - low;
		}
		j ++;
	}
	total = total+(currR*currL);
	pd(total);
	return 0;
}
