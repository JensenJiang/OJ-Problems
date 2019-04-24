#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::endl;
#define AB_SIZE 26


class TrieNode {
public:
    TrieNode* next[AB_SIZE];
    int size;
    TrieNode() {
        size = 0;
        for (int i = 0;i < AB_SIZE;i++) next[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0;i < AB_SIZE;i++) {
            if (next[i]) delete next[i];
        }
    }
};

class Trie {
public:
    TrieNode root;
    int nr_pairs = 0;
    void add_rev_str(const string& str) {
        TrieNode *curr = &root;
        for (auto i = str.rbegin();i != str.rend();i++) {
            int idx = *i - 'A';
            if (curr->next[idx] == nullptr) {
                curr->next[idx] = new TrieNode;
            }
            curr->next[idx]->size++;
            curr = curr->next[idx];
        }
    }

    int count_pairs(TrieNode *curr) {
        if (curr->size == 2) {
            nr_pairs += 2;
            return 2;
        }
        else if (curr->size <= 1) return 0;
        
        int new_pairs = 0;
        for (int i = 0;i < AB_SIZE;i++) {
            if (curr->next[i]) {
                new_pairs += count_pairs(curr->next[i]);
            }
        }

        curr->size -= new_pairs;
        if (curr->size >= 2) {
            nr_pairs += 2;
            return new_pairs + 2;
        }
        else return new_pairs;
    }
};

int main() {
    int T;
    string input;
    cin >> T;
    for (int t = 1;t <= T;t++) {
        Trie tr;
        int N;
        cin >> N;
        getline(cin, input);

        for (int i = 0;i < N;i++) {
            getline(cin, input);
            tr.add_rev_str(input);
        }

        for (int i = 0;i < AB_SIZE;i++) {
            if (tr.root.next[i]) tr.count_pairs(tr.root.next[i]);
        }

        cout << "Case #" << t << ": " << tr.nr_pairs << endl;
    }
    return 0;
}
