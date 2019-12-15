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
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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

  int n,m;
  cin>>n>>m;
  //cout << n << " " << m << endl;
  int k;
  //vector<ll> k(n);
  //vector< vector<ll> > a(n,vector<ll>(0));
  vector<ll> food(m,(ll)0);

  rep(i,n){
    cin>>k;
    //cout << k << " ";
    rep(j,k){
      ll a;
      cin>>a;
      //cout << a << " " ;
      //a[i].pb(_a);
      food[a-1]++;
    }
    //cout << endl;
  }
  ll ans=0;
  rep(i,m){
    if(food[i]==n) ans++;
  }

  cout << ans << endl;

  return 0;
}