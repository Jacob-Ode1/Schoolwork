#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd_buf[100];

FILE *input_fh;

const char *read_cmd(void) {
    int len;
    char *res;
    res = fgets(cmd_buf, 80, input_fh);
    if (!res) {
	printf("Exiting on end of file.\n");
	exit(0);
    }
    len = strlen(cmd_buf);
    if (len > 72) {
	printf("Were you expecting a buffer overflow?\n");
	exit(1);
    }
    if (len == 0) {
	return "do nothing";
    }
    if (cmd_buf[len - 1] == '\n') {
	cmd_buf[len - 1] = '\0';
    }
    if (!strcmp(cmd_buf, "quit") || !strcmp(cmd_buf, "quit game") ||
	!strcmp(cmd_buf, "exit") || !strcmp(cmd_buf, "exit game")) {
	exit(0);
    }
    return cmd_buf;
}

typedef void (*room_func)(void);

room_func room = 0;

void wall(void) {
    printf("A wall blocks your way.\n");
}

void nothing(void) {
    printf("Nothing happens.\n");
}

void room_2(void);
void room_3(void);
void room_4(void);
void room_5(void);
void room_6(void);
void room_7(void);
void room_8(void);
void room_9(void);
void room_10(void);
void room_11(void);
void room_12(void);
void room_13(void);
void room_14(void);
void room_15(void);
void room_16(void);


void room_1(void) {
    const char *cmd;
    printf("You are in a maze of twisty passages, all alike\n");
    printf("There are exits to the south and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go north") || !strcmp(cmd, "go east")) {
	wall();
    } else if (!strcmp(cmd, "go west")) {
	room = room_2;
    } else if (!strcmp(cmd, "go south")) {
	room = room_5;
    } else {
	nothing();
    }
}

void room_2(void) {
    const char *cmd;
    printf("You are in a maze of twisty passages, each alike\n");
    printf("There are exits to the east, south and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go north")) {
	wall();
    } else if (!strcmp(cmd, "go east")) {
	room = room_1;
    } else if (!strcmp(cmd, "go west")) {
	room = room_3;
    } else if (!strcmp(cmd, "go south")) {
	room = room_6;
    } else {
	nothing();
    }
}

void room_3(void) {
    const char *cmd;
    printf("You are in a twisty maze of passages, each alike\n");
    printf("There are exits to the east, south and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go north")) {
	wall();
    } else if (!strcmp(cmd, "go east")) {
	room = room_2;
    } else if (!strcmp(cmd, "go west")) {
	room = room_4;
    } else if (!strcmp(cmd, "go south")) {
	room = room_7;
    } else {
	nothing();
    }
}

void room_4(void) {
    const char *cmd;
    printf("You are in a twisty maze of passages, all alike\n");
    printf("There are exits to the east and south\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go north") || !strcmp(cmd, "go west")) {
	wall();
    } else if (!strcmp(cmd, "go east")) {
	room = room_3;
    } else if (!strcmp(cmd, "go south")) {
	room = room_8;
    } else {
	nothing();
    }
}

void room_5(void) {
    const char *cmd;
    printf("You are in a maze of twisting passages, all alike\n");
    printf("There are exits to the north, south and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go east")) {
	wall();
    } else if (!strcmp(cmd, "go north")) {
	room = room_1;
    } else if (!strcmp(cmd, "go west")) {
	room = room_6;
    } else if (!strcmp(cmd, "go south")) {
	room = room_9;
    } else {
	nothing();
    }
}

void room_6(void) {
    const char *cmd;
    printf("You are in a maze of twisting passages, each alike\n");
    printf("There are exits in all directions.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go east")) {
	room = room_5;
    } else if (!strcmp(cmd, "go north")) {
	room = room_2;
    } else if (!strcmp(cmd, "go west")) {
	room = room_7;
    } else if (!strcmp(cmd, "go south")) {
	room = room_10;
    } else {
	nothing();
    }
}

void room_7(void) {
    const char *cmd;
    printf("You are in a twisting maze of passages, each alike\n");
    printf("There are exits in all directions.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go east")) {
	room = room_6;
    } else if (!strcmp(cmd, "go north")) {
	room = room_3;
    } else if (!strcmp(cmd, "go west")) {
	room = room_7;
    } else if (!strcmp(cmd, "go south")) {
	room = room_11;
    } else {
	nothing();
    }

}

void room_8(void) {
    const char *cmd;
    printf("You are in a twisting maze of passages, all alike\n");
    printf("There are exits to the north, south and east.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go west")) {
	wall();
    } else if (!strcmp(cmd, "go north")) {
	room = room_4;
    } else if (!strcmp(cmd, "go east")) {
	room = room_7;
    } else if (!strcmp(cmd, "go south")) {
	room = room_12;
    } else {
	nothing();
    }
}

