#pragma once
#include "CasasEspeciais.h"

class Noticias : public CasasEspeciais
{
private:
    int _valor;
    std::string _texto;
public:
    Noticias(std::string, int, std::string, std::string);
    ~Noticias();
    //getters
    int get_valor();
    std::string get_texto();
    //setters
    void set_valor(int);
    std::string set_texto(std::string texto);
    //metodos Noticias
    void executar_noticia();
};


