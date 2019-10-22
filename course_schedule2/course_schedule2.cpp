#include <iostream>
#include <vector>

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

  std::vector<int> findOrder(int num_courses, const std::vector<std::vector<int>>& prerequisites)
  {
    auto [adj, in_degree] = genAdj(num_courses, prerequisites);

    std::vector<int> out;

    // Find in_degree zero
    std::vector<int> in_degree_zero;
    in_degree_zero.reserve(num_courses);
    for (int i = 0; i < num_courses; i++)
    {
      if (in_degree[i] == 0)
        in_degree_zero.emplace_back(i);
    }

    while (!in_degree_zero.empty())
    {
      int cur_class = in_degree_zero.back();
      in_degree_zero.pop_back();
      out.emplace_back(cur_class);

      for (const auto& to : adj[cur_class])
      {
        in_degree[to]--;
        if (in_degree[to] == 0)
        {
          in_degree_zero.emplace_back(to);
        }
      }
    }

    if (out.size() != num_courses)
    {
      return {};
    }

    return out;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.canFinish(3, { { 2, 1 }, { 1, 0 }, {0, 2} }) << std::endl;
}
