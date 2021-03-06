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
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
int oo = 0x3f3f3f3f;
class C1IncreasingSubsequenceEasyVersion {
    int n;
    vector<int> arr;
public:
	void solve(istream& cin, ostream& cout) {
		cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;arr.pb(x);
        }
        int l=0,r=n-1,prev=0;
        string ans="";

        while(l<=r)
        {
            if(arr[l]<prev && arr[r]<prev)
            {
                break;
            }
            else{
                if((arr[l]<arr[r] && arr[l]>prev)||(arr[r]<prev) )
                {
                    ans+='L';prev=arr[l];l++;
                }
                else{
                    if(arr[r]>prev)
                    {    ans+='R';prev=arr[r];r--;}
                    else
                        break;
                }

            }
        }
        cout<<ans.length()<<endl<<ans;
	}
};
