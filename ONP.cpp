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

char s[450];

int main()	{
	int n;
	sd(n);
	REP(j,n)	{
		cin>>s;
		stack<char> LE;
		stack<char> SY;
		int i=0;
		while(i<strlen(s))	{
			// cout << s[i] << "\n";
			if(s[i]=='(')	{
				i += 1;
				continue;	
			}
			else	{
				if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
					SY.push(s[i]);
				else	{
					if(s[i] == ')')	{
						LE.push(SY.top());
						SY.pop();
					}
					else
						LE.push(s[i]);
				}
			}
			i += 1;
		}
		vector<char> p;
		while(!LE.empty())	{
			p.pb(LE.top());
			LE.pop();
		}
		REP(i,p.size())	{
			cout<<p[p.size()-i-1];
		}
		cout << "\n";
	}
	return 0;
}
