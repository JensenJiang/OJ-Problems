/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 753
 * Problem Title: Cracking the Safe
 * Keyword: graph
 *
 */

#include <string>
#include <vector>
#include <stack>
using std::string;
using std::vector;
using std::stack;
using std::pair;

int *next_visit;
int *head_dk;
int gk;
stack<int> path_stack;

void euler_dfs(int s) {
    while(next_visit[s] < gk) {
        int curr_path = next_visit[s];
        next_visit[s]++;
        euler_dfs(gk*s - head_dk[s] + curr_path);
        path_stack.push(curr_path);
    }
}

class Solution {
public:
    string crackSafe(int n, int k) {
        if(n == 1) {
            string ret = "";
            for(int i = 0;i < k;i++) ret.append(1, '0' + i);
            return ret;
        }
        gk = k;
        int b_num = 1;
        for(int i = 0;i < n - 2;i++) b_num *= k;
        
        next_visit = new int[b_num * k];
        head_dk = new int[b_num * k];
        for(int i = 0;i < b_num * k;i++) {
            next_visit[i] = 0;
            head_dk[i] = i / b_num * (b_num * k);
        }

        euler_dfs(0);
        string ret(n-1, '0');
        while(!path_stack.empty()) {
            ret.append(1, '0' + path_stack.top());
            path_stack.pop();
        }
        return ret;
    }
};
