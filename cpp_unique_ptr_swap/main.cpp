#include <iostream>
#include <memory>

using std::cout;
using std::endl;

 
struct Foo {
    Foo(int _val) : val(_val) { cout << "Foo...\n"; }
    ~Foo() { cout << "~Foo...\n"; }
    int val;
};
 
int main()
{
    std::unique_ptr<Foo> up1(new Foo(1));
    std::unique_ptr<Foo> up2(new Foo(2));
 
    up1.swap(up2);
 
    cout << "up1->val:" << up1->val << endl;
    cout << "up2->val:" << up2->val << endl;
}