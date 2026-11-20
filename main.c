#include <raylib.h>
#include <stdbool.h>

int grid[30][30] = {0};
int newgrid[30][30] = {0};
void update() {
    // display
    for (int row = 0; row < 30; row++) {
        for (int colum = 0; colum < 30; colum++) {

            int alive = 0;

            for (int X = -1; X <= 1; X++) {
                for (int Y = -1; Y <= 1; Y++) {

                    if (X == 0 && Y == 0)
                        continue;

                    int checkX = row + X;
                    int checkY = colum + Y;

                    if (checkX < 0 || checkX >= 30 || checkY < 0 ||
                        checkY >= 30) {
                        continue;
                    }
                    if (grid[checkX][checkY] == 1) {
                        alive++;
                    }
                }
            }
            if (grid[row][colum] == 1) // cell is alive
            {
                if (alive > 3 || alive <= 1) {
                    newgrid[row][colum] = 0;
                } else {
                    newgrid[row][colum] = 1;
                }
            } else {

                if (alive == 3) {
                    newgrid[row][colum] = 1;
                } else {
                    newgrid[row][colum] = 0;
                }
            }
        }
    }

    // real updating grid with new grid
    for (int row = 0; row < 30; row++) {
        for (int col = 0; col < 30; col++) {
            grid[row][col] = newgrid[row][col];
        }
    }
}

int main() {
    int width = 1000;
    int height = 1000;
    int gap = 3;
    int n = 30;
    int key = false;
    float widthBOX = (width - (n - 1) * gap) / (float)n;
    int selectedx = 0;
    InitWindow(width, height, "life game");
    SetTargetFPS(15);

    while (!WindowShouldClose()) {
        // mose positon
        if (!key && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse = GetMousePosition();
            int MX = mouse.x;
            int MY = mouse.y;
            int selectedx = MX / (widthBOX + gap);
            int selectedy = (MY - 100) / (widthBOX + gap);

            if (selectedx >= 0 && selectedx < n && selectedy >= 0 &&
                selectedy < n) {
                grid[selectedy][selectedx] = !grid[selectedy][selectedx];
            }
        }

        if (IsKeyPressed(KEY_R)) {
            key = !key;
        }
        if (!key && IsKeyPressed(KEY_R)) {
            for (int row = 0; row < 30; row++) {
                for (int col = 0; col < 30; col++) {
                    grid[row][col] = 0;
                    newgrid[row][col] = 0;
                }
            }
        }
        if (IsKeyPressed(KEY_SPACE)) {
            key = !key;
        }
        if (key) {
            update();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // header

        DrawRectangle(0, 0, width, 100, BLACK);
        DrawText("conaway game of life ", 0, 0, 20, WHITE);
        DrawText("R : restart", 400, 66, 20, WHITE);
        if (!key) {
            DrawText("current mode : drawing", 750, 66, 20, WHITE);
        } else {
            DrawText("current mode: working", 750, 66, 20, YELLOW);
        }
        DrawText("spacebar: change mode ", 0, 66, 20, RED);
        for (int posY = 0; posY < n; posY++) {
            for (int posX = 0; posX < n; posX++) {
                Color cellcolor = grid[posY][posX] ? GREEN : GRAY;
                DrawRectangle(posX * (widthBOX + gap),
                              100 + posY * (widthBOX + gap), widthBOX, widthBOX,
                              cellcolor);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
