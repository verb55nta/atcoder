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
  cin>>N;
  vector<long long> A(N);


  int temp_cnt=0;
  int cnt=0;
  long long x1,x2;
  int before_end=0;
  for(int i=0;i<N;i++) cin>>A[i];
  x1=0;
  for(int i=0;i<N;i++){
    int next_st=i;
    if(i!=0){
      x1= (x1 xor A[i-1]);
      if(before_end > i) next_st=before_end;
      else next_st=i;
      cnt+=before_end-i;
      cout << "cnt;" << cnt << endl;

    }
    if(next_st == N-1){
      cnt++;
      continue;
    }
    temp_cnt=0;
    for(int j=next_st;j<N;j++){
      if( (x1 xor A[j]) == x1+A[j] ){
        //temp_cnt++;
        cout << i << "," << j << endl;
        cnt++;
        x1=(x1 xor A[j]);
        before_end=j;
      }
      else{
        //cnt+=temp_cnt;
        cout << i << "," << j << endl;
        //before_end=j;
        cout << before_end << endl;
        break;
      }

    }
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}
