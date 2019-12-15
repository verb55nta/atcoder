#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<ios>
#include<iomanip>

using namespace std;

int main(void){

  int n,m;
  cin >> n;
  cin >> m;

  vector<int> p(m);
  vector<int> y(m);
  //cout << m << endl;
  for(int i=0;i<m;i++){

    cin >> p[i];
    cin >> y[i];

  }

  vector< vector<int> > pre(n+1,vector<int>(0));

  //cout << pre.size() << endl;
  //cout << pre[0].size() << endl;

  for(int i=0;i<m;i++){
    pre[p[i]].push_back(y[i]);
  }
  for(int i=1;i<n+1;i++){
    sort(pre[i].begin(),pre[i].end());
    for(int j=0;j<pre[i].size();j++){
      //cout << pre[i][j] << " ";
    }

    //cout << endl;
  }

  for(int i=0;i<m;i++){
    //auto itr = find(pre[p[i]].begin(),pre[p[i]].end(),y[i]);
    auto itr = lower_bound(pre[p[i]].begin(),pre[p[i]].end(),y[i]);
    //cout << distance(pre[p[i]].begin(),itr)+1 << endl;
    auto d=distance(pre[p[i]].begin(),itr)+1;
    cout << setfill('0') << right << setw(6) << p[i];
    cout << setfill('0') << right << setw(6) << d;
    cout << endl;
  }


  return 0;
}
