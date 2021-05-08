#include "Partida.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

Partida::Partida() {
    _turno = 5;
    _rodada = 0;
    _casas[0] = new Casa("Início", 0, "img/home.png");
    _casas[1] = new Casa("Início", 0, "img/home.png");
    _casas[2] = new Casa("Início", 0, "img/home.png");
    _casas[3] = new Casa("Início", 0, "img/itau.png");
    _casas[4] = new Casa("Início", 0, "img/home.png");
    _casas[5] = new Casa("Início", 0, "img/home.png");
    _casas[6] = new Casa("Início", 0, "img/news.png");
    _casas[7] = new Casa("Início", 0, "img/home.png");
    _casas[8] = new Casa("Início", 0, "img/imovel1.png");
    _casas[9] = new Casa("Início", 0, "img/home.png");
    _casas[10] = new Casa("Início", 0, "img/news.png");
    _casas[11] = new Casa("Início", 0, "img/home.png");
    _casas[12] = new Casa("Início", 0, "img/nivea.png");
    _casas[13] = new Casa("Início", 0, "img/home.png");
    _casas[14] = new Casa("Início", 0, "img/receive.png");
    _casas[15] = new Casa("Início", 0, "img/home.png");
    _casas[16] = new Casa("Início", 0, "img/home.png");
    _casas[17] = new Casa("Início", 0, "img/home.png");
    _casas[18] = new Casa("Início", 0, "img/home.png");
    _casas[19] = new Casa("Início", 0, "img/home.png");
    _casas[20] = new Casa("Início", 0, "img/home.png");
    _casas[21] = new Casa("Início", 0, "img/pay.png");
    _casas[22] = new Casa("Início", 0, "img/home.png");
    _casas[23] = new Casa("Início", 0, "img/imovel5.png");
    _casas[24] = new Casa("Início", 0, "img/home.png");
    _casas[25] = new Casa("Início", 0, "img/home.png");
    _casas[26] = new Casa("Início", 0, "img/home.png");
    _casas[27] = new Casa("Início", 0, "img/home.png");
    _casas[28] = new Casa("Início", 0, "img/home.png");
    _casas[29] = new Casa("Início", 0, "img/home.png");
    _casas[30] = new Casa("Início", 0, "img/home.png");
    _casas[31] = new Casa("Início", 0, "img/imovel6.png");
    _casas[32] = new Casa("Início", 0, "img/home.png");
    _casas[33] = new Casa("Início", 0, "img/home.png");
    _casas[34] = new Casa("Início", 0, "img/home.png");
    _casas[35] = new Casa("Início", 0, "img/home.png");

    //posicoes das casas
    int xCasaAux = 1920 - 192;
    int yCasaAux = 1080 - 108;
    for (int i = 0; i < 36; i++) {
        _casas[i]->set_x(xCasaAux);
        _casas[i]->set_y(yCasaAux);
        if (i < 9) {
            xCasaAux -= 192;
        }
        else {
            if (i < 18) {
                yCasaAux -= 108;
            }
            else {
                if (i < 27) {
                    xCasaAux += 192;
                }
                else {
                    yCasaAux += 108;
                }
            }
        }
    }

    _jogador[0] = new Jogador(0, 0, "Ana", 0, "img/player1.png");
    _jogador[1] = new Jogador(0, 0, "Bruno", 1, "img/player2.png");
    _jogador[2] = new Jogador(0, 0, "Felipe", 2, "img/player3.png");
    _jogador[3] = new Jogador(0, 0, "Jonas", 3, "img/player4.png");
    _jogador[4] = new Jogador(0, 0, "Lademir", 4, "img/player5.png");
    _jogador[5] = new Jogador(0, 0, "Luisa", 5, "img/player6.png");
}

Partida::~Partida() {}

//getters
int Partida::get_turno()
{
    return this->_turno;
}
int Partida::get_rodada()
{
    return this->_rodada;
}
std::string Partida::get_nome_jogador(int i)
{
    return this->_jogador[i]->get_nome();
}

//setters
void Partida::set_turno(int turno)
{
    this->_turno = turno;
}

//metodos
int Partida::novo_turno()
{
    this->_turno++;
    return _turno;
}
void Partida::nova_rodada()
{
    this->_rodada++;
}
std::pair<int, int> Partida::jogar_dados() //gera um numero aleatorio de 1 ate 6
{
    srand(time(NULL));
    //gera de 0 a 5, como nao pode ser 0, soma 1 e so podera retornar de 1 ate 6
    std::pair<int, int> dados;
    dados.first = (rand() % 6) + 1;
    dados.second = (rand() % 6) + 1;
    return dados;
}