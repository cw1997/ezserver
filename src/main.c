#include <stdio.h>
#include "log/log.h"
#include "datetime.h"
#include "string.h"


int main(int argc, char const *argv[])
{
	write_log(LOG_LEVEL_ERROR, "error");
	return 0;
}









	/*printf("%s\n", "test");
	char buf[2][128];
	split(buf, ":", "k:v");
	printf("%s\n", buf[0]);*/
	// printf("%s\n", getDateText());