#include <cstdlib>
#include <iostream>
#include <memory>

#include "StudentW4.h"

using namespace std;


void przypadek1()
{

    StudentW4*  student_temp = new StudentW4;

    // ...

    StudentW4  Adam;
    Adam.ZaliczDruty();

    // ...

    delete student_temp;
}


void przypadek2()
{
    std::auto_ptr<StudentW4> student_temp(new StudentW4);

    // ...

    StudentW4  Adam;
    Adam.ZaliczDruty();

    // ...
}


int main()
{
    try{
        // przypadek1();
        przypadek2();

    }
    catch(const StudentW4::Egzamin_Oblany& e)
    {
        cout << "Prowadzacy:  " << e.prowadzacy  << endl;
        cout << "Przedmiot:   " << e.przedmiot   << endl;
        cout << "Typ porazki: " << e.typ_porazki << endl;
    }
    
    cout << endl;
    system("pause");
}