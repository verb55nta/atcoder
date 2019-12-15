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

struct node{
  vector< pair<ll,ll> > next;
};

void dfs(){

}

int main(void){

  ll n,m;
  cin>>n>>m;

  auto pair_cout = []( pair<ll,ll> c ){ cout << c.first << "," << c.second << endl; };

  vector< vector<node> > g( 3,vector<node>(n+1) );
  vector< vector<ll> > cost( 3,vector<ll>(n+1,10*n) );
  vector< vector<bool> > been(3,vector<bool>(n+1,false));

  rep(i,m){
    ll u,v;
    cin>>u>>v;
    
    //g[0][u].next.pb( &g[1][v] );
    g[0][u].next.pb( make_pair(1,v) );
    //g[1][u].next.pb( &g[2][v] );
    g[1][u].next.pb( make_pair(2,v) );
    //g[2][u].next.pb( &g[0][v] );
    g[2][u].next.pb( make_pair(0,v) );

  }
  ll s,t;
  cin>>s>>t;

  queue< pair<ll,ll> > que;

  cost[0][s]=0;

  que.push( make_pair(0,s) );

  while(que.size()>0){
    auto q=que.front();
    que.pop();
    //pair_cout(q);
    
    ll c=cost[q.first][q.second];

    for(auto n: g[q.first][q.second].next ){
      if( cost[n.first][n.second] > c+1 ){
        cost[n.first][n.second]=c+1;
        que.push( n );
      }
      
    }

  }


  if( cost[0][t]==10*n ) cout << -1 << endl;
  else cout << cost[0][t]/3 << endl;

  return 0;

}
