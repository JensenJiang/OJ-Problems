/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 1542
 * Problem Title: Autocompletion
 * Keyword: Trie
 *
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define TRIE_MAX_NODE_SIZE 400000
#define TRIE_CHARSET_SIZE 26
#define MAX_WORD_LEN 16
#define MAX_OUTPUT 10
#define MAXN 100005
using namespace std;

struct InputPair {
  char word[MAX_WORD_LEN];
  int num;
  bool operator <(const InputPair& c)const {
    if(this->num == c.num) return strcmp(this->word, c.word) < 0;
    else return c.num < this->num;
  }
} inputs[MAXN];

class TrieNode {
public:
  int *next;
  vector<InputPair*> *top_arr;
  bool is_valid;

  TrieNode() {
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
    this->nodes[this->root].next = new int[TRIE_CHARSET_SIZE];
    memset(this->nodes[this->root].next, 0, sizeof(int) * TRIE_CHARSET_SIZE);
  }

  void add_string(const char *str, InputPair *info) {
    int str_len = strlen(str);
    TrieNode *cur_node = &this->nodes[root];

    for(int i = 0;i < str_len;i++) {
      int cid = this->char_to_id(str[i]);

      if(cur_node->next[cid] == 0) {
        cur_node->next[cid] = this->size++;
        this->nodes[cur_node->next[cid]].top_arr = new vector<InputPair*>();
        this->nodes[cur_node->next[cid]].next = new int[TRIE_CHARSET_SIZE];
        memset(this->nodes[cur_node->next[cid]].next, 0, sizeof(int) * TRIE_CHARSET_SIZE);
      }
      cur_node = &this->nodes[cur_node->next[cid]];
      if(cur_node->top_arr->size() < MAX_OUTPUT) cur_node->top_arr->push_back(info);
    }

    cur_node->is_valid = true;
  }

  void find_string(const char *str) {
    int str_len = strlen(str);
    TrieNode *cur_node = &this->nodes[root];

    for(int i = 0;i < str_len;i++) {
      int cid = this->char_to_id(str[i]);

      if(cur_node->next[cid] == 0) return;
      cur_node = &this->nodes[cur_node->next[cid]];
    }

    for(int i = 0;i < cur_node->top_arr->size();i++) puts(cur_node->top_arr->at(i)->word);
  }

private:
  int char_to_id(char c) {
    return c - 'a';
  }
} trie;


int main()
{
  int N, M;
  scanf("%d", &N);
  for(int i = 0;i < N;i++) {
    scanf("%s %d", inputs[i].word, &inputs[i].num);
  }
  sort(inputs, inputs + N);
  for(int i = 0;i < N;i++) trie.add_string(inputs[i].word, &inputs[i]);

  scanf("%d", &M);
  for(int i = 0;i < M;i++) {
    char input_word[MAX_WORD_LEN];
    scanf("%s", input_word);
    trie.find_string(input_word);
    if(i < M - 1) puts("");
  }
	return 0;
}
