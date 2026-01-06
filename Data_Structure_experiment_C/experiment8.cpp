#include <iostream>
#include <vector>

// 快速排序的分割操作
int Partition(std::vector<int>& arr, int low, int high) {
    // 选择最右边的元素作为基准
    int pivot = arr[high];
    int i = low - 1;

    // 遍历数组，将比基准小的元素交换到基准左边
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]); // 交换元素
        }
    }

    // 将基准元素放到正确的位置
    std::swap(arr[i + 1], arr[high]);
    return (i + 1); // 返回基准元素的位置
}

// 快速排序的主函数，递归实现
void QSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // 获取基准元素位置
        int pivotIndex = Partition(arr, low, high);
        
        // 递归排序基准左侧子数组
        QSort(arr, low, pivotIndex - 1);
        
        // 递归排序基准右侧子数组
        QSort(arr, pivotIndex + 1, high);
    }
}

// 快速排序的封装函数
void QuickSort(std::vector<int>& arr) {
    QSort(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {23, 5, 17, 12, 26, 31, 13, 4, 6, 17};

    std::cout << "原始数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 调用快速排序
    QuickSort(arr);

    // 输出排序后的数组
    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
