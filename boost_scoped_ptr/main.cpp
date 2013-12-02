#include <boost/scoped_ptr.hpp>
#include <iostream>

using std::cout;
using std::endl;

struct Shoe 
{ 
    ~Shoe() 
    { 
        cout << "Buckle my shoe" << endl; 
    } 
};


class MyClass 
{
    boost::scoped_ptr<int> ptr;

  public:
    MyClass() : ptr(new int) 
    {
        *ptr = 0;
    }

    int add_one() 
    {
        return ++*ptr;
    }
};


int main()
{
    boost::scoped_ptr<Shoe> x(new Shoe);

    MyClass my_instance;

    cout << my_instance.add_one() << endl;
    cout << my_instance.add_one() << endl;
} // przy wyj�ciu z zakresu nast�pi usuni�cie obiektu x oraz obiektu my_instance - a co za tym idzie r�wnie� zwolnienie zasobu wskazywanego przez ptr
