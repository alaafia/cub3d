# cub3d
Cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.

Description :

    You must create a “realistic” 3D graphical representation of the inside of a maze from a first person perspective. 
    You have to create this representation using the Ray-Casting principles mentioned earlier.

Authorized functions :

      • open, close, read, write, malloc, free, perror,strerror, exit
      • All functions of the math library (-lm man man 3 math)
      • All functions of the MinilibX

The constraints are as follows:
  
      • You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you         will need to apply the same rules for your libft as those written above in Common Instructions part.
      • The management of your window must remain smooth: changing to another window, minimizing, etc.
      • Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).
      • Your program must be able to display an item (sprite) instead of a wall.
      • Your program must be able to set the floor and ceilling colors to two different ones.
      • In case the Deepthought has eyes one day to evaluate your project, your program must save the first rendered image in bmp format when its second argument         is  "––save".
      • If no second argument is supllied, the program displays the image in a window and
      respects the following rules:
                ◦ The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
                ◦ The W, A, S and D keys must allow you to move the point of view through the maze.
                ◦ Pressing ESC must close the window and quit the program cleanly.
                ◦ Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
                ◦ If the declared screen size in the map is greater than the display resolution, the window size will be set depending to the current display                       resolution.
                ◦ The use of images of the minilibX is strongly recommended.
      • Your program must take as a first argument a scene description file with the .cub extension.
                ◦ The map must be composed of only 4 possible characters: 0 for an empty space, 1 for a wall, 2 for an item and N,S,E or W for the player’s start                 position and spawning orientation.
                This is a simple valid map:
                
                  111111
                  100101
                  102001
                  1100N1
                  111111
                  
                ◦ The map must be closed/surrounded by walls, if not the program must return an error.
                ◦ Except for the map content, each type of element can be separated by one or more empty line(s).
                ◦ Except for the map content which always has to be the last, each type of element can be set in any order in the file.
                ◦ Except for the map, each type of information from an element can be separated by one or more space(s).
                ◦ The map must be parsed as it looks like in the file. Spaces are a valid part of the map, and is up to you to handle. You must be able to parse                    any kind of map, as long as it respects the maps rules.
                
              





  
  Resources 

https://lodev.org/cgtutor/raycasting.html

