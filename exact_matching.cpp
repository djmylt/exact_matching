#include "exact_matching.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <assert.h>

#define test_check(correct, correct_len, results, results_len) assert((correct_len == results_len) && (check_results(correct, results, correct_len)))

using namespace std;

int check_results(int* correct, int* result, int size) {
    for (int i = 0; i < size; i++) if (correct[i] != result[i]) return 0;
    return 1;
}

int main(void) {
    string T = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaaabbbbbbbbbbaaaaaaaaaabbbbbcccccaaaaa", P = "aaaaabbbbbcccccaaaaa";
    int i, *results = (int*)malloc((T.size() - P.size() + 1) * sizeof(int)), alpha = 0, *correct = (int*)malloc(81 * sizeof(int)), correct_len;

    correct[0] = 19; correct[1] = 59; correct[2] = 99;
    correct_len = 3;
    int results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    P = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccddddd";
    correct[0] = 39;
    correct_len = 1;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    T = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaaabbbbbcccccaaaaaaaaaabbbbbcccccddddd";
    correct[0] = 39; correct[1] = 99;
    correct_len = 2;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    P = "aaaaabbbbbcccccaaaaaaaaaabbbbbcc";
    correct[0] = 31; correct[1] = 71; correct[2] = 91;
    correct_len = 3;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    P = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaa";
    correct[0] = 63;
    correct_len = 1;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    T = "aaaaaaabbbbbcccccaaaaaaaaaabbbaaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaa";
    correct[0] = 93;
    correct_len = 1;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    T = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    P = "aaaaaaaaaaaaaaaaaaaa";
    for (i = 0; i < 81; i++) {
        correct[i] = i + 19;
    }
    correct_len = 81;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    T = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    P = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    correct[0] = 63; correct[1] = 199;
    correct_len = 2;
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    T = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabb";
    P = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabb";
    results_len = fingerprint_match(T, P, alpha, results);
    test_check(correct, correct_len, results, results_len);

    free(results);
    free(correct);
    return 0;

}
