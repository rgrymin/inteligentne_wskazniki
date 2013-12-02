#include <boost/shared_ptr.hpp>

void f(boost::shared_ptr<int>, int);
int g();

void ok()
{
    boost::shared_ptr<int> p( new int(2) );
    f( p, g() );
}

void bad()
{
    f( boost::shared_ptr<int>( new int(2) ), g() );
} // niezidentyfikowana kolejno�� obliczania parametr�w funkcji, je�eli g() zwr�ci wyj�tek, to pami�� nie zostanie zaalokowana