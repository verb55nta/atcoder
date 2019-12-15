#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  string s;
  cin>>s;
  int k;
  cin>>k;

  vector<string> s_set;

  if(s.length()==1){
    cout << s << endl;
    return 0;
  }

  for(int i=1;i<=s.length() and i <= 5;i++){
    for(int j=0;j<s.length()-i+1;j++){
      s_set.push_back(s.substr(j,i));
    }
  }

  for(string kk:s_set){
    //cout << kk << endl;
  }

  //cout << endl;

  sort(s_set.begin(),s_set.end());

  for(string kk:s_set){
    //cout << kk << endl;
  }

  //cout << endl;

  s_set.erase(unique(s_set.begin(),s_set.end()),s_set.end());

  for(string kk:s_set){
    //cout << kk << endl;
  }

  //cout << endl;

  cout << s_set[k-1] << endl;

  return 0;
}
