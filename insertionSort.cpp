/**
 * @file insertionSort.cpp
 * @author your name (you@domain.com)
 * @brief 插入排序
 * 
 * 步骤:
 *  1、将第一个元素看作有序序列，后续元素当作无需序列，依次将无序序列元素插入有序序列当中
 * 
 * 稳定性：稳定算法
 * 
 * 排序方式：In-place
 * 
 * 时间复杂度：
 *  平均：O(n^2)
 *  最好：O(n)
 *  最坏：O(n^2)
 * 
 * 空间复杂度：O(1)
 * 
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

/**
 * @brief 
 * 
 * @param vec 
 */

void insertionSort(std::vector<int> &vec)
{
  // i 代表无序序列首元素（无序序列前为有序序列）
  for (auto i = 1; i < vec.size(); i++)
  {
    // 无序序列前为有序序列
    auto j = i - 1;
    auto itemToInsert = vec[i];
    while (j >= 0)
    {
      if (vec[j] > itemToInsert)
      {
        vec[j + 1] = vec[j];
        --j;
      }
      else
      {
        break;
      }
    }
    vec[j + 1] = itemToInsert;
  }
}

int main(int argc, char **argv)
{
  std::vector<int> vec{1, 3, 9, 5, 7};
  insertionSort(vec);

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}
