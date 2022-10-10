//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());

        double avg_trips = 0.0;
        for (int t: time) {
            avg_trips += 1.0 / t;
        }
        int64_t min = int64_t(totalTrips / avg_trips);
        int64_t max = min + time.back();
        int64_t lo = min - 1, hi = max + 1;
        while (hi - lo > 1) {
            int64_t mid = (hi + lo) / 2;
            int64_t trips = 0;
            for (int t: time) {
                trips += mid / t;
            }
            if (trips >= totalTrips) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};
