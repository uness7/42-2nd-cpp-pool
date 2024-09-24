CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

S = src

TARGET = exec

SRCS = src/main.cpp \
       src/Bureaucrat.cpp \
       src/Form.cpp \

OBJS = $(SRCS:.cpp=.o)

# colors 
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
WHITE		=	\033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	printf "$(GREEN)Compilation finished\n$(WHITE)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)
	printf "$(YELLOW)Directory is cleaned\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