void room_9(void) {
    const char *cmd;
    printf("You are in a labyrinth of twisty passages, all alike\n");
    printf("There are exits to the north, south and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go east")) {
	wall();
    } else if (!strcmp(cmd, "go north")) {
	room = room_5;
    } else if (!strcmp(cmd, "go west")) {
	room = room_10;
    } else if (!strcmp(cmd, "go south")) {
	room = room_13;
    } else {
	nothing();
    }
}

void room_10(void) {
    const char *cmd;
    printf("You are in a labyrinth of twisty passages, each alike\n");
    printf("There are exits in all directions.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go east")) {
	room = room_9;
    } else if (!strcmp(cmd, "go north")) {
	room = room_6;
    } else if (!strcmp(cmd, "go west")) {
	room = room_11;
    } else if (!strcmp(cmd, "go south")) {
	room = room_14;
    } else {
	nothing();
    }
}

void room_11(void) {
    const char *cmd;
    printf("You are in a twisty labyrinth of passages, each alike\n");
    printf("There are exits in all directions.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go east")) {
	room = room_10;
    } else if (!strcmp(cmd, "go north")) {
	room = room_7;
    } else if (!strcmp(cmd, "go west")) {
	room = room_12;
    } else if (!strcmp(cmd, "go south")) {
	room = room_15;
    } else {
	nothing();
    }
}

/* It's not actually possible to make a C program that is guaranteed
   to perform a null pointer dereference, because a null pointer
   dereference is an undefined behavior that the compiler is allowed
   to optimize away. But this function intoduces a number of
   complexities that tend to inhibit compilers from optimizing things
   away, which are enough to keep the null dereference present at
   least up through LLVM 14 with LTO mode. */
int global_variable_for_null_deref = 10;
void null_dereference(void) {
    char c = 41;
    char *null_ptr = &c;
    int limit = global_variable_for_null_deref;
    for (int i = 0; i < limit; i++) {
	for (int j = 0; j < limit; j++) {
	    if (i > 1 && j > 1 && i * i == j)
		null_ptr = 0;
	}
    }
    global_variable_for_null_deref = (*null_ptr)++;
    printf("This shouldn't be printed, the program should have crashed: %d\n",
	   global_variable_for_null_deref);
}

void room_12(void) {
    const char *cmd;
    printf("You are in a twisty labyrinth of passages, all alike\n");
    printf("There are exits to the north, south and east.\n");
    printf("There is a bottle on the ground "
	   "labeled 'null dereference potion'.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go west")) {
	wall();
    } else if (!strcmp(cmd, "go north")) {
	room = room_8;
    } else if (!strcmp(cmd, "go east")) {
	room = room_11;
    } else if (!strcmp(cmd, "go south")) {
	room = room_16;
    } else if (!strcmp(cmd, "drink potion")) {
	null_dereference();
    } else {
	nothing();
    }
}

void room_13(void) {
    const char *cmd;
    printf("You are in a labyrinth of twisting passages, all alike\n");
    printf("There are exits to the north and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go south") || !strcmp(cmd, "go east")) {
	wall();
    } else if (!strcmp(cmd, "go west")) {
	room = room_14;
    } else if (!strcmp(cmd, "go north")) {
	room = room_9;
    } else {
	nothing();
    }
}

void room_14(void) {
    const char *cmd;
    printf("You are in a labyrinth of twisting passages, each alike\n");
    printf("There are exits to the north, east, and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go south")) {
	wall();
    } else if (!strcmp(cmd, "go east")) {
	room = room_13;
    } else if (!strcmp(cmd, "go west")) {
	room = room_15;
    } else if (!strcmp(cmd, "go north")) {
	room = room_10;
    } else {
	nothing();
    }
}

void room_15(void) {
    const char *cmd;
    printf("You are in a twisting labyrinth of passages, each alike\n");
    printf("There are exits to the north, east, and west.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go south")) {
	wall();
    } else if (!strcmp(cmd, "go east")) {
	room = room_14;
    } else if (!strcmp(cmd, "go west")) {
	room = room_16;
    } else if (!strcmp(cmd, "go north")) {
	room = room_11;
    } else {
	nothing();
    }
}

void room_16(void) {
    const char *cmd;
    printf("You are in a twisting labyrinth of passages, all alike\n");
    printf("There are exits to the north and east.\n");
    cmd = read_cmd();
    if (!strcmp(cmd, "go south") || !strcmp(cmd, "go west")) {
	wall();
    } else if (!strcmp(cmd, "go east")) {
	room = room_15;
    } else if (!strcmp(cmd, "go north")) {
	room = room_12;
    } else {
	nothing();
    }
}

int main(int argc, char **argv) {
    printf("Welcome to the bug adventure game!\n");
    printf("All legal commands are of the form <verb> <noun>\n");

    if (argc == 1) {
	input_fh = stdin;
    } else if (argc == 2) {
	input_fh = fopen("r", argv[1]);
	if (!input_fh) {
	    fprintf(stderr, "Failed to open command file %s for reading\n",
		    argv[1]);
	    exit(1);
	}
    }

    room = room_2;
    for (;;) {
	(*room)();
    }
}
