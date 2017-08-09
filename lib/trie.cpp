#include <cstring>
#define TRIE_MAX_NODE_SIZE 10000
#define TRIE_CHARSET_SIZE 26

class TrieNode {
public:
  int next[TRIE_CHARSET_SIZE];
  bool is_valid;

  TrieNode() {
    memset(this->next, 0, sizeof(next));
    this->is_valid = false;
  }
};

class Trie {
public:
  int root, size;
  TrieNode nodes[TRIE_MAX_NODE_SIZE];

  Trie() {
    this->root = 0;
    this->size = 1;
  }

  void add_string(const char *str) {
    int str_len = strlen(str);
    TrieNode *cur_node = &this->nodes[root];

    for(int i = 0;i < str_len;i++) {
      int cid = this->char_to_id(str[i]);

      if(cur_node->next[cid] == 0) {
        cur_node->next[cid] = this->size++;
      }
      cur_node = &this->nodes[cur_node->next[cid]];
    }

    cur_node->is_valid = true;
  }

  bool find_string(const char *str) {
    int str_len = strlen(str);
    TrieNode *cur_node = &this->nodes[root];

    for(int i = 0;i < str_len;i++) {
      int cid = this->char_to_id(str[i]);

      if(cur_node->next[cid] == 0) return false;
      cur_node = &this->nodes[cur_node->next[cid]];
    }
    return cur_node->is_valid;
  }

private:
  int char_to_id(char c) {
    return c - 'a';
  }
};
