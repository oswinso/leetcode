#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
  using AdjList = std::vector<std::vector<int>>;

  std::pair<AdjList, std::vector<int>> parseEdges(int num_courses, const std::vector<std::vector<int>>& prerequisites)
  {
    AdjList adj_list(num_courses, std::vector<int>{});

    std::vector<bool> no_prereqs(num_courses, true);

    for (const auto& edge : prerequisites)
    {
      auto to = edge[0];
      auto from = edge[1];
      adj_list[from].emplace_back(to);
      no_prereqs[to] = false;
    }

    std::vector<int> no_prereq;
    for (int cls = 0; cls < num_courses; cls++)
    {
      if (no_prereqs[cls])
      {
        std::cout << cls << " ";
        no_prereq.emplace_back(cls);
      }
    }
    std::cout << std::endl;

    return {adj_list, no_prereq};
  }

  bool canFinish(int numCourses, const std::vector<std::vector<int>> &prerequisites) {
    auto [adj, queue] = parseEdges(numCourses, prerequisites);

    if (queue.empty())
    {
      return false;
    }

    std::vector<bool> can_take(numCourses, false);

    while (!queue.empty())
    {
      std::vector<int> new_queue;
      for (const auto cls : queue)
      {
        can_take[cls] = true;

        for (const auto next_classes : adj[cls])
        {
          if (!can_take[next_classes])
          {
            can_take[next_classes] = true;
            new_queue.emplace_back(next_classes);
          }
        }
      }
      queue = std::move(new_queue);
    }
    return std::find(can_take.begin(), can_take.end(), false) == can_take.end();
  }
};

int main() {
  Solution solution;
  std::cout << solution.canFinish(3, {{0, 1}, {1, 2}, {0, 1}});
}