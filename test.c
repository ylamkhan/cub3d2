#include "mlx.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 200

typedef struct s_game
{
    void *mlx;
    void *win;
    int player_x;
    int player_y;
    // Ajouter une référence à la minimap
    struct s_minimap *minimap;
} t_game;

typedef struct s_minimap
{
    void *mlx;
    void *win;
    void *img;
    char *img_data;
    int bpp;
    int size_line;
    int endian;
} t_minimap;

void initialize_game(t_game *game, t_minimap *minimap)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Game Window");
    game->player_x = WINDOW_WIDTH / 2;
    game->player_y = WINDOW_HEIGHT / 2;
    game->minimap = minimap; // Assurez-vous d'avoir une référence à la minimap
}

void initialize_minimap(t_minimap *minimap)
{
    minimap->mlx = mlx_init();
    minimap->win = mlx_new_window(minimap->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT, "Minimap");
    minimap->img = mlx_new_image(minimap->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
    minimap->img_data = mlx_get_data_addr(minimap->img, &(minimap->bpp), &(minimap->size_line), &(minimap->endian));
}

void update_minimap(t_minimap *minimap, t_game *game)
{
    mlx_clear_window(minimap->mlx, minimap->win);
    mlx_pixel_put(minimap->mlx, minimap->win, game->player_x * MINIMAP_WIDTH / WINDOW_WIDTH, game->player_y * MINIMAP_HEIGHT / WINDOW_HEIGHT, 0xFFFFFF);
    mlx_put_image_to_window(minimap->mlx, minimap->win, minimap->img, 0, 0);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == 65361)
        game->player_x -= 10;
    else if (keycode == 65363)
        game->player_x += 10;
    else if (keycode == 65362)
        game->player_y -= 10;
    else if (keycode == 65364)
        game->player_y += 10;

    update_minimap(game->minimap, game);

    return 0;
}

int main(void)
{
    t_game game;
    t_minimap minimap;

    initialize_minimap(&minimap);
    initialize_game(&game, &minimap);

    mlx_hook(game.win, 2, 1L << 0, key_hook, &game);

    mlx_loop(game.mlx);

    return 0;
}
