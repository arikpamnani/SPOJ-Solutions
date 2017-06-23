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

ll factorial(int n)	{
	return (n == 0 | n == 1) ? 1 : factorial(n-1) * n;
}

int main()	{
	while(true)	{
		int A, B;
		sd(A);
		sd(B);
		if(A == -1 && B == -1)
			break;
		ll C = factorial(A+B) / (factorial(A) * factorial(B));
		// plld(C);
		string s = "!=";
		if(C == A+B)
			s = "=";
		cout << A << "+" << B << s << A+B << "\n";
	}
	return 0;
}
