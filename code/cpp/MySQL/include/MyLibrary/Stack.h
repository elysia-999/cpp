#ifndef MYLIBRARY_STACK_H
#define MYLIBRARY_STACK_H

#include "Vector.h"

template <typename T>
class Stack : public Vector<T> {
public:
    // 使用默认构造函数
    Stack() : Vector<T>() {}
    Stack(int c) : Vector<T>(c) {}
    
    void push(T const& e) { 
        this->insert(this->size(), e); 
    }
    
    T pop() { 
        if (this->empty()) {
            return T(); // 返回默认值
        }
        return this->remove(this->size() - 1); 
    }
    
    T& top() { 
        return (*this)[this->size() - 1]; 
    }
    
    const T& top() const { 
        return (*this)[this->size() - 1]; 
    }
};

// 进制转换函数
template <typename T>
void convert(Stack<T>& S, long long n, int base) {
    static const char digit[] = {
        '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
    };
    
    if (n == 0) {
        S.push(digit[0]);
        return;
    }
    
    bool isNegative = false;
    if (n < 0 && base == 10) {
        isNegative = true;
        n = -n;
    }
    
    while (n > 0) {
        int remainder = (int)(n % base);
        S.push(digit[remainder]);
        n /= base;
    }
    
    if (isNegative) {
        S.push('-');
    }
}

// 括号匹配函数
bool paren(const char exp[], int lo, int hi) {
    Stack<char> S;
    for (int i = lo; i < hi; i++) {
        char c = exp[i];
        switch (c) {
            case '(': case '[': case '{':
                S.push(c);
                break;
            case ')':
                if (S.empty() || '(' != S.pop()) return false;
                break;
            case ']':
                if (S.empty() || '[' != S.pop()) return false;
                break;
            case '}':
                if (S.empty() || '{' != S.pop()) return false;
                break;
            default:
                break;
        }
    }
    return S.empty();
}

#endif // MYLIBRARY_STACK_H