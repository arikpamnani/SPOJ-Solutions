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

int level[100007];
int visited[100007];

pii bfs(vector<vi> Adj,int s)	{
	queue<int> q;
	q.push(s);
	level[s] = 1;
	pii F = mp(-1,-1);
	while(!q.empty())	{
		int c=0;
		int A = q.front();
		// cout << A << endl;
		q.pop();
		REP(i,Adj[A].size())	{
			if(!level[Adj[A][i]])	{
				level[Adj[A][i]] = level[A]+1;
				c += 1;
				q.push(Adj[A][i]);
			}
		}
		// cout << c << endl;
		if(c == 0)	{
			if(level[A]-1 > F.s)	{
				F.s = level[A]-1;
				F.f = A;
			}
		}
	}
	return F;
}

int main()	{
	int t;
	sd(t);
	while(t)	{
		t--;
		int n;
		sd(n);
		vector<vi> Adj(n);	
		REP(i,n-1)	{
			int u,v;
			sd(u);
			sd(v);
			Adj[u].pb(v);	
			Adj[v].pb(u);
		}
		CLEAR(level);
		pii F = bfs(Adj,0);
		CLEAR(level);
		F = bfs(Adj,F.f);
		if(!(F.s%2))	
			printf("%d\n",F.s/2);
		else
			printf("%d\n",F.s/2+1);
	}
	return 0;
}
