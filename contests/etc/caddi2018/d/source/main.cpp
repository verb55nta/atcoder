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
  cin>>n;
  vector<int> a(n);

  for(int i=0;i<n;i++){
    cin>>a[i];
    //cout << a[i] << endl;
  }

  for(int i=0;i<n;i++){
    if(a[i]%2==1){
      cout << "first" << endl;
      return 0;
    }
  }
  cout << "second" << endl;

  return 0;
}
