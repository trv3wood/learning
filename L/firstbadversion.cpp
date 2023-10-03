#include <iostream>
// Forward declaration of isBadVersion API.
class Solution {
public:
    int firstBadVersion(int n) {
        bool isBadVersion(int version);
        int left = 1, right = n;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
