#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		sz;
	char	*buf;

	buf = malloc(sizeof(*buf) * 108);
	fd1 = open("foo.txt", O_RDONLY);
	fd2 = open("foo.txt", O_RDONLY);
	sz = read(fd1, buf, 14);
	printf("called read(%d, buf, 10),returned that %d bytes were read\n", fd1,	sz);
	sz = read(fd1, buf, 14);
	printf("called read(%d, buf, 10),returned that %d bytes were read\n", fd1,	sz);
	// sz = read(fd2, buf, 12);
	printf("called read(%d, buf, 10),returned that %d bytes were read\n", fd2,	sz);
	buf[50] = '\0';
	printf("those bytes were: %s\n", buf);
}
