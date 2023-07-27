#include "livro.h"

Livro::Livro(std::string entradaTitulo, std::string entradaAutor)
: titulo(entradaTitulo), autor(entradaAutor), idadeMinima(0), dataRetirada(time(0)), quemTem(-1) {}

Livro::Livro(std::string entradaTitulo, std::string entradaAutor, unsigned int entradaIdadeMinima)
: titulo(entradaTitulo), autor(entradaAutor), idadeMinima(entradaIdadeMinima), dataRetirada(time(0)), quemTem(-1) {}

Livro::Livro(std::string entradaTitulo, std::string entradaAutor, unsigned int entradaIdadeMinima, time_t entradaDataRetirada, int entradaQuemTem)
: titulo(entradaTitulo), autor(entradaAutor), idadeMinima(entradaIdadeMinima), dataRetirada(entradaDataRetirada), quemTem(entradaQuemTem) {}

Livro::~Livro()
{
    //dtor
}

std::string Livro::to_string(){
    std::string divisor = ",";
    return      titulo
    + divisor + autor
    + divisor + std::to_string(idadeMinima)
    + divisor + std::to_string(dataRetirada)
    + divisor + std::to_string(quemTem);
}
