/**
 * @file quickSort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-05-13
 * 
 * 步骤：
 *  1、从列表中选出一个元素，作为“基准”pivot，基准一般随机选择，或采用最左端、最右端和中间位置3元素的中值
 *  2、将小于基准的元素排在基准前面，大于基准的元素排在基准后面，此时基准元素所在位置即为其最终排序完成时的位置
 *  3、以基准元素为界，将列表分为两个子列表
 *  4、递归地对子列表重复上述操作
 * 
 * 稳定性：不稳定算法 
 *  
 * 排序方式：In-place
 * 
 * 时间复杂度：
 *  平均：O(nlogn)
 *  最好：O(nlogn)
 *  最坏：O(n^2)
 * 
 * 空间复杂度：O(nlogn)
 * 
 * Ps：当数据量很小（N<=20）时，快速排序效果不如插入排序，因为快速排序不稳定且有递归开销 
 * 
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/**
 * @brief 
 * 
 * @param s 
 * @param l 
 * @param r 
 */
void doSort(std::vector<int> &s, int l, int r)
{
  if (l < r)
  {
    int i = l;
    int j = r;
    // 直接将左边的当成 pivot
    int pivot = s[l];
    while (i < j)
    {
      // 从右向左找第一个小于 x 的数
      while (i < j && s[j] >= pivot)
      {
        j--;
      }
      if (i < j)
      {
        s[i++] = s[j];
      }
      // 从左向右找第一个大于等于 x 的数
      while (i < j && s[i] < pivot)
      {
        i++;
      }
      if (i < j)
      {
        s[j--] = s[i];
      }
    }
    s[i] = pivot;
    // 递归调用
    doSort(s, l, i - 1);
    doSort(s, i + 1, r);
  }
}

/**
 * @brief 
 * 
 * @param array 
 */
void quickSort(std::vector<int> &array)
{
  doSort(array, 0, array.size() - 1);
}

int main(int argc, char **argv)
{
  std::vector<int> vec{1, 3, 9, 5, 10, 7};
  quickSort(vec);

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
