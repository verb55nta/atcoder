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

ll all_wh(string &s){

  ll cnt=0;
  for(auto c:s){
    if(c!='.') cnt++;
  }
  return cnt;
}

ll all_bl(string &s){

  ll cnt=0;
  for(auto c:s){
    if(c!='#') cnt++;
  }
  return cnt;
}

ll change_bl(string &s,ll n){
  ll cnt=0;
  for(int i=n;i<s.size();i++){
    if(s[i]!='#') cnt++;
  }
  return cnt;
}

ll change_wh(string &s,ll n){

  ll cnt=0;
  for(int i=0;i<n;i++){
    if(s[i]!='.') cnt++;
  }
  return cnt;

}

int main(void){

  ll n;
  string s;
  cin>>n;
  cin>>s;

  ll f_wh=-1;
  ll f_bl=-1;
  ll af_wh=-1;
  ll sc_wh=-1;
  ll af_bl=-1;

  char pre='a';

  vector<ll> w;
  vector<ll> b;
  ll _w=0;
  ll _b=0;

  for(ll i=0;i<n;i++){

    

    //cout << pre << "," << s[i] << endl;
    if(f_wh==-1 && s[i]=='.') f_wh = i;
    if(f_bl==-1 && s[i]=='#') f_bl = i;

    if(pre=='#' && s[i]=='.' && af_wh==-1) af_wh=i;
    else if(pre=='#' && s[i]=='.' && af_wh!=-1) sc_wh=i;
    else if(pre=='.' && s[i]=='#' && af_bl==-1) af_bl=i;
    pre=s[i];
    if(s[i]=='.') _w++;
    else _b++;
    w.pb(_w);
    b.pb(_b);
  }

  //cout << f_wh << "," << f_bl << "," << af_wh << "," << af_bl << "," << sc_wh << endl;

  if(af_wh==-1){
    cout << 0 << endl;
    return 0;
  }
  else{
    ll ans=1LL<<20;
    ans=min(ans,all_bl(s));
    ans=min(ans,all_wh(s));
    
    if(sc_wh!=-1){
      rep(i,n){
        //cout << b[i]+(w[n-1]-w[i]) << endl;
        ans = min(ans, b[i]+(w[n-1]-w[i]) );
      }
    }
    
    cout << ans << endl;
  }

  return 0;

}
