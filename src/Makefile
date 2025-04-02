CC = gcc

CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror -Wno-gnu-zero-variadic-macro-arguments
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs --coverage -pthread -I./check -L./check -lcheck

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    LIFLAG = -I./check
    LDFLAGS += -I./check -L./check -lcheck
	OPEN = open
else
    LIFLAG = 
    LDFLAGS += -lcheck -lcheck_pic -lrt -lm -lsubunit 
	OPEN = xdg-open
endif

SRC_DIR = s21_decimal
SRC_TESTS_DIR = s21_tests
BUILD_DIR = build
BUILD_SRC_DIR = $(BUILD_DIR)/src
BUILD_SRC_COV_DIR = $(BUILD_DIR)/src_cov
BUILD_TESTS_DIR = $(BUILD_DIR)/tests

LIBRARY = s21_decimal.a
LIBRARY_COV = s21_decimal_cov.a
TEST_BINARY = test

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC_FILES = $(wildcard $(SRC_TESTS_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_SRC_DIR)/%.o, $(SRC_FILES))
OBJ_COV_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_SRC_COV_DIR)/%.o, $(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(SRC_TESTS_DIR)/%.c, $(BUILD_TESTS_DIR)/%.o, $(TEST_SRC_FILES))



all: clean $(LIBRARY) test gcov_report


$(LIBRARY): $(OBJ_FILES)	
	ar rcs $@ $^

$(BUILD_SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@



$(LIBRARY_COV): $(OBJ_COV_FILES)
	ar rcs $@ $^

$(BUILD_SRC_COV_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $^ -o $@

test: clean no_clean_test

no_clean_test: $(TEST_OBJ_FILES) $(LIBRARY_COV)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(TEST_BINARY)
	./$(TEST_BINARY)

$(BUILD_TESTS_DIR)/%.o: $(SRC_TESTS_DIR)/%.c
	$(CC) $(CFLAGS) $(LIFLAG) -c $^ -o $@

gcov_report: test
	lcov -t "Report" -c -d $(BUILD_SRC_COV_DIR) --output-file coverage.info
	genhtml coverage.info -o ./report
	$(OPEN) report/index.html




clean:
	-rm -rf $(BUILD_SRC_DIR)/*.o
	-rm -rf $(BUILD_SRC_COV_DIR)/*.o
	-rm -rf $(BUILD_SRC_COV_DIR)/*.gcno
	-rm -rf $(BUILD_SRC_COV_DIR)/*.gcda
	-rm -rf $(BUILD_TESTS_DIR)/*.o
	-rm -rf $(TEST_BINARY)
	-rm -rf report
	-rm -rf coverage.info
	-rm -rf *.a

