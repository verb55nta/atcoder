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


int main(void){

  ll n,ww;
  cin>>n>>ww;
  vector<ll> w(n);
  vector<ll> v(n);
  vector<ll> min_weight(100001,INF);
  vector<ll> old_min_weight(100001,INF);
  rep(i,n){
    cin>>w[i];
    cin>>v[i];
  }
  min_weight[0]=0;
  old_min_weight[0]=0;
  rep(i,n){
    rep(j,100001){
      if(j+v[i] > 100000) continue;
      old_min_weight[j+v[i]] = min(min_weight[j]+w[i],min_weight[j+v[i]]);
    }
    rep(j,100001){
      min_weight[j] = old_min_weight[j];
    }
    rep(j,20){
      //cout << min_weight[j] << " ";
    }
    //cout << endl;
  }
  ll ans=0;
  rep(i,100001){
    if(min_weight[i] <= ww) ans=i;
  }

  cout << ans << endl;

  return 0;

}
