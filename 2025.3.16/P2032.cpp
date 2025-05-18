#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void findMaxInSlidingWindow(const vector<int>& nums, int n, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        // 移除不在滑动窗口范围内的元素
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // 移除所有小于当前元素的元素
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 将当前元素添加到双端队列
        dq.push_back(i);

        // 从第 k 个元素开始记录结果
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    // 输出结果
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    findMaxInSlidingWindow(nums, n, k);

    return 0;
}