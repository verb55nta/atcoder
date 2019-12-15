#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int x;

  int val;

  int val_max=1;

  cin>>x;

  if(x==1){
    cout << 1 << endl;
    return 0;
  }

  for(int i=2;i <= sqrt(x);i++){

    for(int j=2;powl(i,j) <= x ;j++){
      //cout << powl(i,j) << endl;
      if(val_max < powl(i,j)) val_max= powl(i,j);
    }

  }

  cout << val_max << endl;

  return 0;
}
