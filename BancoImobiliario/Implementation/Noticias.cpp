#include "./Header/Noticias.h"

//Construtor
Noticias::Noticias(std::string nome, int posicao, std::string tipo) : CasasEspeciais(nome,posicao,tipo) {}
//Destrutor
Noticias::~Noticias(){}

//getters
bool Noticias::get_tipo_noticia(){
    return this->tipo_noticia;
}
int Noticias::get_valor(){
    return this->valor;
}

//setters
void Noticias::set_tipo_noticia(std::string tipo){
    this->tipo_noticia = tipo_noticia;
}
void Noticias::set_valor(int valor){
    this->valor = valor;
}

//metodos
void Noticias::executar_noticia(){}