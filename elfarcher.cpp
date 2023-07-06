#include <iostream>

struct Unit {
    virtual ~Unit() {}
};

struct Elf : Unit {};

struct Archer : Unit {};

struct ElfArcher : Elf, Archer {};

template <class T>
bool isSameObjects(T const* p, T const* q) {
    return (dynamic_cast<const void*>(p)) == (dynamic_cast<const void*>(q));
}

int main() {
    ElfArcher a, b;
    Unit* ue = (Unit*)(Elf*)&a;
    Unit* ua = (Unit*)(Archer*)&a;
    std::cout << isSameObjects(ue, ua);

}