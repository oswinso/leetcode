#include <iostream>
#include <vector>

class Solution
{
public:
  int uniquePaths(int m, int n) {
    std::vector<int> row(n, 1);

    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < m; j++){
        row[j] += row[j - 1];
      }
    }

    return row.back();
  }
private:
};

int main()
{
  Solution solution;
  std::cout << solution.uniquePaths(3, 3);
}