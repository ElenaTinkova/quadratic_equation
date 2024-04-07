CC=gcc
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = -lcheck -lm
TESTS_FUN:=tests/solve_equation_test.c
SOURCE_FUN:=solve_equation.c

all: solve_equation.a check
		

solve_equation.a:
		$(CC) $(CFLAGS) -c $(SOURCE_FUN)
		ar rcs solve_equation.a *.o
		@ranlib solve_equation.a

check: 
		@$(CC) $(CFLAGS) $(TESTS_FUN) $(SOURCE_FUN) $(TESTFLAGS) -o testing
		./testing

lint:
		@clang-format --style=Google -i *.c *.h

clean:
		@rm -rf *.o *.out testing *.a