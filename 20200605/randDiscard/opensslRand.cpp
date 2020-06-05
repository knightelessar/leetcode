//link with crypto library in the compile command:
// g++ -lcrypto opensslRand.cpp -o roll.out
// clang++ -I/usr/local/include/node/ -L/usr/local/Cellar/openssl@1.1/1.1.1g/lib/ -lcrypto opensslRand.cpp -o roll.out 

#include <iostream>
#include <assert.h>
#include <limits>
#include <openssl/rand.h>

volatile uint32_t dummy;
uint64_t discardCount;
// Undefined symbols for architecture x86_64:
//   "_RAND_bytes", referenced from:
//       uniformRandomUint32(unsigned int) in opensslRand-cea9c9.o
//   "_RAND_status", referenced from:
//       uniformRandomUint32(unsigned int) in opensslRand-cea9c9.o
// ld: symbol(s) not found for architecture x86_64

uint32_t uniformRandomUint32(uint32_t upperBound)
{
    assert(RAND_status() == 1);
    uint64_t discard = (std::numeric_limits<uint64_t>::max() - upperBound) % upperBound;
    uint64_t randomPool;
    RAND_bytes((uint8_t*)(&randomPool), sizeof(randomPool));
    // std::cout << "sizeof(randomPool) = " << sizeof(randomPool) << std::endl;
    // std::cout << "randomPool = " << randomPool << std::endl;
    // std::cout << "discard line = " << std::numeric_limits<uint64_t>::max() - discard << std::endl;
    while(randomPool > (std::numeric_limits<uint64_t>::max() - discard)) {
        // std::cout << "discard" << std::endl;
        RAND_bytes((uint8_t*)(&randomPool), sizeof(randomPool));
        ++discardCount;
    }

    return randomPool % upperBound;
}

int main() {
    discardCount = 0;

    const uint32_t MODULUS = (1ul << 31)-1;
    const uint32_t ROLLS = 1e6;
    std::cout << "uint64 max: " << std::numeric_limits<uint64_t>::max() << std::endl;

    for(uint32_t i = 0; i < ROLLS; ++i) {
        dummy = uniformRandomUint32(MODULUS);
    }
    std::cout << "MODULUS = " << MODULUS << std::endl;
    std::cout << "Discard count = " << discardCount << std::endl;
}