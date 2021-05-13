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
    int get_posicao_jogador(int jogador_id);
    void set_posicao_jogador(int jogador_id, int posicao);
    std::string get_nome_jogador(int);
    std::string get_foto_jogador(int);
    std::string get_nome_casa(int);
    std::string get_foto_casa(int);
    bool jogador_perdeu(int);
    bool jogador_proprietario(int indiceJogador, int indiceProprietario);
    Casa* get_casa(int casa_id);

    //metodos da partida
    int novo_turno();
    void nova_rodada();
    std::pair<int, int> jogar_dados();
    
};