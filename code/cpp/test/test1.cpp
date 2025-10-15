#include <iostream>
#include <string>
#include "../MySQL/include/MyLibrary/List.h"

using namespace std;

void printInt(int& value) {
    cout << value << " ";
}

class DoubleValue {
public:
    void operator()(int& value) {
        value *= 2;
    }
};

int main() {
    cout << "=== List Library Test ===" << endl;
    
    // 1. Create list
    List<int> myList;
    cout << "1. Created empty list, current size: " << myList.size() << endl;
    
    // 2. Insert elements
    myList.insertAsFirst(10);
    myList.insertAsLast(30);
    myList.insertAsLast(40);
    
    ListNodePosi(int) firstNode = myList.first();
    myList.insertAfter(firstNode, 20);
    
    cout << "2. After inserting elements: ";
    myList.traverse(printInt);
    cout << endl << "   Current size: " << myList.size() << endl;
    
    // 3. Index access
    cout << "3. Index access test:" << endl;
    cout << "   myList[0] = " << myList[0] << endl;
    cout << "   myList[1] = " << myList[1] << endl;
    cout << "   myList[2] = " << myList[2] << endl;
    
    // 4. Find element
    ListNodePosi(int) found = myList.find(30);
    if (found) {
        cout << "4. Found element 30, its predecessor: " << found->pred->data << endl;
    }
    
    // 5. Remove element
    if (found) {
        int removed = myList.remove(found);
        cout << "5. Removed element: " << removed << endl;
        cout << "   List after removal: ";
        myList.traverse(printInt);
        cout << endl;
    }
    
    // 6. Modify elements using function object
    DoubleValue doubler;
    myList.traverse(doubler);
    cout << "6. After doubling all elements: ";
    myList.traverse(printInt);
    cout << endl;
    
    // 7. Copy constructor test
    List<int> copiedList(myList);
    cout << "7. New list from copy constructor: ";
    copiedList.traverse(printInt);
    cout << endl;
    
    // 8. Deduplication test
    myList.insertAsLast(40);
    myList.insertAsLast(40);
    cout << "8. After inserting duplicates: ";
    myList.traverse(printInt);
    cout << endl;
    
    int duplicates = myList.deduplicate();
    cout << "   Removed " << duplicates << " duplicate elements" << endl;
    cout << "   List after deduplication: ";
    myList.traverse(printInt);
    cout << endl;
    
    cout << "=== Test Finished ===" << endl;
    
    system("pause");  // 添加暂停，防止窗口立即关闭
    return 0;
}