/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 952
 * Problem Title: Largest Component Size by Common Factor
 * Keyword: ufs, prime, good
 *
 */

#include <vector>
#include <cmath>
#define MAX_LEN 100001
using std::vector;
using std::max;

class SUFS {
public:
    int nr_nodes;
    int *par;
    int *size;
    SUFS(const int n): nr_nodes(n) {
        par = new int[n];
        size = new int[n];      // after union opreation, only the root parent's value is valid
        for(int i = 0;i < n;i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int find(const int cur) {
        if(cur == par[cur]) return cur;
        else return par[cur] = find(par[cur]);
    }

    void union_nodes(const int a, const int b) {
        int par_a = find(a), par_b = find(b);
        if(par_a == par_b) return;
        if(size[par_a] >= size[par_b]) {
            par[par_b] = par_a;
            size[par_a] += size[par_b];
        }
        else {
            par[par_a] = par_b;
            size[par_b] += size[par_a];
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        if(A.empty()) return 0;
        int max_ele = -1;
        for(int i = 0;i < MAX_LEN;i++) nr_nums[i] = 0;
        for(int e : A) {
            nr_nums[e]++;
            max_ele = max(max_ele, e);
        }
        SUFS ufs(max_ele + 1);
        for(int i = 1;i <= max_ele;i++) {
            ufs.size[i] = nr_nums[i];
            vis[i] = false;
        }

        for(int i = 2;i <= max_ele;i++) {
            if(!vis[i]) {
                for(int j = i * 2;j <= max_ele;j += i) {
                    if(nr_nums[j] > 0) {
                        ufs.union_nodes(j, i);
                        // printf("%d %d\n", j, i);
                    }
                    vis[j] = true;
                }
            }
        }
        int max_size = 1;
        for(int i = 1;i <= max_ele;i++) {
            max_size = max(max_size, ufs.size[i]);
        }
        return max_size;
    }
private:
    int nr_nums[MAX_LEN];
    bool vis[MAX_LEN];
};
