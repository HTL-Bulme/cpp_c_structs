#include <cstddef>

void capitalize(char string[]);
std::size_t str_len(const char str[]);
void str_invert_case(char str[]);
bool str_starts_with(const char str[], const char prefix[]);
bool str_ends_with(const char str[], const char suffix[]);
unsigned str_count(const char str[], const char sub[]);
bool str_is_ascii(const char str[]);
bool str_is_digit(const char str[]);
long str_index(const char str[], const char sub[]);
void str_copy(char dst[], const char src[], std::size_t dst_size);
bool str_equal(const char first[], const char second[]);
void join(const char* array[], std::size_t count, char str[], const char sep[]);

