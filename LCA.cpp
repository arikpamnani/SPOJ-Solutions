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

int P[1007];
int L[1007];
int PI[1007][50];

int lca(int p, int q)	{
	if(L[p] < L[q])	
		swap(p, q);
	
	int log;
	if(L[p] == 1)
		log=0;
	else
		log=ceil(log2(L[p]))-1;
	
	for(int i=log; i>=0; i--)	{
		if((L[p]-L[q]) >= pow(2, i))	
			p=PI[p][i];
	}
	
	if(p==q)
		return p;

	for(int i=log; i>=0; i--)	{
		if(PI[p][i] != -1 && (PI[p][i] != PI[q][i]))	{
			p=PI[p][i];
			q=PI[q][i];
		}
	}
	return P[p];
}

int main()	{
	int T;
	sd(T);
	REP(t, T)	{
		// t--;
		int n;
		sd(n);
		// sd(m);
		P[0]=-1;
		L[0]=0;
		REP(i, n)	{
			int m;
			sd(m);
			REP(j, m)	{
				int v;
				sd(v);
				P[v-1]=i;
				L[v-1]=L[i]+1;
				// Adj[v-1].pb(i);
			}
		}	

		memset(PI, -1, sizeof(PI));

		REP(i, n)	{
			PI[i][0]=P[i];
		}	

		for(int j=0; pow(2, j) < n; j++)	{
			REP(i, n)	{
				if(PI[i][j-1]!=-1)
					PI[i][j]=PI[PI[i][j-1]][j-1];
				
			}
		}
		
		int Q;
		sd(Q);
		
		printf("Case %d:\n", t+1);
		
		REP(q, Q)	{
			int a, b;
			sd(a);
			sd(b);
			printf("%d\n", lca(a-1, b-1)+1);
		}
	}
	return 0;
}
