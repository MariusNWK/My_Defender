/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** bs defender
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

enum Move {
    STOP,
    RIGHT,
    UP,
    LEFT,
    DOWN,
};

enum LeftRect {
    FROM_LEFT,
    FROM_RIGHT,
};

struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    enum Move move;
    enum LeftRect leftrect;
    sfClock *clock;
    sfClock *slow_clock;
    int hp;
    unsigned int speed;
    unsigned int poison;
    float speedf;
    sfBool launched;
    sfVector2f traj;
};

struct game_text
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    unsigned int size;
    char const *str;
};

//////////////////////////////////////////////////////

typedef struct Cell
{
    struct game_object data;
    struct Cell *next;
} list_t, cell_t;

/*lists.c*/

int is_empty_list(list_t *);
unsigned int len_list(list_t *);
list_t *add_at(list_t *, struct game_object, int);
struct game_object get_at(list_t *, int);
void set_at(list_t *, struct game_object, int);
list_t *free_at(list_t *, int);
list_t *free_list(list_t *);
void print_list(list_t *);

//////////////////////////////////////////////////////

typedef struct Clocks
{
    sfClock *deltaclock;
    sfClock *fireclock;
    sfClock *lostgoldsclock;
    sfClock *notenoughmoneyclock;
    sfClock *createclock;
    sfClock *timeclock;
} clocks_t;

typedef struct Texts
{
    struct game_text title;
    struct game_text howto;
    struct game_text gameover;
    struct game_text money;
    struct game_text lostgolds;
    struct game_text notenoughmoney;
    struct game_text knights_killed;
} texts_t;

typedef struct Audio
{
    sfMusic *music;
    sfSoundBuffer *click_buffer;
    sfSound *click;
    sfSoundBuffer *building_buffer;
    sfSound *building;
    sfSoundBuffer *hurt_buffer;
    sfSound *hurt;
    sfSoundBuffer *die_buffer;
    sfSound *die;
} audio_t;

typedef struct Storage
{
    sfVector2f mouse;
    list_t *menu;
    list_t *play;
    list_t *cases;
    list_t *cursors;
    list_t *knights;
    list_t *bars;
    list_t *proj;
    clocks_t clocks;
    float deltaseconds;
    texts_t texts;
    sfBool echap;
    sfBool display_notenoughmoney;
    int hp;
    unsigned int golds;
    unsigned int lost_golds;
    audio_t audio;
    unsigned int knights_killed;
    sfBool fivehundredskills;
    sfBool fiftykills;
} storage_t;

//////////////////////////////////////////////////////

enum Game {
    MENU,
    PLAY,
    QUIT,
};

enum Event {
    NOEVENT,
    PRESSED,
    RELEASED,
    ECHAP,
};

enum Menu {
    DEFAULT,
    HTP_TRUE,
    OPT_TRUE,
};

enum Play {
    ALIVE,
    GAMEOVER,
};

enum Holding {
    NOHOLDING,
    HOLDING_STONE,
    HOLDING_POISON,
    HOLDING_WIZARD,
    HOLDING_TESLA,
    HOLDING_MAGNUS,
};

enum TouchCase {
    FALSE,
    TRUE,
};

enum Sound {
    NOSOUND,
    CLICK,
    BUILDING,
};

enum FPS {
    THIRTY,
    SIXTY,
    HUNDREDFF,
};

enum HoldingSound {
    NO,
    YES,
};

enum Style {
    FULLSCREEN,
    WINDOWED,
    MOVE_TO_FS,
    MOVE_TO_W,
};

typedef struct Status {
    enum Game game;
    enum Event event;
    enum Menu menu;
    enum Play play;
    enum Holding hold;
    enum TouchCase touchcase;
    enum Sound sound;
    enum FPS fps;
    enum HoldingSound holdsound;
    enum Style style;
} status_t;

enum Sprites_Menu {
    HTPLAY_EMPTY,
    HTPLAY_FILLED,
    HTPLAY_PR,
    PLAY_EMPTY,
    PLAY_FILLED,
    PLAY_PR,
    QUIT_EMPTY,
    QUIT_FILLED,
    QUIT_PR,
    BACKGROUND_ONE,
    BACKGROUND_TWO,
    BACKGROUND_THREE,
    ARROW_EMPTY,
    ARROW_FILLED,
    ARROW_PR,
    OPT_EMPTY,
    OPT_FILLED,
    OPT_PR,
    MODE,
    WNDW_EMPTY,
    WNDW_FILLED,
    WNDW_PR,
    WNDW_GREEN,
    FS_EMPTY,
    FS_FILLED,
    FS_PR,
    FS_GREEN,
    FPS,
    TTY_EMPTY,
    TTY_FILLED,
    TTY_PR,
    TTY_GREEN,
    STY_EMPTY,
    STY_FILLED,
    STY_PR,
    STY_GREEN,
    HFF_EMPTY,
    HFF_FILLED,
    HFF_PR,
    HFF_GREEN,
    SOUND,
    CONE,
    TONGUE,
};

