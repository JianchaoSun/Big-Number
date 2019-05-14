/**
 * @file BigNumber.cpp
 * @author Jianchao Sun
 * @brief Do calculation / * % + - to very large integer number
 * @mainpage BigNumber
   Below is documents for big numbers
 */

#ifndef BigNumber_hpp
#define BigNumber_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#endif /* BigNumber_hpp */


//!  BigNumber class
/*!
  Can do add,sub,mul,division,and mod to integer number with very long digits
  store those digits in vector
 */
class BigNumber{
public:
    bool pos;//!< Holding the sign of the bigNumber, true for positive, false for negative
    std::vector<int> v;//!< A vector that hold all the digits in the BigNumber
    
    //! A constructor.
    /*!
     Empty constructor
     */
    BigNumber();
    
    //! A constructor.
    /*!
     \param s an string of digits that may include - sign, will store input
     string to the vector
     */
    BigNumber(std::string s);
    
    
    //! A addition function, perform addition
    /*!
     \sa operator-(BigNumber n), operator+(BigNumber n),removeLeadingZeros()
      \return The a BigNumber
     \param n the first argument.
     \param n2 the second BigNumber.
     */
    BigNumber add( BigNumber n, BigNumber n2);
   
    
    //!A subtraction function, will perform subtraction for bignumber
    /*!
     \sa operator+(BigNumber n)
      \return The a BigNumber
     \param n1 the first argument.
     \param n2 the second BigNumber.
     */
    BigNumber sub(BigNumber n1, BigNumber n2);
    
    //!A overloading operator - function, will perform subtraction for bignumber
    /*!
     \sa add(BigNumber n,BigNumber n2),removeLeadingZeros()
      \return The a BigNumber
     \param n the big number argument.
     */
    BigNumber operator -( BigNumber n);
    
    //!A overloading operator * function, will perform multiplication for bignumber
    /*!
     \sa mul(BigNumber n,BigNumber n2),removeLeadingZeros()
      \return The a BigNumber
     \param n the big number argument.
     */
    BigNumber  operator *( BigNumber n);
    
    //!A overloading operator / function, will perform division for bignumber
    /*!
     \sa div(BigNumber n,BigNumber n2)
      \return The a BigNumber
     \param n the big number argument.
     */
    BigNumber operator /( BigNumber n);
    
    //!A overloading operator % function, will perform mod operation for bignumber
    /*!
     \sa mod(BigNumber n,BigNumber n2),removeLeadingZeros()
     \return The a BigNumber
     \param n the big number argument.
     */
    BigNumber operator %( BigNumber n);
    
    //! A overloading operator + function, will perform add for big number
    /*!
     \param n an BigNumber argument.
     \return The a BigNumber after addition
     \sa    add(BigNumber n1,BigNumber n2), sub(BigNumber n1,BigNumber n2)
     */
    BigNumber operator +( BigNumber n);
    
    //! A simple multiplication function will perform multiplication for big number
    /*!
     \param n1 an BigNumber argument.
     \param n2 an BigNumber argument.
     \return The a BigNumber
     */
    BigNumber mul(BigNumber n1, BigNumber n2);
    
    //! A simple mod function will perform mod operation for big number
    /*!
     \param d1 an BigNumber argument.
     \param d2 an BigNumber argument.
     \return The a BigNumber after mod
     */
    BigNumber mod(BigNumber d1, BigNumber d2);
    
    //! A simple division function will perform divide operation for big number
    /*!
     \param d1 an BigNumber argument.
     \param d2 an BigNumber argument.
     \return The a BigNumber after division
     */
    BigNumber div(BigNumber d1, BigNumber d2);
    
    //! A function that remove non need 0s.
    /*!
     */
    void removeLeadingZeros();
    
    //!a comparsion function
    /*!
     \param n1 an BigNumber argument.
     \param nu an BigNumber argument.
     \return bool true for n1 large, false for nu large
     \sa void removeLeadingZeros()
     */
    bool isLarger(BigNumber n1,BigNumber nu);
    
    //!a comparsion function
    /*!
     \param n1 an BigNumber argument.
     \param nu an BigNumber argument.
     \return bool false for n1 large, true for nu large
     \sa void removeLeadingZeros()
     */
    bool isLess(BigNumber n1,BigNumber nu);
    
    bool largeEqual(BigNumber n1, BigNumber nu);
    bool equal( BigNumber n1, BigNumber nu);
    
};
