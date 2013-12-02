#include <memory>

int main()
{
    const std::auto_ptr<int> p1(new int);
    
    std::auto_ptr<int> p2=p1;
}
