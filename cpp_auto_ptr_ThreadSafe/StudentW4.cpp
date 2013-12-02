#include "StudentW4.h"

StudentW4::Egzamin_Oblany::Egzamin_Oblany(const char* prow, const char* przed, const char * typ):
    prowadzacy(prow),
    przedmiot(przed),
    typ_porazki(typ)
{
}

void StudentW4::ZaliczDruty()
{
    throw Egzamin_Oblany("dr Jerzy M.", "Teoria obwodow", "Akupunktura"); 
}