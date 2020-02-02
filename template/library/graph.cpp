#include <vector>

#define INF INT_MAX
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long int;
using namespace std;
using vec = vector<ll>;
using mat = vector<vector<ll>>;

struct edge
{
    ll to, cost, id;
};

class Graph
{
public:
    ll N;
    vector<vector<edge>> G;

    Graph(ll N) : N(N)
    {
        G = vector<vector<edge>>(N, vector<edge>(0));
    }

    void add_Directed_edge(ll from, ll to, ll cost = 1, ll id = 0)
    {
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(ll v1, ll v2, ll cost = 1, ll id = 0)
    {
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    mat waeshall_floyd()
    {
        mat d(N, vec(N, INF));
        REP(i, N)
        d[i][i] = 0;
        REP(i, N)
        for (edge e : G[i])
        {
            d[i][e.to] = min(d[i][e.to], e.cost);
        }
        REP(k, N)
        REP(i, N)
        REP(j, N)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        return d;
    }
    vec dikstra(ll x)
    {
        vec distance(N, INF);
        distance[x] = 0;
        PQG<pa> pque;
        pque.push(make_pair(0, x));

        while (!pque.empty())
        {

            auto pq = pque.top();
            pque.pop();
            for (auto e : G[pq.second])
            {
                ll d = distance[pq.second] + e.cost;
                if (d < distance[e.to])
                {
                    distance[e.to] = d;
                    pque.push(make_pair(d, e.to));
                }
            }
        }

        return distance;
    }
};