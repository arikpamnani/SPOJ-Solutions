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

char A[505];
char B[505];

int main()	{
	while(true)	{
		cin>>A;
		cin>>B;
		if(A[0]=='*' && B[0]=='*')
			break;
		// pd(strlen(A));
		int answer=0;
		int t=0;
		int j=0;
		while(j<strlen(A))	{
			if(A[j]==B[j])	{
				t>0 ? answer+=1 : answer+=0;
				t=0;
			}
			else	{
				t++;
			}
			j++;
		}
		t>0 ? answer+=1 : answer+=0;
		pd(answer);
	}
	return 0;
}
