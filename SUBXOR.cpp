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

const int MAXLOG=50;

struct Node	{
	int init;
	Node* left;
	Node* right;
	int sub_left;
	int sub_right;
	Node(int in)	{
		init=in;
		left=NULL;
		right=NULL;
		sub_left=0;
		sub_right=0;
	}
};

struct TRIE	{
	Node* root;
	TRIE(Node* R)	{
		root=R;
	}	

	
	void insert(Node* root, int num, int level)	{
		if(level==-1)
			return;
		int x=(num>>level&1);
		if(x == 1)	{
			if(root -> right==NULL)	{
				Node* R=new Node(x);
				root -> right=R;
				// insert(root->right, num, num_index, level-1, log_limit);
			}
			insert(root->right, num, level-1);
			root->sub_right += 1;
		}
		else	{
			if(root -> left==NULL)	{
				Node* L=new Node(x);
				root -> left=L;
			} 
			insert(root->left, num, level-1);
			root->sub_left += 1;
		}
	}	

	int query(Node* root, int num, int level, int k)	{
		if(level==-1 || root==NULL)
			return 0;
		
		int x=(num>>level)&1;
		int y=(k>>level)&1;
		
		if(y)	{
			if(x==0)	{
				return root->sub_left + query(root->right, num, level-1, k);
			}
			else	{
				return root->sub_right + query(root->left, num, level-1, k);
			}
		}
		else	{
			if(x==0)	
				return query(root->left, num, level-1, k);
			else
				return query(root->right, num, level-1, k);
		}
	}
	
};

int main()	{
	int t;
	scanf("%d",&t);
	while(t)	{
		t--;
		int n,k;
		scanf("%d%d",&n,&k);
		vi keep(n);		

		for(int i=0; i<n; i++)	{
			int num;
			scanf("%d",&keep[i]);
		}


		Node* root=new Node(-1);
		TRIE trie(root);		
		trie.insert(root, 0, MAXLOG);

		int q, p=0;
		ll ans=0;

		for(int i=0; i<keep.size(); i++)	{
			q=p^keep[i];
			ans = ans + ll(trie.query(root, q, MAXLOG, k));
			trie.insert(root, q, MAXLOG);
			p=q;
		}
	
		printf("%lld\n",ans);
	}

	return 0;
}
