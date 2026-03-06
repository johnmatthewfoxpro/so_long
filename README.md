_This project has been created as part of the 42 curriculum by jfox_
# so_long
Creating our first computer graphics project. A small game! For school 42.
## DESCRIPTION
A graphical project where we built a game!
First we build a map file and pass that to the so_long executable and then we launch
our game, generating a window and importing graphics like out player image and the environment.

Aliens have destroyed earth, leaving it a barren waste.\
Only glowing blue crystals remain to mark the aliens passing, but these crystals are powerful items and can be used to power your bunker!\
Collect all the crystals and escape back to safety!

## INSTRUCTIONS
Use 'make' to generate the so_long executable. This will also download the minilibx library that we have been authrorized to use for this project. It is this library that permits the generation
of the graphical elements and the game window.

***NOTE*** If using this program outside of school 42 environment you will need WSL and Vulkan support. Refer to the dependancies in the Macrolibx documentation.

Once the game executable is made we it with a map file. Any .ber will be accepted but certain conditions must be met, for example:
* The map must exist, no empty .ber files will be accepted.
* The map must be rectangular.
* The map must not be too tall or too wide.
* The map can only be map from chars "1, 0, C, E, P"
* The map must be fully surrounded by 1's and have only one E and P.
* There must be at least 1 C and a clear path between the P, E and all the C's.

If the Map passes these checks, the game will be launched.

After that have fun, use 'WASD' or the 'ARROW' keys to move through the maps and find the collectibles and leave via the exit.

You can exit at any time with 'ESC' key or by closing the window by clicking the 'x' with your mouse.

You will see how many moves you made on exit, try to get a low score!

Valgrind checks will show huge leaks unless you use:
* --suppressions=macrolibx/valgrind.supp

## RESOURCES

AI Declaration: Chat gpt was used to understand the lay out of the project and to help with flood fill.\
I also used it to impliment the git clone of the minilibx into my makefile.\
Finally I used Chat GPT to generate my sprites for the game assets.\
I have used [Online Image Editor](https://www.online-image-editor.com/) for editing those sprite.\
I first looked up the minilibx documentation [here](https://harm-smits.github.io/42docs/libs/minilibx).\
But I later chose to go with Macrolibx, [here](https://github.com/seekrs/MacroLibX) and its [documentation](https://macrolibx.kbz8.me/).\
I followed a couple of guides to get my project started on [Medium](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b) and [Gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/so_long/understand-so_long).