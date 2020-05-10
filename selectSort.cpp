/**
 * @file selectSort.cpp
 * @author your name (you@domain.com)
 * @brief 选择排序
 * 
 * 步骤:
 *  1、搜索整个列表，找出最小项，若此项不为第1项，则与第1项交换位置
 *  2、重复上述步骤，每次搜索未被排序的剩余列表，并将最小元素与已排序段的后一位交换，直至列表所有元素均被排序
 * 
 * 稳定性：不稳定算法
 * 
 * 排序方式：In-place
 * 
 * 时间复杂度：
 *  平均：O(n^2)
 *  最好：O(n^2)
 *  最坏：O(n^2)
 * 
 * 空间复杂度：O(1)
 * 
 * 为什么是不稳定：
 * 举个例子，序列5 8 5 2 9，我们知道第一遍选择第1个元素5会和2交换，那么原序列中2个5的相对前后顺序就被破坏了，
 * 所以选择排序不是一个稳定的排序算法。
 * 
 * @version 0.1
 * @date 2020-05-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include <iostream>
#include <vector>
#include <iterator>

void selectSort(std::vector<int> &vec)
{
  for (std::size_t i = 0; i < vec.size(); i++)
  {
    auto minInx = i;
    for (std::size_t j = i + 1; j < vec.size(); j++)
    {
      if (vec[minInx] > vec[j])
      {
        minInx = j;
      }
    }
    if (minInx != i)
    {
      std::swap(vec[i], vec[minInx]);
    }
  }
}

int main(int argc, char **argv)
{
  std::vector<int> vec{1, 3, 9, 5, 7};
  selectSort(vec);

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}
