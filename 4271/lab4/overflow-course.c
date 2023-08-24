#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input_fh;
int line_num = 1;

void read_attack_line_into_buf(char *buffer, size_t len) {
    char *inbuf = 0;
    size_t inbuf_size = 0;
    ssize_t num_read;
    int i;
    num_read = getline(&inbuf, &inbuf_size, input_fh);
    if (num_read == -1) {
	fprintf(stderr, "Failed to read line %d from input: %s\n",
		line_num, errno ? strerror(errno) : "end of file");
	exit(1);
    }
    if (num_read > 0 && inbuf[num_read - 1] == '\n') {
	/* Remove a trailing newline, if any */
	inbuf[num_read - 1] = '\0';
	num_read--;
    }
    if (num_read > len) {
	fprintf(stderr, "Line %d is too long (%zd vs. %zd)\n",
		line_num, num_read, len);
	exit(1);
    }
    for (i = 0; i < num_read; i++) {
	unsigned char c = inbuf[i];
	if (!isprint(c)) {
	    fprintf(stderr, "Line %d contains the illegal character "
		    "%c (0x%02x)\n", line_num, c, c);
	    exit(1);
	}
    }
    line_num++;

    /* Now that all the safety checks have passed, copy the data */
    memcpy(buffer, inbuf, num_read);

    if (inbuf)
	free(inbuf);
}

/* ---------------------------------------------------------------------- */

struct stage1_s {
    char buf[4];
    int i;
};

void stage1(void) {
    struct stage1_s s;
    s.i = 0x4271;
    read_attack_line_into_buf(s.buf, 8);
    if (s.i == 0x4271) {
	printf("Stage 1 failed (still 0x%08x)\n", s.i);
    } else {
	printf("Stage 1 succeeded (changed to 0x%08x)\n", s.i);
    }
}

/* ---------------------------------------------------------------------- */

struct stage2_s {
    char buf[10];
    int i;
    long j;
    float f;
    unsigned char uc;
    char c;
    signed char sc;
    double d;
};

void stage2(void) {
    struct stage2_s s;
    s.c = 'c';
    read_attack_line_into_buf(s.buf, sizeof(s));
    if (s.c == '!') {
	printf("Stage 2 succeeded\n");
    } else {
	printf("Stage 2 failed (c is '%c')\n", s.c);
    }
}

/* ---------------------------------------------------------------------- */

struct stage3_s {
    char buf[8];
    long l1;
    long l2;
};

void stage3(void) {
    struct stage3_s s;
    s.l1 = 0x4271;
    s.l2 = 0x2021;
    read_attack_line_into_buf(s.buf, sizeof(s));
    if (s.l1 - s.l2 == 10) {
	printf("Stage 3 succeeded\n");
    } else {
	printf("Stage 3 failed (0x%016lx-0x%016lx = 0x%016lx)\n",
	       s.l1, s.l2, s.l1 - s.l2);
    }
}

/* ---------------------------------------------------------------------- */

struct stage4_s {
    char buf[4];
    int x;
    int y;
};

void stage4(void) {
    struct stage4_s s;
    s.x = 0xcafe2021;
    read_attack_line_into_buf(s.buf, sizeof(s));
    if (s.x == 0xcafe4271) {
	printf("Stage 4 succeeded\n");
    } else {
	printf("Stage 4 failed (x is 0x%08x)\n", s.x);
    }
}

/* ---------------------------------------------------------------------- */

struct stage5_s {
    char buf[17];
    int i;
};

void stage5(void) {
    struct stage5_s s;
    int x;
    s.i = 0;
    read_attack_line_into_buf(s.buf, sizeof(s));
    x = 256 * s.i + 255;
    if (x < s.i) {
	printf("Stage 5 succeeded\n");
    } else {
	printf("Stage 5 failed (256*0x%08x + 255 = 0x%08x)\n", s.i, x);
    }
}

/* ---------------------------------------------------------------------- */

struct stage6_s {
    char buf[4];
    char buf2[4];
    int i;
    char buf3[4];
};

void stage6(void) {
    struct stage6_s s;
    s.i = 0;
    read_attack_line_into_buf(s.buf, sizeof(s));
    if (memcmp(s.buf2, "4271", 4) || (s.i << 4) != 0x44227770
	|| memcmp(s.buf3, "5271", 4)) {
	printf("Stage 6 failed\n");
    } else {
	printf("Stage 6 succeeded\n");
    }
}

/* ---------------------------------------------------------------------- */

struct stage7_s {
    char buf[8];
    void (*fn_ptr)(void);
};

void stage7_win1(void) {
    fputs(".", stdout); printf("%c", '.'); printf("%s", "."); putchar('.');
    fputs(".", stdout); printf("%c", '.'); printf("%s", "."); putchar('.');
    printf("Stage 7 succeeded, thanks for playing!\n");
    exit(0);
}

void stage7_lose(void) {
    printf("Stage 7 failed\n");
}

void stage7_win2(void) {
    fputs(".", stdout); printf("%c", '.'); printf("%s", "."); putchar('.');
    fputs(".", stdout); printf("%c", '.'); printf("%s", "."); putchar('.');
    printf("Stage 7 succeeded, congratulations!\n");
    exit(0);
}

void stage7(void) {
    struct stage7_s s;
    s.fn_ptr = &stage7_lose;
    read_attack_line_into_buf(s.buf, sizeof(s));
    (*s.fn_ptr)();
}

/* ---------------------------------------------------------------------- */

int main(int argc, char **argv) {
    char *input_fname;
    if (argc != 2) {
	fprintf(stderr, "Usage: overflow-course <attacks-file>\n");
    }
    input_fname = argv[1];
    input_fh = fopen(input_fname, "r");
    if (!input_fh) {
	fprintf(stderr, "Failed to open %s for reading: %s\n",
		input_fname, strerror(errno));
	exit(1);
    }
    stage1();
    stage2();
    stage3();
    stage4();
    stage5();
    stage6();
    stage7();
}
