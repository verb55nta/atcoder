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


#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll ,ll );
ll mod_add(ll ,ll );
ll mod_mul(ll ,ll );
ll mod_div(ll ,ll );
void make_fact(ll );
void make_invfact(ll );

int cnt_l(string s){
  ll ans=0;
  for(ll i=1;i<s.size();i++){
    if(s[i-1]=='L' &&s[i]=='L') ans++;
  }
  return ans;
}
int cnt_r(string s){
  ll ans=0;
  for(ll i=0;i<s.size()-1;i++){
    if(s[i]=='R' &&s[i+1]=='R') ans++;
  }
  return ans;
}

int cnt_both(string s){
  ll ans=0;
  for(ll i=0;i<s.size();i++){
    char c=s[i];
    if(c=='L'){
      if(i!=0) if(s[i-1]=='L' &&s[i]=='L') ans++;
    }
    else{
      if(i!=s.size()-1) if(s[i+1]=='R' && s[i]=='R') ans++;
    }
  }
  return ans;  
}

int main(void){

  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;

  priority_queue< pair<ll,ll> > pql;
  priority_queue< pair<ll,ll> > pqr;
  ll tmp=0;
  ll start=-1;
  rep(i,n){
    if( s[i]=='R' ){
      if(tmp>0){
        pql.push( make_pair(tmp,start) );
        tmp=0;
      }
      
    }
    else{
      if(tmp==0){
        start=i;
      }
      tmp++;
    }
    
  }
  if(tmp>0) pql.push( make_pair(tmp,start) );
  tmp=0;
  start=-1;
  rep(i,n){
    if( s[i]=='L' ){
      if(tmp>0){
        pqr.push( make_pair(tmp,start) );
        tmp=0;
      }
      
    }
    else{
      if(tmp==0){
        start=i;        
      }
      tmp++;
    }
    
  }
  if(tmp>0) pqr.push( make_pair(tmp,start) );
  cout << cnt_both(s)<< endl;
  ll ori_n=cnt_both(s);
  /*
  while(!pql.empty()){
    auto p=pql.top();
    pql.pop();
    cout << p.first << "," << p.second << endl;
  }
  cout << endl;
  while(!pqr.empty()){
    auto p=pqr.top();
    pqr.pop();
    cout << p.first << "," << p.second << endl;
  }
  */
  auto ori_s=s;

  ll cand_l=ori_n;
  ll cand_r=ori_n;

  ll cnt=k;
  //cout << "pql" << endl;
  while(!pql.empty() && cnt>0 ){
    auto p=pql.top();
    pql.pop();
    if(p.second==0) cand_l++;
    else if(p.first+p.second==n) cand_l++;
    else cand_l+=2;
    cnt--;
    cout << p.first << "," << p.second << endl;
    cout << cand_l << endl;
  }
  cnt=k;
  //cout << "pqr" << endl;
  while(!pqr.empty() && cnt>0 ){
    auto p=pqr.top();
    pqr.pop();
    if(p.second+p.first==n) cand_r++;
    else if(p.second==0) cand_r++;
    else cand_r+=2;
    cnt--;
    cout << p.first << "," << p.second << endl;
    cout << cand_r << endl;
  }
  cout << max(cand_l,cand_r) << endl;

  return 0;

}

ll mod_pow(ll x,ll r){
  if(r==0) return 1;
  else if(r==1) return x%mod;
  else if(r%2==0){
    ll t=mod_pow(x,r/2)%mod;
    return t*t %mod;
  } 
  else{
    ll t=mod_pow(x,r/2)%mod;
    ll k= t*t %mod;
    return k*x%mod;
  } 
}
ll mod_add(ll a,ll b){
  return (a+b)%mod;
}

ll mod_mul(ll a,ll b){
  return (a*b)%mod;
}

ll mod_div(ll a,ll b){
  return mod_mul(a,mod_pow(b,mod-2));
}

void make_fact(ll n){
  fac[0]=1;
  rep(i,n){
    fac[i+1]=mod_mul(fac[i],i+1);
  }  
}

void make_invfact(ll n){
  invfac[n]= mod_pow( fac[n] ,mod-2);
  for(int i=n-1;i>=0;i--){
    invfac[i]=mod_mul(invfac[i+1],i+1);
  }

}