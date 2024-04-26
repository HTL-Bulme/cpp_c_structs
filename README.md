# C++ C-Strings Exercises

In this homework you are asked to restrict yourself to not using any
`include` except `<cstddef>`.
The purpose of this homework is to understand low level
functionality that is usually provided by libraries.

Compile your code via

```shell
mkdir build -p && cd build
cmake ..
make -j8  # use 8 processor cores when compiling
```

## Task 1 - Capitalize String
Implement a function `void capitalize(char string[]);` that capitalizes the
given string. For example,

```cpp
char text[] = "The world is beautiful!";
capitalize(text);  // `text` becomes "The World Is Beautiful."
```

Write your code in `c_strings.cpp`.

## Task 2 - String Functions
Implement the following functions:

```cpp
// Return the number of characters in `str` excluding the trailing '\0'.
std::size_t str_len(const char str[]);

// "Hello World!" => "hELLO wORLD!"
void str_invert_case(char str[]);

// Return true if `str` starts with prefix, otherwise false.
bool str_starts_with(const char str[], const char prefix[]);

// true if `str` ends with suffix
bool str_ends_with(const char str[], const char suffix[]);

// number of occurences of `sub` in `str`
unsigned str_count(const char str[], const char sub[]);

// true if `str` only has 7 bit ascii chars (no extended ascii)
bool str_is_ascii(const char str[]);

// true if `str` only has digits
bool str_is_digit(const char str[]);

// position of first occurance of `sub` in `str` | -1
long str_index(const char str[], const char sub[]);
```

## Task 3 - Copy and Compare
Implement the functions

```cpp
void str_copy(char* dst, const char src[], std::size_t dst_size);
```

and

```cpp
bool str_equal(const char first[], const char second[]);
```

When copying `src` to `dst` make sure not to copy more than `dst_size` - 1
characters and properly terminate `dst`. Don't copy more bytes than strictly
needed.

`str_equal(.)` must compare strings byte by byte. Make sure not to read
beyond the length of a string.

Write your code in `c_strings.cpp`.


## Task 4 - Join array of C-strings
The task is to implement the following function

```cpp
void join(const char* array[], std::size_t count, char str[], const char sep[]);
```

`count` denotes the number of strings in `array`.
You may assume that the caller always passes a `str` that is large enough to
contain all of the joined strings including the separators between them.
`sep` can contain any number of characters that are inserted between the
strings in `array`. For example

```cpp
char* array[] = {"Chris", "Pat", "Maria"};
char result[100];
join(array, 3, result, " | ");  // => "Chris | Pat | Maria"
```

Write your code in `c_strings.cpp`.
