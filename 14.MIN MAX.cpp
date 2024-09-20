#include <stdio.h>
#include <string.h>
int main()
{
	char Str[] = "mahi";
	int i = 0, cnt = 0;
	while (Str[i]) {
		cnt++;
		i++;
	}
	printf("%d", cnt);
	return 0;
}
