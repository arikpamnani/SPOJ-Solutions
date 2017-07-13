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

int dfs(vector<vi> Adj,int s,vi& visited)	{
	REP(i,Adj[s].size())	{
		if(visited[Adj[s][i]]!=-1)	{
			if(visited[Adj[s][i]] == visited[s])
				return -1;
		}				
		else	{
			visited[Adj[s][i]]=1-visited[s];
			if(dfs(Adj,Adj[s][i],visited) == -1)	
				return -1;
		}
	}
	return 0;
}

int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	sd(t);
	REP(j,t)	{
		ll n, m;
		slld(n);
		slld(m);
		vector<vi> Adj(n);
		REP(i,m)	{
			int u,v;
			sd(u);
			sd(v);
			Adj[u-1].pb(v-1);
			Adj[v-1].pb(u-1);
		}
		vi visited(n,-1);
		int x=0;
		REP(i,n)	{
			if(visited[i]==-1)	{
				visited[i]=0;
				x = dfs(Adj,i,visited);
				if(x == -1)	
					break;
			}
		}
		printf("Scenario #%d:\n",j+1); 
		if(x == -1)	
			printf("Suspicious bugs found!\n");
		else	
			printf("No suspicious bugs found!\n");
	}
	return 0;
}
