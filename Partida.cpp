#include "Partida.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

Partida::Partida() {
    _turno = 0;
    _rodada = 1;
    _casas[0] = new CasasEspeciais("Início", 0, "img/home.png");
    _casas[1] = new Imovel("Sydney", 0, "img/imovel0.png", 200, 400);
    _casas[2] = new Imovel("Camberra", 0, "img/imovel0.png", 300, 600);
    _casas[3] = new Acao("Itau", 0, "img/itau.png", 2000, 500);
    _casas[4] = new Imovel("Brisbane", 0, "img/imovel0.png", 400, 800);
    _casas[5] = new Imovel("Durban", 0, "img/imovel1.png", 500, 1000);
    _casas[6] = new Noticias("Noticia", 0, "img/news.png");
    _casas[7] = new Imovel("Nairóbi", 0, "img/imovel1.png", 600, 1200);
    _casas[8] = new Imovel("Luanda", 0, "img/imovel1.png", 700, 1400);
    _casas[9] = new CasasEspeciais("Xadrez", 0, "img/jail.png");
    _casas[10] = new Noticias("Noticia", 0, "img/news.png");
    _casas[11] = new Imovel("Belize", 0, "img/imovel2.png", 800, 1600);
    _casas[12] = new Acao("Nivea", 0, "img/nivea.png", 2000, 500);
    _casas[13] = new Imovel("Havana", 0, "img/imovel2.png", 900, 1800);
    _casas[14] = new CasasEspeciais("Receba", 0, "img/receive.png");
    _casas[15] = new Imovel("Lima", 0, "img/imovel3.png", 1000, 2000);
    _casas[16] = new Imovel("Bogota", 0, "img/imovel3.png", 1100, 2200);
    _casas[17] = new Imovel("Toronto", 0, "img/imovel4.png", 1200, 2400);
    _casas[18] = new CasasEspeciais("Feriado", 0, "img/holiday.png");
    _casas[19] = new Imovel("Miami", 0, "img/imovel4.png", 1300, 2600);
    _casas[20] = new Acao("Vivo", 0, "img/vivo.png", 2000, 500);
    _casas[21] = new CasasEspeciais("Pague", 0, "img/pay.png");
    _casas[22] = new Noticias("Noticia", 0, "img/news.png");
    _casas[23] = new Imovel("Roma", 0, "img/imovel5.png", 1400, 2800);
    _casas[24] = new Imovel("Madrid", 0, "img/imovel5.png", 1500, 3000);
    _casas[25] = new Noticias("Noticia", 0, "img/news.png");
    _casas[26] = new Imovel("Lisboa", 0, "img/imovel5.png", 1400, 2800);
    _casas[27] = new CasasEspeciais("Prisão", 0, "img/go_to_jail.png");
    _casas[28] = new Imovel("Pequim", 0, "img/imovel6.png", 1300, 2600);
    _casas[29] = new Noticias("Noticia", 0, "img/news.png");
    _casas[30] = new Imovel("Moscou", 0, "img/imovel6.png", 1200, 2400);
    _casas[31] = new Imovel("Pequim", 0, "img/imovel6.png", 1100, 2200);
    _casas[32] = new Imovel("Tokyo", 0, "img/imovel7.png", 1000, 2000);
    _casas[33] = new Acao("Fiat", 0, "img/fiat.png", 2000, 500);
    _casas[34] = new Imovel("Cairo", 0, "img/imovel7.png", 900, 1800);
    _casas[35] = new Imovel("Dubai", 0, "img/imovel7.png", 800, 1600);

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

    _jogador[0] = new Jogador(0, 15000, "Ana", 0, "img/player1.png");
    _jogador[1] = new Jogador(1, 15000, "Bruno", 1, "img/player2.png");
    _jogador[2] = new Jogador(2, 15000, "Felipe", 2, "img/player3.png");
    _jogador[3] = new Jogador(3, 15000, "Jonas", 3, "img/player4.png");
    _jogador[4] = new Jogador(4, 15000, "Lademir", 4, "img/player5.png");
    _jogador[5] = new Jogador(5, 15000, "Luisa", 5, "img/player6.png");
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

int Partida::get_posicao_jogador(int jogador_id)
{
    return this->_jogador[jogador_id]->get_posicao();
}

void Partida::set_posicao_jogador(int jogador_id, int posicao)
{
    this->_jogador[jogador_id]->set_posicao(posicao);
}

std::string Partida::get_nome_jogador(int i)
{
    return this->_jogador[i]->get_nome();
}

std::string Partida::get_foto_jogador(int i)
{
    return this->_jogador[i]->get_path();
}

std::string Partida::get_nome_casa(int i)
{
    return this->_casas[i]->get_nome();
}

std::string Partida::get_foto_casa(int i)
{
    return this->_casas[i]->get_path();
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

bool Partida::jogador_perdeu(int i) {
    if (this->_jogador[i]->get_quantidadeDinheiro() <= 0 && this->get_rodada() != 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Partida::jogador_proprietario(int indiceJogador, int indiceProprietario) {
    if (indiceProprietario == -1 || indiceProprietario != indiceJogador) {
        return false;
    }
    else {
        return true;
    }
}

Casa* Partida::get_casa(int casa_id)
{
    return this->_casas[casa_id];
}

Jogador* Partida::get_jogador(int jogador_id)
{
    return this->_jogador[jogador_id];
}