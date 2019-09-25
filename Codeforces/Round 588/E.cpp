    
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
#define int     long long

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
const int N=1e5+10,mod=1e9+7;
int n,ans;
map<int,int> values, m[N];
vector<int> graph[N];

void dfs(int curr, int parent)
{
    m[curr][values[curr]]++;
    for(auto &p:m[parent])
    {
        m[curr][__gcd(values[curr],p.ff)]+=p.ss;
    }
    for(int i=0;i<graph[curr].size();i++)
    {
        if(graph[curr][i]!=parent)
        {
            dfs(graph[curr][i],curr);
        }
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        values[i]=x;
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto &p:m[i])
        {
            ans=(ans+((p.ff%mod)*(p.ss%mod))%mod)%mod;
        }
    }
    cout<<ans;
    return 0;
}
