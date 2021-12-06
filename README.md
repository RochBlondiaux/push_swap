<h1 align="center">
	 Push Swap
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' push swap project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/rochblondiaux/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rochblondiaux/push_swap?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/rochblondiaux/push_swap?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rochblondiaux/push_swap?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rochblondiaux/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rochblondiaux/push_swap?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to write an algorithm that sort numbers._

For detailed information, refer to the [**subject of this project**](https://github.com/RochBlondiaux/push_swap/blob/main/fr.subject.pdf).

	🚀 TLDR: Write a C program named push_swap, which computes and displays on the
    standard output the smallest program in the instruction language of Push_swap
    allowing to sort the integers passed in parameter.

## 📑 Index

`@root`

* [**📁 includes:**](includes/) contains all prototypes and libraries includes.
* [**📁 srcs:**](srcs/) contains all project sources files.
    * [**📁 checker:**](srcs/checker/) contains all checker files.
    * [**📁 elements:**](srcs/elements/) contains all elements files.
    * [**📁 operations:**](srcs/operations/) contains all operations files.
    * [**📁 parsing:**](srcs/parsing/) contains all parsing files.
    * [**📁 sorting:**](srcs/sorting/) contains all sorting files.
    * [**📁 utils:**](srcs/utils/) contains all utilities files.
* [**📁 libft:**](srcs/libft/) contains the libft project sources.
* [**📁 gnl:**](srcs/gnl/) contains the gnl project sources.

`@/srcs/main.c`
* `main` - Start the program.

`@/srcs/checker/checker.c`
* `main` - Start the program.
* `handle_standard_input` - Reads standard input.
* `dispatch_command` - Parses and executes commands from standard input.

`@/srcs/elements/clear_elements.c`
* `clear_elements` - Clear both stacks to avoid leaks at program exit.

`@/srcs/elements/element_size.c`
* `element_size` - Get stack length.

`@/srcs/elements/get_element.c`
* `get_element` - Get element from its index.

`@/srcs/elements/new_element.c`
* `new_element` - Create a new element.

`@/srcs/operations/push.c`
* `push_silently` - Push first element from a stack to another one without printing nothing.
* `push` - Push first element from a stack to another one and print it.

`@/srcs/operations/reverse_rotate.c`
* `reverse_rotate_silently` - Reverse rotate an element silently.
* `reverse_rotate` - Reverse rotate an element.
* `reverse_rotate_both` - Reverse rotate an element on each stack.

`@/srcs/operations/rotate.c`
* `rotate_silently` - Rotate an element silently.
* `rotate` - Rotate an element.
* `rotate_both` - Rotate an element on each stack.

`@/srcs/operations/swap.c`
* `swap_silently` - Swap an element silently.
* `swap` - Swap an element.
* `swap_both` - Swap an element on each stack.

`@/srcs/parsing/parser.c`
* `check_data` - Validate linked list after parsing.
* `strlen_` - Get the length of a pointer on string.
* `contains_space` - Check if a string contains a space.
* `create_new_element` - Create a new element and exit if it doesn't match requirements.
* `parse` - Get linked list from string.

`@/srcs/sorting/sort.c`
* `sort_3` - Sort a linked list of 3 elements or fewer.
* `sort_5` - Sort a linked list of 5 elements or fewer.
* `sort_100` - Sort a linked list of 100 elements or fewer.
* `sort_500` - Sort a linked list of 500 elements or fewer.
* `sort` - Executes the right sort function depending on the list size.

`@/srcs/utils/element_utils.c`
* `get_top` - Get first element value of a linked list.
* `get_bottom` - Get last element value of a linked list.
* `get_bigger` - Get the bigger element of a linked list.
* `get_lowest` - Get the lowest element of a linked list.

`@/srcs/utils/sorting_utils.c`
* `is_sorted` - Check if a linked list is sorted in ascending order.
* `nicest_5sort` - Executes right functions to sort 5 random numbers.

`@/srcs/utils/utils.c`
* `exit_error` - Exits program with error.
* `print_stacks` - Prints both stacks if debug mode is enabled. 
* `ft_strcmp` - Compares two strings.

`@/srcs/gnl/get_next_line`

* `ft_read`	- read & wrap a buffer from a file descriptor.
* `ft_read_next`	- concatenate last red buffer and latest one.
* `ft_find_nl`	- cut line at the right length.
* `get_next_line`	- main function.

`@/srcs/gnl/get_next_line_utils.c`

* `ft_strchr_` - find first occurrence of a character and return its index.

`@/srcs/libft/`

* `ft_strlcpy`	- copy string to another location
* `ft_strlcat`	- concatenate strings
* `ft_strdup`	- save a copy of a string (with malloc)
* `ft_strjoin`	- join two strings (with malloc)
* `ft_substr`	- extract a substring (with malloc)
* `ft_atoi`	    - convert a string to an integer
* `ft_isascii`	- check if a character is in the ascii table
* `ft_isprint`  - check if a character is printable
* `ft_isdigit`	    - check if a character is a digit
* `ft_isupper`	    - check if a character is uppercase
* `ft_islower`	    - check if a character is lowercase
* `ft_memset`	    - fill memory with a constant byte
* `ft_memmove`	    - copy memory area
* `ft_strlcpy`	    - size-bounded string copying
* `ft_strlcat`	    - size-bounded string concatenation
* `ft_strchr`	    - locate first character instance in string
* `ft_strrchr`	    - locate last character instance in string
* `ft_strncmp`	    - compare two strings within given size
* `ft_memchr`	    - scan memory for a character
* `ft_memcmp`	    - compare memory areas
* `ft_strnstr`	    - locate a substring in a string
* `ft_calloc`	    - allocates memory for an array of a given length
* `ft_strdup`	    - duplicate a string
* `ft_substr`	- get a sub string from the original string
* `ft_strjoin`	- concatenate two strings
* `ft_strtrim`	- remove targeted characters
* `ft_split`	- split string into a 2d array
* `ft_itoa`	- convert numbers to string
* `ft_strmapi`	- apply a function on each character of a string
* `ft_striteri`	- execute a function on each character of a string
* `ft_putchar_fd`	- write a character
* `ft_putstr_fd`	- write a string
* `ft_putnbr_fd`	- write numbers
* `ft_putendl_fd`	- add a new line at the end of a file
* `ft_lstnew`	- create a new linked list element
* `ft_lstadd_front`	- add an element to the front of a linked list
* `ft_lstsize`	- get the size of a linked list
* `ft_lstlast`	- get the last element of a linked list
* `ft_lstadd_back`	- add an element to the end of a linked list
* `ft_lstdelone`	- delete an element from a linked list
* `ft_lstclear`	- clear a linked list
* `ft_lstiter`	- apply a function to each element of a linked list
* `ft_lstmap`	- apply a function to each element of a linked list & create a new list

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

_Coming soon_

## 📋 Testing

_Coming soon_