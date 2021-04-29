#pragma once
#include "CasasNegociaveis.h"

class Imovel : public CasasNegociaveis
{
private:
    double valor_por_casa;
    int aluguel;
    int valor_1_casa;
    int valor_2_casas;
    int valor_3_casas;
    int valor_4_casas;
    int valor_5_casas;
    int valor_hotel;
    int num_casas;
public:
    Imovel(std::string, int, int, int, int);
    ~Imovel();
//getters
    double get_valor_por_casa();
    int get_aluguel();
    int get_valor_1_casa();
    int get_valor_2_casas();
    int get_valor_3_casas();
    int get_valor_4_casas();
    int get_valor_5_casas();
    int get_valor_hotel();
    int get_num_casas();
//setters
    void set_valor_por_casa(double);
    void set_aluguel(int);
    void set_valor_1_casa(int);
    void set_valor_2_casas(int);
    void set_valor_3_casas(int);
    void set_valor_4_casas(int);
    void set_valor_5_casas(int);
    void set_valor_hotel(int);
    void set_num_casas(int);
//metodos de imovel
    void upgrade();
    void cobrar();
};

