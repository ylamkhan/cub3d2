#include <mlx.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_data {
    void *mlx_ptr;
    void *mlx_win;
    void	*img;
	int 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    int *dst =(int *) mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    *(unsigned int *)(dst + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
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
    double arrow_length = 15.0;

    int arrow1_x = x2 - arrow_length * cos(angle + M_PI / 6);
    int arrow1_y = y2 - arrow_length * sin(angle + M_PI / 6);

    int arrow2_x = x2 - arrow_length * cos(angle - M_PI / 6);
    int arrow2_y = y2 - arrow_length * sin(angle - M_PI / 6);

    draw_line(data, x2, y2, arrow1_x, arrow1_y, color);
    draw_line(data, x2, y2, arrow2_x, arrow2_y, color);
}

void rotate_point(double *x, double *y, double angle)
{
    double new_x = (*x) * cos(angle) - (*y) * sin(angle);
    double new_y = (*x) * sin(angle) + (*y) * cos(angle);

    *x = new_x;
    *y = new_y;
}

void rotate_arrow(t_data *data, int x1, int y1, int x2, int y2, double angle, int color)
{
    // Rotate the coordinates of the arrowhead points
    rotate_point(&x2, &y2, angle + M_PI / 6);
    draw_line(data, x1, y1, x2, y2, color);

    rotate_point(&x2, &y2, -2 * (angle + M_PI / 6));
    draw_line(data, x1, y1, x2, y2, color);
}

int main()
{
    t_data data;
    data.mlx_ptr = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_ptr, 800, 600, "Rotated Arrow Drawing");

    // Create an image (you need to modify this part based on your program structure)
    data.img = mlx_new_image(data.mlx_ptr, 800, 600);
    data.bits_per_pixel = 32; // Assuming 32 bits per pixel
    data.line_length = 800 * 4; // Assuming 4 bytes per pixel
    data.endian = 0; // Little endian

    // Example: Draw a rotated arrow from (100, 100) to (400, 300) with color 0xFFFFFF (white)
    double angle = M_PI / 4; // Rotation angle in radians
    draw_arrow(&data, 100, 100, 400, 300, 0xFFFFFF);
    rotate_arrow(&data, 100, 100, 400, 300, angle, 0xFFFFFF);

    // Display the image in the window
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);

    mlx_loop(data.mlx_ptr);

    return 0;
}
