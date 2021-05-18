// BancoAllegro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include "Partida.h"

int main()
{
    //classe que controla o jogo
    Partida partida;
    //inicializacoes do allegro
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_BITMAP* ps2;
    ALLEGRO_BITMAP* blueScreen;
    ALLEGRO_BITMAP* bitmap[36];
    for (int i = 0; i < 36; i++) {
        bitmap[i] = NULL;
    }
    ALLEGRO_BITMAP* players[6];
    ALLEGRO_BITMAP* players_128[6];
    ALLEGRO_BITMAP* dice[6];
    for (int i = 0; i < 6; i++) {
        players[i] = NULL;
        players_128[i] = NULL;
        dice[i] = NULL;
    }
    ALLEGRO_BITMAP* blur = NULL;
    ALLEGRO_BITMAP* card_model = NULL;
    ALLEGRO_BITMAP* card_noticias[3];
    for (int i = 0; i < 3; i++) {
        card_noticias[i] = NULL;
    }

    al_init();

    //ajustando o jogo para diferentes monitores
    ALLEGRO_MONITOR_INFO info;

    int res_x_comp, res_y_comp;
    al_get_monitor_info(0, &info);
    res_x_comp = info.x2 - info.x1;
    res_y_comp = info.y2 - info.y1;

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(res_x_comp, res_y_comp);

    float red_x = res_x_comp / (float)1920;
    float red_y = res_y_comp / (float)1080;

    ALLEGRO_TRANSFORM transform;

    al_identity_transform(&transform);
    al_scale_transform(&transform, red_x, red_y);
    al_use_transform(&transform);

    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);

    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));


    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_acodec_addon();
    al_init_primitives_addon();

    ALLEGRO_FONT* opensans_bold_16 = al_load_ttf_font("ProductSansRegular.ttf", 16, 0);
    ALLEGRO_FONT* opensans_bold_24 = al_load_ttf_font("ProductSansRegular.ttf", 24, 0);
    ALLEGRO_FONT* opensans_bold_32 = al_load_ttf_font("ProductSansBold.ttf", 32, 0);
    ALLEGRO_FONT* opensans_bold_48 = al_load_ttf_font("ProductSansBold.ttf", 48, 0);

    ALLEGRO_SAMPLE* themeSong = NULL;
    ALLEGRO_SAMPLE* diceSound = NULL;
    ALLEGRO_SAMPLE* cashSound = NULL;
    ALLEGRO_SAMPLE* startingSound = NULL;
    ALLEGRO_SAMPLE* bruhSound = NULL;
    ALLEGRO_SAMPLE* you_winSound = NULL;
    ALLEGRO_SAMPLE* to_be_continuedthemeSound = NULL;
    ALLEGRO_SAMPLE* mamamiaSound = NULL;
    ALLEGRO_SAMPLE* shutdownSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE* themeSongInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* diceSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* cashSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* startingSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* bruhSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* you_winSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* to_be_continuedthemeSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* mamamiaSoundInstance = NULL;
    ALLEGRO_SAMPLE_INSTANCE* shutdownSoundInstance = NULL;

    al_reserve_samples(9);
    themeSong = al_load_sample("sound/MiiPlaza.mp3");
    diceSound = al_load_sample("sound/dice.mp3");
    cashSound = al_load_sample("sound/cash.mp3");
    startingSound = al_load_sample("sound/starting.mp3");
    bruhSound = al_load_sample("sound/bruh.mp3");
    you_winSound = al_load_sample("sound/you_win.mp3");
    to_be_continuedthemeSound = al_load_sample("sound/to_be_continued.mp3");
    mamamiaSound = al_load_sample("sound/mamamia.mp3");
    shutdownSound = al_load_sample("sound/shutdown.mp3");

    themeSongInstance = al_create_sample_instance(themeSong);
    diceSoundInstance = al_create_sample_instance(diceSound);
    cashSoundInstance = al_create_sample_instance(cashSound);
    startingSoundInstance = al_create_sample_instance(startingSound);
    bruhSoundInstance = al_create_sample_instance(bruhSound);
    you_winSoundInstance = al_create_sample_instance(you_winSound);
    to_be_continuedthemeSoundInstance = al_create_sample_instance(to_be_continuedthemeSound);
    mamamiaSoundInstance = al_create_sample_instance(mamamiaSound);
    shutdownSoundInstance = al_create_sample_instance(shutdownSound);
    al_attach_sample_instance_to_mixer(themeSongInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(diceSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(cashSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(startingSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(bruhSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(you_winSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(to_be_continuedthemeSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(mamamiaSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(shutdownSoundInstance, al_get_default_mixer());

    //importando as imagens
    ps2 = al_load_bitmap("img/ps2.png");
    blueScreen = al_load_bitmap("img/blueScreen.png");

    for (int i = 0; i < 36; i ++) {
        bitmap[i] = al_load_bitmap(partida.get_foto_casa(i).c_str());
    }

    for (int i = 0; i < 6; i++) {
        players[i] = al_load_bitmap(partida.get_foto_jogador(i).c_str());
        std::string getFotoAux = "img/128_" + partida.get_foto_jogador(i).substr(4, partida.get_foto_jogador(i).length());
        players_128[i] = al_load_bitmap(getFotoAux.c_str());
        std::string diceAux = "img/dice" + std::to_string(i + 1) + ".png";
        dice[i] = al_load_bitmap(diceAux.c_str());
    }

    blur = al_load_bitmap("img/blur.png");
    card_model = al_load_bitmap("img/card_model.png");
    card_noticias[0] = al_load_bitmap("img/noticias_down_model.png");
    card_noticias[1] = al_load_bitmap("img/noticias_up_model.png");
    card_noticias[2] = al_load_bitmap("img/noticias_back.png");

    //definindo quais casas tem precos
    int precos[36];
    for (int i = 0; i < 36; i++) {
        precos[i] = 100;
    }
    precos[0] = precos[6] = precos[9] = precos[10] = precos[18] = precos[22] = precos[25] = precos[27] = precos[29] = 0;
    assert (bitmap != NULL);

    //definindo paleta de cores para uso posterior
    int colorR[36], colorG[36], colorB[36];
    for (int i = 0; i < 36; i++) {
        colorR[i] = colorG[i] = colorB[i] = 0;
    }
    //green
    colorR[1] = colorR[2] = colorR[4] = 11;
    colorG[1] = colorG[2] = colorG[4] = 77;
    colorB[1] = colorB[2] = colorB[4] = 19;
    //red
    colorR[5] = colorR[7] = colorR[8] = 161;
    colorG[5] = colorG[7] = colorG[8] = 22;
    colorB[5] = colorB[7] = colorB[8] = 22;
    //blue
    colorR[11] = colorR[13] = 31;
    colorG[11] = colorG[13] = 129;
    colorB[11] = colorB[13] = 147;
    //pink
    colorR[15] = colorR[16] = 185;
    colorG[15] = colorG[16] = 24;
    colorB[15] = colorB[16] = 132;
    //purple
    colorR[17] = colorR[19] = 110;
    colorG[17] = colorG[19] = 28;
    colorB[17] = colorB[19] = 146;
    //blue
    colorR[23] = colorR[24] = colorR[26] = 24;
    colorG[23] = colorG[24] = colorG[26] = 54;
    colorB[23] = colorB[24] = colorB[26] = 85;
    //orange
    colorR[28] = colorR[30] = colorR[31] = 254;
    colorG[28] = colorG[30] = colorG[31] = 123;
    colorB[28] = colorB[30] = colorB[31] = 0;
    //yellow
    colorR[32] = colorR[34] = colorR[35] = 236;
    colorG[32] = colorG[34] = colorG[35] = 200;
    colorB[32] = colorB[34] = colorB[35] = 0;
    //grey
    colorR[3] = colorR[12] = colorR[20] = colorR[33] = 77;
    colorG[3] = colorG[12] = colorG[20] = colorG[33] = 77;
    colorB[3] = colorB[12] = colorB[20] = colorB[33] = 77;

    //variaveis para o controle do jogo pelo allegro
    bool fimPartida = false;
    bool running = true, diceOn = false, diceStillPressed = false, playerMoving = false, playerMovingAux = false;
    bool mouseOn = false, allReady = false, noticiaOn = false, negociavelOn = false;
    float x = 0, y = 0;
    int width = al_get_display_width(display);
    int dice1Position = 0, dice2Position = 0, throwDice = 0, casaFinal = 0;
    int xMouse = 0, yMouse = 0;
    int casaClicada = -1;
    std::string texto_noticia = "";
    int valor_noticia = 0;
    int casa_exibida = -1;
    bool jogadores_eliminados[6];
    int valorAnterior[6], valorMudanca[6], contFramesMudanca[6];
    float indAumento[36];
    for (int i = 0; i < 6; i++) {
        jogadores_eliminados[i] = false;
        valorAnterior[i] = partida.get_jogador(i)->get_quantidadeDinheiro();
        valorMudanca[i] = contFramesMudanca[i] = 0;
    }

    //posicoes dos players
    int casaAtual[6];
    for (int i = 5; i >= 0; i--) {
        casaAtual[i] = 0;
    }

    //posicoes das casas
    int xCasa[36];
    int yCasa[36];
    int xCasaAux = 1920 - 192;
    int yCasaAux = 1080 - 108;
    for (int i = 0; i < 36; i++) {
        xCasa[i] = xCasaAux;
        yCasa[i] = yCasaAux;
        indAumento[i] = 0;
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

    al_start_timer(timer);
    al_play_sample_instance(startingSoundInstance);
    while (al_get_sample_instance_playing(startingSoundInstance)) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            if (al_get_sample_instance_position(startingSoundInstance) > 30000 && al_get_sample_instance_position(startingSoundInstance) < 134000) {
                al_draw_bitmap(ps2, 462, 444, 0);
            }
            else {
                if (al_get_sample_instance_position(startingSoundInstance) > 148000) {
                    for (int i = 0; i < 6; i++) {
                        al_draw_bitmap(players_128[i], 576 + (i * 128), 476, 0);
                    }
                }
            }
            al_flip_display();
        }
    }
    al_set_sample_instance_playmode(themeSongInstance, ALLEGRO_PLAYMODE_LOOP);
    al_play_sample_instance(themeSongInstance);
    while (running) {
        
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }

        //mouse
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            if (!mouseOn) {
                xMouse = (int) ((event.mouse.x + 1) * (1920.0 / res_x_comp)) - 1;
                yMouse = (int) ((event.mouse.y + 1) * (1080.0 / res_y_comp)) - 1;
            }
            mouseOn = !mouseOn;
        }

        ALLEGRO_KEYBOARD_STATE keyState;
        al_get_keyboard_state(&keyState);

        if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) {
            running = false;
        }

        //esse evento e executado 60 vezes por segundo
        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
            casa_exibida = -1;
            int xTabuleiro = 1920 - 192;
            int yTabuleiro = 1080 - 108;

            //exibe as casas no tabuleiro
            for (int i = 0; i < 36; i++) {
                al_draw_bitmap(bitmap[i], xCasa[i], yCasa[i], 0);
                if (CasasNegociaveis* casaNegociavelAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(i)))
                {
                    std::string tmp = "$" + std::to_string(casaNegociavelAux->get_valor_compra());
                    al_draw_text(opensans_bold_32, al_map_rgb(255, 255, 255), xCasa[i] + 96, yCasa[i] + 68, ALLEGRO_ALIGN_CENTRE, tmp.c_str());
                }
                else if ((i == 14) || (i == 21)){
                    std::string tmp = "$";
                    if (i == 14) tmp = "+" + tmp + "2000 ";
                    if (i == 21) tmp = "-" + tmp + "2000 ";
                    al_draw_text(opensans_bold_32, al_map_rgb(255, 255, 255), xCasa[i] + 96, yCasa[i] + 68, ALLEGRO_ALIGN_CENTRE, tmp.c_str());
                }
                if (i != 0 && i != 3 && i != 6 && i != 9 && i != 10 && i != 12 && i != 14 && i != 18 && i != 20 && i != 21 && i != 22 && i !=25 && i != 27 && i !=  29 && i != 33)
                {
                    al_draw_text(opensans_bold_32, al_map_rgb(255, 255, 255), xCasa[i] + 96, yCasa[i] + 3, ALLEGRO_ALIGN_CENTRE, partida.get_nome_casa(i).c_str());
                }
            }

            //exibe os players na casa em que eles estiverem
            xTabuleiro = 0;
            for (int i = 5; i >= 0; i--) {
                if (!jogadores_eliminados[i]) al_draw_bitmap(players[i], xCasa[casaAtual[i]] + 192 - 64 - 4 - xTabuleiro, yCasa[casaAtual[i]] + 22, 0);
                xTabuleiro += 24;
            }

            //exibe os dados dos players, como dinheiro e propriedades
            xTabuleiro = 324;
            for (int i = 5; i >= 0; i--) {
                yTabuleiro = 240;
                al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 1920 - xTabuleiro, yTabuleiro, ALLEGRO_ALIGN_CENTRE, partida.get_nome_jogador(i).c_str());
                if (partida.get_jogador(i)->get_quantidadeDinheiro() <= 0) {
                    al_draw_line(1920 - xTabuleiro - 64, yTabuleiro + 22, 1920 - xTabuleiro + 64, yTabuleiro + 22,
                        al_map_rgb(255, 0, 0), 8);
                }
                else if (partida.get_jogador(i)->get_preso() != 0) {
                    al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 1920 - xTabuleiro, yTabuleiro - 26, ALLEGRO_ALIGN_CENTRE, "(No xadrez!)");
                }
                yTabuleiro += 50;
                std::string dinheiroAux = "$" + std::to_string(partida.get_jogador(i)->get_quantidadeDinheiro());
                al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 1920 - xTabuleiro, yTabuleiro, ALLEGRO_ALIGN_CENTRE, dinheiroAux.c_str());
                yTabuleiro += 50;
                for (int j = 0; j < 36; j++) {
                    if (CasasNegociaveis* casaAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(j)))
                    {
                        if (casaAux->get_proprietario() == i) {
                            std::string nomeEInd;
                            if (Imovel* casaAux2 = dynamic_cast<Imovel*> (partida.get_casa(j))) {
                                std::stringstream stream;
                                stream << std::fixed << std::setprecision(1) << (indAumento[j] + 1);
                                nomeEInd = "x(" + stream.str() + ")";
                                al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 1920 - xTabuleiro - 67, yTabuleiro, ALLEGRO_ALIGN_LEFT, casaAux->get_nome().c_str());
                                al_draw_text(opensans_bold_16, al_map_rgb(0, 0, 0), 1920 - xTabuleiro + 67, yTabuleiro + 8, ALLEGRO_ALIGN_RIGHT, nomeEInd.c_str());
                            }
                            else {
                                nomeEInd = casaAux->get_nome();
                                al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 1920 - xTabuleiro, yTabuleiro, ALLEGRO_ALIGN_CENTRE, nomeEInd.c_str());
                            }
                            
                            al_draw_line(1920 - xTabuleiro - 68, yTabuleiro + 32, 1920 - xTabuleiro + 68, yTabuleiro + 32,
                                al_map_rgb(colorR[j], colorG[j], colorB[j]), 8);
                            yTabuleiro += 42;
                        }
                    }
                }
                xTabuleiro += 160;
            }

            //mudanca no dinheiro
            xTabuleiro = 324;
            yTabuleiro = 240;
            for (int i = 5; i >= 0; i--) {
                if (valorAnterior[i] != partida.get_jogador(i)->get_quantidadeDinheiro()) {
                    al_play_sample_instance(cashSoundInstance);
                    valorMudanca[i] = partida.get_jogador(i)->get_quantidadeDinheiro() - valorAnterior[i];
                    valorAnterior[i] = partida.get_jogador(i)->get_quantidadeDinheiro();
                }
                if (valorMudanca[i] != 0 && contFramesMudanca[i] < 60) {
                    std::string valorMudancaAux;
                    int colorRAux = 0, colorGAux = 0, colorBAux = 0;
                    if (valorMudanca[i] > 0) {
                        valorMudancaAux = "+$" + std::to_string(valorMudanca[i]);
                        colorRAux = 46;
                        colorGAux = 216;
                        colorBAux = 16;
                    }
                    else {
                        valorMudancaAux = "-$" + std::to_string(valorMudanca[i] * -1);
                        colorRAux = 234;
                        colorGAux = 2;
                        colorBAux = 7;
                    }
                    al_draw_text(opensans_bold_32, al_map_rgb(colorRAux, colorGAux, colorBAux), 1920 - xTabuleiro, yTabuleiro - contFramesMudanca[i], ALLEGRO_ALIGN_CENTRE, valorMudancaAux.c_str());
                    contFramesMudanca[i]++;
                }
                else {
                    valorMudanca[i] = 0;
                    contFramesMudanca[i] = 0;
                }
                xTabuleiro += 160;
            }

            //controla os dados
            if (diceOn && !fimPartida) {
                al_draw_bitmap(dice[dice1Position - 1], 1300, 1080 - throwDice, 0);
                al_draw_bitmap(dice[dice2Position - 1], 1400, 1080 - throwDice, 0);
                if (throwDice < 400) {
                    if (throwDice < 300) {
                        throwDice += 30;
                    }
                    else {
                        throwDice += 15;
                    }
                }
            }
            if (al_key_down(&keyState, ALLEGRO_KEY_C) && negociavelOn && !fimPartida) {
                if (CasasNegociaveis* casaAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(partida.get_posicao_jogador(partida.get_turno()))))
                {
                    casaAux->set_proprietario(partida.get_turno());
                    partida.get_jogador(partida.get_turno())->pagar(casaAux->get_valor_compra());
                }
                negociavelOn = false;
                allReady = true;
            }
            if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) && !fimPartida) {
                mouseOn = false;
                if (!diceStillPressed && !playerMoving ) {
                    diceStillPressed = true;
                    if (noticiaOn)
                    {   
                        partida.get_jogador(partida.get_turno())->receber_dinheiro(valor_noticia);
                        noticiaOn = false;
                        allReady = true;
                    }
                    else if (negociavelOn) {
                        negociavelOn = false;
                        allReady = true;
                    }
                    else if (!diceOn) {
                        dice1Position = partida.jogar_dados().first;
                        dice2Position = partida.jogar_dados().second;
                        diceOn = true;
                        al_play_sample_instance(diceSoundInstance);
                    }
                    else if (throwDice >= 400) {
                        casaFinal = casaAtual[partida.get_turno()];
                        casaFinal += dice1Position + dice2Position;
                        if (casaFinal >= 36) {
                            casaFinal -= 36;
                        }
                        playerMoving = true;
                        throwDice = 0;
                        diceOn = false;
                    }
                }
            }
            else {
                diceStillPressed = false;
            }

            //realiza o movimento do jogador de casa em casa
            if (playerMoving && !fimPartida) {
                if (!playerMovingAux) {
                    if (casaFinal != casaAtual[partida.get_turno()]) {
                        casaAtual[partida.get_turno()]++;
                        if (casaAtual[partida.get_turno()] == 36) {
                            partida.get_jogador(partida.get_turno())->receber_dinheiro(500);
                            for (int i = 0; i < 36; i++) {
                                if (CasasNegociaveis* casaNegociavelAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(i))) {
                                    if (casaNegociavelAux->get_proprietario() == partida.get_turno()) {
                                        indAumento[i] += 0.2;
                                    }
                                }
                            }
                            casaAtual[partida.get_turno()] = 0;
                        }
                    }
                    else {
                        partida.set_posicao_jogador(partida.get_turno(), casaAtual[partida.get_turno()]);
                        playerMoving = false;

                        if (partida.get_nome_casa(partida.get_posicao_jogador(partida.get_turno())) == "Noticia")
                        {
                            noticiaOn = true;

                            if (Noticias* noticia = dynamic_cast<Noticias*> (partida.get_casa(partida.get_posicao_jogador(partida.get_turno()))))
                            {
                                noticia->executar_noticia();
                                texto_noticia = noticia->get_texto();
                                valor_noticia = noticia->get_valor();
                                if (valor_noticia > 0) {
                                    al_play_sample_instance(you_winSoundInstance);
                                }
                                else {
                                    al_play_sample_instance(bruhSoundInstance);
                                }
                            }
                        }
                        else if (CasasEspeciais* casaEspecialAux = dynamic_cast<CasasEspeciais*> (partida.get_casa(partida.get_posicao_jogador(partida.get_turno())))) {
                            try {
                                if (partida.get_jogador(partida.get_turno())->get_posicao() == 27) al_play_sample_instance(mamamiaSoundInstance);
                                casaEspecialAux->executa(partida.get_jogador(partida.get_turno()));
                            }
                            catch (ExcecaoJogador& e) {
                                std::cout << e.what();
                            }
                            casaAtual[partida.get_turno()] = partida.get_posicao_jogador(partida.get_turno());
                            allReady = true;
                        }
                        else if (CasasNegociaveis* casaNegociavelAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(partida.get_posicao_jogador(partida.get_turno()))))
                        {
                            if (casaNegociavelAux->get_proprietario() == -1) {
                                if (partida.get_jogador(partida.get_turno())->get_quantidadeDinheiro() <= casaNegociavelAux->get_valor_compra()) {
                                    allReady = true;
                                }
                                else {
                                    negociavelOn = true;
                                }
                            }
                            else {
                                if (casaNegociavelAux->get_proprietario() != partida.get_turno()) {
                                    try {
                                        casaNegociavelAux->efetua_cobranca(partida.get_jogador(partida.get_turno()), partida.get_jogador(casaNegociavelAux->get_proprietario()), (indAumento[partida.get_jogador(partida.get_turno())->get_posicao()] + 1));
                                    }
                                    catch (ExcecaoJogador &e) {
                                        std::cout << e.what();
                                    }
                                }
                                allReady = true;
                            }
                        }
                        else {
                            allReady = true;
                        }
                    }
                }
                playerMovingAux = !playerMovingAux;
            }

            //controla o card de noticias
            if (noticiaOn && !fimPartida)
            {
                std::string textoValorNoticia;

                if (valor_noticia> 0)
                {
                    al_draw_bitmap(card_noticias[1], 288, 324, 0);
                    textoValorNoticia = "+$" + std::to_string(valor_noticia);
                }
                else
                {
                    al_draw_bitmap(card_noticias[0], 288, 324, 0);
                    textoValorNoticia = "-$" + std::to_string(valor_noticia * -1);
                }
                al_draw_multiline_text(opensans_bold_24,
                    al_map_rgb(255, 255, 255), 288 + (384 / 2), 324 + 100, 384 - 16, 32,
                    ALLEGRO_ALIGN_CENTRE, texto_noticia.c_str());

                al_draw_text(opensans_bold_48, al_map_rgb(255, 255, 255), 288 + 384 - 12, 324 + 432 - 66, ALLEGRO_ALIGN_RIGHT, textoValorNoticia.c_str());
               
            }
            else {
                al_draw_bitmap(card_noticias[2], 288, 324, 0);
            }
            
            //finaliza o turno do jogador
            if (allReady && !fimPartida)
            {
                if (partida.get_jogador(partida.get_turno())->get_quantidadeDinheiro() <= 0 && !jogadores_eliminados[partida.get_turno()]) {
                    jogadores_eliminados[partida.get_turno()] = true;
                    partida.get_jogador(partida.get_turno())->set_quantidadeDinheiro(0);
                    for (int i = 0; i < 36; i++) {
                        if (CasasNegociaveis* casaNegociavelAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(i))) {
                            if (casaNegociavelAux->get_proprietario() == partida.get_turno()) {
                                indAumento[i] = 0;
                                casaNegociavelAux->set_proprietario(-1);
                            }
                        }
                    }
                }
                int cont = 0;
                for (int i = 0; i < 6; i++) {
                    if (jogadores_eliminados[i]) {
                        cont++;
                    }
                }
                if (cont >= 5) {
                    fimPartida = true;
                    al_play_sample_instance(to_be_continuedthemeSoundInstance);
                }
                while (true) {
                    partida.novo_turno();
                    if (partida.get_turno() == 6) {
                        partida.nova_rodada();
                        partida.set_turno(0);
                    }
                    if (partida.get_jogador(partida.get_turno())->get_preso() > 0 && partida.get_jogador(partida.get_turno())->get_preso() < 3) {
                        partida.get_jogador(partida.get_turno())->set_preso(partida.get_jogador(partida.get_turno())->get_preso() + 1);
                    }
                    else if (!jogadores_eliminados[partida.get_turno()]) {
                        partida.get_jogador(partida.get_turno())->set_preso(0);
                        break;
                    }
                }
                allReady = false;
            }

           
            //controla o mouse click
            if (mouseOn && !negociavelOn && !fimPartida) {
                casaClicada = -1;
                for (int i = 0; i < 36; i++) {
                    if (xMouse >= xCasa[i] && xMouse < xCasa[i] + 192 && yMouse >= yCasa[i] && yMouse < yCasa[i] + 108) {
                        casaClicada = i;
                    }
                }
                if (casaClicada != -1 && precos[casaClicada] > 0 && casaClicada != 14 && casaClicada != 21) {
                    casa_exibida = casaClicada;
                }
                else {
                    mouseOn = false;
                }
            }

            //exibe a rodada e o turno
            std::string texto_rodada = "Rodada " + std::to_string(partida.get_rodada());
            std::string texto_nome = "Vez de " + partida.get_nome_jogador(partida.get_turno());
            al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 1920 - 208, 120, ALLEGRO_ALIGN_RIGHT, texto_rodada.c_str());
            al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 208, 120, ALLEGRO_ALIGN_LEFT, texto_nome.c_str());
            al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 1920 - 208, 1080 - 120 - 32, ALLEGRO_ALIGN_RIGHT, "Aperte (Espaco) para avancar");
            al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 208, 1080 - 120 - 32, ALLEGRO_ALIGN_LEFT, "Aperte (Esc) para encerrar o jogo");


            //mostra o card das casas e suas informacoes
            if (negociavelOn) casa_exibida = partida.get_jogador(partida.get_turno())->get_posicao();
            if (casa_exibida != -1) {
                al_draw_bitmap(blur, 0, 0, 0);
                al_draw_bitmap(card_model, 620, 340, 0);
                al_draw_filled_rounded_rectangle(620 + 680 - 140, 340 + 30, 620 + 680 - 30, 340 + 82,
                    15, 15, al_map_rgb(colorR[casa_exibida], colorG[casa_exibida], colorB[casa_exibida]));
                if (CasasNegociaveis* casaNegociavelAux = dynamic_cast<CasasNegociaveis*> (partida.get_casa(casa_exibida))) {
                    std::string valorCompraAux = "Valor de compra: $" + std::to_string(casaNegociavelAux->get_valor_compra());
                    al_draw_text(opensans_bold_48, al_map_rgb(0, 0, 0), 620 + 30, 340 + 30, 0, casaNegociavelAux->get_nome().c_str());
                    al_draw_text(opensans_bold_48, al_map_rgb(0, 0, 0), 620 + 30, 340 + 100, 0, valorCompraAux.c_str());
                    if (Acao* acaoAux = dynamic_cast<Acao*> (casaNegociavelAux)) {
                        std::string indiceDeMultiplicacaoAux = "Ind. de Multiplicacao: $" + std::to_string(((int) acaoAux->get_indiceDeMultiplicacao()));
                        al_draw_text(opensans_bold_48, al_map_rgb(0, 0, 0), 620 + 30, 340 + 170, 0, indiceDeMultiplicacaoAux.c_str());
                        al_draw_multiline_text(opensans_bold_24,
                            al_map_rgb(0, 0, 0), 620 + 30, 340 + 240, 680 - 60, 30,
                            0, "Aquele que cair nessa casa pagara ao proprietario um numero sorteado de 1 a 12 vezes o indice de multiplicacao.");
                    }
                    else {
                        if (Imovel* imovelAux = dynamic_cast<Imovel*> (casaNegociavelAux)) {
                            std::string valorAluguelAux = "Valor do aluguel: $" + std::to_string(imovelAux->get_valor_aluguel());
                            al_draw_text(opensans_bold_48, al_map_rgb(0, 0, 0), 620 + 30, 340 + 170, 0, valorAluguelAux.c_str());
                        }
                    }
                }
                if (negociavelOn) {
                    al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 620 - 30 + 680, 340 + 310, ALLEGRO_ALIGN_RIGHT, "Para comprar, pressione: (C)");
                    al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 620 - 30 + 680, 340 + 340, ALLEGRO_ALIGN_RIGHT, "Para seguir sem comprar, pressione: (Espaco)");
                }
                else {
                    al_draw_multiline_text(opensans_bold_24,
                        al_map_rgb(0, 0, 0), 620 - 30 + 680, 340 + 310, 680 - 60, 30,
                        ALLEGRO_ALIGN_RIGHT, "Para ter a opcao de comprar uma casa negociavel sem proprietario, voce precisa cair nela durante a partida.");
                }
            }

            //quando a partida acaba, esse metodo e executado
            if (fimPartida) {
                al_draw_bitmap(blur, 0, 0, 0);
                al_draw_bitmap(card_model, 620, 340, 0);
                int vencedor = 0;
                for (int i = 0; i < 6; i++) {
                    if (!jogadores_eliminados[i]) {
                        vencedor = i;
                    }
                }
                std::string vencedorAux = "Vencedor: " + partida.get_jogador(vencedor)->get_nome() + "!!";
                al_draw_text(opensans_bold_48, al_map_rgb(0, 0, 0), 620 + 30, 340 + 30, 0, "Fim de jogo!");
                al_draw_text(opensans_bold_48, al_map_rgb(0, 0, 0), 620 + 30, 340 + 100, 0, vencedorAux.c_str());
                al_draw_bitmap(players_128[vencedor], 620 + 30, 340 + 246, 0);
                al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 620 - 30 + 680, 340 + 310, ALLEGRO_ALIGN_RIGHT, "Desenvolvido por:");
                al_draw_text(opensans_bold_24, al_map_rgb(0, 0, 0), 620 - 30 + 680, 340 + 340, ALLEGRO_ALIGN_RIGHT, "A.B.F.J.L.L.");
            }

            al_flip_display();
        }
    }
    al_draw_bitmap(blueScreen, 0, 0, 0);
    al_flip_display();
    al_stop_sample_instance(themeSongInstance);
    al_play_sample_instance(shutdownSoundInstance);
    while (al_get_sample_instance_playing(shutdownSoundInstance)) {}

    //encerra todas as utilizacoes do programa
    al_destroy_display(display);
    al_destroy_font(opensans_bold_16);
    al_destroy_font(opensans_bold_24);
    al_destroy_font(opensans_bold_32);
    al_destroy_font(opensans_bold_48);
    al_destroy_sample_instance(themeSongInstance);
    al_destroy_sample_instance(diceSoundInstance);
    al_destroy_sample_instance(cashSoundInstance);
    al_destroy_sample_instance(startingSoundInstance);
    al_destroy_sample_instance(bruhSoundInstance);
    al_destroy_sample_instance(you_winSoundInstance);
    al_destroy_sample_instance(to_be_continuedthemeSoundInstance);
    al_destroy_sample_instance(mamamiaSoundInstance);
    al_destroy_sample_instance(shutdownSoundInstance);
    al_destroy_sample(themeSong);
    al_destroy_sample(diceSound);
    al_destroy_sample(cashSound);
    al_destroy_sample(startingSound);
    al_destroy_sample(bruhSound);
    al_destroy_sample(you_winSound);
    al_destroy_sample(to_be_continuedthemeSound);
    al_destroy_sample(mamamiaSound);
    al_destroy_sample(shutdownSound);
    al_destroy_timer(timer);
    al_destroy_bitmap(ps2);
    al_destroy_bitmap(blueScreen);
    for (int i = 0; i < 36; i++) {
        al_destroy_bitmap(bitmap[i]);
    }
    for (int i = 0; i < 6; i++) {
        al_destroy_bitmap(players[i]);
        al_destroy_bitmap(players_128[i]);
        al_destroy_bitmap(dice[i]);
    }
    al_destroy_bitmap(blur);
    al_destroy_bitmap(card_model);
    for (int i = 0; i < 3; i++) {
        al_destroy_bitmap(card_noticias[i]);
    }
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_uninstall_audio();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
