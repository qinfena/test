#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
    /* 假设小写字符是连续的 */
static_assert('z' - 'a' == 25,
				"alphabetic characters not contiguous");
#include <ctype.h>
    /* 将字母数字转换为无符号的 */
    /* '0' ... '9' =>  0 ... 9u */
    /* 'A' ... 'Z' => 10 ... 35u*/
    /* 'a' ... 'z' => 10 ... 35u*/
    /* 其他值=>更大 */
unsigned hexatridecimal(int a) {
	if (isdigit(a)) { /* 这保证工作有效:十进制数字
	 * 是连续的，isdigit不依赖
	 * 于区域设置 */
		return a - '0';
	}else {
    /* 如果不是小写,则保持不变 */
		a = toupper(a);
    /* 返回值>=36,如果不是拉丁大写 */
		return (isupper(a)?10+(a-'A'):-1);
	}
}
unsigned long Strtoul_inner(char const s[static 1],
							size_t i,
							unsigned base){
	unsigned long ret = 0;
	while (s[i]) {
		unsigned c = hexatridecimal(s[i]);
		if (c >= base) break;
    /* 以36为基数，64位的最大可表示值
	 * 为3w5e11264sgsf */
	if (ULONG_MAX/base < ret) {
		ret = ULONG_MAX;
		errno = ERANGE;
		break;
	}
	ret *= base;
	ret += c;
	++i;
	}
	return ret;
}
unsigned long Strtoul (char const s[static 1], unsigned base) {
	if (base > 36u) {			    /* 测试基数 */
		errno = EINVAL;    /* 扩展规范 */
		return ULONG_MAX;
	}
	size_t i = strspn(s, "\f\n\r\t\v");    /* 跳过空格 */
	bool switchsign = false;    /* 寻找迹象 */
	switch (s[i]) {
		case '-' : switchsign = true;
		case '+' : ++i;
	}
	if (!base || base == 16) {
		size_t adj = find_prefix(s, i, "0x");
		if (!base) base = (unsigned[]) {10, 8, 16, }[adj];
		i += adj;
	}
    /* 现在，开始真正的转换 */
	unsigned long ret = Strtoul_inner(s,i,base);
	return (switchsign) ? -ret : ret;
}

int main() {
	return EXIT_SUCCESS;
}

