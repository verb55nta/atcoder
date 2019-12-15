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

  ll h,w;
  cin>>h>>w;

  vector< vector<char> > a(h,vector<char>(w));
  vector< vector<ll> > dp(h,vector<ll>(w,0));
  //vector< vector<bool> > used(h,vector<bool>(w,false));
  vector< vector<bool> > q_used(h,vector<bool>(w,false));
  queue<pair<ll,ll>> que;
  dp[0][0]=1;
  que.push(make_pair(0,0));
  q_used[0][0]=true;

  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
      if(a[i][j] == '#') dp[i][j]=-INF;
      //cout << a[i][j];
    }
    //cout << endl;
  }

  while(!que.empty()){
    pair<ll,ll> c=que.front();
    //cout << c.first << "," << c.second << endl;
    que.pop();
    for(ll i=0;i<2;i++){
      if( !(c.first+dx[i]>=0 && c.first+dx[i]<w && c.second+dy[i]>=0 && c.second+dy[i]<h ) ) continue;
      if(dp[c.second+dy[i]][c.first+dx[i]] == -INF) continue;
      if(q_used[c.second+dy[i]][c.first+dx[i]] == true) continue;
      que.push(make_pair(c.first+dx[i],c.second+dy[i]));
      q_used[c.second+dy[i]][c.first+dx[i]] = true;
    }
    for(ll i=2;i<4;i++){
      if( !(c.first+dx[i]>=0 && c.first+dx[i]<w && c.second+dy[i]>=0 && c.second+dy[i]<h ) ) continue;
      if(dp[c.second+dy[i]][c.first+dx[i]] == -INF) continue;
      dp[c.second][c.first] += dp[c.second+dy[i]][c.first+dx[i]];
      dp[c.second][c.first] %= mod;
    }

  }
  /*
  rep(i,h){
    rep(j,w){
      if(dp[i][j] == -INF) cout << "x" << " ";
      else cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */

  cout << dp[h-1][w-1] << endl;

  return 0;

}
