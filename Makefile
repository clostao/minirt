default: 	./camera_controller/camera_controller.c ./camera_controller/ray_calculation/base_calculations.c ./camera_controller/ray_calculation/matrix_utils.c ./color_calculation/color_calculation.c ./color_calculation/color_tools.c ./color_calculation/ray_calculation.c ./coordenates_utils/point_tools.c ./coordenates_utils/vector_tools.c ./main/main.c ./object_collision/circle_collide.c ./object_collision/cylinder_collide.c ./object_collision/cylinder_collide_2.c ./object_collision/equation_solver.c ./object_collision/microtools.c ./object_collision/plane_collide.c ./object_collision/polinomial_tools.c ./object_collision/polinomial_tools2.c ./object_collision/sphere_collide.c ./scene_reader/scene_reader.c ./screen_controller/screen_printer.c
			gcc ./camera_controller/camera_controller.c ./camera_controller/ray_calculation/base_calculations.c ./camera_controller/ray_calculation/matrix_utils.c ./color_calculation/color_calculation.c ./color_calculation/color_tools.c ./color_calculation/ray_calculation.c ./coordenates_utils/point_tools.c ./coordenates_utils/vector_tools.c ./main/main.c ./object_collision/circle_collide.c ./object_collision/cylinder_collide.c ./object_collision/cylinder_collide_2.c ./object_collision/equation_solver.c ./object_collision/microtools.c ./object_collision/plane_collide.c ./object_collision/polinomial_tools.c ./object_collision/polinomial_tools2.c ./object_collision/sphere_collide.c ./scene_reader/scene_reader.c ./screen_controller/screen_printer.c -lmlx -framework OpenGL -framework AppKit -lz