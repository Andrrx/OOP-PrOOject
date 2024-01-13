main.cpp

// main.cpp
#include "game.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;

    // Definirea atacurilor disponibile
    Attack a1("Slash", 10, 0.8, 0.2, 1.5);
    Attack a2("Hadouken", 15, 0.7, 0.3, 1.8);
    Attack a3("Puch", 12, 0.9, 0.1, 1.7);
    Attack a4("Hadoken", 18, 0.6, 0.4, 2.0);

    // Crearea jucatorilor cu asocierea atacurilor disponibile
    Character player1("Ryu", 100);
    player1.addAttack(a1);
    player1.addAttack(a2);

    Character player2("Ken", 100);
    player2.addAttack(a3);
    player2.addAttack(a4);

    try {
        do {
            choice = displayMenu();

            switch (choice) {
                case 1: {
                    cout << "Jocul a inceput!\n";

                    while (player1.getHP() > 0 && player2.getHP() > 0) {
                        cout << "Starea jucatorilor:\n";
                        cout << player1 << endl;
                        cout << player2 << endl;

                        // Jucatorul 1 alege un atac
                        cout << "Jucator 1, este randul tau!\n";
                        player1.chooseAttacks();

                        // Aplica atacul asupra jucatorului 2
                        player1.performAttack(player2);

                        // Verifica daca jucatorul 2 a ramas fara HP
                        if (player2.getHP() <= 0) {
                            cout << "Jucatorul 1 a castigat! Felicitari!\n";
                            break;
                        }

                        // Jucatorul 2 alege un atac
                        cout << "Jucator 2, este randul tau!\n";
                        player2.chooseAttacks();

                        // Aplica atacul asupra jucatorului 1
                        player2.performAttack(player1);

                        // Verifica daca jucatorul 1 a ramas fara HP
                        if (player1.getHP() <= 0) {
                            cout << "Jucatorul 2 a castigat! Felicitari!\n";
                            break;
                        }
                    }
                    break;
                }
                case 2:
                    cout << "Jocul s-a incheiat.\n";
                    break;
                default:
                    cout << "Optiune invalida. Va rugam alegeti o optiune valida.\n";
            }

        } while (choice != 2);

    } catch (const exception& e) {
        cerr << "Exceptie: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    std::system("pause");

    return 0;
}
/*
 * #include <iostream>
#include"string.h"

///Singleton
class GeneratorIDUnic {
private:
    static GeneratorIDUnic *copie;
    uint32_t id;
    GeneratorIDUnic();

public:
    static GeneratorIDUnic *instanta();
    uint32_t next();
};

GeneratorIDUnic* GeneratorIDUnic::copie = 0;
GeneratorIDUnic::GeneratorIDUnic() : id(0) {}

uint32_t GeneratorIDUnic::next() {
    return id ++;
}

GeneratorIDUnic *GeneratorIDUnic::instanta() {
    if (!copie)
        copie = new GeneratorIDUnic();

    return copie;
}

///Template
template <typename T> class Lista {
private:
    T* ptr;
    int size;

public:
    Lista(T* objInit);
    void adauga(T* el);
    void afiseaza() const;
    T get(int i);
};

template <typename T> Lista<T>::Lista(T* objInit)
{
    ptr = (T*) malloc(sizeof(T));
    ptr = objInit;
    size = 1;
}

template <typename T> void Lista<T>::afiseaza() const
{
    for (int i = 0; i < size; i++) {
        ptr[i].getProductie()->afiseaza();
        std::cout << std::endl;
    }
}

template <typename T> void Lista<T>::adauga(T* el)
{
    size ++;
    ptr = (T*) realloc(ptr, sizeof(T) * size);
    ptr[size - 1] = *el;
}

template <typename T> T Lista<T>::get(int i)
{
    return ptr[i];
}

class Productie {
protected:
    uint32_t id;
    std::string titlu;
    std::string numeRegizor;
    int anAparitie;
    unsigned int durataMinute;

public:
    Productie(const std::string titlu, const std::string numeRegizor, int anAparitie, unsigned int durataMinute);

    Productie();

    ~Productie();

    Productie& operator=(const Productie &rhs);

    static int getId();

    std::string getTitlu() const;

    void setTitlu(std::string titlu);

    std::string getNumeRegizor() const;

    void setNumeRegizor(std::string numeRegizor);

    int getAnAparitie() const;

    void setAnAparitie(int anAparitie);

    int getDurataMinute() const;

    void setDurataMinute(unsigned int durataMinute);

    virtual Productie* cloneaza() const = 0;

    virtual void afiseaza() const = 0;
};

Productie::Productie(const std::string titlu, const std::string numeRegizor, int anAparitie, unsigned int durataMinute)
{
    this->id = GeneratorIDUnic::instanta()->next();
    this->titlu = titlu;
    this->numeRegizor = numeRegizor;
    this->anAparitie = anAparitie;
    this->durataMinute = durataMinute;
}

Productie::Productie()
{
    titlu = "";
    numeRegizor = "";
    anAparitie = 0;
    durataMinute = 0;
}

Productie::~Productie() = default;

Productie& Productie::operator=(const Productie &rhs)
{
    this->titlu = rhs.titlu;
    this->numeRegizor = rhs.numeRegizor;
    this->anAparitie = rhs.anAparitie;
    this->durataMinute = rhs.durataMinute;

    return *this;
}

std::string Productie::getTitlu() const
{
    return titlu;
}

void Productie::setTitlu(std::string titlu)
{
    this->titlu = titlu;
}

std::string Productie::getNumeRegizor() const
{
    return numeRegizor;
}

void Productie::setNumeRegizor(std::string numeRegizor)
{
    this->numeRegizor = numeRegizor;
}

int Productie::getAnAparitie() const
{
    return anAparitie;
}

void Productie::setAnAparitie(int anAparitie)
{
    this->anAparitie = anAparitie;
}

int Productie::getDurataMinute() const
{
    return durataMinute;
}

void Productie::setDurataMinute(unsigned int durataMinute)
{
    this->durataMinute = durataMinute;
}

class FilmDocumentar : public Productie {
public:
    FilmDocumentar(const std::string titlu, const std::string numeRegizor, int anAparitie, unsigned int durataMinute)
            : Productie(titlu, numeRegizor, anAparitie, durataMinute) {}

    FilmDocumentar() : Productie() {}

    void afiseaza() const override {
        std::cout << this->id << " - Filmul documentar " << this->titlu << ", regizor: "
                  << this->numeRegizor << ". An aparitie: " << this->anAparitie
                  << ". Durata: " << this->durataMinute << " minute";
    }

    FilmDocumentar* cloneaza() const override
    {
        FilmDocumentar* f = new FilmDocumentar(titlu, numeRegizor, anAparitie, durataMinute);

        return f;
    }
};

class FilmAnimatie : public Productie {
public:
    FilmAnimatie(const std::string titlu, const std::string numeRegizor, int anAparitie, unsigned int durataMinute)
            : Productie(titlu, numeRegizor, anAparitie, durataMinute) {}

    FilmAnimatie() : Productie() {}

    void afiseaza() const override {
        std::cout << this->id << " - Filmul de animatie " << this->titlu << ", regizor: "
                  << this->numeRegizor << ". An aparitie: " << this->anAparitie
                  << ". Durata: " << this->durataMinute << " minute";
    }

    FilmAnimatie* cloneaza() const override
    {
        FilmAnimatie* f = new FilmAnimatie(titlu, numeRegizor, anAparitie, durataMinute);

        return f;
    }
};

class FilmFictiune : public Productie {
public:
    FilmFictiune(const std::string titlu, const std::string numeRegizor, int anAparitie, unsigned int durataMinute)
            : Productie(titlu, numeRegizor, anAparitie, durataMinute) {}

    FilmFictiune() : Productie() {}

    void afiseaza() const override {
        std::cout << this->id << " - Filmul de fictiune " << this->titlu << ", regizor: "
                  << this->numeRegizor << ". An aparitie: " << this->anAparitie
                  << ". Durata: " << this->durataMinute << " minute";
    }

    FilmFictiune* cloneaza() const override
    {
        FilmFictiune* f = new FilmFictiune(titlu, numeRegizor, anAparitie, durataMinute);

        return f;
    }

};

///Factory method
class FilmFactory {
private:
    Productie* productie;

public:
    FilmFactory(const std::string type, const std::string titlu, const std::string numeRegizor, int anAparitie, unsigned int durataMinute)
    {
        if (type == "FilmDocumentar")
        {
            productie = new FilmDocumentar(titlu, numeRegizor, anAparitie, durataMinute);
        }

        else if (type == "FilmAnimatie")
        {
            productie = new FilmAnimatie(titlu, numeRegizor, anAparitie, durataMinute);
        }

        else if (type == "FilmFictiune")
        {
            productie = new FilmFictiune(titlu, numeRegizor, anAparitie, durataMinute);
        }

        else
        {
            productie = NULL;
        }
    }

    FilmFactory(const std::string type = "")
    {
        if (type == "FilmDocumentar")
        {
            productie = new FilmDocumentar();
        }

        else if (type == "FilmAnimatie")
        {
            productie = new FilmAnimatie();
        }

        else if (type == "FilmFictiune")
        {
            productie = new FilmFictiune();
        }

        else
        {
            productie = NULL;
        }
    }

    ~FilmFactory()
    {
        if (productie) {
            delete productie;
            productie = NULL;
        }
    }

    Productie* getProductie() { return productie; }
};

///Template
template <typename T> void auAcelasiRegizor(T* x, T* y)
{
    if (x->getNumeRegizor() == y->getNumeRegizor())
        std::cout << "Filmele au acelasi regizor!" << std::endl;
}

template<>
void auAcelasiRegizor(FilmAnimatie* x, FilmAnimatie* y)
{
    if (x->getNumeRegizor() == y->getNumeRegizor())
        std::cout << "Cele doua animatii au acelasi producator!" << std::endl;
}

int main()
{
    Lista<FilmFactory> L(new FilmFactory("FilmDocumentar", "Documentar despre Programare", "John Doe", 2003, 90));
    L.adauga(new FilmFactory("FilmAnimatie", "Alba ca Zapada", "John Smith", 2009, 70));
    L.adauga(new FilmFactory("FilmAnimatie", "Alice in Tara Minunilor", "Steve Jobs", 2019, 60));
    L.afiseaza();
    FilmAnimatie* clona = dynamic_cast<FilmAnimatie*>(L.get(1).getProductie())->cloneaza();
    clona->afiseaza();
    FilmAnimatie* clona2 = dynamic_cast<FilmAnimatie*>(L.get(2).getProductie())->cloneaza();
    std::cout << std::endl;
    auAcelasiRegizor<FilmAnimatie>(clona, clona2);
    return 0;
}
 */
