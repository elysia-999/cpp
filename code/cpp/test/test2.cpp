#include <iostream>
#include <cstring>
#include <io.h>
#include <fcntl.h>
#include "../MySQL/include/MyLibrary/Vector.h"
#include "../MySQL/include/MyLibrary/Stack.h"

using namespace std;

void demoBasicStack() {
    wcout << L"=== 基本栈操作演示 ===" << endl;
    
    Stack<int> stack;
    
    wcout << L"入栈: ";
    for (int i = 1; i <= 5; i++) {
        stack.push(i);
        wcout << i << L" ";
    }
    wcout << endl;
    
    wcout << L"栈顶: " << stack.top() << endl;
    wcout << L"栈大小: " << stack.size() << endl;
    
    wcout << L"出栈: ";
    while (!stack.empty()) {
        wcout << stack.pop() << L" ";
    }
    wcout << endl << endl;
}

void demoConversion() {
    wcout << L"=== 进制转换演示 ===" << endl;
    
    long long numbers[] = {255, 1024, 123};
    int bases[] = {2, 8, 16};
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Stack<char> stack;
            convert(stack, numbers[i], bases[j]);
            
            wcout << numbers[i] << L" 的" 
                 << (bases[j] == 2 ? L"二进制" : 
                     bases[j] == 8 ? L"八进制" : L"十六进制") 
                 << L": ";
            while (!stack.empty()) {
                wcout << stack.pop();
            }
            wcout << endl;
        }
    }
    wcout << endl;
}

void demoParenthesis() {
    wcout << L"=== 括号匹配演示 ===" << endl;
    
    const char* expressions[] = {
        "((1+2)*3)",
        "{[()]}",
        "([)]",
        "((1+2)*3"
    };
    
    for (int i = 0; i < 4; i++) {
        bool result = paren(expressions[i], 0, strlen(expressions[i]));
        wcout << L"表达式 \"" << expressions[i] << L"\": " 
             << (result ? L"匹配" : L"不匹配") << endl;
    }
    wcout << endl;
}

int main() {
    // 设置控制台为UTF-8编码
    _setmode(_fileno(stdout), _O_U16TEXT);
    
    wcout << L"栈库测试程序" << endl;
    wcout << L"============" << endl << endl;
    
    demoBasicStack();
    demoConversion();
    demoParenthesis();
    
    wcout << L"测试完成!" << endl;
    
    // 暂停，等待用户按键
    wcout << L"请按任意键继续..." << endl;
    wcin.get();
    
    return 0;
}