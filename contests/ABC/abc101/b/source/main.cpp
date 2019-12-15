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
int N_a=N;
//cout << N << endl;
int sum=0;
while(N>0){
  sum+=N%10;
  N/=10;
}
//cout << sum << endl;

//cout<<N_a%sum<< endl;
if(N_a%sum==0) cout << "Yes" << endl;
else cout << "No" << endl;

  return 0;
}
