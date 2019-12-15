#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<memory>

using namespace std;

class UnionFind{
private:
  UnionFind *parent;
  int rank;
  //UnionFind *t_root;
public:
  UnionFind(){
    parent=this;
    rank=0;
  }
  UnionFind *root(UnionFind *x){
    if(x->parent == x){
      return x;
    }
    else{
      //return root(x->parent);
      x->parent=root(x->parent);
      return x->parent;
    }

    return 0;
  }
  int _union(UnionFind *x){
    UnionFind *rx=root(x);
    UnionFind *rt=root(this);

    if(rx->rank > rt->rank) rt->parent = rx;
    else if(rx->rank < rt->rank) rx->parent = rt;
    else if(rx != rt){
      rt->parent = rx;
      rx->rank+=1;
    }

    //rx->parent=rt;
    return 0;
  }
  int find(UnionFind *x){
    if(root(x) == root(this)){
      return 1;
    }
    else{
      return 0;
    }
  }
  void show_root(){
    cout << this->root(this) << endl;
  }
};

void show_v(vector< vector<int> > &v,int n);

int par[100001];
int rnk[100001];

void init(int);
int rt(int);
bool same(int,int);
void unite(int,int);

int main(void){

  int n,m;
  cin>>n;
  cin>>m;

  vector<int> p(n+1);
  vector<int> x(m);
  vector<int> y(m);
  /*
  vector< vector<int> > v(n,vector<int>(n,0));
  */
  int cnt=0;

  for(int i=1;i<n+1;i++){
    cin >> p[i];
  }

  for(int i=0;i<m;i++){
    cin >> x[i];
    cin >> y[i];
  }

  //show_v(v,n);
  /*
  for(int i=0;i<m;i++){
    v[y[i]-1][x[i]-1] = 1;
  }
  */
  /*
  init(n);

  for(int i=0;i<m;i++){
    unite(x[i],y[i]);
    //unite(y[i]-1,x[i]-1);
  }

  for(int i=1;i<n+1;i++){
    if(i == p[i]){
      cnt++;
      continue;
    }
    else{
    }
  }
  cout << cnt << endl;
  */
  //show_v(v,n);
  ///*
  vector< UnionFind > graph(n+1);

  for(int i=0;i<m;i++){
    graph[y[i]]._union(&graph[x[i]]);
  }

  for(int i=1;i<n+1;i++){
    //graph[i].show_root();
  }

  for(int i=1;i<n+1;i++){
    cnt+=graph[i].find(&graph[p[i]]);
  }

  cout << cnt << endl;
  //*/
  //cout << "debug" << endl;

  //for(int i=1;i<n+1;i++) cout << par[i] << endl;

  return 0;
}

void show_v(vector< vector<int> > &v,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    rnk[i]=0;
  }
}
int rt(int x){

  return par[x]==x ? x : par[x]=rt(par[x]);
}
bool same(int x,int y){
  return rt(x) == rt(y);
}
void unite(int x,int y){
  int temp_x;
  int temp_y;
  temp_x=rt(x);
  temp_y=rt(y);

  if(temp_x==temp_y) return ;
  if(rnk[temp_x] < rnk[temp_y]){
    par[temp_x]=temp_y;
  }
  else{
    par[temp_y]=temp_x;
    if(rnk[temp_x] == rnk[temp_y]) rnk[temp_x]++;
  }
}
