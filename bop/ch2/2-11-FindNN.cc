/*
 * =====================================================================================
 *
 *       Filename:  2-11-FindNN.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2013 10:02:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cassert>
#include<utility>
#include<cmath>
#include<cstdio>

struct Point{
    double x;
    double y;
};

const double EPS = 0.0000001;
void find_bound(struct Point* data, int start, int end,
        double min_dist, int& left_bound, int& right_bound);
double merge_nn(struct Point* data, double min_dist, int left, int right);

int partion(Point *data, int start, int end, int (*cmp)(struct Point, struct Point)) {
    assert(start < end);
    struct Point key = data[start];
    int i = start;
    int j = start + 1;
    for (; j <= end; j++) {
        int flag = cmp(key, data[j]);
        if (flag >= 0)
            continue;
        std::swap(data[i++], data[j]);
    }
    std::swap(data[start], data[i]);
    return i;
}

void quick_sort(Point *data, int start, int end, int (*cmp)(struct Point, struct Point)) {
    if (start >= end);
        return;
    int mid = partion(data, start, end, cmp);
    if (start < (mid - 1) )
        quick_sort(data, start, mid - 1, cmp);
    if ( (mid + 1) < end)
        quick_sort(data, mid + 1, end, cmp);
}

int cmp_x(struct Point p1, struct Point p2) {
    if (p1.x < p2.x)
        return -1;
    if (p1.x > p2.x)
        return 1;
    return 0;
}

int cmp_y(struct Point p1, struct Point p2) {
    if (p1.y < p2.y)
        return -1;
    if (p1.y > p2.y)
        return 1;
    return 0;
}

double compute_dist(struct Point p1, struct Point p2) {
    double ret = 0;
    ret += pow(p1.x - p2.x, 2);
    ret += pow(p1.y - p2.y, 2);
    return ret;
}

double find_nn(struct Point* data, int start, int end) {
    if (start >= end)
        return -1;
    if ( (end - start) == 1)
        return compute_dist(data[start], data[end]);
    int mid = start + (end - start) / 2;
    double left_min_dist = -1;
    double right_min_dist = -1;
    if (start < mid)
        left_min_dist = find_nn(data, start, mid);
    if (end > (mid + 1) )
        right_min_dist = find_nn(data, mid + 1, end);
    double min_dist = -1;
    if (left_min_dist < 0)
        min_dist = right_min_dist;
    if (right_min_dist < 0)
        min_dist = left_min_dist;
    if (min_dist < 0)
        min_dist = (left_min_dist < right_min_dist) ? left_min_dist : right_min_dist;
    if (min_dist < EPS)
        return sqrt(EPS);
    int left_bound;
    int right_bound;
    find_bound(data, start, end, sqrt(min_dist), left_bound, right_bound);
    return merge_nn(data, min_dist, left_bound, right_bound);
}

double merge_nn(struct Point* data, double min_dist, int left, int right) {
    quick_sort(data, left, right, cmp_y);
    for (int i = left; i < right; i++) {
        for (int j = i+1; (j <= (i + 7)) && (j <= right); j++) {
            double tmp = compute_dist(data[i], data[j]);
            min_dist = (min_dist < tmp) ? min_dist : tmp;
        }
    }
    return min_dist;
}


void find_bound(struct Point* data, int start, int end,
        double min_dist, int& left_bound, int& right_bound) {
    int mid = start + (end - start) / 2;
    double m = (data[mid].x + data[mid+1].x) / 2;
    left_bound = mid;
    for (; left_bound >= start; left_bound--) {
        if (m - data[left_bound].x > min_dist)
            break;
    }
    left_bound += 1;
    right_bound = mid + 1;
    for (; right_bound <= end; right_bound++) {
        if (data[right_bound].x -m > min_dist)
            break;
    }
    right_bound -= 1;
}


int main() {
    int case_num;
    scanf("%d", &case_num);
    for (int i = 0; i < case_num; i++) {
        int len;
        scanf("%d", &len);
        struct Point *data = new struct Point[len];
        for (int j = 0; j < len; j++) {
            scanf("%lf %lf", &(data[j].x), &(data[j].y));
        }
        quick_sort(data, 0, len - 1, cmp_y);
        double t = find_nn(data, 0, len - 1);
        printf("%.3f", sqrt(t));
    }
    return 0;
}
