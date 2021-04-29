#pragma once
#include "CasasEspeciais.h"

class Noticias : public CasasEspeciais
{
private:
    bool tipo_noticia;
    int valor;
public:
    Noticias(std::string, int, std::string);
    ~Noticias();
//getters
    bool get_tipo_noticia();
    int get_valor();
//setters
    void set_tipo_noticia(std::string);
    void set_valor(int);
//metodos Noticias
    void executar_noticia();
};


