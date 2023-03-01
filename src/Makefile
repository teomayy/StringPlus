FLAGS = -std=c11 -Wall -Wextra -Werror 
#для варианта с linux
OS := $(shell uname)

ifeq ($(OS),Linux)
	CHFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	CHFLAGS = -lcheck -lm -lpthread
endif

all: clean s21_string.a s21_string.o

#TEST_UNIT: запуск теста
all2: clean cl2 s21_string.a s21_string.o unit-test.o test gcov_report

s21_string.o:
	gcc $(FLAGS) -c s21_*.c

s21_string.a: s21_string.o
	ar -cr s21_string.a *.o
	rm -rf *.o
unit-test.o:
	gcc $(FLAGS) -c unit_test.c s21_*.c

test: unit_test.c s21_string.a
	gcc $(FLAGS) unit_test.c s21_string.a -o unit_test $(CHFLAGS)

gcov_report: s21_string.a
	gcc --coverage s21_*.c unit_test.c -o gcov -lcheck $(CHFLAGS)
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov
clean:
	rm -rf *.o *.a unit_test
	rm -rf *.gcno *gcda *.gcov gcov program
	rm -rf report report.info

# TEST_UNIT: сделать перед запуском теста
# TESTT: t1 t2 t3 t4 t5
#t1:
#	cd /opt/goinfre/USER
#	git clone https://github.com/Homebrew/brew homebrew
#t2:
#	eval "$(/opt/goinfre/USER/homebrew/bin/brew shellenv)"
# 	brew update --force --quiet
# t3:
# 	chmod -R go-w "$(brew --prefix)/share/zsh"
# 	brew install gcov
# t4:
# 	brew install lcov
# t5: 
# 	cd  /Users/USER/C2_s21_stringplus-3/src/

##############__clang check__###############
cl1:
	clang-format -style=Google -n *.c *.h
#clang formatte
cl2:
	clang-format -style=Google -i *.c *.h
#############################################

