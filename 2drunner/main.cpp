#include <C:\raylib\raylib\src\raylib.h>



int main()
{
    const int window_width{512*2};
    const int window_height{380*2};

    InitWindow(window_width, window_height, "RunnerGame");

    int velocity{0};

    //acceleration due to gravity pixels/s / s
    const int gravity{1000};
    bool isInAir{false};
    const int jumpVel{-600};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.height = scarfy.height;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = window_width/2 - scarfyRec.width/2;
    scarfyPos.y = window_height - scarfyRec.height;
    int frame{};
    //ammount of time before we update anim
    const float updateTime{1.0/12.0};
    float runningTime{};

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(WHITE);

        const float dT = {GetFrameTime()};

        if(scarfyPos.y >= window_height-scarfyRec.height)
        {
            //rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectange is in the air
            velocity += gravity * dT;
            isInAir=true;
        }
        
        if(IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }
        
        scarfyPos.y += velocity * dT;

        //update running time
        runningTime += dT;

        //update animation frame
        if(runningTime >= updateTime)
        {
            runningTime = 0.0;

            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if(frame>5)
            {
                frame = 0;
            }
        }
        

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        
        EndDrawing();

    }
    UnloadTexture(scarfy);
    CloseWindow();

}