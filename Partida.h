#pragma once

#include "Casa.h"
#include "Jogador.h"
#include "Imovel.h"
#include "Acao.h"
#include "Noticias.h"

class Partida
{
private:
    Jogador* _jogador[6];
    int _turno;
    int _rodada;
    Casa* _casas[36];

public:
    //construtores e destrutores
    Partida();
    ~Partida();
    //getters e setters;
    int get_turno();
    void set_turno(int);
    int get_rodada();
    std::string get_nome_jogador(int);
    std::string get_foto_jogador(int);
    std::string get_nome_casa(int);
    std::string get_foto_casa(int);
    //metodos da partida
    int novo_turno();
    void nova_rodada();
    std::pair<int, int> jogar_dados();
};