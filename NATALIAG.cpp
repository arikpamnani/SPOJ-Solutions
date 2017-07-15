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

int visited[10007];
int level[10007];

void bfs(vector<vi> Adj,int s,int m,int n)	{
	visited[s]=1;
	level[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())	{
		int A=q.front();
		q.pop();
		REP(i,Adj[A].size())	{
			if(!visited[Adj[A][i]] && (Adj[A][i] < m*n))	{
				visited[Adj[A][i]]=1;
				level[Adj[A][i]]=level[A]+1;	
				q.push(Adj[A][i]);
			}
		}	
	}
}

int main()	{
	int t;
	sd(t);
	while(t)	{
		t--;
		int m,n;
		sd(m);
		sd(n);
		vector<vi> Adj(m*n);
		int s=-1;
		int f=-1;
		// cout << m << " " << n << endl;
		int i=0;
		while(i < m)	{
			string e;
			cin >> e;
			int j=0;
			while(j < n)	{	
				char d=e[j];
				if(d == '*')
					visited[m*i+j] = 1;
				if(d == '$')	
					s = m*i+j;
				if(d == '#')
					f = m*i+j;
				int num=m*i+j;
				int num_up = m*(i-1)+j;	
				int num_down = m*(i+1)+j;
				int num_left = m*i+j-1;
				int num_right = m*i+j+1;


				if(i == 0 && j == 0)	{
					Adj[num].pb(num_right);
					Adj[num].pb(num_down);
				}
				else	{
					if(i == 0 && j == n-1)	{	
						Adj[num].pb(num_left);
						Adj[num].pb(num_down);
					}
					else	{
						if(i == m-1 && j == 0)	{
							Adj[num].pb(num_up);
							Adj[num].pb(num_right);
						}
						else	{
							if(i == m-1 && j == n-1)	{
								Adj[num].pb(num_left);
								Adj[num].pb(num_up);
							}
							else	{
								if(i == 0)	{
									Adj[num].pb(num_left);
									Adj[num].pb(num_right);
									Adj[num].pb(num_down);
								}
								else	{
									if(i == m-1)	{
										Adj[num].pb(num_left);
										Adj[num].pb(num_right);
										Adj[num].pb(num_up);
									}	
									else	{
										if(j == 0)	{
											Adj[num].pb(num_right);
											Adj[num].pb(num_up);
											Adj[num].pb(num_down);
										}	
										else	{
											if(j == n-1)	{
												Adj[num].pb(num_left);
												Adj[num].pb(num_up);	
												Adj[num].pb(num_down);
											}
											else	{
												Adj[num].pb(num_left);
												Adj[num].pb(num_right);
												Adj[num].pb(num_up);	
												Adj[num].pb(num_down);
											}
										}
									}
								}
							}
						}
					}
				}
				
			
				j += 1;
			}	
			i += 1;
		}
		bfs(Adj,s,m,n);
		if(level[f] == 0)	{
			printf("%d\n",-1);
		}
		else	{
			printf("%d\n",level[f]);
		}
		REP(i,10007)	{
			visited[i]=0;
			level[i]=0;
		}
	}
	return 0;
}
