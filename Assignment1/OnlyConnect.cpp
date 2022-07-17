/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include "set.h"
#include <cctype>
using namespace std;

string helperConnectize(string phrase, Set<char> vowels, int index);

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */

    // first create a set of all the vowels
    Set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'I', 'O', 'U', 'E'};

    string answer = helperConnectize(phrase, vowels, 0);
    return answer;
}

string helperConnectize(string phrase, Set<char> vowels, int index){

    // base case, if reached the end of the string the just return it
    if (index == phrase.length()){
        return phrase;
    }

    string new_str;
    char curr_char = phrase[index];
    // if the character is not a consonent, remove it
    if ((!isalpha(curr_char)) || isblank(curr_char) || vowels.contains(curr_char)){
        new_str = phrase.substr(0, index) + phrase.substr(index+1);
    }
    else{
        new_str = phrase.substr(0, index) + charToString(toUpperCase(phrase[index])) + phrase.substr(index+1);
        index += 1;
    }
    return helperConnectize(new_str, vowels, index);
}




/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






