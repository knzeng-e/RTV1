all:
	make -C ./scene_all/
	make -C ./scene_cone/
	make -C ./scene_cylinder/
	make -C ./scene_sphere/
	make -C ./scene_plane/
	make -C ./scene_global_illumination/

clean:
	make -C ./scene_all/ clean
	make -C ./scene_cone/ clean
	make -C ./scene_cylinder/ clean
	make -C ./scene_sphere/ clean
	make -C ./scene_plane/ clean
	make -C ./scene_global_illumination/ clean

fclean:
	make -C ./scene_all/ fclean
	make -C ./scene_cone/ fclean
	make -C ./scene_cylinder/ fclean
	make -C ./scene_sphere/ fclean
	make -C ./scene_plane/ fclean
	make -C ./scene_global_illumination/ fclean

norme :
	make -C ./scene_all/ norme
	make -C ./scene_cone/ norme
	make -C ./scene_cylinder/ norme
	make -C ./scene_sphere/ norme
	make -C ./scene_plane/ norme
	make -C ./scene_global_illumination/ norme

re: 
	make -C ./scene_all/ re
	make -C ./scene_cone/ re
	make -C ./scene_cylinder/ re
	make -C ./scene_sphere/ re
	make -C ./scene_plane/ re
	make -C ./scene_global_illumination/ re

.PHONY : all clean fclean norme re
