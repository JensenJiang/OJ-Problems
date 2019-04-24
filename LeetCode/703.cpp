/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 703
 * Problem Title: Kth Largest Element in a Stream
 * Keyword: stream
 *
 */

#include <queue>
using std::priority_queue;

#include <vector>
using std::vector;

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        pq = priority_queue<int, vector<int>, std::greater<int>>(nums.begin(), nums.end());
        K = k;
        while(pq.size() > K) pq.pop();
    }
    
    int add(int val) {
        if(pq.size() == K) {
            if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        else pq.push(val);
        return pq.top();
    }
private:
    int K;
    priority_queue<int, vector<int>, std::greater<int> > pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
