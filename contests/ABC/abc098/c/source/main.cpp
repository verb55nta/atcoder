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
  string s;
  cin>>N;
  cin>>s;
  int mmin=N;
  int temp_min=0;
  int no_east=0;
  int no_west;

  for(int j=1;j<N;j++){
    if(s[j] != 'W' ) temp_min++;
  }
  no_west=temp_min;
  //cout << no_east << "," << no_west << endl;
  mmin=no_east+no_west;
  for(int i=1;i<N;i++){
    if( s[i-1] != 'E' ) no_east++;
    if( s[i] == 'E' ) no_west--;
    if(mmin > no_east+no_west) mmin = no_east+no_west ;
    //cout << no_east << "," << no_west << endl;
  }


  cout << mmin << endl;

  return 0;
}
