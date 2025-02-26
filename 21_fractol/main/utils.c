#include "fractol.h"
#include <math.h>

void data_init(t_data *data)
{
    data->x_size = 800;
    data->y_size = 600;
    data->x_center = data->x_size / 2;
    data->y_center = data->y_size / 2;
    data->zoom = 250.0;
    //data->max_iterations = 1000;
    data->max_iterations = 20;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->x_size, data->y_size, "Fractol 42");
    data->offset_x = 0.0;  // Deslocamento horizontal no plano complexo
    data->offset_y = 0.0;   // Deslocamento vertical no plano complexo
    data->color = 0;
}

//////////////////////////////////////////////// teste leak
void free_resources(t_data *data)
{
    if (!data) // verifica se data é NULL
        return;
//    if (data->img)
    if (data->img != NULL)
    {
        mlx_destroy_image(data->mlx, data->img);
        data->img = NULL; // Set to NULL after freeing
    }
    //if (data->win)
    if (data->win != NULL) // Check if the window was created
    {
        mlx_destroy_window(data->mlx, data->win);
        data->win = NULL; // Good practice: set to NULL
    }
    //if (data->mlx)
    if (data->mlx != NULL) // Only free if mlx was initialized
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx); // 🔥 LIBERAÇÃO FINAL DO MLX
        data->mlx = NULL; // Good practice: set to NULL
        //free(data->mlx);
    }
}
/////////////////////////////////////////////////

void change_max_interations(t_data *data)
{
    char *str;
    if(data->max_iterations == 25)
    {
        data->max_iterations = 60;
        str = "max_iterations = 60\n";
    }
    else if (data->max_iterations == 60)
    {
        data->max_iterations = 150;
        str = "max_iterations = 150\n";
    }
    else if (data->max_iterations == 150)
    {
        data->max_iterations = 400;
        str = "max_iterations = 400\n";
    }
    else if (data->max_iterations == 400)
    {
        data->max_iterations = 1000;
        str = "max_iterations = 1000\n";
    }
    else if (data->max_iterations == 1000)
    {
        data->max_iterations = 5000;
        str = "max_iterations = 5000\n";
    }
    else
    {
        data->max_iterations = 25;
        str = "max_iterations = 25\n";
    }
    write(1, str, ft_strlen(str));
}

//int get_color(int iterations, int max_iterations)
int get_color(t_data *data)
{
    if (data->n_iterations == data->max_iterations)
        return 0x000000;

    double t = (double)data->n_iterations / data->max_iterations; // Normaliza as iterações para 0-1
    int r,g,b;

    if(data->color == 0) {
        r = 255 * t; //cinza
        g = 255 * t;
        b = 255 * t;
    }
    else if(data->color == 1) {
        r = 255 * t; //quentes
        g = 128 * t;
        b = 64 * t;
    }
    else if(data->color == 2) {
        r = (int)(255 * (sin(t * M_PI * 4) + 1) / 2); // Multiplicador 4 controla a frequência
        g = (int)(255 * (cos(t * M_PI * 4) + 1) / 2);
        b = (int)(255 * (sin(t * M_PI * 6) + 1) / 2); // Frequência diferente para o azul
    }
    else if(data->color == 3) {// cores frias
        r = (int)(255 * t * 0.2); // Componente vermelha baixa
        g = (int)(255 * t * 0.8); // Componente verde alta
        b = (int)(255 * t * 0.6); // Componente azul média
    }
    else if(data->color == 4) { //psicodel
        r = (int)(sin(5 * t) * 127 + 128);  // Onda de cor em vermelho
        g = (int)(sin(7 * t) * 127 + 128);  // Onda de cor em verde
        b = (int)(sin(11 * t) * 127 + 128); // Onda de cor em azul
    }
    else {//psicode 5
        r = (data->n_iterations * 9) % 256;
        g = (data->n_iterations * 2) % 256;
        b = (data->n_iterations * 5) % 256;
    }

    return (r << 16) | (g << 8) | b; //combina rgb em um valor de cor
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return (i);
}

char read_input()
{
    char c;
    if (read(0, &c, 1) == -1)
    {
        write(1, "Error to read\n", 14);
        exit (1);
    }

    // Consumir caractere extra '\n' se houver
    char temp;
    while (read(0, &temp, 1) > 0 && temp != '\n');

    return (c);
}

void define_julia_set(t_data *data)
{
    if (data->jul_set == '1')
    {
        data->jreal = -0.8;
        data->ji = 0.156;
    }
    else if (data->jul_set == '2')
    {
        data->jreal = -0.7269;
        data->ji = 0.1889;
    }
    else if (data->jul_set == '3')
    {
        data->jreal = -0.1;
        data->ji = 0.651;
    }
    else if (data->jul_set == '4')
    {
        data->jreal = -0.4;
        data->ji = 0.6;
    }
}

void julia_input(t_data *data)
{
    char *msg0, *msg1, *msg2, *msg3, *msg4;
    msg0 = "\nYou selected Julia Set.\nSelect one of the following sets:\n";
    write(1, msg0, ft_strlen(msg0));
    msg1 = "(1)\tc = -0.8 + 0.156i\n";
    write(1, msg1, ft_strlen(msg1));
    msg2 = "(2)\tc = -0.7269 + 0.1889i\n";
    write(1, msg2, ft_strlen(msg2));
    msg3 = "(3)\tc = -0.1 + 0.651i\n";
    write(1, msg3, ft_strlen(msg3));
    msg4 = "(4)\tc = -0.4 + 0.6i\n";
    write(1, msg4, ft_strlen(msg4));

    data->jul_set = read_input();
    write(1, "Digit: ", 7);
    write(1, &data->jul_set, 1);
    write(1, "\n", 1);
    if(data->jul_set != '1' && data->jul_set != '2' && data->jul_set != '3' && data->jul_set != '4')
    {
        write(1, "ERROR\n", 6);
        exit (1);
    }
    define_julia_set(data);
}

void get_input(t_data *data)
{
    char *message, *msg0;
    msg0 = "Welcome to FRACTOL\nAt the beginning you must select one type of fractal set.\nType the correspondent letter to select:\n"; 
    write(1, msg0, ft_strlen(msg0));
    message = "(J)\tJulia\n(M)\tMandelbroot\n(S)\tBurning Ship\n"; 
    write(1, message, ft_strlen(message));
    data->set = read_input();
    write(1, "Digit: ", 7);
    write(1, &data->set, 1);
    write(1, "\n", 1);
    if(data->set != 'J' && data->set != 'M' && data->set != 'S')
    {
        write(1, "ERROR\n", 6);
        exit (1);
    }
}

void put_color_to_pixel(t_data data, int x, int y, int color)
{
    int *buffer;

    buffer = data.addr;
    buffer[(y * data.line_len / 4) + x] = color;
}

void draw_fractal(t_data *data)
{
    /*if (data->set == 'M')
        make_mandelbrot(data);
    else if (data->set == 'J')
        make_julia(data);
    else if (data->set == 'S')
        make_burning_ship(data);*/
    make_fractal(data);
}