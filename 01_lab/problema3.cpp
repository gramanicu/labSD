#include <iostream>
#include <memory>

class Matrice {
   private:
    int** m;
    int size;

   public:
    Matrice(){};
    Matrice(int size) {
        set_size(size);
        this->m = new int*[size];
        for (int i = 0; i < this->get_size(); i++) {
            this->m[i] = new int[size];
            this->m[i] = 0;
        }
    };

    ~Matrice() {
        delete[] this->m[0];
        delete[] this->m;
    };

    void printMatrix() {
        for (int i = 0; i < this->get_size(); i++) {
            for (int j = 0; j < this->get_size(); j++) {
                std::cout << this->m[i][j];
            }
        }
    }

    void set_size(int size) { this->size = size; };

    int get_size() { return this->size; };
};

int main() {
    Matrice* m = new Matrice(3);
    m->printMatrix();
    return 0;
}