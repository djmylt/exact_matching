#include "karp_rabin.h"
#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main(void) {
    int n = 100, m = 20, i;
    fingerprinter printer = fingerprinter_build(n, 0);
    gmp_printf("p = %Zd\n", printer->p);
    gmp_printf("r = %Zd\n", printer->r);

    fingerprint print = get_fingerprint(printer, "aaaaabbbbbcccccaaaaa", m);

    gmp_printf("uv finger = %Zd\n", print->finger);
    printf("uv k = %d\n", print->k);
    gmp_printf("uv r_k = %Zd\n", print->r_k);
    gmp_printf("uv r_mk = %Zd\n", print->r_mk);

    fingerprint prefix = get_fingerprint(printer, "aaaaa", 5);

    fingerprint v = fingerprint_suffix(printer->p, print, prefix);

    fingerprint suffix = get_fingerprint(printer, "bbbbbcccccaaaaa", 15);
    assert(fingerprint_equals(v, suffix));

    fingerprint u = fingerprint_prefix(printer->p, print, suffix);
    assert(fingerprint_equals(u, prefix));

    fingerprint uv = fingerprint_concat(printer->p, prefix, suffix);
    assert(fingerprint_equals(uv, print));

    int* results = malloc((n - m + 1) * sizeof(int));
    int count = fingerprint_match("aaaaabbbbbcccccaaaaaaaaaabbbbbcccccdddddaaaaabbbbbcccccaaaaaaaaaabbbbbbbbbbaaaaaaaaaabbbbbcccccaaaaa", n, "aaaaabbbbbcccccaaaaa", m, 0, results);

    for (i = 0; i < count - 1; i++) {
        printf("%d, ", results[i]);
    }
    printf("%d\n", results[count - 1]);


    return 0;
}