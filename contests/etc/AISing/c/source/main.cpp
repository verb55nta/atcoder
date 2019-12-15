#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

typedef uint_fast64_t uif;

int dir[2][4] = { {1,0,-1,0},{0,1,0,-1} }; //x,y
int cnt;
int h,w;
char s[400][400];
vector< vector<int> > c(400,vector<int>(400,-1));

int search(int i,int j){
  if(c[i][j] != -1) return 0;
  int suc=0;
  for(int k=0;k<4;k++){
    if(j + dir[0][k] >=0 && j + dir[0][k] <w){
      if(i + dir[1][k] >=0 && i + dir[1][k] <h){
        if( s[i][j] != s[ i + dir[1][k] ][ j + dir[0][k] ] ){
          c[i][j]=cnt;
          suc=1;
          search(i + dir[1][k],j + dir[0][k]);
        }
      }
    }
  }

  if(suc == 0){
    return 0;
  }
  else{
    return 1;
  }

}

int main(void){

  cin>>h;
  cin>>w;

  //vector<string> s(0);

  //cout << h << "," << w << endl;
  for(int i=0;i<h;i++){
    string str;
    cin>>str;

    for(int j=0;j<w;j++){
      s[i][j]=str[j];
      //cout << s[i][j] ;
    }
    //cout << endl;
  }

  //vector< vector<int> > c(h,vector<int>(w,-1));

  cnt=0;

  //c[0][0]=0;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(search(i,j) != 0){
        cnt++;
      }
    }
    //cout << endl;
  }
  ///*
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      //cout << c[i][j] ;
    }
    //cout << endl;
  }
  //cout << cnt << endl;
  //*/
  vector< vector<long long int> > aa(cnt+1,vector<long long int>(2,0));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(c[i][j]==-1) continue;
      if(s[i][j]=='#'){
        aa[c[i][j]][0]++;
      }
      else{
        aa[c[i][j]][1]++;
      }
    }
  }
  long long int ans=0;
  for(int i=0;i<cnt;i++){
    //cout << aa[i][0] << "," << aa[i][1] << endl;
    ans+=aa[i][0]*aa[i][1];
  }
  cout << ans << endl;

  return 0;
}
