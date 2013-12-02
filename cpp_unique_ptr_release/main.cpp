#include <memory>
#include <iostream>

using std::cout;
using std::endl;
 
struct Foo {
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
};
 
int main()
{
    cout << "Creating new Foo..." << endl;
    std::unique_ptr<Foo> up(new Foo);
 
    cout << "About to release Foo..." << endl;
    Foo* fp = up.release();
 
    if (up.get() == nullptr)
        std::cout << "Foo is no longer owned by unique_ptr...\n";
 
    delete fp;
}
