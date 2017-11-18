#include <QCoreApplication>
#include <iostream>
#include <Windows.h>
#include <time.h>

const int gridSize = 50;
void PrintGrid(bool grid[gridSize+2][gridSize+2]);
void DetermineState(bool grid[gridSize+2][gridSize+2]);
int CountAlive(bool grid[gridSize+2][gridSize+2]);

void ExplodeConfiguration(bool grid[gridSize+2][gridSize+2]);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    bool grid[gridSize+2][gridSize+2] = {};

    std::srand(time(0));
    for (int i = 0; i<= gridSize+1; ++i)
    {
        if (i == 0 || i == gridSize+1)
        {
            for (int j = 0; j <= gridSize+1; ++j)
            {
                grid[i][j] = false;
            }
        }

        for (int j = 0; j <= gridSize+1; ++j)
        {
            if (j == 0 || j == gridSize+1)
            {
                grid[i][j] = false;
            }

            bool temp = rand() % 2;

            grid[i][j] = temp;
        }
    }

    while (true)
    {
        PrintGrid(grid);
        DetermineState(grid);
        std::cout << "Alive = " << CountAlive(grid) << std::endl;
        Sleep(500);
        system("CLS");
   }

    return a.exec();
}

void PrintGrid(bool grid[gridSize+2][gridSize+2]){
    for(int i = 1; i <= gridSize; ++i)
        {
        for(int j = 1; j <= gridSize; ++j)
        {
            if(grid[i][j] == true)
            {
                std::cout << " O ";
            } else
            {
                std::cout << " . ";
            }

            if(j == gridSize)
            {
                std::cout << std::endl;
            }
        }
    }
}

int CountAlive(bool grid[gridSize+2][gridSize+2])
{
    int result{0};

    for (int i = 0; i <= gridSize + 1; ++i)
    {
        for (int j = 0; j <= gridSize + 1; ++j)
        {
            if (grid[i][j])
            {
                ++result;
            }
        }
    }

    return result;
}

void CompareGrid (bool grid[gridSize+2][gridSize+2], bool anotherGrid[gridSize+2][gridSize+2]){
    for(int i = 0; i <= gridSize + 1; ++i)
    {
        for(int j = 0; j <= gridSize + 1; ++j)
        {
                anotherGrid[i][j] = grid[i][j];
        }
    }
}

void DetermineState(bool grid[gridSize+2][gridSize+2]){
    bool anotherGrid[gridSize+2][gridSize+2] = {};
    CompareGrid(grid, anotherGrid);

    for(int i = 1; i <= gridSize; ++i)
    {
        for(int j = 1; j <= gridSize; ++j)
        {
            int alive = 0;

            for(int c = -1; c < 2; ++c)
            {
                for(int d = -1; d < 2; ++d)
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(anotherGrid[i+c][j+d])
                        {
                            ++alive;
                        }
                    }
                }
            }

            if(alive < 2)
            {
                grid[i][j] = false;
            } else if(alive == 3  || alive == 2)
            {
                grid[i][j] = true;
            } else if(alive > 3)
            {
                grid[i][j] = false;
            }
        }
    }
}

void ExplodeConfiguration(bool grid[gridSize+2][gridSize+2])
{
    for(int i = 0; i <= gridSize + 1; ++i)
    {
        for(int j = 0; j <= gridSize + 1; ++j)
        {
                grid[i][j] = false;
        }
    }

    int center = (int)floor(gridSize/2);
}
