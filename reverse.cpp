/**
 * @file    reverse.cpp
 * @author  Josh Borthick <jborthick019919@gmail.com>
 * @brief   Output the reverse of a string of characters.
 * @version 1.0
 * @date    2022-07-04
 *
 * @copyright Copyright (c) 2022 Josh Borthick
 *
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::setfill;
using std::setw;
using std::string;

int len(char*);
void rev_recursive(char*, int);
void rev_recursive2(char*);
void rev_iterative(char*, int);

/**
 * @brief Output a string in reverse.
 * @pre Function call and a single string.
 * @post None.
 * @return 0, for situation normal.
 *
 * USAGE: ./rev <string to reverse>
 */
int main(int argc, char **argv)
{
    std::string str (argv[1]);
    cout << endl;
    cout << str.string::size() << endl;
    cout << str.string::length() << endl;
    cout << len(argv[1]) << endl;
    int n = len(argv[1]);

    cout << endl << "Finding size: ";
    auto start = high_resolution_clock::now();
    str.string::size();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "took " << duration.count() / 100 << " nanoseconds" << endl;

    cout << "Finding length: ";
    start = high_resolution_clock::now();
    str.string::length();
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "took " << duration.count() / 100 << " nanoseconds" << endl;

    cout << "Finding len: ";
    start = high_resolution_clock::now();
    len(argv[1]);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "took " << duration.count() / 100 << " nanoseconds" << endl << endl;

    // Iterative solution
    cout << "Iterative: ";
    start = high_resolution_clock::now();
    cout << endl;
    cout << "----------";
    cout << endl;
    rev_iterative(argv[1], n);
    cout << endl;
    cout << "----------";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << " | took " << duration.count() / 100 << " nanoseconds" << endl << endl;

    // First recursive solution
    cout << "Remove from End Recursion: ";
    start = high_resolution_clock::now();
    cout << endl;
    cout << "----------";
    cout << endl;
    rev_recursive(argv[1], n);
    cout << endl;
    cout << "----------";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << " | took " << duration.count() / 100 << " nanoseconds" << endl << endl;

    // Second recursive solution
    cout << "Remove from Front Recursion: ";
    start = high_resolution_clock::now();
    cout << endl;
    cout << "----------";
    cout << endl;
    rev_recursive2(argv[1]);
    cout << endl;
    cout << "----------";
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << " | took " << duration.count() / 100 << " nanoseconds" << endl << endl;

    return 0;
}

/** @brief Output the string backwards via recursion.
  * @pre Pointer to string to write backwards and string's length
  * @post None.
  * @param s Pointer to the first char of the string
  * @param n Length of string.
  *
  * Finish by outputting the first character and otherwise recursively
  * call to output the next character, with the last recursive call
  * being to output the final character, then outputting in order of
  * calls on the stack till outputting the first character.
  *
  * @return None.
  */
void rev_recursive2(char *s)
{
    if (*s == '\0') return;
    rev_recursive2(s+1);
    cout << *s;
}

/** @brief Output the string backwards via recursion.
  * @pre Pointer to string to write backwards and string's length
  * @post None.
  * @param s Pointer to the first char of the string
  * @param n Length of string.
  *
  * Recursively call function again with one fewer chars.
  * If chars left is 0, exit function.
  *
  * @return None.
  */
void rev_recursive(char *s, int n)
{
    if (n == 0) return;
    cout << *(s + n - 1);
    rev_recursive(s, n-1);
}

/**
 * @brief Output a string backwards via a loop.
 * @pre Pointer to string to write backwards and string's length
 * @post None.
 * @param s Pointer to first char of string.
 * @param n Length of string.
 * @return None.
 */
void rev_iterative(char* s, int n)
{
    for (int i = n; i >= 0; i--)
    {
        cout << s[i];
    }
}

int len(char *s)
/**
 * @brief Find the length of a string.
 * @pre Pointer to the string, s.
 * @post None.
 * @param s Pointer to the first char of string, s.
 *
 * Create a traversal pointer to loop through the addresses till the
 * null terminator.  The distance between the traversal pointer at the
 * null terminator and the starting address is one more than the length
 * of the string.
 *
 * @return One address location less than traversal pointer minus start
 */
{
    char *trv = s;
    while (*++trv);
    return trv - s - 1;
}
