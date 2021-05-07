#pragma once

#include "Casa.h"
#include "Jogador.h"
#include "Imovel.h"

class Partida
{
private:
    Jogador* _jogador[6];
    int _rodada;
    Casa* _casas[36];

public:
//construtores e destrutores
    Partida();
    ~Partida();
//getters e setters;
    int get_rodada();
    void set_rodada(int);
//metodos da partida
    int nova_rodada();
    int jogar_dados();
};