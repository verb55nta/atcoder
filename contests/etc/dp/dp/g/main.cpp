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

vector<ll> d(100001,-INF);
vector< vector<ll> > G(100001,vector<ll>(0));

ll dp(ll i){
  if(d[i] != -INF) return d[i];
  else if( G[i].size() == 0 ) return 0;
  else{
    ll G_max=-INF;
    for(auto e:G[i]){
      G_max=max(G_max,dp(e));
    }
    d[i]=G_max+1;
    return d[i];
  }
}

int main(void){

  ll n,m;
  cin>>n>>m;
  vector<ll> x(m);
  vector<ll> y(m);


  rep(i,m){
    cin>>x[i];
    cin>>y[i];
    G[x[i]].pb(y[i]);
  }
  /*
  for(auto g:G){
    for(auto gg:g){
      cout << gg << " ";
    }
    cout << endl;
  }
  */
  rep1(i,n){
    dp(i);
  }

  cout << *max_element(all(d)) << endl;

  return 0;

}
