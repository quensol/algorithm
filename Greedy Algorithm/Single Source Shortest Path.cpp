#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(vector<vector<int>> &graph, int src) {
  // 初始化距离数组
  vector<int> dist(graph.size(), INT_MAX);
  dist[src] = 0;

  // 使用优先队列来维护未访问过的节点
  priority_queue<pair<int, int>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    // 取出距离最小的节点
    int u = pq.top().second;
    pq.pop();

    // 遍历 u 的邻居
    for (int v = 0; v < graph.size(); v++) {
      // 存在边并且距离可以更新
      if (graph[u][v] > 0 && dist[v] > dist[u] + graph[u][v]) {
        dist[v] = dist[u] + graph[u][v];
        pq.push({dist[v], v});
      }
    }
  }

  // 打印最短路径
  for (int i = 0; i < dist.size(); i++) {
    cout << "从 " << src << " 到 " << i << " 的最短路径为：" << dist[i] << endl;
  }
}

int main() {
  // 图的邻接矩阵
  vector<vector<int>> graph = {{0, 10, 5, 0}, {10, 0, 2, 1}, {5, 2, 0, 3}, {0, 1, 3, 0}};

  // 源节点
  int src = 0;

  dijkstra(graph, src);

  return 0;
}
