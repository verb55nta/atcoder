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

  ll a,b,q;
  cin>>a>>b>>q;

  vector<ll> s(100001,INF);
  vector<ll> t(100001,2LL*INF);
  vector<ll> qq(q);


  rep(i,a){
    cin>>s[i];
  }
  rep(i,b){
    cin>>t[i];
  }
  rep(i,q){
    cin>>qq[i];

    auto s_k=distance(s.begin(),upper_bound(all(s),qq[i]));
    auto t_k=distance(t.begin(),upper_bound(all(t),qq[i]));
    //cout << s_k << "," << t_k << ":";
    //cout << s[s_k] << "," << t[t_k] << endl;

    ll before_s,before_t,after_s,after_t;

    if(s_k == 0) before_s=-INF;
    else before_s=s[s_k-1];
    if(t_k == 0) before_t=-2LL*INF;
    else before_t=t[t_k-1];



    after_s=s[s_k];
    after_t=t[t_k];

    //cout << before_s << "," << before_t << "," << after_s << "," << after_t << endl;

    cout << min( { abs(before_s-before_t)+min(abs(before_s-qq[i]),abs(before_t-qq[i])) , abs(after_s-after_t)+min(abs(after_s-qq[i]),abs(after_t-qq[i])) , abs(before_s-after_t)+min(abs(before_s-qq[i]),abs(after_t-qq[i])) , abs(before_t-after_s)+min(abs(before_t-qq[i]),abs(after_s-qq[i])) } ) << endl;

  }



  return 0;

}
