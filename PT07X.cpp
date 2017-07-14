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

int dp[100007][2];
int visited[100007];

void dfs(vector<vi> Adj,int s)	{
	int x=0;
	int y=0;
	REP(i,Adj[s].size())	{
		if(!visited[Adj[s][i]])	{
			visited[Adj[s][i]]=1;
			if(dp[Adj[s][i]][0] == -1)
				dfs(Adj,Adj[s][i]);
			x=x+dp[Adj[s][i]][1];
			y=y+min(dp[Adj[s][i]][0],dp[Adj[s][i]][1]);
		}
	}
	dp[s][0]=x;
	dp[s][1]=1+y;
}

int main()	{
	int n;
	sd(n);
	if(n == 1)	{
		int x=1;
		printf("%d\n",x);	
		while(true)	{
			int g;
			cin >> g;
			if(g == EOF)
				break;
		}
	}
	else	{
		vector<vi> Adj(n);
		REP(i,n-1)	{
			int u,v;
			sd(u);
			sd(v);
			Adj[u-1].pb(v-1);	
			Adj[v-1].pb(u-1);
		}
		memset(dp,-1,1007*2*sizeof(int));
		visited[0]=1;
		dfs(Adj,0);
		int x=1;
		if(n!=1)
			x=min(dp[0][0],dp[0][1]);
		printf("%d\n",x);
	}
	return 0;
}
