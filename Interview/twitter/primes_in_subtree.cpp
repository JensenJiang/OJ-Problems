#include <vector>
#include <iostream>
using std::vector;
using std::cin;

class Tree {
public:
    vector<int> first;
    vector<int> next;
    vector<int> to;
    vector<int> nums;
    Tree(int n) {
        first.reserve(n);
        next.reserve(n);
        to.reserve(n);
        nums.reserve(n);
    }
};

int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {

    }
}
