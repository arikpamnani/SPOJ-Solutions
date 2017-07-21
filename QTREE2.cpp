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

int P[10007];
int L[10007];
int PI[10007][50];
int AM[10007][10007];

void bfs(vector<vi> Adj, int s, vi& visited)	{

	visited[s]=1;
	P[s]=-1;
	L[s]=0;
	queue<int> q;
	q.push(s);
	

	while(!q.empty())	{
		int A=q.front();
		q.pop();
		REP(i, Adj[A].size())	{
			if(!visited[Adj[A][i]])	{	
				visited[Adj[A][i]]=1;
				P[Adj[A][i]]=A;
				L[Adj[A][i]]=L[A]+1;
				q.push(Adj[A][i]);
			}
		}
	}

}



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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	sd(t);
	while(t)	{
		t--;
		int n;
		sd(n);
		vector<vi> Adj(n);
		REP(i, n-1)	{	
			int a, b, c;
			sd(a);
			sd(b);
			sd(c);
			Adj[a-1].pb(b-1);
			Adj[b-1].pb(a-1);
			AM[a-1][b-1]=c;
			AM[b-1][a-1]=c;
		}
		vi visited(n);	
		bfs(Adj, 0, visited);	

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

		char in[10];	
	
		while(true)	{
			int a,b,k;
			cin>>in;
			if(in[1] == 'I')	{
				cin >> a >> b;
				a--;
				b--;
				int d=lca(a, b);
				ll res=0;
				while(a!=d)	{
					res+=AM[a][P[a]];
					a=P[a];
				}
				while(b!=d)	{
					res+=AM[b][P[b]];
					b=P[b];
				}
				printf("%lld\n",res);
			}
			else	{
				if(in[1] == 'T')	{
					cin >> a >> b >> k;
					a--;
					b--;

					int d=lca(a,b);

					int te=L[a]+L[b]-2*L[d]+1;

					if(k <= L[a]-L[d]+1)	{
						int z=1;
						while(z<k)	{
							a=P[a];
							z++;
						}
						printf("%d\n",a+1);	
					}			
					else	{
						int z=1;
						while(z<te-k+1)	{
							b=P[b];	
							z++;
						}		
						printf("%d\n",b+1);				
					}	
					
				}		
				else	{
					printf("\n");
					break;
				}
			}
			
		}		
		// printf("\n");

	}
	return 0;
}
