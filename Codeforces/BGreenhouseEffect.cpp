/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
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
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"
#define int long long

using namespace std;
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;

vector<string> split(const string& s, char c) {
	vector<string> v; stringstream ss(s); string x;
	while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
	stringstream s; s << "[";
	for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
		s << arr[n - 1] << "]";
	return s.str();
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
    template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
int oo = 0x3f3f3f3f;

int n,m,arr[5005],cache[5005][5005];
long double position[5005];

int dp(int curr,int species)
{
	if(curr==n)
		return 0;
	if(cache[curr][species]!=-1)
		return cache[curr][species];
	if(arr[curr]==species)
	{
		cache[curr][species]=dp(curr+1,species);
	}
	else if(arr[curr]>species)
	{
		cache[curr][species]=min(1+dp(curr+1,species),dp(curr+1,arr[curr]));
	}
	else
	{
		cache[curr][species]=1+dp(curr+1,species);
	}
	return cache[curr][species];
}

int32_t main() 
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif

	fastIO;

    // int testcases;cin>>testcases;
    // while(testcases--)
    // {
	memset(cache,-1,sizeof(cache));
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i]>>position[i];
	}

	cout<<dp(0,1)<<endl;
    // }

	return 0;
}
