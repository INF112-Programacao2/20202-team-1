#include "Noticias.h"
#include <cstdlib>
#include <time.h>

//Construtor
Noticias::Noticias(std::string nome, int posicao, std::string path) : CasasEspeciais(nome, posicao, path), _valor(0), _texto("") {}
//Destrutor
Noticias::~Noticias() {}

//getters
int Noticias::get_valor() {
    return this->_valor;
}

std::string Noticias::get_texto()
{
    return std::string();
}

//setters
void Noticias::set_valor(int valor) {
    this->_valor = valor;
}

std::string Noticias::set_texto(std::string texto)
{
    return std::string();
}

//metodos
void Noticias::executar_noticia() {
    int carta;
    srand(time(NULL));
    carta = (rand() % 31);
    if (carta == 0) {
        set_valor(800);
        set_texto("Parabens! Você ganhou 1 premio no PIC Itau!");
    }
    else if (carta == 1) {
        set_valor(1.500);
        set_texto("Com o cartao de credito MasterCard você tem muitos beneficios para aproveitar!");
    }
}