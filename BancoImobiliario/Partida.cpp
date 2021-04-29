#include "Partida.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

Partida::Partida(){}
Partida::~Partida(){}

//getters
int Partida::get_num_jogadores()
{
    return this->num_jogadores;
}
int Partida::get_rodada()
{
    return this->rodada;
}

//setters
void Partida::set_num_jogadores(int num_jogadores)
{
    this->num_jogadores = num_jogadores;
}
void Partida::set_rodada(int rodada)
{
    this->rodada = rodada;
}

//metodos
int Partida::nova_rodada()
{
    this->rodada++;
}
int Partida::jogar_dados() //gera um numero aleatorio de 1 ate 6
{
    srand(time(NULL));
    //gera de 0 a 5, como nao pode ser 0, soma 1 e so podera retornar de 1 ate 6
    return (rand()%6) + 1;
}