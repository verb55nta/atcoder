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
  vector<char> a(26,0);
  vector<char> b(26,0);
  int mmax,temp_max;
  mmax=0;
  cin>>N;
  cin>>s;

  for(int i=0;i<N;i++){

    for(int j=0;j<i;j++){
      a[s[j]-'a']=1;
    }
    for(int j=i;j<N;j++){
      b[s[j]-'a']=1;
    }
    temp_max=0;
    for(int j=0;j<26;j++){
      if(a[j]==b[j] and a[j]!= 0) temp_max++;
    }

    if(temp_max > mmax) mmax=temp_max;

    for(int j=0;j<26;j++){
      a[j]=0;
      b[j]=0;
    }

  }

  cout << mmax << endl;

  return 0;
}
