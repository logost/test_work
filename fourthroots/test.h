#ifndef TEST_H
#define TEST_H

/**
 * @brief check that fourth root is within epsilon to the reference value
 * 
 * @param root fourth root of value
 * @param value 
 * @param epsilon allowable error
 * @return int 0 if correct, othr if incorrect
 */
int check_fourth_root(float root, float value, float epsilon);

/**
 * @brief unit test of fourth root function
 * 
 * @return int 0 if tests passed, other if failed 
 */
int unit_tests();

#endif