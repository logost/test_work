#ifndef MODULAR_INVERSE_H
#define MODULAR_INVERSE_H

/**
 * @brief compute modular multiplicative inverses: [a^-1 mod n_prime]
 * 
 *  Computing modular multiplicative inverses by algorithm described at
 *  https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
 * 
 * @param a 
 * @param n_prime modular prime number
 * @return uint32_t modular multiplicative inverses
 */
uint32_t inverse(uint32_t a, uint32_t n_prime);

#endif