#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pr;
int const INF = (1e6+7)/2;
int const N = 1e5+7;
vector <pr> adjList[N];
vector <bool> visited (N);
vector <int> dist (N, INF);
int parent[N];

void dijkstra(int src, int dst)
{
    priority_queue <pr, vector <pr>, greater<pr>> pq;
    dist[src] = 0;

    pq.push ({dist[src],src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pr v : adjList[u]) {
            int weight = v.first;
            int value = v.second;

            if (visited[value]) continue;

            if (dist[value] > dist [u] + weight) {
                dist [value] = dist[u] + weight;
                parent[value] = u;
                pq.push({dist[value], value});

            }
        }
    }
    cout << "Jumps needed to reach the destination " << dist[dst] << endl;
    vector <int> path;

    while (src != dst) {
        path.push_back(dst);
        dst = parent[dst];
    }
    path.push_back(dst);

    reverse(path.begin(), path.end());

    for (int i=0; i<path.size(); i++) {
        cout << "--> " << path[i] << " ";
    }
}

int main ()
{
    int node, edge; cin >> node >> edge;

    while (edge--)
    {
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back ({w,v});
        adjList[v].push_back ({w,u});
    }

    int src, dst; cin >> src >> dst;

    dijkstra (src, dst);

}
