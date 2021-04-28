#ifndef INF112_EXCECAO_JOGADOR_H
#define INF112_EXCECAO_JOGADOR_H

#include <stdexcept>

class ExcecaoJogador : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

#endif