#include <bits/stdc++.h>

bool check_cycle(int src, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, int parent)
{
  visited[src] = 1;
  for (auto i : adj[src])
  {
    if (i != parent)
    {
      if (visited[i])
        return true;
      if (!visited[i] && check_cycle(i, adj, visited, src))
        return true;
    }
  }
  return false;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> adj(n);
  int u, v;
  for (int i = 0; i < m; i++)
  {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::vector<bool> visited(n, false);
  bool cycle = false;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && check_cycle(i, adj, visited, -1))
    {
      cycle = true;
    }
  }
  if (cycle)
    std::cout << "The cycle is present";
  else
    std::cout << "There is no cycle";
}
