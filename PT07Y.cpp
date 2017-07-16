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

int visited[100007];

void bfs(vector<vi> Adj,int s)	{
	visited[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())	{
		int A=q.front();
		q.pop();
		REP(i,Adj[A].size())	{
			if(!visited[Adj[A][i]])	{
				visited[Adj[A][i]]=1;
				q.push(Adj[A][i]);
			}
		}
	}
}

int main()	{
	int n,m;
	sd(n);	
	sd(m);
	vector<vi> Adj(n);
	REP(i,m)	{
		int u,v;
		sd(u);	
		sd(v);	
		Adj[u-1].pb(v-1);	
		Adj[v-1].pb(u-1);
	}
	if(m != n-1)	{
		printf("NO\n");
		return 0;
	}
	bfs(Adj,0);	
	REP(i,n)	{
		if(!visited[i])	{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
