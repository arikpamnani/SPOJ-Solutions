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

char A[MAX];
char B[MAX];
char P[MAX];

void ComputeP(void)	{
	int m=strlen(B);
	int k=0;
	P[0]=0;
	for(int i=1; i<m; i++)	{
		while(k>0 && P[k]!=B[i])	{
			k=P[k-1];
		}
		if(P[k]==B[i])	
			k++;
		P[k]=k;
	}
}

vi KMP(void)	{
	int n=strlen(A);
	int m=strlen(B);
	vi C;
	ComputeP();
	int q=0;
	for(int i=0; i<n; i++)	{
		while(q>0 && B[q]!=A[i])
			q=P[q-1];
		if(B[q]==A[i])
			q++;
		if(q==m)	{
			C.pb(i-m+1);	
			q=P[q-1];
		}
	}
	return C;
}

int main()	{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);	
	int t;
	sd(t);
	while(t)	{
		t--;
		scanf("%s",A);
		scanf("%s",B);
		vi C=KMP();
		if(C.size()==0)
			printf("Not Found\n\n");
		else	{
			printf("%d\n",C.size());
			for(int i=0; i<C.size(); i++)	
				printf("%d ",C[i]+1);		
			printf("\n\n");
		}
	}
	return 0;
}
