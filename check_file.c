#include <sys/types.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv) {
int fd;
off_t from, till;
size_t sz;
char *endptr, *buf;

if ((fd = open(argv[1], O_RDONLY)) == -1)
err(1, "open: %s", argv[1]);
from = strtoull(argv[2], &endptr, 10);
if (!endptr)
errx(1, "from is wrong: %s", argv[2]);
till = strtoull(argv[3], &endptr, 10);
if (!endptr)
errx(1, "till is wrong: %s", argv[3]);
sz = (size_t)(till - from);
buf = malloc(sz);
if (pread(fd, buf, sz, from) == -1)
err(1, "read");
puts(buf);
return 0;
}
