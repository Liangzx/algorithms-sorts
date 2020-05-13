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
#include <stack>

/**
 * @brief 合并两有序序列，两序列分别为array的0到mid部分和mid+1到末尾部分
 *
 * @param vec 
 */
void merge(std::vector<int> &array, std::vector<int> &copyArray, int left, int right)
{
  int mid = (left + right) / 2;
  // 左序列指针
  int i = left;
  // 右序列指针
  int j = mid + 1;
  // 临时数组指针
  int k = 0;

  while (i <= mid && j <= right)
  {
    if (array[i] <= array[j])
    {
      copyArray[k++] = array[i++];
    }
    else
    {
      copyArray[k++] = array[j++];
    }
  }
  // 将左边剩余元素填充进 temp
  while (i <= mid)
  {
    copyArray[k++] = array[i++];
  }
  // 将右序列剩余元素填充进 temp
  while (j <= right)
  {
    copyArray[k++] = array[j++];
  }
  // 将 temp 中的元素全部拷贝到原数组中
  k = 0;
  while (left <= right)
  {
    array[left++] = copyArray[k++];
  }
}

/**
 * @brief 
 * 
 * @param array 
 * @param copyArray 
 * @param left 
 * @param right 
 */
void mergeSortHelp(std::vector<int> &array, std::vector<int> &copyArray, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    // 左边归并排序，使得左子序列有序
    mergeSortHelp(array, copyArray, left, mid);
    // 右边归并排序，使得右子序列有序
    mergeSortHelp(array, copyArray, mid + 1, right);
    // 将两个有序子数组合并操作
    merge(array, copyArray, left, right);
  }
}
/**
 * @brief 归并排序 递归实现
 * 
 * @param array 
 */
void mergeSort(std::vector<int> &array)
{
  // 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
  std::vector<int> copyArray(array);
  mergeSortHelp(array, copyArray, 0, array.size() - 1);
}
/**
 * @brief 归并排序 迭代实现
 * 
 * @param array 
 */
void mergeSortIteration(std::vector<int> &array)
{
  std::vector<int> copyArray(array);
  int left = 0;
  int right = array.size() - 1;
  std::stack<std::vector<int>> boundaries;
  while (left < right || !boundaries.empty())
  {
    if (left < right)
    {
      boundaries.push({left, right});
      right = (left + right) / 2;
    }
    else
    {
      std::vector<int> boundary = boundaries.top();
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
  std::vector<int> vec{1, 3, 9, 5, 7, 0, 9, 8};
  mergeSort(vec);

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}