enum Sprites_Play {
    GRASS,
    RESUME_EMPTY,
    RESUME_FILLED,
    RESUME_PR,
    MENU_EMPTY,
    MENU_FILLED,
    MENU_PR,
    QUIT2_EMPTY,
    QUIT2_FILLED,
    QUIT2_PR,
    SMOKE,
    CASTLE,
    CASTLE_DESTR,
    FIRE,
    BAR,
    HP,
    TRYAG_EMPTY,
    TRYAG_FILLED,
    TRYAG_PR,
    MENU2_EMPTY,
    MENU2_FILLED,
    MENU2_PR,
    QUIT3_EMPTY,
    QUIT3_FILLED,
    QUIT3_PR,
    STONE_GREY,
    STONE_WHITE,
    POISON_GREY,
    POISON_WHITE,
    WIZARD_GREY,
    WIZARD_WHITE,
    TESLA_GREY,
    TESLA_WHITE,
    MAGNUS_GREY,
    MAGNUS_WHITE,
    GOLD_BAG,
};

enum Cursors {
    HAND,
    LSTONE,
    LPOISON,
    LWIZARD,
    LTESLA,
    LMAGNUS,
};

enum Towers {
    S1,
    S2,
    S3,
    P1,
    P2,
    P3,
    W1,
    W2,
    W3,
    T1,
    T2,
    T3,
    M1,
};

typedef struct Limits {
    float offset_x;
    float offset_y;
    float lim_x;
    float lim_y;
} limits_t;

//////////////////////////////////////////////////////

/*create_object.c*/

struct game_object create_object (const char *, sfVector2f,
sfIntRect, sfVector2f);
void apply_settings(struct game_object *);

//////////////////////////////////////////////////////

/*game.c*/

void define_status(sfRenderWindow *, status_t *, storage_t *);
void define_deltaseconds(storage_t *);
void game(void);

//////////////////////////////////////////////////////

/*display_menu.c*/

