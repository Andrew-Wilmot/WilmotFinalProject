// WilmotFinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
using namespace std;
using namespace sf;
using namespace sfp;


int main()
{
    
    int const gridsize = 25; //sets the row and column count 
    int windowsize = 1000;//sets the x and y of the window
    int blocksize = windowsize / gridsize; //Gets the size of each individule cell 
    //Build to be scallable 

    RenderWindow window(VideoMode(windowsize, windowsize), "grid");
    World world(Vector2f(0, 1));
    
    //Sets up the 2D array for the grid.  This is done before the for loops so that way it can easily be changed to follow the rules later on 
    PhysicsRectangle grid[gridsize][gridsize];
    
    //DISPLAY THE GIRD
    for (int i = 0; i < gridsize; i++) {
        for (int j = 0; j < gridsize; j++){
            grid[i][j].setFillColor(Color(255, 255, 255, 255));
            grid[i][j].setOutlineColor(Color(0, 0, 0, 255));
            grid[i][j].setOutlineThickness(3);

            grid[i][j].setSize(Vector2f(blocksize, blocksize));

            //Sets the x and y of the current cell 
            grid[i][j].setCenter(Vector2f(blocksize * i + (blocksize / 2), blocksize * j + (blocksize / 2)));

            grid[i][j].setStatic(true);
            world.AddPhysicsBody(grid[i][j]);
            window.draw(grid[i][j]);
        }
    }
     window.display();
    while (true)
    {
       
    }
}
