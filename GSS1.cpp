#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000;
int n;

int sum[N];
int msum[N];
int presum[N];
int sufsum[N];

// segment tree
int st[2*N];

void init(int p, int val)	{
	sum[p]=val;
	msum[p]=val;
	presum[p]=val;
	sufsum[p]=val;
}

void count(int i)	{
	sum[i]=sum[2*i]+sum[2*i+1];
	msum[i]=max(max(msum[2*i], msum[2*i+1]), sufsum[2*i]+presum[2*i+1]);
	presum[i]=max(presum[2*i], sum[2*i]+presum[2*i+1]);
	sufsum[i]=max(sufsum[2*i+1], sum[2*i+1]+sufsum[2*i]);
}

void print()	{
	for(int i=1; i<2*n; i++)	{
		cout<<st[i]<<" ";
	}
	cout<<endl;
}

void build()	{
	for(int i=n-1; i>0; i--)	
		// st[i]=st[2*i]+st[2*i+1];
		count(i);
}

// set value at position p
void modify(int p, int value)	{
	p+=n;
	st[p]=value;
	init(p, value);
	while(p>1)	{
		// st[p >> 1]=st[p]+st[p^1];
		count(p>>1);
		p >>= 1;
	}
}

// sum on interval [l, r)
int query(int l, int r)	{
	int res=-1e9;
	int lsum=0;
	vector<int> LNL;
	vector<int> RNL;
	l+=n;
	r+=n;
	while(l<r)	{
		if(l&1)	{ LNL.push_back(l); res+=st[l++]; }
		if(r&1)	{ RNL.push_back(r-1); res+=st[--r]; }
		l >>= 1;
		r >>= 1;
	}
	for(int i=RNL.size()-1; i>=0; i--)
		LNL.push_back(RNL[i]);
	for(int i=0; i<LNL.size(); i++)	{
		res=max(res, msum[LNL[i]]);
		res=max(res, lsum+presum[LNL[i]]);
		lsum=max(sufsum[LNL[i]], lsum+sum[LNL[i]]);
	}
	return res;
}

int main()	{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cin>>n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)	{
		// cin>>st[i+n];
		int c;
		scanf("%d", &c);
		st[n+i]=c;
		init(n+i, c);
	}
	build();
	// print();
	int q;
	// cin>>q;
	scanf("%d", &q);
	while(q)	{
		q--;
		int l, r;
		scanf("%d %d", &l, &r);
		// cin>>l>>r;
		// if(t==1)	
		//	modify(l, r);
		// else
		// cout<<query(l-1, r)<<endl;
		printf("%d\n", query(l-1, r));
	}
	return 0;
}