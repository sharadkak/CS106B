/* File: PlayingFair.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "PlayingFair.h"
#include "GUI/SimpleTest.h"
#include "error.h"
using namespace std;

string sequenceOfA(string sequence, int order);
string calculateCompliment(string sequence);

string aSequenceOfOrder(int n) {
    /* TODO: Delete this line and the next two lines, then implement this function. */

    // raise error
    if (n<0) error("Order must be greater than zero!!");

    // call helper function
    return sequenceOfA("A", n);
}


string sequenceOfA(string sequence, int order){

    // base case
    if (order == 0) return sequence;

    // recursive case
    string compliment = calculateCompliment(sequence);
    sequence = sequence + compliment;
    return sequenceOfA(sequence, order-1);
}

string calculateCompliment(string sequence){

    for (int i=0; i < sequence.length(); i++){
        if (sequence[i] == 'A') sequence[i] = 'B';
        else sequence[i] = 'A';
    }
    return sequence;
}

string bSequenceOfOrder(int n) {
    /* TODO: Delete this line and the next two lines, then implement this function. */

    if (n<0) error("Order must be greater than zero!!");

    // writing this one without any helper function
    if (n == 0) return "B";

    string sequence = bSequenceOfOrder(n-1);
    string compliment = calculateCompliment(sequence);
    return sequence + compliment;
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Sequences of order 3 are correct.") {
    /* Some very basic checks. */
    EXPECT_EQUAL(aSequenceOfOrder(3), "ABBABAAB");
    EXPECT_EQUAL(bSequenceOfOrder(3), "BAABABBA");
}

PROVIDED_TEST("Only characters should be As and Bs.") {
    for (int i = 0; i < 10; i++) {
        for (char ch: aSequenceOfOrder(i)) {
            EXPECT(ch == 'A' || ch == 'B');
        }
    }
}

PROVIDED_TEST("A-sequence of positive order should have equal As and Bs.") {
    /* Exclude the sequence of order 0, which is just a single character. */
    for (int i = 1; i < 10; i++) {
        int as = 0;
        int bs = 0;
        for (char ch: aSequenceOfOrder(i)) {
            if (ch == 'A') as++;
            else bs++;
        }

        EXPECT_EQUAL(as, bs);
    }
}

PROVIDED_TEST("Triggers error on negative inputs.") {
    /* The EXPECT_ERROR macro expects the given expression to call error(). Remember that
     * you need to guard against invalid inputs.
     */
    EXPECT_ERROR(aSequenceOfOrder(-137));
    EXPECT_ERROR(bSequenceOfOrder(-137));
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








