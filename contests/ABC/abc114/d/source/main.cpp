#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int N;
  cin >> N;

  int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  int num[15];
  for(int i=0;i<15;i++){
    num[i]=0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<15;j++){
      int val=i+1;
      while(val%prime[j] == 0){
        //cout << val << endl;
        num[j]++;
        val/=prime[j];
      }
    }
  }
  int judge[5]={2,4,14,24,74};
  int judge_num[5]={0,0,0,0,0};
  for(int i=0;i<15;i++){
    for(int j=0;j<5;j++){
      if( num[i] >= judge[j] ) judge_num[j]++;
    }
    //cout <<num[i] << " ";
  }
  for(int j=0;j<5;j++){
    //cout << judge_num[j] << " ";
  }
  int res = judge_num[1]*(judge_num[1]-1)*(judge_num[1]-2)/2 + (judge_num[0]-judge_num[1])*judge_num[1]*(judge_num[1]-1)/2
          + judge_num[2]*(judge_num[2]-1) + (judge_num[1]-judge_num[2])*judge_num[2]
          + judge_num[3]*(judge_num[3]-1) + (judge_num[0]-judge_num[3])*judge_num[3]
          + judge_num[4];
  cout << res << endl;



  return 0;
}
