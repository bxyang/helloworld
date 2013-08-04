/*
 * =====================================================================================
 *
 *       Filename:  InsertInterval.cc
 *
 *    Description:  
        Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

        You may assume that the intervals were initially sorted according to their start times.

        Example 1:
        Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

        Example 2:
        Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

        This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/3 18:50:57
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() == 0)
            return vector<Interval>(1, newInterval);
        if (intervals.size() == 1) {
            Interval i1 = intervals[0];
            intervals.clear();
            merge_interval(i1, newInterval, intervals);
            return intervals;
        }
        
        
        int i = 0;
        int p1 = -1;
        int p2 = -1;
        int start;
        int end;
        vector<Interval> ret;
        vector<Interval>::iterator it = intervals.begin();
        for (; it != intervals.end(); it++, i++) {
            if (newInterval.start <= it -> start)
                break;           
        }
        p1 = i;
        if (p1 == intervals.size()) {
            Interval i1 = (*(intervals.end() - 1));
            intervals.pop_back();
            merge_interval(i1, newInterval, intervals);
            return intervals;
        }
        
        if (p1 == 0)
            start = newInterval.start;
        else {
            if (newInterval.start > intervals[p1-1].end)
                start = newInterval.start;
            else
                start = intervals[--p1].start;
        }
        
        for (int j = 0; j < p1; j++)
            ret.push_back(intervals[j]);
        if (i != 0) {
            it--;
            i--;
        }
        for (; it != intervals.end(); it++, i++) {
            if (newInterval.end <= it -> end)
                break;           
        }
        p2 = i;
        if (p2 == intervals.size()) {
            ret.push_back(Interval(start, newInterval.end));
            return ret;
        }
        
        if (newInterval.end < intervals[p2].start) {
            end = newInterval.end;
        } else {
            end = intervals[p2].end;
            p2++;
        }
        ret.push_back(Interval(start, end));
        for (int j = p2; j < intervals.size(); j++)
            ret.push_back(intervals[j]);
        return ret;
    }
    
    void merge_interval(Interval i1, Interval i2, vector<Interval> &intervals) {
        if (i1.start > i2.end) {
            intervals.push_back(i2);
            intervals.push_back(i1);
        } else if (i1.end < i2.start) {
            intervals.push_back(i1);
            intervals.push_back(i2);
        } else {
            i1.start = i1.start < i2.start ? i1.start : i2.start;
            i1.end = i1.end > i2.end ? i1.end : i2.end;
            intervals.push_back(i1);    
        }
    }
};

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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() == 0)
            return vector<Interval>(1, newInterval);
        int i = bi_search(intervals, 0, intervals.size() - 1, newInterval.start);
        vector<Interval> ret;
        for (int j = 0; j <= (i-2); j++)
            ret.push_back(intervals[j]);
        int start;
        if (i==0)
            start = newInterval.start;
        else {
            if (newInterval.start <= intervals[i-1].end)
                start = intervals[i-1].start;
            else {
                start = newInterval.start;
                ret.push_back(intervals[i-1]);
            }
        }
        
        int k = (i == 0) ? 0:(i-1);
        int end = newInterval.end;
        if (intervals[k].start > newInterval.end)
            ret.push_back(Interval(start, end));
        else{
            for (; k < intervals.size(); k++) {
                if (intervals[k].end >= newInterval.end) {
                    if (intervals[k].start > newInterval.end) {
                        end = newInterval.end;
                        k--;
                        break;
                    }
                    end = intervals[k].end;
                    break;
                }
            }
            ret.push_back(Interval(start, end));
            k++;
        }
        for (; k < intervals.size(); k++)
            ret.push_back(intervals[k]);
        return ret;
    }
    
    int bi_search(vector<Interval> &intervals, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left)/2;
            int key = intervals[mid].start;
            if (key >= target)
                right = mid;
            else if (key < target)
                left = mid + 1;
        }
        if (intervals[left].start >= target)
            return left;
        return intervals.size();
    }
};


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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() == 0)
            return vector<Interval>(1, newInterval);
        vector<Interval> ret;
        int left = bi_search(intervals, get_start, 0, intervals.size() - 1, newInterval.start);
        int right = bi_search(intervals, get_end, 0, intervals.size() - 1, newInterval.end);
        for (int j = 0; j <= (left-2); j++)
            ret.push_back(intervals[j]);
        int start;
        if (left == 0)
            start = newInterval.start;
        else {
            if (newInterval.start <= intervals[left-1].end)
                start = intervals[left-1].start;
            else {
                start = newInterval.start;
                ret.push_back(intervals[left-1]);
            }
        }
        int end ;
        if ((right == intervals.size()) || (intervals[right].start > newInterval.end)) {
            end = newInterval.end;
        } else  {
            end = intervals[right].end;
            right++;
        }
        ret.push_back(Interval(start, end));
        for (; right < intervals.size(); right++)
            ret.push_back(intervals[right]);
        return ret;
    }
    
    static int get_start(Interval &interval) {
        return interval.start;
    }
    
    static int get_end(Interval &interval) {
        return interval.end;
    }
    int bi_search(vector<Interval> &intervals, int (*f) (Interval&), int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left)/2;
            int key = f(intervals[mid]);
            if (key >= target)
                right = mid;
            else if (key < target)
                left = mid + 1;
        }
        if (f(intervals[right]) >= target)
            return left;
        return intervals.size();
    }
};

