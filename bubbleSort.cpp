/**
 * @file bubbleSort.cpp
 * @author your name (you@domain.com)
 * @brief 冒泡排序
 * 
 * 步骤:
 *  1、从头开始，每次比较两元素，若大者在前，则交换两元素，直至数组末尾，此时最大元素为数组最后的元素
 *  2、重复以上步骤，从头开始至上一轮比较的末尾元素
 * 
 * 稳定性：
 *  稳定算法
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

void bubbleSort(std::vector<int> &vec)
{
  for (std::size_t i = 0; i < vec.size(); i++)
  {
    bool isChanged = false;
    for (std::size_t j = 0; j < vec.size() - i - 1; j++)
    {
      if (vec[j] > vec[j + 1])
      {
        std::swap(vec[j], vec[j+1]);
        isChanged = true;
      }
    }
    if (!isChanged)
    {
      break;
    }
  }
}

int main(int argc, char **argv)
{
  std::vector<int> vec {3, 8, 1, 4, 9};
  bubbleSort(vec);
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
