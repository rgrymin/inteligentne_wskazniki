#include <iostream>
#include <memory>      // wzorzec klasy std::auto_ptr zadeklarowany jest w standardowym pliku nag��wkowym <memory>


using std::cout;
using std::endl;

/*
 *  Co� co b��dnie jest uwa�ane, za wska�nik inteligentny!
 *
 *  Wzorzec klasy auto_ptr wspiera technik� RAII (ang. Resource Acquisition Is Initialization) - inicjowanie przy pozyskaniu zasobu.
 *  Zasadniczo auto_ptr jest inicjowana wska�nikiem i mo�na go u�ywa� jak wska�nika.
 *  Wskazywany obiekt b�dzie niejawnie usuni�ty w chwili opuszczenia zasi�gu klasy auto_ptr.
 *
 *  Wzorzec klasy auto_ptr dostarcza semantyk� �cis�ej w�asno�ci.
 *  W zwi�zku z tym, semantyka kopiowania w klasie auto_ptr r�ni si� znacznie od semantyki kopiowania zwyk�ych wska�nik�w:
 *  po skopiowaniu jednego obiektu auto_ptr na drugi, obiekt �rd�owy na nic ju� nie wskazuje.
 *  Poniewa� kopiowanie takiego obiektu modyfikuje go, wi�c nie mo�na kopiowa� obiekt�w z atrybutem const.
 *
 *  Wychodzi z u�ytku.
 *
 *  Przyk�ad z polimorfizmem (rzutowanie w g�r�) (por�wnanie z u�yciem normalnego wska�nika) - nie nale�y go wykorzystywa�, nie wsp�pracuje z wektorami
 *      Dlaczego?
 *      Standard C++ m�wi, �e element STL musi mie� mo�liwo�� przypisania 
 *
 *  Przyk�ad przeniesienia prawa w�asno�ci z dokonaniem konwersji typ�w
 *  Przyk�ad w kt�rym wi�cej ni� jeden obiekt auto_ptr jest w�a�cicielem obiektu - b. niebezpieczne. Wlasnosc inteligentne wska�niki musz� przekazywa� sobie nawzajem
 *  Przyk�ad - auto_ptr nie spe�nia wymaga� nak�adanych na elementy standardowej kolekcji i standardowe algorytmy, takie jak sort(); rozrysowa�
 *  Przyk�ad - dlaczego auto_ptr jest deprecated. http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=400
 */



struct Zasob {
    int m;

    Zasob()
    {
        cout << "Utworzono zasob!" << endl;
    }

    ~Zasob()
    {
        cout << "Usuni�to zasob!" << endl;
    }
};


void ZabawaZasobem(Zasob* pz)
{
    // Szablon klasy std::auto_ptr wspiera technik� RAII 
	// (ang. Resource Acquisition Is Initialization) --- inicjowanie przy pozyskaniu zasobu. 
    // Wskazywany obiekt b�dzie niejawnie usuni�ty w chwili opuszczenia zasi�gu	obiektu szablonu klasy auto_ptr
    std::auto_ptr<Zasob> p1(pz);
    std::auto_ptr<Zasob> p2 = p1;   // teraz p2 jest odpowiedzialny za usuni�cie (a p1 nie jest)
                                    // p1.get() zwr�ci NULL
    
    p1->m = 7;                     // b��d! p1.get()==NULL

    Zasob *p3 = p2.get();          // pobranie wskaznika uzyskuje si� poprzez wywo�anie metody get()

    std::auto_ptr<Zasob> p4(pz);   // b��d! teraz p4 i p2 s� odpowiedzialne za usuni�cie! 
                                   // wyj�cie z zakresu sko�czy si� b��dem!
                                   // W�asno�� nale�y przekazywa� za pomoc� operatora =  
}

int main()
{
    Zasob z;
    ZabawaZasobem(&z);

    system("pause");
}