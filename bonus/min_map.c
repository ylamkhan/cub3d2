// #include "cub3d_bonus.h"

// void my_mlx_pixel_put(t_data **data, int x, int y, int color)
// {
//     char *dst = mlx_get_data_addr((*data)->img.img_ptr, &(*data)->img.bpp, &(*data)->img.size_l, &(*data)->img.endian);
//     *(unsigned int *)(dst + (y * (*data)->img.size_l + x * ((*data)->img.bpp / 8))) = color;
// }

// void min_map(t_data **d)
// {
//     int i=0;

    
//     while(i<(*d)->map_width)
//     {
//         int j=0;
//         while(j<(*d)->map_height)
//         {
//             if((*d)->world_map[i][j]==1)
//             {
//                 int i1 = i*20;
//                 while (i1<(i+1)*20 && i1<20*(*d)->map_width)
//                 {
//                     int j1 = j*20;
//                     while (j1<(j+1)*20 && j1<(*d)->map_height)
//                     {
//                         if (j1==(j+1)*20 - 1 || j1 == 0 || i1==(i+1)*20-1 || i1==0)
//                             my_mlx_pixel_put(d, i1, j1,0x000000);
//                         else
//                             my_mlx_pixel_put(d, i1, j1,0xFFFFFF);
//                         j1++;
//                     }
//                     i1++;   
//                 } 
//             }
//             else if((*d)->world_map[i][j]==0)
//             {
//                 int i1 = i*20;
//                 while (i1<(i+1)*20 && i1<20*(*d)->map_width)
//                 {
//                     int j1 = j*20;
//                     while (j1<(j+1)*20 && j1<20*(*d)->map_width)
//                     {
//                         if (j1==(j+1)*20 - 1 || j1 == 0 || i1==(i+1)*20-1 || i1==0)
//                             my_mlx_pixel_put(d, i1, j1,0x000000);
//                         else
//                             my_mlx_pixel_put(d, i1, j1,0x808080);
//                         j1++;
//                     }
//                     i1++;   
//                 }
//             }
//             j++;
//         }
//         i++;
//     }
// }