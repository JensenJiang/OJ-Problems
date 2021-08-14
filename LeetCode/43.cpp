/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 43
 * Problem Title: Multiply Strings
 * Keyword: BigInteger
 *
 */

#include <vector>
#include <string>
using namespace std;

class MyBigInteger {
public:
    MyBigInteger(const string& num_str) : num_arr(num_str.length()) {
        for (int i = 0;i < num_str.length();i++) {
            num_arr[i] = num_str[num_str.length() - i - 1] - '0';
        }
    }

    MyBigInteger(MyBigInteger&& temp) {
        num_arr = std::move(temp.num_arr);
    }

    int length() const {
        return num_arr.size();
    }

    string to_string() const {
        string ret;
        for (auto i = num_arr.rbegin();i != num_arr.rend();i++) {
            ret += ('0' + *i);
        }
        return ret;
    }

    MyBigInteger operator *(const MyBigInteger& b) const {
        int len_a = length(),
            len_b = b.length();
        MyBigInteger res(len_a + len_b);

        for (int i = 0;i < len_a;i++) {
            for (int j = 0;j < len_b;j++) {
                res.num_arr[i + j] += num_arr[i] * b.num_arr[j];
            }
        }

        for (int i = 0;i < len_a + len_b - 1;i++) {
            res.num_arr[i + 1] += res.num_arr[i] / 10;
            res.num_arr[i] %= 10;
        }

        while (res.num_arr.size() > 1 && res.num_arr.back() == 0) res.num_arr.pop_back();

        return res;
    }

private:
    vector<int> num_arr;

    MyBigInteger(int nr_digits) : num_arr(nr_digits) {}
};

class Solution {
public:
    string multiply(string num1, string num2) {
        MyBigInteger n1(num1), n2(num2);
        MyBigInteger prod = n1 * n2;
        return prod.to_string();
    }
};
