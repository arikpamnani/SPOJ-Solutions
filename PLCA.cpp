// Arik Pamnani
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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



int query(int a, int b)	{
	if(L[a] < L[b])	{
		int temp=b;
		b=a;
		a=temp;
	}
	while(L[a] != L[b])	
		a=P[a];
	
	if(a==b)	
		return a;
	while(P[a] != -1 && (P[a] != P[b]))	{
		a=P[a];
		b=P[b];
	}
	return P[a];
}


int main()	{
	int T;
	sd(T);
	REP(t, T)	{
		int n;
		sd(n);
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
			}
		}
		// vi visited(n);	
		// bfs(Adj, 0, visited);

		int Q;
		sd(Q);
		printf("Case %d:\n", t+1);
		REP(q, Q)	{
			int a, b;
			sd(a);
			sd(b);
			printf("%d\n",query(a-1, b-1)+1);
		}
		
	}
	return 0;
}
