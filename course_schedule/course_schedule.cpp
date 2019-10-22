#include <iostream>
#include <vector>

// class Solution
//{
// public:
//  using Adj = std::vector<std::vector<int>>;
//
//  std::pair<Adj, std::vector<int>> genAdj(int num_courses, const std::vector<std::vector<int>>& edges)
//  {
//    Adj adj(num_courses, std::vector<int>{});
//    std::vector<int> in_degree(num_courses, 0);
//
//
//    for (const auto& edge : edges)
//    {
//      auto to = edge[0];
//      auto from = edge[1];
//
//      adj[from].emplace_back(to);
//      in_degree[to]++;
//    }
//
//    return {adj, in_degree};
//  }
//
//  bool canFinish(int num_courses, const std::vector<std::vector<int>>& prerequisites)
//  {
//    auto [adj, in_degree] = genAdj(num_courses, prerequisites);
//
//    int taken_courses = 0;
//
//    // Find in_degree zero
//    std::vector<int> in_degree_zero;
//    for (int i = 0; i < num_courses; i++)
//    {
//      if (in_degree[i] == 0)
//        in_degree_zero.emplace_back(i);
//    }
//
//    while (!in_degree_zero.empty())
//    {
//      int cur_class = in_degree_zero.back();
//      in_degree_zero.pop_back();
//      taken_courses++;
//
//      for (const auto& to : adj[cur_class])
//      {
//        in_degree[to]--;
//        if (in_degree[to] == 0)
//        {
//          in_degree_zero.emplace_back(to);
//        }
//      }
//    }
//
//    return taken_courses == num_courses;
//  }
//};

class Solution
{
public:
  using Adj = std::vector<std::vector<int>>;

  std::pair<Adj, std::vector<int>> genAdj(int num_courses, const std::vector<std::vector<int>>& edges)
  {
    Adj adj(num_courses, std::vector<int>{});
    std::vector<int> in_degree(num_courses, 0);


    for (const auto& edge : edges)
    {
      auto to = edge[0];
      auto from = edge[1];

      adj[from].emplace_back(to);
      in_degree[to]++;
    }

    return {adj, in_degree};
  }

  // Approach: DFS, add node to "stack" to track visited, if we visit a visited node, then return false
  bool canFinish(int num_courses, const std::vector<std::vector<int>>& prerequisites)
  {
    std::vector<bool> visited(num_courses, false);
    std::vector<bool> rec_stack(num_courses, false);

    auto [adj, in_degree] = genAdj(num_courses, prerequisites);

    for (int i = 0; i < num_courses; i++)
    {
      if (!visited[i])
      {
        if (isCyclic(i, visited, rec_stack, adj))
        {
          return false;
        }
      }
    }

    return true;
  }

private:
  bool isCyclic(int node, std::vector<bool>& visited, std::vector<bool>& rec_stack, const Adj& adj)
  {
    visited[node] = true;
    rec_stack[node] = true;

    for (const auto to : adj[node])
    {
      if (!visited[to])
      {
        if (isCyclic(to, visited, rec_stack, adj))
        {
          return true;
        }
      }
      else if (rec_stack[to])
      {
        return true;
      }
    }

    rec_stack[node] = false;
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.canFinish(3, { { 2, 1 }, { 1, 0 }, {0, 2} }) << std::endl;
}
