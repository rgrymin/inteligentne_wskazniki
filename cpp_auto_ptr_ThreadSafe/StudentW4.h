#ifndef STUDENT_W4
#define STUDENT_W4

#include <iostream>

class StudentW4
{
public:
    StudentW4() 
    {
        std::cout << "Stworzono konto studenta!"<< std::endl;
    }

    ~StudentW4()
    {
        std::cout << "Usunieto konto studenta!" << std::endl;
    }


    void ZaliczDruty();

    struct Egzamin_Oblany
    {
        Egzamin_Oblany(const char* prow, const char* przed, const char * typ);

        const char* prowadzacy;
        const char* przedmiot;
        const char* typ_porazki;
    };
};

#endif
