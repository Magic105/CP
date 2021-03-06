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
int oo = 0x3f3f3f3f;
pair<int,int> doll[20003];
vector<pair<int,int> > v;
int N;

bool fn(const pair<int,int>& L, const pair<int,int>& R){
    if(L.first == R.first){
        return L.second > R.second;
    } else {
        return L.first < R.first;
    }
}

void solv(){
    sort(doll, doll+N, fn);
    v.clear();
    v.push_back(doll[N-1]);
    for(int i=N-2;i>=0;--i){
        int hi = v.size()-1, lo = 0, mid;
        while(lo <= hi){
            mid = (hi+lo)/2;
            if(v[mid].first == doll[i].first
               || v[mid].second <= doll[i].second){
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        if(lo == v.size()){
            v.push_back(doll[i]);
        } else {
            v[lo].second = doll[i].second;
            v[lo].first = doll[i].first;
        }
    }
    cout<<v.size()<<"\n";
}

class NestedDolls {
public:
	void solve(istream& cin, ostream& cout) {
        int tc, u, v;
        scanf("%d", &tc);
        while(tc--){
            scanf("%d", &N);
            for(int i=0;i<N;++i){
                scanf("%d %d", &u, &v);
                doll[i] = make_pair(u,v);
            }
            solv();
        }

	}
};
