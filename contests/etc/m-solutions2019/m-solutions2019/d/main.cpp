#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<bits/stdc++.h>
#include<queue>
#include<set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define INF bit(60)
#define pb push_back
#define mod 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;
using uif=uint_fast64_t;
using ll=long long int;

int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct Tree{

  ll val;
  ll par;
  vector<Tree*> child;

};

int main(void){

  ll n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> b(n);

  vector<ll> is_made(n+1,0);

  map<ll, vector<ll> > next_map;

  rep(i,n-1){
    cin>>a[i];
    cin>>b[i];

    next_map[ a[i] ].pb( b[i] );
    next_map[ b[i] ].pb( a[i] );

  }
  vector<ll> c(n);

  rep(i,n) cin>>c[i];

  sort(all(c),greater<ll>() );
  vector<ll> way(n+1);

  

  //stack<Tree*> sta;
  stack<ll> sta;
  sta.push(1);
  is_made[1]=1;

  ll cnt=0;

  way[1]=c[cnt];
  cnt++;

  while(sta.size()>0){
    auto val=sta.top();
    sta.pop();
    //cout << node->val << endl;
    //cout << next_map[1].size() << endl;
    for(auto x: next_map[ val ]){
      //pripare(x);
      //if(x.first==node->par) continue;
      if(is_made[x]==1) continue;
      else{
        
        is_made[x]=1;
        way[x]=c[cnt];
        cnt++;

        sta.push(x);

      }
    }

  }
  ll ans=0;
  for(ll i=1;i<=n;i++){
    //cout << way[i] << " ";
    if(i!=1) ans+=way[i];
  }
  
  cout << ans << endl;
  for(ll i=1;i<=n;i++){
    cout << way[i] << " ";
  }
  cout << endl;
  

  return 0;

}
