/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl       "\n"
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
int oo = 0x3f3f3f3f;
 
int n,r;
vector<pii> pos,neg;
 
bool comp(pii a, pii b)
{
    return a.ff+a.ss>b.ff+b.ss;
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    clock_t clk = clock();
 
    cin>>n>>r;
    for(int  i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(y>=0)
        {
            pos.pb({x,y});
        }
        else
        {
            neg.pb({x,y});
        }
    }
    sort(pos.begin(),pos.end());
    for(int i=0;i<pos.size();i++)
    {
        if(r>=pos[i].ff)
        {
            r+=pos[i].ss;
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    trace(r);
    sort(neg.begin(),neg.end(),comp);
    for(int i=0;i<neg.size();i++)
    {
        if(r>=neg[i].ff)
        {
            r+=neg[i].ss;
            if(r<0)
            {
                cout<<"NO";
                return 0;
            }
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    clk = clock() - clk;
    cerr << "Time Elapsed: " << fixed << setprecision(10) << ((long double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}