/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 341
 * Problem Title: Flatten Nested List Iterator
 * Keyword: good
 *
 */

#include <vector>
#include <stack>
using std::vector;
using std::stack;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

typedef vector<NestedInteger> vni;
struct nextLoc {
    const vni* next_vni;
    int idx;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        vni_ptr = &nestedList;
        curr_idx = 0;
    }

    int next() {
        curr_idx++;
        return (*vni_ptr)[curr_idx - 1].getInteger();
    }

    bool hasNext() {
        while(vni_ptr) {
            if(curr_idx >= vni_ptr->size()) {
                if(!st.empty()) {
                    nextLoc next = st.top();
                    st.pop();
                    vni_ptr = next.next_vni;
                    curr_idx = next.idx;
                }
                else vni_ptr = nullptr;
            }
            else {
                if(!(*vni_ptr)[curr_idx].isInteger()) {
                    st.push({vni_ptr, curr_idx + 1});
                    vni_ptr = &(*vni_ptr)[curr_idx].getList();
                    curr_idx = 0;
                }
                else break;
            }
        }
        return vni_ptr ? true : false;
    }

private:
    const vni* vni_ptr;
    int curr_idx;
    stack<nextLoc> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
