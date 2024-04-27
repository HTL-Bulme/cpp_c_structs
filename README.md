# C++ C-Structs Exercises

Compile your code via

```shell
mkdir build -p && cd build
cmake ..
make -j8  # use 8 processor cores when compiling
```

## Task 1 - Complex Numbers
Implement a struct `Complex` that stores the `real`
number and the imaginary unit (`imag`). Both `real`
and `image` should be `double`.
Implement the following functions:

```cpp
Complex add(Complex a, Complex b);  // return the sum of `a` and `b`
Complex sub(Complex a, Complex b);  // return the difference of `a` and `b`
Complex mul(Complex a, Complex b);  // return the product of `a` and `b`
```

Having these functions in place, it becomes possible to add, substract,
and multiply two complex numbers. The mathematical basis for the
implementation is available for

[addition and substraction](https://en.wikipedia.org/wiki/Complex_number#Addition_and_subtraction)
as well as
[multiplication](https://en.wikipedia.org/wiki/Complex_number#Multiplication_and_square).

Use these functions in <code>main(.)</code> to make sure they produce
the correct outcomes for the following combinations:
<ol>
  <li>5+5i, 7+i;</li>
  <li>5+5i, 7-3i;</li>
  <li>3-2i, 7-3i;</li>
  <li>-5, 7-3i</li>
</ol>

Name the source file: `complex_numbers.cpp`


## Task 2 - Student Data
Implement a struct that stores information about a student in a struct
called `Student`. Each student has a
`std::string first_name`,
`std::string last_name` and a `uint64_t id`.
Implement the following functions:

```cpp
Student read_student(std::istream& in);  // read student info from stream
// print one student per line to stdout
void print_students(Student students[], size_t dimension);
```

In <code>main(.)</code> ask the user how many students should be stored.
Create an array holding the correct number of students and fill the array
by repeatedly calling <code>read_student()</code>. Once finished,
print your in-memory student database to <code>stdout</code>.<br />

Name the source file: `student_database.cpp`


