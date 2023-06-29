#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 325;
const int MAXM = 100005;

struct OPR
{
	int p,t;
	ll v;
	OPR(int p_ = 0,int t_ = 0,ll v_ = 0)
	{
		p = p_;
		t = t_;
		v = v_;
	}
};

struct QUE
{
	int a,b;
	int c,d;
	int t,v;
	QUE(int a_ = 0,int b_ = 0,int c_ = 0,int d_ = 0,int t_ = 0,int v_ = 0)
	{
		a = a_;
		b = b_;
		c = c_;
		d = d_;
		t = t_;
		v = v_;
	}
};

int n,m,k,Q;
int ans[MAXM];
int nextt[MAXM];

ll sum[MAXM];

bool flag;

pair<int,ll> tmp[MAXM];
pair<int,ll> state[MAXM];

vector<OPR> opr;
vector<QUE> que,temp;
vector<vector<int> > t;
vector<vector<int> > f;

inline void add(int x,ll v)
{
	x = m - x + 1;
	while (x <= m)
	{
		sum[x] += v;
		x += (x & -x);
	}
}

inline ll ask(int x)
{
	x = m - x + 1;
	ll ret = 0;
	while (x >= 1)
	{
		ret += sum[x];
		x -= (x & -x);
	}
	return ret;
}

void search(int id,int l,int r,int vl,int vr,int pl,int pr)
{
	if (l > r)
		return;
	if (vl == vr)
	{
		for (int i = l;i <= r;i++)
			t[id][state[i].first] = nextt[vl];
		return;
	}
	int mid = (vl + vr) >> 1,pmid = pr;
	for (int i = pl;i <= pr;i++)
	{
		if (opr[i].t > mid)
		{
			pmid = i - 1;
			break;
		}
		add(opr[i].p,opr[i].v);
	}
	int L = l - 1,R = r + 1;
	for (int i = l;i <= r;i++)
	{
		ll val = ask(state[i].first);
		if (state[i].second + val < k)
		{
			state[i].second += val;
			tmp[--R] = state[i];
		}
		else
			tmp[++L] = state[i];
	}
	for (int i = l;i <= r;i++)
		state[i] = tmp[i];
	for (int i = pl;i <= pmid;i++)
		add(opr[i].p,-opr[i].v);
	search(id,l,L,vl,mid,pl,pmid);
	search(id,R,r,mid + 1,vr,pmid + 1,pr);
}

