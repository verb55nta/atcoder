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


#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll ,ll );
ll mod_add(ll ,ll );
ll mod_mul(ll ,ll );
ll mod_div(ll ,ll );
void make_fact(ll );
void make_invfact(ll );

struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};

int main(void){

  ll n,m,p;
  cin>>n>>m>>p;

  vector<ll> d(n+1,INF);
  d[1]=0;

  vector<edge> edges;
  rep(i,m){
    int x,y,z;
    cin>>x>>y>>z;
    edge e;
    e.from=x;
    e.to=y;
    e.cost=p-z;
    edges.push_back( e );
  }

  bool loop=false;

  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < (int)edges.size(); j++) {
        struct edge e = edges[j];
        if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
            d[e.to] = d[e.from] + e.cost;
            if (i == n) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                //cout << "negative loop" << endl;
                loop=true;
                break;
            } 
        }
    }
  }

  /*
  for(auto x:d) cout << x << " ";
  cout << endl;
  */
  /**
  if( loop && d[n]<0){
    cout << -1 << endl;
  }
  */

  if(loop){
    ll cmp=d[n];
    for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < (int)edges.size(); j++) {
          struct edge e = edges[j];
          if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
              d[e.to] = d[e.from] + e.cost;
              if (i == n) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                  //cout << "negative loop" << endl;
                  loop=true;
                  break;
              } 
          }
      }
    }

    if( cmp > d[n] ) cout << -1 << endl;
    else{
      cout << max( 0LL, -d[n] ) << endl;
    }

  }

  else{
    cout << max( 0LL, -d[n] ) << endl;
  }

  return 0;

}

ll mod_pow(ll x,ll r){
  if(r==0) return 1;
  else if(r==1) return x%mod;
  else if(r%2==0){
    ll t=mod_pow(x,r/2)%mod;
    return t*t %mod;
  } 
  else{
    ll t=mod_pow(x,r/2)%mod;
    ll k= t*t %mod;
    return k*x%mod;
  } 
}
ll mod_add(ll a,ll b){
  return (a+b)%mod;
}

ll mod_mul(ll a,ll b){
  return (a*b)%mod;
}

ll mod_div(ll a,ll b){
  return mod_mul(a,mod_pow(b,mod-2));
}

void make_fact(ll n){
  fac[0]=1;
  rep(i,n){
    fac[i+1]=mod_mul(fac[i],i+1);
  }  
}

void make_invfact(ll n){
  invfac[n]= mod_pow( fac[n] ,mod-2);
  for(int i=n-1;i>=0;i--){
    invfac[i]=mod_mul(invfac[i+1],i+1);
  }

}