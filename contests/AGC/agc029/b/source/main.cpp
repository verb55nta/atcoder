#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include <iterator>

using namespace std;

int main(void){
  int N;

  cin >> N;
  vector<int> A(N);
  vector<int> his(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  sort(A.begin(),A.end(),greater<int>());

  for(int i=0;i<N;i++){
    ////cout << A[i] << endl;
    his[i]=0;

  }
  int cnt=0;
  ////cout << (int)( 1 << 8 ) << endl;
  long long target= (long long)( 1 << 30 );

  int i=0;
  int mid=0;

  while(target > 1){
    target = (target >> 1);
    //cout << "target:" << target << endl;
    if(A[i] < target) continue;
    for( ;A[i]> target && i < A.size();i++){
      //cout << "i:" << i << endl;
      if(his[i]) continue;
        auto low = distance(A.begin(),lower_bound(A.begin()+mid,A.end(),2*target-A[i],greater<long long>()));
        auto up = distance(A.begin(),upper_bound(A.begin()+mid,A.end(),2*target-A[i],greater<long long>()));
        //cout << low << "," << up << endl;
        for ( ; (his[ low ] || low == i) && low < up; low++);
        //cout << "low:" << low << endl;
        if(low == up) continue;
        cnt++;
        his[i]=1;
        his[low]=1;
      }
      mid=0;
      for ( ; A[i] == target; i++) if (!his[i]) mid++;
      cnt += mid/2;

  }

  cout << cnt << endl;
  return 0;
}
