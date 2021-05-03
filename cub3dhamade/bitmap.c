#include "cub3d.h"

void			ft_initheader(void)
{
	ft_memcpy(g_bitmap.header, "BM", 2);
	ft_memcpy(g_bitmap.header + 2, &g_bitmap.filesize, 4);
	ft_memcpy(g_bitmap.header + 10, &g_bitmap.bfofbits, 4);
	ft_memcpy(g_bitmap.header + 14, &g_bitmap.bisize, 4);
	ft_memcpy(g_bitmap.header + 18, &g_bitmap.width, 4);
	ft_memcpy(g_bitmap.header + 22, &g_bitmap.height, 4);
	ft_memcpy(g_bitmap.header + 26, &g_bitmap.biplanes, 2);
	ft_memcpy(g_bitmap.header + 28, &g_bitmap.bitcount, 2);
	ft_memcpy(g_bitmap.header + 34, &g_bitmap.imagesize, 4);
	write(g_bitmap.fd, g_bitmap.header, 54);
}

void			init_bitmap(void)
{
	g_bitmap.width = g_win_width;
	g_bitmap.height = g_win_height;
	g_bitmap.bitcount = 24;
	g_bitmap.width_in_bytes = ((g_bitmap.width *
	g_bitmap.bitcount + 31) / 32) * 4;
	g_bitmap.imagesize = g_bitmap.width_in_bytes * g_bitmap.height;
	g_bitmap.bisize = 40;
	g_bitmap.bfofbits = 54;
	g_bitmap.filesize = 54 + g_bitmap.imagesize;
	g_bitmap.biplanes = 1;
	g_bitmap.fd = open("images.bmp", O_CREAT | O_RDWR, 0644);
	ft_initheader();
}

void			bitmapp(void)
{
	unsigned char	*buf;
	t_rgb			rgbcolor;
	int				i;
	int				row;
	int				col;

	init_bitmap();
	i = 0;
	row = g_bitmap.height;
	buf = (unsigned char *)malloc(g_bitmap.imagesize);
	while (--row >= 0)
	{
		col = -1;
		while (++col < g_bitmap.width)
		{
			rgbcolor = colorconverter(g_pxl_ptr[col + (g_win_width * i)]);
			buf[row * g_bitmap.width_in_bytes + col * 3 + 0] = rgbcolor.b;
			buf[row * g_bitmap.width_in_bytes + col * 3 + 1] = rgbcolor.g;
			buf[row * g_bitmap.width_in_bytes + col * 3 + 2] = rgbcolor.r;
		}
		i++;
	}
	write(g_bitmap.fd, (char *)buf, g_bitmap.imagesize);
	close(g_bitmap.fd);
	free(buf);
}
