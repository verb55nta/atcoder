#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int n,a,b;
  cin>>n;
  cin>>a;
  cin>>b;

  int a_num=0;
  int b_num=0;
  int c_num=0;

  vector<int> p(n);

  for(int i=0;i<n;i++){
    cin>>p[i];
    if(p[i]<=a){
      a_num++;
    }
    else if(p[i]>a && p[i]<=b){
      b_num++;
    }
    else{
      c_num++;
    }
  }

  cout << min({a_num,b_num,c_num}) << endl;


  return 0;
}
