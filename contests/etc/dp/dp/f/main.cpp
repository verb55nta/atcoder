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

  string s,t;
  cin>>s;
  cin>>t;

  vector< vector< ll > > dp(3002,vector<ll>(3002,0));

  string lcs;

  rep(i,s.size()+1){
    rep(j,t.size()+1){

      if(s[i] == t[j]){
        dp[i+1][j+1] = max({dp[i][j]+1,dp[i][j+1],dp[i+1][j]});

      }
      else{
        dp[i+1][j+1] = max({dp[i][j+1],dp[i+1][j]});
      }

    }
  }

  rep(i,s.size()+1){
    rep(j,t.size()+1){
      //cout << dp[i][j] << " ";
    }
    //cout << endl;
  }

  ll i=s.size(),j=t.size();
  ll cnt=dp[i][j];
  if(cnt==0){
    cout << "" << endl;
    return 0;
  }
  while(i>0 && j>0){

    while(cnt==dp[i][j-1] && j>1) j--;
    while(cnt==dp[i-1][j] && i>1) i--;

    lcs+=s[i-1];
    //cout << i << "," << j << endl;
    //cout << s[i-1] << "," << t[j-1] << endl;
    i--;
    j--;
    cnt--;
    if(cnt==0) break;

  }

  reverse(all(lcs));

  cout << lcs << endl;

  return 0;

}
