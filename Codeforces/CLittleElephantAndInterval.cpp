#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define mp make_pair
#define ll long long
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

ll l,r;

ll find(ll n)
{
	if(n==0)
		return 0;

	if(n>=1 && n<=9)
		return n;

	ll ans=(n/10)+8;
	string str=to_string(n);
	if(str[0]<=str[str.length()-1])
		ans++;
	return ans;
}

class CLittleElephantAndInterval {
public:
	void solve(istream& cin, ostream& cout) {
		cin>>l>>r;
		cout<<find(r)-find(l-1);
	}
};