void display_background(sfRenderWindow *, status_t *, storage_t *);
void display_buttons(sfRenderWindow *, status_t *, storage_t *);
void display_text(sfRenderWindow *, status_t *, storage_t *);
void display_menu(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*creator.c*/

void create_menu_sprites(storage_t *);
void create_play_sprites(storage_t *);
clocks_t create_clocks(void);
storage_t creator(void);

//////////////////////////////////////////////////////

/*tools.c*/

sfVector2f vectorf(float, float);
sfVector2i vectori(int, int);
sfIntRect rect(int, int, int, int);
limits_t set_lim(float, float, float, float);
int is_same_rect(sfIntRect, sfIntRect);

//////////////////////////////////////////////////////

/*destroyer.c*/

void destroy_list_sprites_and_textures(list_t *);
void destroy_clocks(storage_t *);
void destroy_text(struct game_text);
void destroyer(storage_t *);

//////////////////////////////////////////////////////

/*destroy_obj.c*/

void destroy_obj_sprite_and_texture(struct game_object);
void destroy_obj_sprite_and_texture_and_clock(struct game_object);

//////////////////////////////////////////////////////

/*state_button.c*/

int does_mouse_touch_sprite(struct game_object, sfVector2f);
int state_button(sfRenderWindow *, list_t *, unsigned int, status_t *);

//////////////////////////////////////////////////////

/*create_text.c*/

struct game_text create_text(char const *, sfVector2f,
unsigned int, char const *);

//////////////////////////////////////////////////////

/*htplaystr.c*/

char const *htplay_str(void);

//////////////////////////////////////////////////////

/*display_game.c*/

void display_cases(sfRenderWindow *, status_t *, storage_t *);
void display_echap(sfRenderWindow *, status_t *, storage_t *);
void display_castle(sfRenderWindow *, status_t *, storage_t *);
void display_gameover(sfRenderWindow *, status_t *, storage_t *);
void display_game(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*create_cases_and_projectiles.c*/

typedef struct Cases_Pos {
    int initial;
    int final;
    float offset_x;
    float offset_y;
} case_t;

void add_case(storage_t *, sfVector2f, int);
void create_cases(storage_t *);

//////////////////////////////////////////////////////

/*create_echap.c*/

void create_echap(storage_t *);

//////////////////////////////////////////////////////

/*seconds_clock.c*/

float seconds_clock(sfClock *);

//////////////////////////////////////////////////////

/*create_castle.c*/

void create_castle(storage_t *);

//////////////////////////////////////////////////////

/*create_gameover.c*/

void create_gameover(storage_t *);

//////////////////////////////////////////////////////

/*is_sprite_pressed*/

sfBool is_sprite_pressed(sfRenderWindow *, list_t *, unsigned int, status_t *);

//////////////////////////////////////////////////////

/*animate_sprite*/

list_t *animate_sprite(list_t *, unsigned int, sfClock *, limits_t);

//////////////////////////////////////////////////////

/*display_sprite.c*/

void display_sprite(sfRenderWindow *, list_t *, unsigned int);

//////////////////////////////////////////////////////

/*create_shop.c*/

void create_store(storage_t *);

//////////////////////////////////////////////////////

/*display_shop.c*/

void display_store(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*uint_to_str.c*/

char *uint_to_str(unsigned int);

//////////////////////////////////////////////////////

/*my_strlen.c*/

unsigned int my_strlen(char *);

//////////////////////////////////////////////////////

/*create_menu_sprites.c*/

void create_menu_sprites(storage_t *);

//////////////////////////////////////////////////////

/*state_other.c*/

int state_case(sfRenderWindow *, storage_t *, unsigned int, status_t *);
int state_tower(sfRenderWindow *, storage_t *, unsigned int, status_t *);

//////////////////////////////////////////////////////

/*display_cases_towers_knights.c*/

void display_cases_towers_knights(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*display_knights.c*/

void display_knights_1(sfRenderWindow *, storage_t *);
void display_knights_3(sfRenderWindow *, storage_t *);
void display_knights_5(sfRenderWindow *, storage_t *);

//////////////////////////////////////////////////////

/*display_cases.c*/

void display_cases_2(sfRenderWindow *, status_t *, storage_t *);
void display_cases_4(sfRenderWindow *, status_t *, storage_t *);
void display_cases_6(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*reset.c*/

void reset(storage_t *);

//////////////////////////////////////////////////////

/*select_tower.c*/

struct game_object select_tower1(status_t *, storage_t *, int, sfVector2f);
struct game_object select_tower2(status_t *, storage_t *, int, sfVector2f);

//////////////////////////////////////////////////////

/*display_cursor.c*/

void display_cursor(sfRenderWindow *, storage_t *, status_t *);

//////////////////////////////////////////////////////

void upgrade_tower(storage_t *, int);

//////////////////////////////////////////////////////

/*check_towers_rect.c*/

void check_towers1_rect(sfIntRect *, unsigned int);
void check_towers2_rect(sfIntRect *, unsigned int);
void check_towers3_rect(sfIntRect *, unsigned int);

//////////////////////////////////////////////////////

/*which_tower_it_is*/

int which_tower_it_is(struct game_object);

//////////////////////////////////////////////////////

/*are_enough_golds.c*/

int are_enough_golds_to_buy(storage_t *, status_t *);
int are_enough_golds_to_upgrade(storage_t *, int);

//////////////////////////////////////////////////////

/*create_display_destroy_knights.c*/

void create_display_destroy_knights(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*animate_knight.c*/

void animate_knight(status_t *status, storage_t *, int, float);

//////////////////////////////////////////////////////

/*create_a_knight.c*/

void create_a_knight(storage_t *, int);

//////////////////////////////////////////////////////

/*destroy_list_sprites_and_textures_and_clock.c*/

void destroy_list_sprites_and_textures_and_clock(list_t *);

//////////////////////////////////////////////////////

/*move_knight.c*/

void move_knight(status_t *, storage_t *, int);

//////////////////////////////////////////////////////

/*manage_sprite*.c*/

void manage_sprite(status_t *, storage_t *, int);

//////////////////////////////////////////////////////

/*create_hp_bar.c*/

void create_hp_bar(storage_t *);

//////////////////////////////////////////////////////

/*destroy_knight_if_0_hp.c*/

void destroy_knight_if_0_hp(storage_t *);

//////////////////////////////////////////////////////

/*create_projectiles.c*/

void create_projectiles(storage_t *);

//////////////////////////////////////////////////////

/*hp_bars_position.c*/

void hp_bars_position(storage_t *, int, struct game_object);

//////////////////////////////////////////////////////

void define_projectile(storage_t *, int, struct game_object);

//////////////////////////////////////////////////////

/*display_projectiles*/

void display_projectiles(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*redef_pos_case.c*/

sfVector2f redef_pos(sfVector2f pos, float, float);
sfVector2f redef_pos_case(sfVector2f, int);

//////////////////////////////////////////////////////

/*is_knight_in_range.c*/

int is_knight_in_range(struct game_object, struct game_object);

//////////////////////////////////////////////////////

/*define_traj.c*/

sfVector2f define_traj(struct game_object, struct game_object);

//////////////////////////////////////////////////////

/*is_proj_out_of_map*/

int is_proj_out_of_map(struct game_object);

//////////////////////////////////////////////////////

/*reset_proj.c*/

struct game_object reset_proj(struct game_object proj,
struct game_object a_case);

//////////////////////////////////////////////////////

/*does_proj_touch_knight*/

int does_proj_touch_knight(struct game_object, struct game_object);

//////////////////////////////////////////////////////

/*apply_effects.c*/

struct game_object apply_effects(struct game_object, struct game_object);

//////////////////////////////////////////////////////

/*create_audio.c*/

void create_audio(storage_t *);

//////////////////////////////////////////////////////

/*sound_effect.c*/

void sound_effect(status_t *, storage_t *);

//////////////////////////////////////////////////////

/*display_knights_killed_nbr*/

void display_knights_killed_nbr(sfRenderWindow *, storage_t *);

//////////////////////////////////////////////////////

/*display_options*/

void display_options(sfRenderWindow *, status_t *, storage_t *);

//////////////////////////////////////////////////////

/*set_fps.c*/

int set_fps(status_t *);

//////////////////////////////////////////////////////