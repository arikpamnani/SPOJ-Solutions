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
const int INF = 1000;

int visited[205];
int parent[205];
int AM[205][205];

int bfs(vector<vi> Adj,int s,int t,vi& visited,vi& parent)	{
	visited[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())	{
		int A=q.front();
		q.pop();
		REP(i,Adj[A].size())	{
			if(!visited[Adj[A][i]] && (AM[A][Adj[A][i]] > 0))	{
				visited[Adj[A][i]]=1;
				parent[Adj[A][i]]=A;
				q.push(Adj[A][i]);
			}
		}
	}
	return visited[t];
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
			int num;
			sd(num);		
			REP(j,num)	{
				int v;
				sd(v);
				if(i == 0 || v-1 == n-1)	{	
					AM[i][v-1]=1;
				}
				else	{
					AM[i][v-1]=n;
				}
				Adj[i].pb(v-1);
			}
		}
		int max_flow=0;
		while(true)	{	
			vi visited(n);
			vi parent(n);
			visited[0]=1;
			int x=bfs(Adj,0,n-1,visited,parent);				
			// cout << x << endl;
			if(x==0)	
				break;
			int curr_flow=INF;
			int v=n-1;
			while(v != 0)	{
				if(AM[parent[v]][v] < curr_flow)	{
					curr_flow=AM[parent[v]][v];
				}
				v=parent[v];
			}
			v=n-1;
			while(v!=0)	{
				AM[parent[v]][v] -= curr_flow;
				AM[v][parent[v]] += curr_flow;
				int c=0;
				REP(f,Adj[v].size())	{
					if(Adj[v][f]==parent[v])
						c+=1;
				}
				if(c<=0)
					Adj[v].pb(parent[v]);
				v=parent[v];
			}
			max_flow+=curr_flow;	
			// cout << curr_flow << endl;
		}
		printf("%d\n",max_flow);
	}
	return 0;
}
