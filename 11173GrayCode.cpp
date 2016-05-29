#include <iostream>


int main() {
    int n;
    std::cin >> n;
    while(n--)
    {
        int nBits;
        unsigned long long int kTh;
        std::cin >> nBits >> kTh;
        std::cout << (kTh ^ (kTh >> 1)) << std::endl;
    }
    return 0;
}

//Wooowww C is a lot more faster :|  425ms vs 50ms WTF

/*
 * Exact Problem In C For Comparing Time
 #include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int nBits;
        unsigned long long int kTh;
        scanf("%d%lld", &nBits, &kTh);
        printf("%lld\n", kTh ^ (kTh >> 1));
    }
    return 0;
}
 */