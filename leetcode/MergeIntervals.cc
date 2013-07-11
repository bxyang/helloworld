/*
 * =====================================================================================
 *
 *       Filename:  MergeIntervals.cc
 *
 *    Description:
        Given a collection of intervals, merge all overlapping intervals.

        For example,
        Given [1,3],[2,6],[8,10],[15,18],
        return [1,6],[8,10],[15,18].
 *
 *        Version:  1.0
 *        Created:  2013/7/10 17:06:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), *this);
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ret;
        if (intervals.size() == 0)
            return ret;
        vector<Interval>::iterator it = intervals.begin();
        int start = it -> start;
        int end = it -> end;
        it++;
        for (; it != intervals.end(); it++) {
            if ((it -> start) > end) {
                ret.push_back(Interval(start, end));
                start = it -> start;
                end = it -> end;
            } else {
                end = ((it -> end) > end) ? it -> end : end;
            }
        }
        ret.push_back(Interval(start, end));
        return ret;
    }
    
    static bool cmp(const Interval& i1, const Interval& i2) {
        return (i1.start < i2.start);
    }
    
    bool operator()(const Interval& i1, const Interval& i2) {
        return (i1.start < i2.start);
    }
};
