#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Sort
{
public:
    void printVec(vector<int> &nums)
    {
        for (auto c : nums)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    vector<int> bubbleSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            bool flag = false;
            for (int j = n - 1; j > i; --j)
            {
                if (nums[j - 1] > nums[j])
                {
                    swap(nums[j - 1], nums[j]);
                    flag = true;
                }
            }
            if (!flag)
                return nums; // 意味着后面的没有顺序需要调换了
        }
        return nums;
    }

    vector<int> insertSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            int cur = nums[i];
            int index = i - 1;
            while (index >= 0 && cur < nums[index])
            {
                nums[index + 1] = nums[index];
                index--;
            }
            nums[index + 1] = cur;
        }
        return nums;
    }

    vector<int> shellSort(vector<int> &nums)
    {
        const int INCRGAR = 3; // 先固定一个常量，用于gap = gap / INCRGAP
        int cur = 0;           // 还是插入排序思想中的用于存放当前的数字的变量，后面直接赋值给nums[index+1]
        int n = nums.size();
        int gap = n / INCRGAR + 1; // 需要保证gap至少为1
        while (gap)                // 只要gap不为零就一直循环，并且gap最后一次一定是1，即做一个插入排序
        {
            gap = gap / INCRGAR+1;
            for (int i = gap; i < n; i++)
            {
                int cur = nums[i];
                int index = i - gap;
                while (nums[index] > cur && index >= 0)
                {
                    nums[index + gap] = nums[index];
                    index -= gap;
                }
                nums[index + gap] = cur;
            }
            //printVec(nums);
        }
        return nums;
    }

    vector<int> quickSort(vector<int> nums)
    {
        recursionPartition(nums, 0, nums.size() - 1);
        // 其实可以直接使用recursionPartition就算是一个递归快排，但是由于题目只让传参一个vector，所以再加一个函数
        return nums;
    }

    int partition(vector<int> &nums, int left, int right) // 一定要使用&nums作为引用，否则nums不会改变
    {
        int i = rand() % (right - left + 1) + left;
        swap(nums[left], nums[i]);
        // 这两步的原因，每次都使用最左边的数字作为pivot的话，对比起来耗时太大，leetcode中会超时
        // 在partition中随机抽一个作为pivot，把这个数字换到最右边
        int pivot = nums[left];
        // pivot的目的一个是用作基准值，另一个是存储nums[left]的值，因为这个值后面回直接被覆盖掉
        while (left < right)
        {
            while (left < right && nums[right] >= pivot)
                --right;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot)
                ++left;
            nums[right] = nums[left];
        }
        nums[left] = pivot;

        return left;
    }

    void recursionPartition(vector<int> &nums, int left, int right) // 一定要使用&nums作为引用，否则nums不会改变
    {
        if (left < right)
        {
            int index = partition(nums, left, right);
            recursionPartition(nums, left, index - 1);
            recursionPartition(nums, index + 1, right);
        }
    }

    vector<int> selectSort(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return nums;
        for (int i = 0; i < n; i++)
        {
            int index = findMin(nums, i);
            swap(nums[i], nums[index]);
        }
        return nums;
    }

    int findMin(vector<int> nums, int i)
    {
        int min = nums[i];
        int index = i;
        while (i < nums.size())
        {
            if (nums[i] < min)
            {
                min = nums[i];
                index = i;
            }
            ++i;
        }
        return index;
    }

    void heapAdjust(vector<int> &nums, int left, int right)
    {
        int dad = left;
        int son = 2 * left + 1; // heap排序的数据结构是一个完全二叉树，每个节点下面挂两个子节点
        while (son <= right)
        {
            if (son <= right - 1 && nums[son] < nums[son + 1])
                // 选取较大的来和父节点比较，如果较大的小于父节点，那么这两个子节点一定都小于父节点
                son++;
            if (nums[dad] > nums[son])
                // 如果父节点确实大于子节点，那么这个堆的顺序就是对的，就直接return
                return;
            else
            // 如果父节点没有大于子节点，那么父节点就去做子节点，并且继续向下对比孙节点，以此类推
            {
                swap(nums[dad], nums[son]);
                dad = son;
                son = 2 * dad + 1;
            }
        }
    }

    vector<int> heapSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = (n / 2) - 1; i >= 0; i--) // 画一个完全二叉树的图就可以知道，最后一个父节点是(n/2)-1
        {
            heapAdjust(nums, i, n - 1);
            // printVec(nums);
        }
        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            heapAdjust(nums, 0, i - 1);
        }
        return nums;
    }

    void merge(vector<int> &nums, int left, int mid, int right)
    // 实际上，left、mid、right三者将整个vector划分成两个区间：[left, mid] [mid+1, right]
    {
        int i = left;                       // 第一个区间的第一个指针
        int j = mid + 1;                    // 第二个区间的第一个指针
        vector<int> temp(right - left + 1); // 分配一个用于存放排好序数组的数组变量
        int k = 0;                          // 用于遍历temp数组
        while (i <= mid && j <= right)
        {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= right)
            temp[k++] = nums[j++];

        for (int i = left, k = 0; i <= right; i++, k++)
        {
            nums[i] = temp[k];
        }
        temp.clear();
    }

    void mergeSort(vector<int> &nums, int left, int right)
    // 和下面的mergeSort名字一样，传参不一样，返回值也不一样，函数重载了
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    vector<int> mergeSort(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        mergeSort(nums, left, right);
        return nums;
    }

    vector<int> bucketSort(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return nums;
        int min = INT_MAX; // 2147483647
        int max = INT_MIN; //-2147483648
        for (auto c : nums)
        {
            if (c > max)
                max = c;
            if (c < min)
                min = c;
        }

        int bucketNum = (max - min) / n + 1;
        // 桶的数量是(max-min)/length+1;
        vector<vector<int>> buckets(bucketNum);
        for (int i = 0; i < n; i++)
        {
            int k = (nums[i] - min) / n;
            // 确定这个元素属于哪个桶
            buckets[k].push_back(nums[i]);
            // 把这个元素放到对应的桶里去
        }
        int count = 0;
        for (int i = 0; i < bucketNum; ++i)
        {
            if (!buckets[i].empty())
            {
                sort(buckets[i].begin(), buckets[i].end());
                for (int j = 0; j < buckets[i].size(); ++j)
                {
                    nums[count++] = buckets[i][j];
                }
            }
        }
        return nums;
    }
};

int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 20;
        nums.push_back(num);
    }

    Sort sort;
    sort.printVec(nums);
    vector<int> res;
    //res = sort.bubbleSort(nums);
    //res = sort.insertSort(nums);
    res = sort.shellSort(nums);
    //res = sort.quickSort(nums);
    //res = sort.selectSort(nums);
    //res = sort.heapSort(nums);
    //res = sort.mergeSort(nums);
    //res = sort.bucketSort(nums);
    // sort.(nums.begin(), nums.end());

    sort.printVec(res);
}