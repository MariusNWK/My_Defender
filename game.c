/*
** EPITECH PROJECT, 2021
** game
** File description:
** main structure of the game
*/

#include "include/my.h"

void define_status(sfRenderWindow *window, status_t *status, storage_t *storage)
{
    define_deltaseconds(storage);
    switch (status->game) {
        case MENU:
            display_menu(window, status, storage);
            break;
        case PLAY:
            display_game(window, status, storage);
            break;
        case QUIT:
            sfRenderWindow_close(window);
            break;
        default:
            break;
    }
    display_cursor(window, storage, status);
    if (status->event != PRESSED)
        status->event = NOEVENT;
    sound_effect(status, storage);
}

void define_deltaseconds(storage_t *storage)
{
    sfTime time = sfClock_getElapsedTime(storage->clocks.deltaclock);

    storage->deltaseconds = time.microseconds / 1000000.0;
    sfClock_restart(storage->clocks.deltaclock);
}

void analyse_events(sfRenderWindow *window, sfEvent *event, status_t *status)
{
    switch (event->type) {
        case sfEvtKeyPressed:
            if (event->key.code == sfKeyQ)
                status->game = QUIT;
            if (event->key.code == sfKeyEscape)
                status->event = ECHAP;
            break;
        case sfEvtMouseButtonPressed:
            if (event->mouseButton.button == sfMouseLeft)
                status->event = PRESSED;
            break;
        case sfEvtMouseButtonReleased:
            if (event->mouseButton.button == sfMouseLeft)
                status->event = RELEASED;
            break;
        default:
            break;
    }
}

sfRenderWindow *define_window(sfRenderWindow *window, status_t *status)
{
    if (status->style == MOVE_TO_FS) {
        sfRenderWindow_destroy(window);
        window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Defender", sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(window, set_fps(status));
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        status->style = FULLSCREEN;
    }
    if (status->style == MOVE_TO_W) {
        sfRenderWindow_destroy(window);
        window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Defender", sfTitlebar, NULL);
        sfRenderWindow_setFramerateLimit(window, set_fps(status));
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        status->style = WINDOWED;
    }
    return (window);
}

void game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Defender",
    sfFullscreen, NULL);
    storage_t storage = creator();
    status_t status = {MENU, NOEVENT, DEFAULT,
    ALIVE, NOHOLDING, FALSE, NOSOUND, SIXTY, NO, FULLSCREEN};
    sfEvent event;

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfMusic_setLoop(storage.audio.music, sfTrue);
    sfMusic_play(storage.audio.music);
    while (sfRenderWindow_isOpen(window = define_window(window, &status))) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, &event, &status);
        define_status(window, &status, &storage);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
    destroyer(&storage);
}