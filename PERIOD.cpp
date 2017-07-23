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
const int MAX = 1000007;

int m;

char A[MAX];
int P[MAX];

void ComputeP(void)	{
	// int m=strlen(A);
	P[0]=0;
	int k=0;
	for(int i=1; i<m; i++)	{
		while(k>0 && A[k] != A[i])	
			k=P[k-1];
		if(A[k] == A[i])	{
			k++;
		}
		P[i]=k;
	}
}

int main()	{
	int t;
	sd(t);
	REP(l, t)	{
		// t--;
		sd(m);
		scanf("%s",A);
		ComputeP();
		printf("Test case #%d\n",l+1);
		for(int i=1; i<m; i++)	{
			if(P[i] >= (i+1)/2 && ( (i+1)%(i+1-P[i]) == 0))	{
				int x=i+1;
				int y=(i+1)/(i+1-P[i]);
				printf("%d %d\n",x,y);
			}
		}
		printf("\n");
	}
	return 0;
}
