#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  long long int n,p;
  cin>>n;
  cin>>p;
  vector<long long int> prime(1000001,1);
  prime[0]=0;
  prime[1]=0;

  vector<long long int>pp(0);

  long long int ans=1;

  //cout << (long long int)pow(10,12) << endl;
  if(n==1){
    cout << p << endl;
    return 0;
  }

  for(int i=2;i<=1000000;i++){
      if(!prime[i] ) continue;
      else{
        for(int j=2;i*j<=1000000;j++){
          prime[i*j]=0;
        }
      }

  }
  for(int i=2;i<=1000000;i++){
    if(prime[i] ) pp.push_back(i);
  }
  for(int i=0;i<pp.size();i++){
    long long int cnt=0;
    while(p%pp[i]==0 && p>=pp[i]){
      cnt++;
      p=p/pp[i];
    }
    //cout << pp[i] << " ";
    //cout << "cnt:" << cnt << endl;
    /*
    if(cnt >= 1){
      //cout << pp[i] << " ";
      //cout << "cnt:" << cnt << endl;
      ans*=(long long int)(pow(pp[i],cnt/n));
    }
    */
    for(int j=0;j<(cnt/n);j++){
      ans*=pp[i];
    }
  }

  cout << ans << endl;

  return 0;
}
