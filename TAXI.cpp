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
const int INF = 1e4;

int AM[605][605];

int bfs(vector<vi> Adj,int s,int t,vi& visited,vi& parent)	{
	visited[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())	{
		int A=q.front();	
		// cout << A << endl;
		q.pop();
		REP(i,Adj[A].size())	{
			if(!visited[Adj[A][i]] && AM[A][Adj[A][i]] > 0)	{
				visited[Adj[A][i]]=1;
				parent[Adj[A][i]]=A;
				q.push(Adj[A][i]);
			}
		}
	}
	return visited[t];
}

int main()	{	
	int k;
	sd(k);
	while(k)	{
		k--;
		int p,t,s;
		ll c;
		sd(p);	
		sd(t);
		sd(s);	
		slld(c);
		vector<vi> Adj(p+t+2);
		vector<pii> PAdj(p);	
		vector<pii> TAdj(t);
		REP(i,p)	{
			int u,v;
			sd(u);
			sd(v);
			PAdj[i]=mp(u,v);
		}
		REP(i,t)	{
			int u,v;
			sd(u);
			sd(v);
			TAdj[i]=mp(u,v);
		}
		REP(i,p)	{
			REP(j,t)	{
				int dist=200*(abs(PAdj[i].f-TAdj[j].f)+abs(PAdj[i].s-TAdj[j].s));
				if(dist <= (s*c))	{	
					Adj[i].pb(p+j);
					AM[i][p+j]=1;
				}
			}
		}
		REP(i,p)	{
			Adj[p+t].pb(i);
			AM[p+t][i]=1;
		}
		REP(i,t)	{
			Adj[p+i].pb(p+t+1);	
			AM[p+i][p+t+1]=1;	
		}
		int max_flow=0;
		while(true)	{
			vi visited(p+t+2);
			vi parent(p+t+2);
			int x=bfs(Adj,p+t,p+t+1,visited,parent);
			if(!x)	{
				break;
			}
			int curr_flow=INF;
			int v=p+t+1;
			while(v!=p+t)	{
				if(AM[parent[v]][v] < curr_flow)
					curr_flow = AM[parent[v]][v];
				v=parent[v];
			}
			v=p+t+1;
			while(v!=p+t)	{
				AM[parent[v]][v]-=curr_flow;
				AM[v][parent[v]]+=curr_flow;
				v=parent[v];
			}
			max_flow+=curr_flow;
		}
		printf("%d\n",max_flow);
	}
	return 0;
}
