#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cin;
using std::getline;
using std::cout;

class Node {
public:
    int next[2];
    char c;
    Node() {
        next[0] = next[1] = -1;
        c = 0;
    }
};

class Tree {
public:
    int root;
    vector<Node> nodes;
    Tree() {
        nodes.push_back(Node());
        root = 0;
    }
    void new_node(int id, int child) {
        nodes.push_back(Node());
        nodes[id].next[child] = nodes.size() - 1;
    }
    void insert(const string& s, char c) {
        // std::cout << s << ' ' << c << std::endl;
        int curr = root;
        for(char d : s) {
            if(nodes[curr].next[d - '0'] < 0) {
                new_node(curr, d - '0');
            }
            curr = nodes[curr].next[d - '0'];
            // std::cout << d << ' ' << curr << std::endl;
        }
        // std::cout << curr << ' ' << c << std::endl;
        nodes[curr].c = c;
    }
    string decode(const string& encoded) {
        int curr = root;
        string ans;
        for(char d : encoded) {
            // std::cout << d;
            curr = nodes[curr].next[d - '0'];
            // std::cout << d << ' ' << curr << std::endl;
            if(nodes[curr].c > 0) {
                ans += nodes[curr].c;
                curr = root;
            }
        }
        return ans;
    } 
};

int main() {
    int n;
    string input;
    Tree btrie;

    cin >> n;
    getline(cin, input);
    for(int i = 0;i < n;i++) {
        getline(cin, input);
        int sep_i = input.find('\t');
        string code = input.substr(sep_i + 1, input.length() - sep_i);
        char c = sep_i > 1 ? '\n' : input[0];
        btrie.insert(code, c);
    }
    
    getline(cin, input);
    string ans = btrie.decode(input);
    std::cout << ans;

    return 0;
}
