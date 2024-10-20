CXX = c++
INC = inc
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC) -g

S = src

TARGET = output 

SRCS = src/main.cpp \
       src/Bureaucrat.cpp \
       src/AForm.cpp \
       src/ShrubberyCreationForm.cpp \
       src/RobotomyRequestForm.cpp \
       src/PresidentialPardonForm.cpp \
       src/Intern.cpp \

OBJS = $(SRCS:.cpp=.o)

# colors for printing
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
	rm -f *_shrubbery
	printf "$(YELLOW)Directory is cleaned\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
