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

int PRE[8007];
int POST[8007];
int IN[8007];

int func(int s1,int f1,int s2,int f2,int s3,int f3)	{
	if(f1-s1+1==1)	{
		if(PRE[s1]==POST[s2] && POST[s2]==IN[s3])	{
			return 1;
		}
		else	{
			return -1;
		}
	}
	if(PRE[s1] == POST[f2])	{
		int c=-1;
		REPB(i,s3,f3+1)	{
			if(IN[i] == PRE[s1])
				c=i;
		}
		if(c == -1)
			return -1;
		int n = c-s3;
		int l,r;
		if(s1+n < n && s2+n-1 < n && c-1 < n)
			l = func(s1+1,s1+n,s2,s2+n-1,s3,c-1);
		else	
			l = 0;
		if(f1 < n && f2-1 < n && f3 < n)	
			r = func(s1+n+1,f1,s2+n,f2-1,c+1,f3);
		else	
			r = 0;
		if(l == -1 || r == -1)	
			return -1;
		else
			return 1;
	}
	else	{
		return -1;
	}
}

int main()	{
	int n;
	sd(n);
	REP(i,n)	{
		sd(PRE[i]);
	}
	REP(i,n)	{
		sd(POST[i]);
	}
	REP(i,n)	{
		sd(IN[i]);
	}
	int x=func(0,n-1,0,n-1,0,n-1);
	if(x == -1)
		printf("no\n");
	else
		printf("yes\n");	
	return 0;
}
