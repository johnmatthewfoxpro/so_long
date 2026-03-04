_This project has been created as part of the 42 curriculum by jfox_
# so_long
Creating our first computer graphics project. A small game! For school 42.
## DESCRIPTION
A graphical project where we built a game!
First we build a map file and pass that to the s0_long executable and then we launch
our game, generating a window and importing graphics like out player image and the environment.

Escape the map by finding all the collectibles and then reaching the exit!

## INSTRUCTIONS
Use 'make' to generate the so_long executable. This will also download the minilibx library that we have been authrorized to use for this project. It is this library that permits the generation
of the graphical elements and the game window.

One the game executable is made we it with a map file. Any .ber will be accepted but certain conditions must be met, for example:
* The map must exist, no empty .ber files will be accepted.
* The map must be rectangular.
* The map must not be too tall or too wide.
* The map can only be map from chars "1, 0, C, E, P"
* The map must be fully surrounded by 1's and have only one E and P.
* There must be at least 1 C and a clear path between the P, E and all the C's.

If the Map passes these checks, the game will be launched.

After that have fun, find the collectibles and leave via the exit.

You will see how many moves you made on exit, try to get a low score!

## RESOURCES

AI Declaration: Chat gpt was used to understand the lay out of the project and to help with flood fill. I also used it to impliment the git clone of the minilibx into my makefile.
I first looked up the minilibx documentation [here](https://harm-smits.github.io/42docs/libs/minilibx)
I followed a couple of guides to get my project started. [Medium](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b) and [Gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/so_long/understand-so_long)