#include <iostream>
#include <vector>

class Solution
{
  int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid)
  {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid.front().size();

    std::vector<int> row(cols, 1);
    for (int i = 0; i < cols; i++)
    {
      if (obstacleGrid[0][i] == 1)
      {
        row[i] = 0;
      }
    }

    for (int i = 1; i < rows; i++)
    {
      for (int j = 1; j < cols; j++)
      {

        if (obstacleGrid[i][j] == 1)
        {
          row[j] = 0;
        }
        else
        {
          row[j] += row[j - 1];
        }
      }
    }

    return row.back();
  }
};

int main()
{

}