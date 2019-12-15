#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int d_dfs(int);

int v[100000][100000];
int v_flag[100000];

int main(void){

  int n,m;
  cin>>n;
  cin>>m;

  vector<int> p(n);
  vector<int> x(m);
  vector<int> y(m);



  int cnt=0;

  for(int i=0;i<n;i++){
    cin >> p[i];
  }

  for(int i=0;i<m;i++){
    cin >> x[i];
  }

  for(int i=0;i<m;i++){
    cin >> y[i];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      v[i][j] = 0;
    }
  }

  for(int i=0;i<m;i++){
    v[x[i]][y[i]]=1;
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      v[i][j] = v[i][j] | v[j][i];
    }
  }

  for(int i=0;i<n;i++){

    for(int j=0;j<n;j++){
      v_flag[j]=0;
    }

    if(p[i] == i){
      cnt++;
      continue;
    }
    else{
      int start=i;
      int goal=p[i];

      d_dfs(start);

    }

  }

  return 0;
}


int d_dfs(int a){

  v_flag[a]=1;

  for(int i=0;i<100000;i++){
    if(v_flag[v[a][i]] == 0){
      d_dfs(i);
    }
  }

}
