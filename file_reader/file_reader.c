/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:38:38 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/14 18:50:10 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

void insert_figure(char *line, t_scene *scene)
{
        if (!strncmp(line, "sp", 2))
            insert_sphere(line, scene);
        else if (!strncmp(line, "pl", 2))
            insert_plane(line, scene);
        else if (!strncmp(line, "cy", 2))
            insert_cylinder(line, scene);
        else if (!strncmp(line, "tr", 2))
            insert_triangle(line, scene);
        else if (!strncmp(line, "sq", 2))
            insert_square(line, scene);
        else
            throw("Error in config file");
}

t_scene read_file(const char *filename)
{
    int         fd;
    int         read;
    char        *line;
    t_scene     scene;

    fd = open(filename, O_WRONLY);
    if (fd == -1)
        throw("File doesn't exist");
    while (read)
    {
        get_next_line(fd, &line);
        if (!strncmp(line, "R", 1))
            insert_resolution(line, &scene);
        else if (!strncmp(line, "A", 1))
            insert_ambient_light(line, &scene);
        else if (!strncmp(line, "c", 1))
            insert_camera(line, &scene);
        else if (!strncmp(line, "l", 1))
            insert_light(line, &scene);
        else
            insert_figure(line, &scene);
    }
}

t_scene read_scene_from_file(int argc, char **argv)
{
    t_scene scene;
    if (argc < 2 || argc > 3)
        throw("El número de argumentos es incorrecto");
    if (argc == 3)
        scene.file = strdup("image.bmp");
    else
        scene.file = 0;
    scene = read_file(argv[1]);
    return (scene);
}