void divide(int lx,int rx,int ly,int ry,int l,int r)
{
	if (lx > rx || ly > ry || l > r)
		return;
	if (rx - lx + 1 > ry - ly + 1)
	{
		int mid = (lx + rx) >> 1,L = l - 1,R = r + 1;
		for (int i = ly;i <= ry;i++)
		{
			f[mid][i] = t[mid][i];
			for (int j = mid - 1;j >= lx;j--)
				f[j][i] = min(t[j][i],f[j + 1][i]);
			for (int j = mid + 1;j <= rx;j++)
				f[j][i] = min(t[j][i],f[j - 1][i]);
			for (int j = i - 1;j >= ly;j--)
				f[mid][j] = min(t[mid][j],f[mid][j + 1]);
			for (int j = i + 1;j <= ry;j++)
				f[mid][j] = min(t[mid][j],f[mid][j - 1]);
			for (int j = mid - 1;j >= lx;j--)
				for (int k = i - 1;k >= ly;k--)
					f[j][k] = min(t[j][k],max(f[j + 1][k],f[j][k + 1]));
			for (int j = mid - 1;j >= lx;j--)
				for (int k = i + 1;k <= ry;k++)
					f[j][k] = min(t[j][k],max(f[j + 1][k],f[j][k - 1]));
			for (int j = mid + 1;j <= rx;j++)
				for (int k = i - 1;k >= ly;k--)
					f[j][k] = min(t[j][k],max(f[j - 1][k],f[j][k + 1]));
			for (int j = mid + 1;j <= rx;j++)
				for (int k = i + 1;k <= ry;k++)
					f[j][k] = min(t[j][k],max(f[j - 1][k],f[j][k - 1]));
			for (int j = l;j <= r;j++)
				if (que[j].a <= mid && que[j].c >= mid && que[j].b <= i && que[j].d >= i)
					ans[que[j].t] = max(ans[que[j].t],min(f[que[j].a][que[j].b],f[que[j].c][que[j].d]));
		}
		for (int i = l;i <= r;i++)
		{
			if (que[i].c < mid)
				temp[++L] = que[i];
			if (que[i].a > mid)
				temp[--R] = que[i];
		}
		for (int i = l;i <= r;i++)
			que[i] = temp[i];
		divide(lx,mid - 1,ly,ry,l,L);
		divide(mid + 1,rx,ly,ry,R,r);
	}
	else
	{
		int mid = (ly + ry) >> 1,L = l - 1,R = r + 1;
		for (int i = lx;i <= rx;i++)
		{
			f[i][mid] = t[i][mid];
			for (int j = i - 1;j >= lx;j--)
				f[j][mid] = min(t[j][mid],f[j + 1][mid]);
			for (int j = i + 1;j <= rx;j++)
				f[j][mid] = min(t[j][mid],f[j - 1][mid]);
			for (int j = mid - 1;j >= ly;j--)
				f[i][j] = min(t[i][j],f[i][j + 1]);
			for (int j = mid + 1;j <= ry;j++)
				f[i][j] = min(t[i][j],f[i][j - 1]);
			for (int j = i - 1;j >= lx;j--)
				for (int k = mid - 1;k >= ly;k--)
					f[j][k] = min(t[j][k],max(f[j + 1][k],f[j][k + 1]));
			for (int j = i - 1;j >= lx;j--)
				for (int k = mid + 1;k <= ry;k++)
					f[j][k] = min(t[j][k],max(f[j + 1][k],f[j][k - 1]));
			for (int j = i + 1;j <= rx;j++)
				for (int k = mid - 1;k >= ly;k--)
					f[j][k] = min(t[j][k],max(f[j - 1][k],f[j][k + 1]));
			for (int j = i + 1;j <= rx;j++)
				for (int k = mid + 1;k <= ry;k++)
					f[j][k] = min(t[j][k],max(f[j - 1][k],f[j][k - 1]));
			for (int j = l;j <= r;j++)
				if (que[j].b <= mid && que[j].d >= mid && que[j].a <= i && que[j].c >= i)
					ans[que[j].t] = max(ans[que[j].t],min(f[que[j].a][que[j].b],f[que[j].c][que[j].d]));
		}
		for (int i = l;i <= r;i++)
		{
			if (que[i].d < mid)
				temp[++L] = que[i];
			if (que[i].b > mid)
				temp[--R] = que[i];
		}
		for (int i = l;i <= r;i++)
			que[i] = temp[i];
		divide(lx,rx,ly,mid - 1,l,L);
		divide(lx,rx,mid + 1,ry,R,r);
	}
}

int main()
{
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> Q;
	if (n > m)
	{
		swap(n,m);
		flag = true;
	}
	t.resize(n + 1);
	f.resize(n + 1);
	for (int i = 1;i <= n;i++)
	{
		t[i].resize(m + 1);
		f[i].resize(m + 1);
	}
	for (int tp,a,b,c,d,v,i = 1;i <= Q;i++)
	{
		cin >> tp;
		if (tp == 1)
		{
			cin >> a >> b >> c >> d >> v;
			nextt[i] = i;
			if (flag)
				swap(a,b),swap(c,d);
			temp.push_back(QUE(a,b,c,d,i,v));
		}
		else
		{
			cin >> a >> b >> c >> d;
			if (flag)
				swap(a,b),swap(c,d);
			que.push_back(QUE(a,b,c,d,i,0));
		}
	}
	nextt[Q + 1] = Q + 1;
	for (int i = Q;i >= 1;i--)
		if (!nextt[i])
			nextt[i] = nextt[i + 1];
	for (int i = 1;i <= n;i++)
	{
		opr.clear();
		for (int j = 0;j < temp.size();j++)
			if (temp[j].a <= i && temp[j].c >= i)
			{
				opr.push_back(OPR(temp[j].b - 1,temp[j].t,-temp[j].v));
				opr.push_back(OPR(temp[j].d,temp[j].t,temp[j].v));
			}
		opr.push_back(OPR(m,Q + 1,k));
		for (int j = 1;j <= m;j++)
			state[j] = make_pair(j,0);
		search(i,1,m,0,Q + 1,0,opr.size() - 1);
	}
	temp.resize(que.size());
	divide(1,n,1,m,0,que.size() - 1);
	for (int i = 1;i <= Q;i++)
		if (ans[i])
		{
			if (ans[i] >= i)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	return 0;
}