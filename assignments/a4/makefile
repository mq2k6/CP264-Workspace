# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
Q1_EXE = q1
Q2_EXE = q2

# Source files
Q1_SRC = mysort.c mysort_ptest.c
Q2_SRC = mysort.c myrecord.c myrecord_ptest.c

# Default target: compile both Q1 and Q2
all: $(Q1_EXE) $(Q2_EXE)

# Compile Q1
$(Q1_EXE): $(Q1_SRC)
	$(CC) $(CFLAGS) $(Q1_SRC) -o $(Q1_EXE)

# Compile Q2
$(Q2_EXE): $(Q2_SRC)
	$(CC) $(CFLAGS) $(Q2_SRC) -o $(Q2_EXE)

# Run Q1
run_q1: $(Q1_EXE)
	./$(Q1_EXE)

# Run Q2
run_q2: $(Q2_EXE)
	./$(Q2_EXE)

# Clean build artifacts
clean:
	rm -f $(Q1_EXE) $(Q2_EXE) *.o