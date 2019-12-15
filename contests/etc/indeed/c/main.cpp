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

  ll n;
  cin>>n;

  vector<ll> s(n);
  vector<ll> C(n);

  rep(i,n){
    cin>>s[i];
    cin>>C[i];
  } 

  ll S,K;
  cin>>S>>K;

  ll ans=0;

  map<ll,ll> his;

  ll cur=S;

  ll loop_start=-1;

  while(K>0){

    if( his.count(cur)>0 ){
      loop_start=cur;
      his[cur]=1LL;
      ans+=C[cur-1];
      cur=s[cur-1];
      K--;
      break;
    }
    else{
      his[cur]=1LL;
      ans+=C[cur-1];
      cur=s[cur-1];
      
    }

    K--;
  }

  if(K==0){
    cout << ans << endl;
    return 0;
  }
  else{
    ll one_loop=C[loop_start-1];
    vector<ll> round;
    round.pb(loop_start);
    while(cur!=loop_start && K>0){
      round.pb(cur);
      his[cur]=1LL;
      ans+=C[cur-1];
      one_loop+=C[cur-1];
      cur=s[cur-1];
      
      
      K--;

    }

    if(K==0){
      cout << ans << endl;
      return 0;
    }
    else{
      /*
      cout << "start:" << loop_start << endl;
      for(auto x:round) cout << x << " ";
      cout << endl;
      cout << "loop:" << one_loop << endl;
      cout << K << endl;
      //*/
      ll rs=K/round.size();
      ans+=rs*one_loop;
      if(K%round.size()==0){
        cout << ans << endl;
      }
      else{
        K=K%round.size();
        cur=loop_start;
        while(K>0){
          ans+=C[cur-1];
          cur=s[cur-1];
          K--;
          //cout << K << endl;
        }
        cout << ans << endl;
      }

    } 

  }

  return 0;

}
