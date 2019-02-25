#include <iostream>
#include <memory>

class Profesor {
   private:
    char materie;

   public:
    Profesor(){};
    ~Profesor(){};
    void schimbaMaterie(char materie) { this->materie = materie; }
    void afiseazaMaterie() { std::cout << this->materie << std::endl; }
};

int main() {
    Profesor p;
    p.schimbaMaterie('M');
    p.afiseazaMaterie();
    p.schimbaMaterie('P');
    p.afiseazaMaterie();

    return 0;
}