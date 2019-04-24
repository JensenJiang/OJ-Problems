/* Count number of substrings
 * https://practice.geeksforgeeks.org/problems/count-number-of-substrings/0
 * Amazon OA2 2019
 */

#include <iostream>
#include <unordered_map>
#include <string>
using std::string;
using std::cin;
using std::cout;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k, 
            tot = 0,
            size = 0;
        string s;
        int cnt_map[27];
        for (int i = 0;i < 27;i++) cnt_map[i] = 0;
        cin >> s;
        cin >> k;
        for (int i = 0;i < k - 1;i++) {
            cnt_map[s[i] - 'a']++;
            if(cnt_map[s[i] - 'a'] == 1) size++;
        }
        int r = k - 1;
        for (int i = 0, j = k - 1;j < s.length();j++) {
            cnt_map[s[j] - 'a']++;
            if(cnt_map[s[j] - 'a'] == 1) size++;
            while (size == k) {
                for(r = r <= j ? j + 1 : r;r < s.length() && cnt_map[s[r] - 'a'] > 0;r++);
                tot += r - j;
                cnt_map[s[i] - 'a']--;
                if(cnt_map[s[i] - 'a'] == 0) size--;
                i++;
            }
        }
        
        cout << tot << std::endl;
    }
    return 0;
}
