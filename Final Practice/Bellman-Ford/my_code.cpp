#include <bits/stdc++.h>
using namespace std;
int nodes, edge;
const int INF = (10e6+2)/2;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
void bellmanford(vector<Edge>edgeList,int src, int dst)
{
    int dist[100], par[100];
    for (int i=0; i<100; i++) {
        dist[i]=INF;
        par[i]=i;
    }

    dist[src] = 0;
    int t=edge-1;

    while (t--) {
        for (int i=0; i<edgeList.size(); i++){
            Edge ed = edgeList[i];

            int u=ed.u, v= ed.v, w=ed.w;

            if (dist[u]!=INF and dist[v]> dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    for (int x=0; x<=nodes; x++) {
        for (int i=0; i<edgeList.size(); i++){
            Edge ed = edgeList[i];

            int u=ed.u, v= ed.v, w=ed.w;

            if (dist[v]> dist[u] + w) {
                cout << "Cycle Detected" << endl;
                cout << "Answer is negative infinity" << endl;
                return;
            }
        }
    }

    cout << "Jumps needed to reach destination: " << dist[dst] << endl;

    vector <int> path;

    while (src!=dst) {
        path.push_back(dst);
        dst = par[dst];
    }
    path.push_back(dst);
    reverse(path.begin(), path.end());

    for (int i=0; i<path.size(); i++) {
        cout << "--> " << path[i] << " ";
    }


}
int main ()
{
    cin >> nodes >> edge;
    int t=edge;
    vector <Edge> edgeList;

    while (t--) {
        int u, v, w; cin >> u >> v >> w;
        Edge ed (u, v, w);
        edgeList.push_back(ed);
    }
    int sr, ds; cin >> sr >> ds;
    bellmanford(edgeList, sr, ds);
}
