#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    int len = n;
    int cnt = 0;

    while (len > 1) {
        int writeIdx = 0;

        for (int i = 0; i < len; i++) {
            int pos = i + 1;
            bool flag;

            if (cnt == 0) {
                flag = pos % 2 != 0;
            } else if (cnt == 1) {
                flag = pos % 2 == 0;
            } else {
                flag = pos % 3 != 0;
            }

            if (flag) {
                nums[writeIdx] = nums[i];
                writeIdx++;
            }
        }

        len = writeIdx;
        nums.resize(len);
        cnt = (cnt + 1) % 3;
    }
    cout << nums[0];
}