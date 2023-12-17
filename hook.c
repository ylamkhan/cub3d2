#include"cub3d.h"
extern int worldMap[map_width][map_height];

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

extern  int worldMap[map_width][map_height];

int key_press_1(int keycode, t_data *data)
{
    printf("Key pressed: %d\n", keycode);

    // Update the player's position based on the pressed key
    // float posx = data->posx;
    // float posy = data->posy;

    // Adjust the position based on the pressed key
    if (keycode == 13) // W key - Move forward
        data->posy -= DX;
    else if (keycode == 1) // S key - Move backward
        data->posy += DX;        
    else if (keycode == 0) // A key - Rotate left
        data->posx -= DX; // Adjust the rotation angle as needed
    else if (keycode == 2) // D key - Rotate right
		data->posx += DX;
		// Update the player's position
    game_loop1(data);
    return 0;
}
int	key_press(int keycode, t_data *d)
{
	printf("Key pressed: %d\n", keycode);
	if(keycode==13||keycode==1||keycode==0||keycode==2)
        key_press_1(keycode, d);
    else if(keycode == 53)
        close_window(d);
	else if (keycode == 124)
	{
        d->angle += 30.0;
        if(d->angle>=360)
            d->angle = (int)d->angle%360;
		game_loop1(d);
	}
	else if (keycode == 123)
	{
		d->angle += -30.0;
        if(d->angle<=-360)
            d->angle = (int)d->angle%360;
		game_loop1(d);
	}
	return (0);
}