#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

//class Solution
//{
//public:
//  std::vector<std::string> generateParentheses(int n)
//  {
//    if (n == 1)
//    {
//      return {"()"};
//    }
//
//    return generateParentheses(n, n, 0, "");
//  }
//
//  std::vector<std::string> generateParentheses(int open_rem, int close_rem, int cur_open, const std::string& str)
//  {
//    // No more open paren, rest are all close_paren
//    if (open_rem == 0)
//    {
//      std::stringstream result_str;
//      for (int i = 0; i < close_rem; i++)
//      {
//        result_str << ")";
//      }
//      return {result_str.str()};
//    }
//
//    std::vector<std::string> out;
//
//    // If open_rem > 0, can generate next by adding (
//    if (open_rem > 0)
//    {
//      auto vec = generateParentheses(open_rem - 1, close_rem, cur_open + 1, str + "(");
//      out.insert(out.end(), vec.begin(), vec.end());
//    }
//
//    if (cur_open > 0)
//    {
//      auto vec = generateParentheses(open_rem, close_rem - 1, cur_open - 1, str + ")");
//      out.insert(out.end(), vec.begin(), vec.end());
//    }
//
//    for (auto& s : out)
//    {
//      s = str + s;
//    }
//
//    return out;
//  }
//};
class Solution
{
public:
  std::vector<std::string> generateParenthesis(int n)
  {
    std::vector<std::string> result;
    result.reserve(1024);
    if (n < 1)
      return result;
    std::string str_buffer;
    generateParentheses(result, str_buffer, n, n);
    return result;
  }

  void generateParentheses(std::vector<std::string>& out, std::string& str, int left_rem, int right_rem)
  {
    if (left_rem == 0 && right_rem == 0)
    {
      out.emplace_back(str);
      return;
    }

    if (left_rem > 0)
    {
      str.push_back('(');
      generateParentheses(out, str, left_rem - 1, right_rem);
      str.pop_back();
    }
    if (left_rem < right_rem)
    {
      str.push_back(')');
      generateParentheses(out, str, left_rem, right_rem - 1);
      str.pop_back();
    }
  }
};

int main()
{
  Solution solution;
  auto parens = solution.generateParenthesis(4);

  for (const auto& str : parens)
  {
    std::cout << str << std::endl;
  }
}