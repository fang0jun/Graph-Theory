#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define PF push_front
#define P push
#define INC(i,a,b) for (ll i = a; i <= b; i++)
#define DEC(i,b,a) for (ll i = b; i >= a ; i--)
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define mod  1000000007
#define eps 1e-9
typedef ostringstream OS ;
typedef stringstream SS ;
typedef long long ll ;
typedef unsigned long long ull;
typedef pair < ll , ll > PLL ;
typedef pair < char,ll > PCL ;
typedef deque < double > DD ;
typedef deque < PCL > DCL ;
typedef deque < ll > DL ;
typedef deque < PLL > DLL ;
typedef deque < char > DC ;
typedef deque < string > DS ;
typedef vector < double > VD;
typedef vector < PCL > VCL ;
typedef vector < ll > VL;
typedef vector < PLL > VLL ;
typedef vector < char > VC ;
typedef vector < string > VS ;
typedef map < ll ,ll > MLL ;
typedef map < char,ll > MCL;
typedef map < ll,char > MLC;
typedef map < string,ll> MSL;
typedef priority_queue < PLL > PQLL ;
typedef priority_queue < ll > PQL ;
typedef stack < ll > SKL ;
typedef stack < PLL > SKLL ;
typedef queue < ll > QL ;
typedef queue < PLL > QLL ;
typedef set < ll > SL ;
typedef set < PLL > SLL ;
typedef set < char > SC ;
 
string numtostr(ll n) {
     OS str1 ;
     str1 << n ;
     return str1.str();
}
ll strtonum(string s) {
     ll x ;
     SS str1(s);
     str1 >> x ;
     return x ;
}
ll GCD(ll a, ll b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}
ll LCM(ll a , ll b) {
    ll gcd = GCD(a,b);
     return (a/gcd)*b ;
}
ll vertex,edges ;
vector < pair<PLL,ll> > graphedge ;
VL dist ;
void setting() {
    graphedge.clear();
}
bool bellmanford() {
    dist.clear();
    dist.resize(vertex+5,0);
    bool fact ;
    INC(i,1,vertex) {
        fact = false ;
        INC(j,0,graphedge.size()-1) {
            ll startnode = graphedge[j].F.F;
            ll endnode = graphedge[j].F.S;
            ll weight = graphedge[j].S;
            if ( dist[startnode]+weight < dist[endnode]) {
                dist[endnode] = dist[startnode]+weight ;
                fact = true ;
            }
        }
    }
    if (fact) return true ;
    else return false ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        ll ratio ;
        scanf("%lld %lld %lld",&vertex,&edges,&ratio);
        setting();
        INC(i,1,edges) {
            ll node1,node2,profit,loss ;
            scanf("%lld %lld %lld %lld",&node1,&node2,&profit,&loss);
            ll val = (loss*ratio)-profit ;
            graphedge.PB({{node1,node2},val});
        }
        bool fact = false ;
        if (edges) fact = bellmanford();
        if(fact)printf("Case %lld: YES\n",++caseno);  
        else printf("Case %lld: NO\n",++caseno);  
    }
 
    return 0 ;
}
