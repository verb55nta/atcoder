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

vector< vector<ll> > dp(100001,vector<ll>(2,-1)); //0:not black ,1:black
vector<ll> node[100001];
vector<ll> node_true[100001];
vector<bool> HasCome(100001,false);

ll search(ll n){
  if(HasCome[n]) return 0;
  HasCome[n]=true;

  if(node[n].size()==1 && n!=1){
    dp[n][0]=1;
    dp[n][1]=1;

    return 1;
  }
  dp[n][0]=1;
  dp[n][1]=1;
  for(auto x:node[n]){
    if(search(x)==1LL){
    dp[n][0]*=(dp[x][0]+dp[x][1]);
    dp[n][0]%=mod;
    dp[n][1]*=(dp[x][0]);
    dp[n][1]%=mod;
    }
  }

  return 1;
}

int main(void){

  ll n;
  cin>>n;

  rep(i,n-1){
    ll x,y;
    cin>>x>>y;
    node[x].pb(y);
    node[y].pb(x);
  }


  search(1);

  cout << (dp[1][0]+dp[1][1])%mod << endl;
  return 0;

}
