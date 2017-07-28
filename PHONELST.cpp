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

char PH[10007];

struct node	{
	// node* par;
	char init;
	vector<node*>chi;
	int leaf;
	
	node(char in)	{
		init=in;
		chi={};
		leaf=0;
	}

};

int fin(vector<node*>F,node* a)	{
	for(int i=0; i<F.size(); i++)	{
		if(F[i] -> init==a -> init)
			return i;
	}	
	return -1;
}

struct trie	{
	node* root;
	trie(node* R)	{
		root=R;
	}
	int insert(vector<node*> a)	{
		// return -1;
		node* iter=this -> root;
		int j=0;
		while(iter -> chi.size() > 0)	{
			if(fin(iter -> chi, a[j]) != -1)	{
				iter=iter -> chi[fin(iter -> chi, a[j])];
				j ++;
			}
			else	{
				break;
			}
			if(j >= a.size() || iter -> chi.size() <= 0)
				return -1;
			// cout << j << endl;
		}
		while(j<a.size())	{
			iter -> chi.pb(a[j]);
			iter=a[j];
			j += 1;
		}
		return 0;
	}
};

int main()	{
	int t;
	scanf("%d",&t);

	while(t)	{

		t-=1;
		int n;
		scanf("%d",&n);
		node* ROOT=new node('P');
		trie TRIE(ROOT);
		int x;
		int ifff=0;
		for(int i=0; i<n; i++)	{
			scanf("%s",PH);
			vector<node*> A(strlen(PH));
			for(int i=0; i<strlen(PH); i++)	{
				A[i]=new node(PH[i]);
			}

			if(i == 0)	{
				node* iter=TRIE.root;
				for(int z=0; z<A.size(); z++)	{
					iter -> chi.pb(A[z]);
					iter=A[z];
				}
				
			}
			else	{

				x=TRIE.insert(A);
				if(x == -1)
					ifff=-1;
			}
			// cout << ROOT -> chi.size() << endl;
		}
		
		if(ifff == -1)
			printf("NO\n");
		else
			printf("YES\n");
		
	}
	return 0;
}
