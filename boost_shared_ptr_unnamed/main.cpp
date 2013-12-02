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
} // niezidentyfikowana kolejnoœæ obliczania parametrów funkcji, je¿eli g() zwróci wyj¹tek, to pamiêæ nie zostanie zaalokowana