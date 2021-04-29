#pragma once

class Partida
{
private:
    int num_jogadores;
    int rodada;
public:
//construtores e destrutores
    Partida();
    ~Partida();
//getters e setters;
    int get_num_jogadores();
    int get_rodada();
    void set_num_jogadores(int);
    void set_rodada(int);
//metodos da partida
    int nova_rodada();
    int jogar_dados();
};