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

  vector<string> s(h);

  rep(i,h) cin>>s[i];

  vector< vector<ll> > row( h,vector<ll>(w,0) );
  vector< vector<ll> > col( h,vector<ll>(w,0) );

  char prev='#';

  rep(i,h){
    ll cnt=0;
    ll start=-1;
    prev='#';
    rep(j,w){
      //cout << s[i][j] << endl;
      if(s[i][j]=='#'){
        if(start==-1){
          cnt=0;
          start=-1;
          prev='#';
          continue;
        }
        if(prev=='.'){
          for(ll k=start;k<j;k++){
          //cout << i << "," << k << endl;
          row[i][k]=cnt;
          }
        }
        cnt=0;
      }
      else{
        if(prev=='#'){
          start=j;
          //cout << i << "," << start << endl;
        }
        cnt++;
      }

      
      prev=s[i][j];
    }

    if(prev=='.'){
      for(ll k=start;k<w;k++){
          row[i][k]=cnt;
        }
      cnt=0;
    }

  }
  /*
  rep(i,h){
    rep(j,w){
      cout << row[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  /*/



  prev='#';

  rep(i,w){
    ll cnt=0;
    ll start=0;
    prev='#';
    rep(j,h){
      if(s[j][i]=='#'){
         if(start==-1){
          cnt=0;
          start=-1;
          prev='#';
          continue;
        }
        if(prev=='.'){
          for(ll k=start;k<j;k++){
          //cout << k << "," << i << endl;
          col[k][i]=cnt;
          }
        }
        
        cnt=0;
      }
      else{
        if(prev=='#'){
          start=j;
        }
        cnt++;
      }


      prev=s[j][i];
    }

    if(prev=='.'){
      for(ll k=start;k<h;k++){
          col[k][i]=cnt;
        }
      cnt=0;
    }
  }
  /*
  rep(i,h){
    rep(j,w){
      cout << col[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  */  

  ll ans=0;

  rep(i,h){
    rep(j,w){
      ans=max(ans,row[i][j]+col[i][j]-1);
    }
  }

  cout << ans << endl;

  return 0;

}
