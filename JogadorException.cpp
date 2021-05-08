#include "JogadorException.h"

const char* ExcecaoJogador::what() const noexcept
{
    return "O jogador nao possui mais dinheiro!";
}