#include <C:\raylib\raylib\src\raylib.h>



int main()
{
    const int window_height{512};
    const int window_width{380};

    const int height{80};
    const int width{50};    
    int velocity{0};
    int posY{window_height-height};

    SetTargetFPS(60);
    InitWindow(window_width, window_height, "RunnerGame");

    while(!WindowShouldClose())
    {   
        DrawRectangle(window_width/2, posY, width, height, BLUE);
        if(IsKeyPressed(KEY_SPACE))
        {
            velocity -= posY;
        }
        posY += velocity;

        
        
        

        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();

    }


}