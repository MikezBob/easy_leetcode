#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        if (n < 3) return 0;
        
        int res = 0;
        
        if (c >= a + b) {
            vector<int> left(n, 0);
            vector<int> right(n, 0);
            
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < j; ++i) {
                    if (abs(arr[i] - arr[j]) <= a) {
                        left[j]++;
                    }
                }
            }
            
            for (int j = 0; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[j] - arr[k]) <= b) {
                        right[j]++;
                    }
                }
            }
            
            for (int j = 0; j < n; ++j) {
                res += left[j] * right[j];
            }
        } else {
            for (int j = 0; j < n; ++j) {
                vector<int> ks;
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[j] - arr[k]) <= b) {
                        ks.push_back(arr[k]);
                    }
                }
                sort(ks.begin(), ks.end());
                
                for (int i = 0; i < j; ++i) {
                    if (abs(arr[i] - arr[j]) <= a) {
                        int target_low = arr[i] - c;
                        int target_high = arr[i] + c;
                        auto left_it = lower_bound(ks.begin(), ks.end(), target_low);
                        auto right_it = upper_bound(ks.begin(), ks.end(), target_high);
                        res += (right_it - left_it);
                    }
                }
            }
        }
        
        return res;
    }
};