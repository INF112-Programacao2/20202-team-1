// BancoAllegro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include "Partida.h"

int main()
{
    Partida partida;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_BITMAP* bitmap[36];
    for (int i = 0; i < 36; i++) {
        bitmap[i] = NULL;
    }
    ALLEGRO_BITMAP* players[6];
    ALLEGRO_BITMAP* dice[6];
    for (int i = 0; i < 6; i++) {
        players[i] = NULL;
        dice[i] = NULL;
    }
    ALLEGRO_BITMAP* blur = NULL;
    ALLEGRO_BITMAP* card_model = NULL;
    ALLEGRO_BITMAP* card_noticias[3];
    for (int i = 0; i < 3; i++) {
        card_noticias[i] = NULL;
    }

    al_init();

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

    //al_set_window_position(display, 0, 0);
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

    ALLEGRO_FONT* opensans_bold_24 = al_load_ttf_font("OpenSans-Bold.ttf", 24, 0);
    ALLEGRO_FONT* opensans_bold_32 = al_load_ttf_font("OpenSans-Bold.ttf", 32, 0);
    ALLEGRO_FONT* opensans_bold_48 = al_load_ttf_font("OpenSans-Bold.ttf", 48, 0);

    ALLEGRO_SAMPLE* themeSong = NULL;
    ALLEGRO_SAMPLE_INSTANCE* themeSongInstance = NULL;

    al_reserve_samples(1);
    themeSong = al_load_sample("sound/MiiPlaza.mp3");

    themeSongInstance = al_create_sample_instance(themeSong);
    al_attach_sample_instance_to_mixer(themeSongInstance, al_get_default_mixer());

    for (int i = 0; i < 36; i ++) {
        bitmap[i] = al_load_bitmap(partida.get_foto_casa(i).c_str());
    }

    for (int i = 0; i < 6; i++) {
        players[i] = al_load_bitmap(partida.get_foto_jogador(i).c_str());
    }

    dice[0] = al_load_bitmap("img/dice1.png");
    dice[1] = al_load_bitmap("img/dice2.png");
    dice[2] = al_load_bitmap("img/dice3.png");
    dice[3] = al_load_bitmap("img/dice4.png");
    dice[4] = al_load_bitmap("img/dice5.png");
    dice[5] = al_load_bitmap("img/dice6.png");

    blur = al_load_bitmap("img/blur.png");
    card_model = al_load_bitmap("img/card_model.png");
    card_noticias[0] = al_load_bitmap("img/noticias_down_model.png");
    card_noticias[1] = al_load_bitmap("img/noticias_up_model.png");
    card_noticias[2] = al_load_bitmap("img/noticias_back.png");

    int precos[36];
    for (int i = 0; i < 36; i++) {
        precos[i] = 100 * (i + 1);
    }
    precos[0] = precos[6] = precos[9] = precos[10] = precos[18] = precos[22] = precos[25] = precos[27] = precos[29] = 0;
    precos[14] = precos[21] = 2000;
    assert (bitmap != NULL);

    bool running = true, diceOn = false, diceStillPressed = false, playerMoving = false, playerMovingAux = false;
    bool mouseOn = false, allReady = false, noticiaOn = false;
    float x = 0, y = 0;
    int width = al_get_display_width(display);
    int dice1Position = 0, dice2Position = 0, throwDice = 0, casaFinal = 0;
    int xMouse = 0, yMouse = 0;
    int casaClicada = -1;
    std::string texto_noticia = "";
    int valor_noticia = 0;

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
   
    al_set_sample_instance_playmode(themeSongInstance, ALLEGRO_PLAYMODE_LOOP);
    al_play_sample_instance(themeSongInstance);
    al_start_timer(timer);
    while (running) {
        
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }

        //mouse
        /*if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            x = event.mouse.x;
            y = event.mouse.y;
        }

        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            x = y = 0;
            al_set_mouse_xy(display, 0,0);
        }*/
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

        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
            int xTabuleiro = 1920 - 192;
            int yTabuleiro = 1080 - 108;
            for (int i = 0; i < 36; i++) {
                al_draw_bitmap(bitmap[i], xCasa[i], yCasa[i], 0);
                if (precos[i] > 0) {
                    std::string tmp = "$" + std::to_string(precos[i]);
                    if (i == 14) tmp = "+" + tmp + " ";
                    if (i == 21) tmp = "-" + tmp + " ";
                    al_draw_text(opensans_bold_32, al_map_rgb(255, 255, 255), xCasa[i] + 96, yCasa[i] + 65, ALLEGRO_ALIGN_CENTRE, tmp.c_str());
                }
                if (i != 0 && i != 3 && i != 6 && i != 9 && i != 10 && i != 12 && i != 14 && i != 18 && i != 20 && i != 21 && i != 22 && i !=25 && i != 27 && i !=  29 && i != 33)
                {
                    al_draw_text(opensans_bold_32, al_map_rgb(255, 255, 255), xCasa[i] + 96, yCasa[i], ALLEGRO_ALIGN_CENTRE, partida.get_nome_casa(i).c_str());
                }
            }

            //players
            xTabuleiro = 0;
            for (int i = 5; i >= 0; i--) {
                al_draw_bitmap(players[i], xCasa[casaAtual[i]] + 192 - 64 - 4 - xTabuleiro, yCasa[casaAtual[i]] + 22, 0);
                xTabuleiro += 24;
            }

            //dices
            if (diceOn) {
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
            if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
                if (!diceStillPressed && !playerMoving ) {
                    diceStillPressed = true;
                    if (noticiaOn)
                    {   
                        noticiaOn = false;
                        allReady = true;
                    }
                    else
                    {
                        if (!diceOn) {
                            dice1Position = partida.jogar_dados().first;
                            dice2Position = partida.jogar_dados().second;
                            diceOn = true;
                        }
                        else {
                            if (throwDice >= 400) {
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
                    
                }
            }
            else {
                diceStillPressed = false;
            }

            if (playerMoving) {
                if (!playerMovingAux) {
                    if (casaFinal != casaAtual[partida.get_turno()]) {
                        casaAtual[partida.get_turno()]++;
                        if (casaAtual[partida.get_turno()] == 36) {
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
                            }
                        }
                        else
                        {
                            allReady = true;
                        }
                    }
                }
                playerMovingAux = !playerMovingAux;
            }

            //card noticias
           
            if (noticiaOn)
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
            
            //Finaliza o Turno do Jogador
            if (allReady)
            {
                partida.novo_turno();
                if (partida.get_turno() == 6) {
                    partida.nova_rodada();
                    partida.set_turno(0);
                }
                allReady = false;
            }

           
            //mouse click
            if (mouseOn) {
                casaClicada = -1;
                for (int i = 0; i < 36; i++) {
                    if (xMouse >= xCasa[i] && xMouse < xCasa[i] + 192 && yMouse >= yCasa[i] && yMouse < yCasa[i] + 108) {
                        casaClicada = i;
                    }
                }
                if (casaClicada != -1 && precos[casaClicada] > 0 && casaClicada != 14 && casaClicada != 21) {
                    al_draw_bitmap(blur, 0, 0, 0);
                    al_draw_bitmap(card_model, 717, 216, 0);
                    std::string tmp2 = "$" + std::to_string(precos[casaClicada]);
                    al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 864 + 96, 486 + 65, ALLEGRO_ALIGN_CENTRE, tmp2.c_str());
                }
                else {
                    mouseOn = false;
                }
            }

            std::string texto_rodada = "Rodada " + std::to_string(partida.get_rodada());
            std::string texto_nome = "Vez de " + partida.get_nome_jogador(partida.get_turno());
            al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 1920 - 208, 120, ALLEGRO_ALIGN_RIGHT, texto_rodada.c_str());
            al_draw_text(opensans_bold_32, al_map_rgb(0, 0, 0), 208, 120, ALLEGRO_ALIGN_LEFT, texto_nome.c_str());

            al_flip_display();
        }
    }

    al_destroy_display(display);
    al_destroy_font(opensans_bold_24);
    al_destroy_font(opensans_bold_32);
    al_destroy_font(opensans_bold_48);
    al_destroy_sample_instance(themeSongInstance);
    al_destroy_sample(themeSong);
    al_destroy_timer(timer);
    for (int i = 0; i < 36; i++) {
        al_destroy_bitmap(bitmap[i]);
    }
    for (int i = 0; i < 6; i++) {
        al_destroy_bitmap(players[i]);
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
