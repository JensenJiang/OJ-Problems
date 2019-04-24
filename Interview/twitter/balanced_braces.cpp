#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> st;
    bool success = true;
    for(char c : s) {
        if(c == '{' || c == '[' || c == '(') {
            st.push(c);
        }
        else {
            if(!st.empty()) {
                char t = st.top();
                if((c == '}' && t == '{') || (c == ']' && t == '[') || (c == ')' && t == '(')) {
                    st.pop();
                }
                else success = false;
            }
            else success = false;
            if(!success) break;
        }
    }
    return st.empty() && success ? "YES" : "NO"; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
