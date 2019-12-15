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

ll nn;


ll search(vector<set<string>> &ini,vector<string> cand,ll cnt){

  if(cnt >= nn) return 1LL;

  int ans=0;

  for(auto t:ini[cnt]){
    //cout << t << endl;
    if(find(all(cand),t) != cand.end()) continue;
    else{
      cand.pb(t);
      ans+=search(ini,cand,cnt+1);
      cand.pop_back();
    }

  }
  return ans;
}

int main(void){

  ll n;
  cin>>n;

  nn=n;

  vector<string> s(n);

  vector<set<string> > ini(n);

  rep(i,n) cin>>s[i];

  

  for(ll cnt=0;cnt<n;cnt++){

    rep(i,s[cnt].size()){
      for(ll j=i+1;j<s[cnt].size();j++){
        string tmp="";
        tmp+=s[cnt][i];
        tmp+=s[cnt][j];
        ini[cnt].insert(tmp);
      }
    }
    //for(auto t:ini[cnt]) cout << t << " ";
    //cout << endl;
  }

  vector<string> k(0);

  ll ans=search(ini,k,0);

  cout << ans << endl;

  return 0;

}
