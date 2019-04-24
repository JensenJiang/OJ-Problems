/* K Closest Points to Origin
 * https://leetcode.com/problems/k-closest-points-to-origin/
 * Amazon OA2 2019
 */

struct Info {
    int id;
    int sqr_dis;
    bool operator <(const Info& a) const {
        return sqr_dis < a.sqr_dis;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Info> info_q;
        for(int i = 0;i < points.size();i++) {
            Info curr_info = {i, points[i][0] * points[i][0] + points[i][1] * points[i][1]};
            if(info_q.size() < K) info_q.push(curr_info);
            else {
                if(curr_info < info_q.top()) {
                    info_q.pop();
                    info_q.push(curr_info);
                }
            }
        }
        vector<vector<int>> ans;
        while(!info_q.empty()) {
            ans.push_back(points[info_q.top().id]);
            info_q.pop();
        }
        return ans;
    }
};
