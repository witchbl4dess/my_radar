/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-radar-menzo.smit-adam
** File description:
** radar.h
*/

#ifndef B_MUL_100_NCE_1_1_MYRADAR_MENZO_SMIT_ADAM_RADAR_H
    #define B_MUL_100_NCE_1_1_MYRADAR_MENZO_SMIT_ADAM_RADAR_H

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "fcntl.h"
    #include "stdbool.h"
    #include "unistd.h"
    #include <math.h>

    #define HEIGHT 1080
    #define WIDTH 1920
    #define FPS 30
    #define MAX_PLANES 1

typedef struct window_s {
    sfRenderWindow* window;
    sfVideoMode mode;
    sfEvent event;
    sfSprite* background;
    sfTexture* texture;
    unsigned int width;
    unsigned int height;
} window_t;

typedef struct node_plane {
    sfSprite *sprite;
    sfVector2f posdeparture;
    sfVector2f posarrival;
    sfVector2f position;
    sfRectangleShape *rect;
    bool is_active_rect;
    bool is_visible;
    int speed;
    bool depart;
    int delay;
    bool protection;
    struct node_plane *next;
} node_plane;

typedef struct plane_list {
    node_plane *head;
} plane_list_t;

typedef struct node_tower {
    sfSprite *sprite;
    sfVector2f position;
    sfCircleShape *circle;
    bool is_active_circle;
    bool is_visible;
    int radius;
    struct node_tower *next;
} node_tower;

typedef struct List {
    node_tower *head;
} list_tower;

window_t *create_window(void);
void destroy_window(window_t *window);
void load_bg(sfTexture **backgroundTexture, sfSprite **backgroundSprite);
void display_usage(void);
int cols_len(const char *filepath);
int rows_len(const char *filepath);
int check_args(int ac, char **av);
void print_map(char **map, int rows, int cols);
void setup_tower(list_tower *li, char **argv, int argc);
char **load_2d_arr_from_file(char *filepath, int rows, int cols);
char **my_str_to_word_array(char *str);
void setup_planes(plane_list_t *li, char **argv, int argc);
void toggleevent(sfEvent event, sfRenderWindow *window, plane_list_t *planes,
    list_tower *li);
void septemberplane(plane_list_t *planes, sfClock *clock1, sfClock *clock2);
void handle_events(window_t *window, plane_list_t *planes,
    list_tower *listower);
void render(window_t *window, sfSprite *backgroundSprite, list_tower *listower,
    plane_list_t *planes);
void update_planes(plane_list_t *planes, sfClock *clock, sfClock *clock2);
void planefucker(node_plane *plane, plane_list_t *planes);
void collisioninter(plane_list_t *planes);
void colision(plane_list_t *planes, list_tower *listower);
void handle_tower_collision(node_plane *plane, node_tower *tower);



#endif //B_MUL_100_NCE_1_1_MYRADAR_MENZO_SMIT_ADAM_RADAR_H
