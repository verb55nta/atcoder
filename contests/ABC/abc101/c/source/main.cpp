#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int N,k;
  cin>>N;
  cin>>k;
  int A[N];
  int min_i;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]==1) min_i=i;
  }

  int cnt=0;
  if(N==k){
    cout << 1 << endl;
    return 0;
  }
  if(min(min_i,N-min_i)<=k){
    cnt=(N-k)/(k-1)+1;
    if((N-k)%(k-1)!=0) cnt++;
    cout << cnt << endl;
    return 0;
  }
  /*
  if(N%k==0 ){
    cnt=N/k;
    cout << cnt << endl;
    return 0;
  }
  */
  /*
  cnt=(min_i)/(k-1) + (N-1-min_i)/(k-1);
  if((min_i)%(k-1)!=0 ) cnt++;
  if((N-1-min_i)%(k-1)!=0) cnt++;
  */
  cnt=(N-k)/(k-1)+1;

  cout << cnt << endl;

  return 0;
}
