#include <iostream>
#include <memory>      // wzorzec klasy std::auto_ptr zadeklarowany jest w standardowym pliku nag³ówkowym <memory>


using std::cout;
using std::endl;

/*
 *  Coœ co b³êdnie jest uwa¿ane, za wskaŸnik inteligentny!
 *
 *  Wzorzec klasy auto_ptr wspiera technikê RAII (ang. Resource Acquisition Is Initialization) - inicjowanie przy pozyskaniu zasobu.
 *  Zasadniczo auto_ptr jest inicjowana wskaŸnikiem i mo¿na go u¿ywaæ jak wskaŸnika.
 *  Wskazywany obiekt bêdzie niejawnie usuniêty w chwili opuszczenia zasiêgu klasy auto_ptr.
 *
 *  Wzorzec klasy auto_ptr dostarcza semantykê œcis³ej w³asnoœci.
 *  W zwi¹zku z tym, semantyka kopiowania w klasie auto_ptr ró¿ni siê znacznie od semantyki kopiowania zwyk³ych wskaŸników:
 *  po skopiowaniu jednego obiektu auto_ptr na drugi, obiekt Ÿrd³owy na nic ju¿ nie wskazuje.
 *  Poniewa¿ kopiowanie takiego obiektu modyfikuje go, wiêc nie mo¿na kopiowaæ obiektów z atrybutem const.
 *
 *  Wychodzi z u¿ytku.
 *
 *  Przyk³ad z polimorfizmem (rzutowanie w górê) (porównanie z u¿yciem normalnego wskaŸnika) - nie nale¿y go wykorzystywaæ, nie wspó³pracuje z wektorami
 *      Dlaczego?
 *      Standard C++ mówi, ¿e element STL musi mieæ mo¿liwoœæ przypisania 
 *
 *  Przyk³ad przeniesienia prawa w³asnoœci z dokonaniem konwersji typów
 *  Przyk³ad w którym wiêcej ni¿ jeden obiekt auto_ptr jest w³aœcicielem obiektu - b. niebezpieczne. Wlasnosc inteligentne wskaŸniki musz¹ przekazywaæ sobie nawzajem
 *  Przyk³ad - auto_ptr nie spe³nia wymagañ nak³adanych na elementy standardowej kolekcji i standardowe algorytmy, takie jak sort(); rozrysowaæ
 *  Przyk³ad - dlaczego auto_ptr jest deprecated. http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=400
 */



struct Zasob {
    int m;

    Zasob()
    {
        cout << "Utworzono zasob!" << endl;
    }

    ~Zasob()
    {
        cout << "Usuniêto zasob!" << endl;
    }
};


void ZabawaZasobem(Zasob* pz)
{
    // Szablon klasy std::auto_ptr wspiera technikê RAII 
	// (ang. Resource Acquisition Is Initialization) --- inicjowanie przy pozyskaniu zasobu. 
    // Wskazywany obiekt bêdzie niejawnie usuniêty w chwili opuszczenia zasiêgu	obiektu szablonu klasy auto_ptr
    std::auto_ptr<Zasob> p1(pz);
    std::auto_ptr<Zasob> p2 = p1;   // teraz p2 jest odpowiedzialny za usuniêcie (a p1 nie jest)
                                    // p1.get() zwróci NULL
    
    p1->m = 7;                     // b³¹d! p1.get()==NULL

    Zasob *p3 = p2.get();          // pobranie wskaznika uzyskuje siê poprzez wywo³anie metody get()

    std::auto_ptr<Zasob> p4(pz);   // b³¹d! teraz p4 i p2 s¹ odpowiedzialne za usuniêcie! 
                                   // wyjœcie z zakresu skoñczy siê b³êdem!
                                   // W³asnoœæ nale¿y przekazywaæ za pomoc¹ operatora =  
}

int main()
{
    Zasob z;
    ZabawaZasobem(&z);

    system("pause");
}