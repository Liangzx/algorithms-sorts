/**
 * @file mergeSort.cpp
 * @author your name (you@domain.com)
 * @brief 归并排序
 * https://www.cnblogs.com/chengxiao/p/6194356.html 
 * 
 * 步骤:
 *  1、将列表从正中间分为两个子列表
 *  2、按照第一步，递归拆分每个子列表，直至子列表最大长度为1
 *  3、按照拆分层级，依次按大小合并各子列表，直至全部合并完成
 * 
 * 稳定性：稳定算法
 * 
 * 
 * 排序方式：Out-place
 * 
 * 时间复杂度：
 *  平均：O(nlogn)
 *  最好：O(nlogn)
 *  最坏：O(nlogn)
 * 
 * 空间复杂度：O(n)
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
// 合并两有序序列，两序列分别为array的0到mid部分和mid+1到末尾部分。
void merge(vector<int> &array, vector<int> &copyArray, int left, int right)
{
  int mid = (left + right) / 2;
  int i = left, j = mid + 1, k = 0;
  while (i <= mid || j <= right)
  {
    if (i > mid)
    {
      copyArray[k] = array[j];
      j++;
    }
    else if (j > right)
    {
      copyArray[k] = array[i];
      i++;
    }
    else if (array[i] > array[j])
    {
      copyArray[k] = array[j];
      j++;
    }
    else
    {
      copyArray[k] = array[i];
      i++;
    }

    k++;
  }

  for (size_t i = left; i <= right; i++)
  {
    array[i] = copyArray[i - left];
  }
}
void mergeSortHelp(vector<int> &array, vector<int> &copyArray, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    mergeSortHelp(array, copyArray, left, mid);
    mergeSortHelp(array, copyArray, mid + 1, right);
    merge(array, copyArray, left, right);
  }
}
// 归并排序 递归实现
void mergeSort(vector<int> &array)
{
  vector<int> copyArray(array);
  mergeSortHelp(array, copyArray, 0, array.size() - 1);
}

// 归并排序 迭代实现
void mergeSortIteration(vector<int> &array)
{
  vector<int> copyArray(array);
  int left = 0, right = array.size() - 1;
  stack<vector<int>> boundaries;
  while (left < right || !boundaries.empty())
  {
    if (left < right)
    {
      boundaries.push({left, right});
      right = (left + right) / 2;
    }
    else
    {
      vector<int> boundary = boundaries.top();
      boundaries.pop();
      left = boundary[0];
      right = boundary[1];
      merge(array, copyArray, left, right);
      if (boundaries.empty())
      {
        break;
      }
      boundary = boundaries.top();
      left = right + 1;
      right = boundary[1];
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
