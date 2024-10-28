SHELL=/bin/bash # specify the shell

compiler := c++
flags := -Wall -Wextra -Werror -std=c++98 -g
target := output

# Notes:
# - to refer to variables, we can use either echo $(x) or echo ${x}
# - all is a default rule that is used to rum multiple commands at the same time

all: main.o

main.o: main.cpp
	$(compiler) main.cpp -o $(target) -I$(flags)

clean:
	rm -f $(target)

.PHONY:
	clean
