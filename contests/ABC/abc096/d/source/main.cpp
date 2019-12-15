#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int n;
  int flag;
  vector<int> prime(0);
  cin>>n;

  //int prime[55556];

  for(int i=2;i<=55555;++i ) {
    flag = 0;
    for(int j=2;j<i;++j ){
      if( i%j==0 ) {
        flag = 1;
        break;
      }
    }

    if( flag==0 ){
      prime.push_back(i);
    }
      //printf("%d ", i);
  }

  //for(int x:prime) cout << x << endl;
  int p_cnt=0;
  for(int x:prime){
    if(x==2){
      cout << x << endl;
      p_cnt++;
      if(p_cnt>=n) break;
    }
    else if(x%10 == 7){
      cout << x << endl;
      p_cnt++;
      if(p_cnt>=n) break;      
    }
  }

  
  
  return 0;
}
