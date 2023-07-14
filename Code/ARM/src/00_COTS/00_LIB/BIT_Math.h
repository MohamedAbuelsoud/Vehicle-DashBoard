/**
 * @file BIT_Math.h
 * @author G3_DashBoard_Team
 * @brief Macros for bitwise operations
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#endif 
