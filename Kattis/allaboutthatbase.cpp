/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: allaboutthatbase
 * Problem Title: All about that base
 * Keyword: base change, string process
 *
 */

#include <cstdio>
#include <cstring>
#define MAXLEN 101

long long MAX_LIMIT = 1;

void raw_string_process(char* ori, char*& opr1, char*& op, char*& opr2, char*& result)
{
	int len = strlen(ori), i = 0;
	opr1 = ori;
	while(ori[i] != ' ') i++;
	ori[i++] = 0;
	op = ori + i;
	while(ori[i] != ' ') i++;
	ori[i++] = 0;
	opr2 = ori + i;
	while(ori[i] != ' ') i++;
	ori[i++] = 0;
	while(ori[i] != ' ') i++;
	result = ori + i + 1;
}

int symbol_to_int(const char& a)
{
	if(a >= '0' && a <= '9') return (a - '0');
	else if(a >= 'a' && a <= 'z') return (a - 'a' + 10);
}

bool is_valid_under_base(char* opr, int base)
{
	int len = strlen(opr);
	if(base == 1){
		for(int i = 0;i < len;i++){
			if(opr[i] == '0') return false; 
			else if(opr[i] != '1') return false;
		}
		return true;
	}
	else{
		for(int i = 0;i < len;i++) if(symbol_to_int(opr[i]) >= base) return false;
		return true;
	}
}

long long raw_opr_to_opr(char* opr, int base)
{
	int len = strlen(opr);
	long long temp = 1, ret = 0;
	for(int i = len - 1; i >= 0;i--){
		ret += symbol_to_int(opr[i]) * temp;
		if(ret > MAX_LIMIT) return -1;
		temp *= base;
	}
	return ret;
}

void print_base_symbol(int base)
{
	if(base <= 9) printf("%d", base);
	else if(base < 36) printf("%c", 'a' + base - 10);
	else printf("0");
}


int main()
{
	int N;
	char raw_str[MAXLEN];
	MAX_LIMIT <<= 32;
	MAX_LIMIT--;
	scanf("%d", &N);
	gets(raw_str);
	while(N--){
		long long _opr1, _opr2, _result, e_result;
		char *opr1, *opr2, *op, *result;
		bool is_valid[37];
		memset(is_valid, 0, sizeof(is_valid));
		gets(raw_str);
		raw_string_process(raw_str, opr1, op, opr2, result);
		for(int i = 1;i <= 36;i++){
			if(!is_valid_under_base(opr1, i) || !is_valid_under_base(opr2, i) || !is_valid_under_base(result, i)) continue;
			_opr1 = raw_opr_to_opr(opr1, i);
			if(_opr1 < 0) break;
			_opr2 = raw_opr_to_opr(opr2, i);
			if(_opr2 < 0) break;
			_result = raw_opr_to_opr(result, i);
			if(_result < 0) break;
			bool zc = true;
			switch(*op){
			case '+':
				e_result = _opr1 + _opr2;
				break;
			case '-':
				e_result = _opr1 - _opr2;
				break;
			case '*':
				e_result = _opr1 * _opr2;
				break;
			case '/':
				e_result = _opr1 / _opr2;
				zc = (_opr1 % _opr2 == 0);
				break;
			}
			if(e_result == _result && zc) is_valid[i] = true;
		}
		int count = 0;
		for(int i = 1; i <= 36;i++) if(is_valid[i]){
			print_base_symbol(i);
			count++;
		}
		if(count == 0) printf("invalid");
		puts("");
	}
	return 0;
}
