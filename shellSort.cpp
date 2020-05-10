/**
 * @file shellSort.cpp
 * @author your name (you@domain.com)
 * @brief 希尔排序
 * https://www.cnblogs.com/chengxiao/p/6104371.html
 * 
 * 步骤:
 *  1、选择一个增量序列，初始增量gap=length/2，后续元素依次为前一元素除2，直至gap=1
 *  2、每轮以gap为步长，在列表上进行采样，将列表分为gap个小组，在每个小组内进行选择排序
 *  3、重复第二步，直至gap=1
 * 
 * 稳定性：不稳定算法
 * https://baijiahao.baidu.com/s?id=1602011058247698952&wfr=spider&for=pc
 * 
 * 排序方式：In-place
 * 
 * 时间复杂度：
 *  平均：O(nlogn)
 *  最好：O(nlog^2n)
 *  最坏：O(nlog^2n)
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

void shellSort(std::vector<int> &vec)
{
  auto n = vec.size();
  for (auto gap = n / 2; gap >= 1; gap /= 2)
  {
    for (auto i = gap; i < n; i++)
    {
      // 使用插入排序算法，将元素依次插入所在小组的已排序列表中
      // 待插入元素
      auto itemToInsert = vec[i];
      auto j = i - gap;
      while ( j >= 0 && vec[j] >= itemToInsert)
      {
        vec[j+gap] = vec[j];
        j -= gap;
      }
      vec[j+gap] = itemToInsert;
    }
  }
}

int main(int argc, char **argv)
{
  std::vector<int> vec{1, 3, 9, 5, 7};
  shellSort(vec);

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}
