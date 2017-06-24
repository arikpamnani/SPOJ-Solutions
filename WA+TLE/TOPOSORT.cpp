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

set<int> white;

int gray[10007];
// vi TOPO;

int visited[10007];

int dfs(vector<vi> Adj, int s)	{
	white.erase(s);
	gray[s] = 1;
	REP(j, Adj[s].size())	{
		const bool is_in = white.find(Adj[s][j]) != white.end();
		int m;	
		if(is_in)	{
			m = dfs(Adj, Adj[s][j]);
			if(m == -1)
				return -1;
		}
		if(gray[Adj[s][j]])
			return -1;
	}
	gray[s] = 0;
	// TOPO.pb(s);
	return 0;
}

int main()	{
	int n, m;
	sd(n);
	sd(m);
	REP(i, n)
		white.insert(i);
	vector<vi> Adj(n);
	vi in(n);
	REP(i, m)	{
		int u, v;
		sd(u);
		sd(v);
		Adj[u-1].pb(v-1);
		in[v-1] += 1;
	}
	/*
	while(!white.empty())	{
		// cout << *white.begin() << endl;
		int x = dfs(Adj, *white.begin());
		if(x == -1)	{
			// cout << "Sandro fails" << endl;
			printf("Sandro fails\n");
			return 0;
		}
	}*/
	vi TOPO;
	priority_queue<int, vector<int>, greater<int>> PQ;
	REP(i, n)	{
		if(in[i] == 0)	{
			visited[i] = 1;
			PQ.push(i);
		}
	}
	while(!PQ.empty())	{
		int i = PQ.top();
		// pd(i);
		PQ.pop();
		REP(j, Adj[i].size())	{
			in[Adj[i][j]] -= 1;
			if(in[Adj[i][j]] == 0 && visited[Adj[i][j]] == 0)	{
				visited[Adj[i][j]] = 1;
				PQ.push(Adj[i][j]);
			}
		}
		TOPO.pb(i);
		// printf("%d ", i+1);
	}
	if(TOPO.size() < n)	{
		printf("Sandro fails\n");
		return 0;
	}
	REP(i, TOPO.size())	{
		printf("%d ", TOPO[i]+1);
	}
	printf("\n");
	return 0;
}
