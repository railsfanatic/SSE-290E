# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OSTYPE),cygwin)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
elseifeq ($(OSTYPE),msys)
    CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.exe
elseifeq ($(OS),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

UNITY_ROOT=../Unity
C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror 
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET_DIR = bin/
TARGET_BASE1 = homework2
TARGET1 = $(TARGET_DIR)$(TARGET_BASE1)$(TARGET_EXTENSION)
TEST_TARGET1 = $(TARGET_DIR)test_$(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1 = multiples.c
MAIN_FILE1 = homework2.c
TEST_FILES1 = $(UNITY_ROOT)/src/unity.c test/test_multiples.c test/test_runners/test_multiples_runner.c
INC_DIRS = -I.
TEST_INC_DIRS = -I$(UNITY_ROOT)/src
SYMBOLS = -DTEST

all: clean default

default:
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/test_multiples.c  test/test_runners/test_multiples_runner.c
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_INC_DIRS) $(SYMBOLS) $(SRC_FILES1) $(TEST_FILES1) -o $(TEST_TARGET1)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES1) $(MAIN_FILE1) -o $(TARGET1)
	./$(TEST_TARGET1)

clean:
	$(CLEANUP) bin/*.* test/test_runners/*.*

