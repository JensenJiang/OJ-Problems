#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::getline;
using std::stringstream;
using std::string;
using std::unordered_map;
using std::vector;

int main() {
    int n,q;
    string input;
    unordered_map<string, vector<int>> words_line;

    cin >> n;
    getline(cin, input);
    for(int i = 0;i < n;i++) {
        getline(cin, input);
        stringstream linestream(input);
        string word;
        while(linestream >> word) {
            words_line[word].push_back(i);
        }
    }

    cin >> q;
    getline(cin, input);
    while(q--) {
        getline(cin, input);
        stringstream linestream(input);
        string word;
        
        linestream >> word;
        vector<int> ans = words_line[word];
        while(linestream >> word) {
            vector<int>& curr_v = words_line[word];
            auto new_end = std::set_intersection(ans.begin(), ans.end(), curr_v.begin(), curr_v.end(), ans.begin());
            ans.resize(std::distance(ans.begin(), new_end));
        }
        if(ans.size() > 0) {
            cout << ans[0];
            for(int i = 1;i < ans.size();i++) {
                cout << ' ' << ans[i];
            }
        }
        else cout << "-1";
        
        cout << std::endl;
    }

    return 0;
}
