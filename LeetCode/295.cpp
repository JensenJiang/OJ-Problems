/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 295
 * Problem Title: Find Median from Data Stream
 * Keyword: hard
 *
 */

#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        is_odd = false;
    }
    
    void addNum(int num) {
        if(is_odd) {
            if(odd_med <= num) {
                lq.push(odd_med);
                gq.push(num);
            }
            else {
                lq.push(num);
                gq.push(odd_med);
            }
        }
        else {
            if(gq.empty()) odd_med = num;
            else if(gq.top() < num) {
                odd_med = gq.top();
                gq.pop();
                gq.push(num);
            }
            else if(lq.top() > num) {
                odd_med = lq.top();
                lq.pop();
                lq.push(num);
            }
            else odd_med = num;
        }
        is_odd = !is_odd;
    }
    
    double findMedian() {
        if(is_odd) return odd_med;
        else return (lq.top() + gq.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>, std::greater<int> > gq;
    priority_queue<int, vector<int>, std::less<int> > lq;
    bool is_odd;
    int odd_med = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
