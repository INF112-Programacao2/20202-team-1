#pragma once
#include "CasasEspeciais.h"

class Noticias : public CasasEspeciais
{
private:
    int _valor;
    std::string _texto;
public:
    Noticias(std::string nome, int posicao, std::string path);
    ~Noticias();
    //getters
    int get_valor();
    std::string get_texto();
    //setters
    void set_valor(int);
    void set_texto(std::string texto);
    //metodos Noticias
    void executar_noticia();
};