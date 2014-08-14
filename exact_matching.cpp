#include "exact_matching.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(void) {
    string T = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaaabbbbbbbbbbaaaaaaaaaabbbbbcccccaaaaa", P = "aaaaabbbbbcccccaaaaa";
    int i, *results = (int*)malloc((T.size() - P.size() + 1) * sizeof(int)), alpha = 0;
    int count = fingerprint_match_naive(T, P, alpha, results);
    for (i = 0; i < count - 1; i++) {
        printf("%d, ", results[i]);
    }
    printf("%d\n", results[count - 1]);
    results = (int*)realloc(results, (T.size() - P.size() + 1) * sizeof(int));

    count = fingerprint_match(T, P, alpha, results);
    for (i = 0; i < count - 1; i++) {
        printf("%d, ", results[i]);
    }
    if (count) printf("%d\n", results[count - 1]);
    else printf("No matches.\n");


    P = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccddddd";
    count = fingerprint_match(T, P, alpha, results);
    for (i = 0; i < count - 1; i++) {
        printf("%d, ", results[i]);
    }
    if (count) printf("%d\n", results[count - 1]);

    T = "aaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaaabbbbbcccccaaaaaaaaaabbbbbcccccddddd";
    count = fingerprint_match(T, P, alpha, results);
    for (i = 0; i < count - 1; i++) {
        printf("%d, ", results[i]);
    }
    if (count) printf("%d\n", results[count - 1]);
    return 0;

}