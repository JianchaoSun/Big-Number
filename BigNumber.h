//
// Created by Jianchao Sun on 2019-05-14.
//

#ifndef TEST1_BIGNUMBER_H
#define TEST1_BIGNUMBER_H

#endif //TEST1_BIGNUMBER_H


#include <stdio.h>
#include<vector>
#include<string>
#include<iostream>


class BigNumber
{
public:
    bool pos;
    std::vector<int> v;
public:
    BigNumber() {

    }

    BigNumber(std::string s)
    {
        if(s.empty())return;
        v.clear();
        pos = s[0] != '-';
        for(int i = s.length()-1; i>-1+!pos; i--){
            this->v.emplace_back(s[i]-'0');
        }
    }


    BigNumber operator +( BigNumber n){

        return add(*this, n);
    }




    BigNumber add( BigNumber n, BigNumber n2){

        if(n.pos!=n2.pos){
            if(v.size() != n.v.size()){
                if(v.size() > n.v.size()){
                    return sub(*this,n);
                }else{
                    return sub(n,*this);
                }
            }else{
                for(long i = v.size()-1; i>=0; i--){
                    if(v[i] == n.v[i]) continue;
                    if(v[i] > n.v[i])
                    {
                        return sub(*this,n);
                    }
                    return sub(n, *this);
                }
            }
        }
        else{

            // BigNumber bn;
            int sum =0,carry=0;
            if(n2.v.size()<n.v.size()) {
                long i = 0;
                for (; i < n.v.size(); i++) {
                    if (i < n2.v.size()) {
                        sum = n2.v[i] + n.v[i] + carry;
                        carry = sum / 10;
                        n.v[i] = sum % 10;
                    } else {
                        sum = n.v[i] + carry;
                        carry = sum / 10;
                        n.v[i] = sum % 10;
                    }
                }
                if (carry) {
                    n.v.push_back(0);
                    n.v[i++] = carry;
                }
                return n;

            }
            else {
                long i = 0;
                for (; i < n2.v.size(); i++) {
                    if (i < n.v.size()) {
                        sum = n2.v[i] + n.v[i] + carry;
                        carry = sum / 10;
                        n2.v[i] = sum % 10;
                    } else {
                        sum = n2.v[i] + carry;
                        carry = sum / 10;
                        n2.v[i] = sum % 10;
                    }
                }
                if (carry) {
                    n2.v.push_back(0);
                    n2.v[i++] = carry;
                }

                return n2;
            }

        }
        return BigNumber("0");

    }

    BigNumber sub(BigNumber n1, BigNumber n2){

        for(int i = 0; i<n1.v.size(); i++){
            if(n1.v[i] < n2.v[i]){
                for(int j = i+1; j<n1.v.size(); j++){
                    if(n1.v[j]){
                        --n1.v[j];
                        break;
                    }else{
                        n1.v[j] = 9;
                    }
                }
                int val1 = n1.v[i]+10, val2 = n2.v[i];
                n1.v[i] = val1-val2;
                if(i+1==n2.v.size()) break;
            }else{
                n1.v[i] = n1.v[i] - n2.v[i];
                if(i+1==n2.v.size()) break;
            }
        }
        n1.removeLeadingZeros();

        return n1;
    }

    BigNumber operator -( BigNumber n){
        n.pos = !n.pos;
        return add(n,*this);
    }
    BigNumber  operator *( BigNumber n){
        return mul(*this, n);
    }
    BigNumber operator /( BigNumber n){
        return div(*this,n);
    }

    BigNumber operator %( BigNumber n){
        return mod(*this,n);
    }

    BigNumber mul(BigNumber n1, BigNumber n2){
        BigNumber n;
        n.v.resize(n1.v.size()+n2.v.size()+1);
        int i,j,carry = 0, product;
        for(i = 0; i<n1.v.size(); i++){
            carry = 0;
            for(j = 0; j<n2.v.size(); j++){
                product = (n2.v[j]*n1.v[i]) + carry + n.v[i+j];
                carry = product/10;
                n.v[i+j] = product%10;
            }
            while(carry)
                product = n.v[i+j] + carry,
                n.v[i+j] = product%10,
                carry = product/10, ++j;
        }
        while(n.v.back() == 0 && v.size() > 1)
            n.v.pop_back();
        n.pos = n1.pos == n2.pos;
        n.removeLeadingZeros();

        return n;
    }

    BigNumber mod(BigNumber d1, BigNumber d2){
        BigNumber nu("0");
        BigNumber temp("0");
        temp.v = d1.v;

        if(d2.v.size()==1&&d2.v[0] == 0){
            std::cout<<"Division by zero.\n";
            exit(1);
        };

        if(isLarger(d2,d1))
            return d1;

        while (largeEqual(temp,d2)) {
            nu = nu + BigNumber("1");
            temp = temp - d2;
        }




        return temp;

    }

    BigNumber div(BigNumber d1, BigNumber d2){
        BigNumber nu("0");
        BigNumber temp("0");
        temp.v = d1.v;

        if(d2.v.size()==1&&d2.v[0] == 0){
            std::cout<<"Division by zero.\n";
            exit(1);
        };
        if(isLarger(d2,d1))
            return BigNumber("0");

        while (largeEqual(temp,d2)) {
            nu = nu + BigNumber("1");
            temp = temp - d2;
        }

        return nu;

    }

    void removeLeadingZeros(){
        while(v.back() == 0 && v.size() > 1)
            v.pop_back();
    }

    bool equal( BigNumber n1, BigNumber nu){
        n1.removeLeadingZeros();
        nu.removeLeadingZeros();

        if (n1.v.size() != nu.v.size()) return false;

        if (n1.v.size() == 1) return n1.v.at(0) == nu.v.at(0);

        for (int place = n1.v.size() - 1; place > 0; place--) {
            if (n1.v.at(place) != nu.v.at(place)) {
                return false;
            }
        }

        return true;

    }

    bool isLarger( BigNumber n1, BigNumber nu){
        n1.removeLeadingZeros();
        nu.removeLeadingZeros();
        short lDigits = n1.v.size();
        short rDigits = nu.v.size();

        if (lDigits != rDigits) {
            return (lDigits > rDigits);
        }

        for (int place = 0; place < lDigits; place++) {
            if (n1.v.at(place) < nu.v.at(place)) {
                return false;
            }
            else if (n1.v.at(place) > nu.v.at(place)) {
                return true;
            }
            else if (place == lDigits) {
                if (n1.v.at(place) == nu.v.at(place)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isLess(BigNumber n1,BigNumber nu){
        n1.removeLeadingZeros();
        nu.removeLeadingZeros();
        return isLarger(nu, n1);
    }

    bool largeEqual(BigNumber n1, BigNumber nu){
        n1.removeLeadingZeros();
        nu.removeLeadingZeros();
        return (isLarger(n1,nu) || equal(n1,nu));
    }

};