#include"cub3d.h"

 int worldMap[map_width][map_height]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,0,0,0,0,1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
t_data	*ft_init(t_data *t)
{
    t->move_speed =5.0;
    t->direction = 0.0;
    t->angle = 0.0;
    return t;
}


void draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(data, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_arrow(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    // Draw the line
    draw_line(data, x1, y1, x2, y2, color);

    // Draw arrowheads
    double angle = atan2(y2 - y1, x2 - x1);
    double arrow_length = 10.0; // You can adjust the length of the arrowheads

    int arrow1_x = x2 - arrow_length * cos(angle + M_PI / 6);
    int arrow1_y = y2 - arrow_length * sin(angle + M_PI / 6);

    int arrow2_x = x2 - arrow_length * cos(angle - M_PI / 6);
    int arrow2_y = y2 - arrow_length * sin(angle - M_PI / 6);

    draw_line(data, x2, y2, arrow1_x, arrow1_y, color);
    draw_line(data, x2, y2, arrow2_x, arrow2_y, color);
}
void draw_player(t_data **data, int radius, int color)
{
    int cx = (int)(*data)->posx;
    int cy = (int)(*data)->posy;

    for (int x = cx - radius; x <= cx + radius; x++)
    {
        for (int y = cy - radius; y <= cy + radius; y++)
        {
            int dx = x - cx;
            int dy = y - cy;
            if (dx * dx + dy * dy <= radius * radius)
            {
                my_mlx_pixel_put((*data), x, y, color);
            }
        }
    }
    if((*data)->angle<0)
    {
        //printf("******%f*****\n",(*data)->angle);
        (*data)->dirx = (*data)->posx + sin((*data)->angle) * 30;
        (*data)->diry= (*data)->posy + cos((*data)->angle) * 30;
    }
    if((*data)->angle>0)
    {
        //printf("******%f*****\n",(*data)->angle);
        (*data)->dirx = (*data)->posx - sin((*data)->angle) * 30;
        (*data)->diry= (*data)->posy - cos((*data)->angle) * 30;
    }
    draw_arrow(*data, (*data)->posx, (*data)->posy, (*data)->dirx, (*data)->diry, color);
    // (*data)->r_angle = (*data)->angle-30;
    // (*data)->inc_angle = 10;
    // while((*data)->r_angle < (*data)->angle)
    // {
    //     printf("***********%f###############\n",(*data)->r_angle);
    //     (*data)->dirx = (*data)->posx - sin((*data)->r_angle) * 30;
    //     (*data)->diry= (*data)->posy - cos((*data)->r_angle) * 30;
    //     draw_line(*data, (*data)->posx, (*data)->posy, (*data)->dirx, (*data)->diry, color);
    //     (*data)->r_angle += (*data)->inc_angle;
    // }

}
void game_loop1(t_data *d)
{
    int i=0;
    while(i<24)
    {
        int j=0;
        while(j<24)
        {
            if(worldMap[i][j]==1)
            {
                int i1 = i*30;
                while (i1<(i+1)*30 && i1<720)
                {
                    int j1 = j*30;
                    while (j1<(j+1)*30 && j1<720)
                    {
                        if (j1==(j+1)*30 - 1 || j1 == 0 || i1==(i+1)*30-1 || i1==0)
                            my_mlx_pixel_put(d, i1, j1,0x000000);
                        else
                            my_mlx_pixel_put(d, i1, j1,0xFFFFFF);
                        j1++;
                    }
                    i1++;   
                } 
            }
            else if(worldMap[i][j]==0 || worldMap[i][j]==4)
            {
                int i1 = i*30;
                while (i1<(i+1)*30 && i1<720)
                {
                    int j1 = j*30;
                    while (j1<(j+1)*30 && j1<720)
                    {
                        if (j1==(j+1)*30 - 1 || j1 == 0 || i1==(i+1)*30-1 || i1==0)
                            my_mlx_pixel_put(d, i1, j1,0x000000);
                        else
                            my_mlx_pixel_put(d, i1, j1,0x808080);
                        j1++;
                    }
                    i1++;   
                }
            }
            j++;
        }
        i++;
    }
    draw_player(&d, 5, 0xFF0000);
    mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img, 0, 0);
}
void game_loop(t_data *d)
{
    int i=0;
    while(i<24)
    {
        int j=0;
        while(j<24)
        {
            if(worldMap[i][j]==1)
            {
                int i1 = i*30;
                while (i1<(i+1)*30 && i1<720)
                {
                    int j1 = j*30;
                    while (j1<(j+1)*30 && j1<720)
                    {
                        if (j1==(j+1)*30 - 1 || j1 == 0 || i1==(i+1)*30-1 || i1==0)
                            my_mlx_pixel_put(d, i1, j1,0x000000);
                        else
                            my_mlx_pixel_put(d, i1, j1,0xFFFFFF);
                        j1++;
                    }
                    i1++;   
                } 
            }
            else if(worldMap[i][j]==0 || worldMap[i][j]==4)
            {
                int i1 = i*30;
                while (i1<(i+1)*30 && i1<720)
                {
                    int j1 = j*30;
                    while (j1<(j+1)*30 && j1<720)
                    {
                        if (j1==(j+1)*30 - 1 || j1 == 0 || i1==(i+1)*30-1 || i1==0)
                            my_mlx_pixel_put(d, i1, j1,0x000000);
                        else
                            my_mlx_pixel_put(d, i1, j1,0x808080);
                        j1++;
                    }
                    i1++;   
                }
            }
            if (worldMap[i][j]==4)
            {
                d->posx = i*30+16;
                d->posy = j*30+16;
                d->direction = 4.0;
            }
            j++;
        }
        i++;
    }
    d->diry=d->posy+30;
    d->dirx=d->posx;
    draw_player(&d, 5, 0xFF0000);
    mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img, 0, 0);
}

int close_window(t_data *data)
{
{
	(void)data;
	exit(0);
	return (0);
}
}
void	raycasting(t_data *t)
{
	t = ft_init(t);
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, WIDTH, HEIGH, "map");
	t->img = mlx_new_image(t->mlx_ptr, WIDTH, HEIGH);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length, &t->endian);
    mlx_key_hook(t->mlx_win, key_press, t);	//mlx_mouse_hook(t->mlx_win, ft_mouse_hook2, t);
	mlx_hook(t->mlx_win, 17, 0, close_window, t);
	//mlx_hook(t->mlx_win, 2, 0, key_press, t);
	game_loop(t);
	mlx_loop(t->mlx_ptr);
}
int main()
{
    t_data  *d;

    d = malloc(sizeof(t_data));
    if (!d)
        return 0;
    raycasting(d);
}