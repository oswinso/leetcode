#include <iostream>
#include <vector>

class Solution
{
public:
  // Find indices i and j to maximize min(heights[i], heights[j]) * std::abs(i - j)
  // idea: Given (i, j), we can increase j as long as heights[i] < heights[j+1]
  // solution: start with leftmost and rightmost. volume can only increase with i increasing / j decreasing
  // We can always increase the volume by moving the one that's the min, as long as the next value is larger
  // => move until we get a value thats larger than the previous value
  int maxArea(const std::vector<int>& heights)
  {
    int left = 0;
    int right = heights.size() - 1;
    int max_water = 0;
    while (left < right)
    {
      int min_height = std::min(heights[left], heights[right]);
      std::cout << "h[l] = " << heights[left] << ", h[r] = " << heights[right] << std::endl;
      max_water = std::max(min_height * (right - left), max_water);
      std::cout << "cur_water: " << (right - left) * min_height << std::endl;

      if (heights[left] < heights[right])
        left++;
      else
        right--;
    }
    return max_water;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7});
}