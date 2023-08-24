#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void read_and_print(int fd, size_t size) {
    char buf[20];

    /* Zero-fill the buffer. The only value to doing this is that if
       the read is less than the full size, it will be
       null-terminated for puts() below. */
    memset(buf, 0, 20);

    /* Read the contents of the file into the buffer. Obviously with
       no check on the size. */
    read(fd, buf, size);

    /* Print the buffer contents. */
    puts(buf);
}

int main(int argc, char **argv) {
    char *fname;
    int res, fd;
    struct stat st_buf;

    if (argc != 2) {
	fprintf(stderr, "Usage: overflow-from-file <file>\n");
	exit(1);
    }
    fname = argv[1];

    /* stat is a Unix system call to get metadata about a file */
    res = stat(fname, &st_buf);
    if (res) {
	fprintf(stderr, "Failed to stat %s: %s\n", fname, strerror(errno));
	exit(1);
    }

    /* open is a Unix system call to open a file */
    fd = open(fname, O_RDONLY);
    if (fd == -1) {
	fprintf(stderr, "Failed to open %s: %s\n", fname, strerror(errno));
	exit(1);
    }
    
    /* Pass the full size of the file as the length to read */
    read_and_print(fd, st_buf.st_size);

    close(fd);

    return 0;
}
