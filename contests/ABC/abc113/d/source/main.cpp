#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include <bitset>

using namespace std;

int main(void){

  int h,w,k;
  cin >> h;
  cin >> w;
  cin >> k;
  const int mod=1000000007;

  vector< vector<uint64_t> > num(w,vector<uint64_t>(102,0));
  num[0][0]=1;

  for(int i=0;i<=h;i++){

    for(int j=0;j<w;j++){
      //num[j][i+1] = num[j][i];
      for(int k=0;k<(1 << (w-1));k++){

        bool check=true;
        for(int l=0;l<w-2;l++){
          if( (k >> l)&1 && (k >> l+1)&1 ) check=false;
        }

        if(!check) continue;

        if(j>=1 && (k >> (j-1))&1 ){
          num[j-1][i+1] += num[j][i];
          num[j-1][i+1] %= mod;
        }
        else if(j<= w-2 && ( k >> j )&1 ){
          num[j+1][i+1] += num[j][i];
          num[j+1][i+1] %= mod;
        }
        else{
          num[j][i+1] += num[j][i];
          num[j][i+1] %= mod;
        }

      }
      //cout << endl;
      //cout << num[j][i] << " ";
      //cout << log10(num[j][i]) << " ";
      //cout << endl;
      //num[j][i]%=(uint64_t)1000000007;

    }
    //cout << num[0][i] << endl;
    //cout << endl;
  }

  //cout << (uint64_t)(num[k-1][h]%(uint64_t)1000000007) << endl;
  cout << num[k-1][h] << endl;
  //uint64_t ans=num[k-1][h]%mod;
  //cout << ans << endl;

  return 0;
}
