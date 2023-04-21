#include <C:\raylib\raylib\src\raylib.h>

int main()
{
    //window
    int width{800};
    int height{450};

    //circle
    int circle_x{width/2};
    int circle_y{height/2};
    int circle_radius{20};

    int l_circle_x{circle_x-circle_radius};
    int r_circle_x{circle_x+circle_radius};
    int u_circle_y{circle_y+circle_radius};
    int b_circle_y{circle_y-circle_radius};
    
    //axe
    int axe_x{400};
    int axe_y{0};
    int direction{10};
    int axe_length{50};

    int l_axe_x{axe_x};
    int r_axe_x{axe_length + axe_x};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y+axe_length};

    bool collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;

    InitWindow(width, height, "Yo");
    SetTargetFPS(60);

    while(WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe)
        {
            DrawText("Game Over!", circle_x, circle_y, 20, RED);
        }
        else
        {
            //game start
            int l_circle_x = circle_x-circle_radius;
            int r_circle_x = circle_x+circle_radius;
            int u_circle_y = circle_y+circle_radius;
            int b_circle_y = circle_y-circle_radius;
            int l_axe_x = axe_x;
            int r_axe_x = axe_length + axe_x;
            int u_axe_y = axe_y;
            int b_axe_y = axe_y+axe_length;

            collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;


            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, 50, axe_length, RED);

            axe_y += direction;
            if(axe_y > height || axe_y < 0)
            {
            direction = - direction;
            }

            if(IsKeyDown(KEY_D) && circle_x < width)
            {
            circle_x += 10;
            }
            if(IsKeyDown(KEY_A) && circle_x > 0)
            {
            circle_x -= 10;
            }

            //game end
        }
        

        EndDrawing();
    }

    return 0;
}

