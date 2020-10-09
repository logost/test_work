#ifndef TEST_H
#define TEST_H

/**
 * @brief check that inverse function returns correct value Y = X^-1 mod Q
 * 
 * @param num X
 * @param inv Y^-1
 * @param modular Q
 * @return int 0 if correct, other if incorrect
 */
int check_inverse(uint32_t num, uint32_t inv, uint32_t modular);

/**
 * @brief unit test of inverse function
 * 
 * @return int 0 if tests passed, other if failed 
 */
int unit_tests();

#endif