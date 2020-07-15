/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:38:38 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/15 20:12:10 by clostao-         ###   ########.fr       */
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
        else if (!strncmp(line, "ci", 2))
            insert_circle(line, scene);
        else
            throw("Error in config file");
}

t_scene read_file(const char *filename)
{
    int         fd;
    int         read;
    char        *line;
    t_scene     scene;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        throw("File doesn't exist");
    read = 1;
    while (read)
    {
        read = get_next_line(fd, &line);
        if (read == -1)
            throw ("Error during reading file (gnl problem)");
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
    return (scene);
}

void    init_minilib_settings(t_scene *scene)
{
    t_camera_list   *list;
    void            **images;
    size_t          length;

    scene->minilib.session = mlx_init();
    list = scene->cameras;
    while (list->next)
    {
        list = list->next;
        length++;
    }
    scene->minilib.images = calloc(length, sizeof(void *));
    images = scene->minilib.images;
    while (length-- > 0)
    {
        (*images) = mlx_new_image(scene->minilib.session, scene->screen.x, scene->screen.y);
        images++;
    }
    
}

void    check_configuration_errors(t_scene scene)
{
    if (scene.screen.x == 0 && scene.screen.y == 0)
        throw ("Resoultion config error, likely is missing.");
    if (scene.cameras == 0)
        throw ("Camera hasn't been configurated.");
}

t_scene read_scene_from_file(int argc, char **argv)
{
    t_scene scene;
    if (argc < 2 || argc > 3)
        throw ("The args number isn't correct");
    if (argc == 3)
        if (!strcmp(argv[2], "--save"))
            scene.file = strdup("image.bmp");
        else
            throw ("The second argument only could be '--save' for saving the image in a file");
    else
        scene.file = 0;
    scene = read_file(argv[1]);
    check_configuration_errors(scene);
    init_minilib_settings(&scene);
    return (scene);
}