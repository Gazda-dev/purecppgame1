#include <C:\raylib\raylib\src\raylib.h>

int main()
{
    // Inicjalizacja okna
    InitWindow(350, 200, "Yo");

    // Pobranie czasu rozpoczęcia programu
    double startTime = GetTime();

    // Pętla główna
    while (!WindowShouldClose())
    {
        // Aktualizacja logiki gry tutaj

        // Rozpoczęcie rysowania
        BeginDrawing();

        // Wyczyszczenie ekranu
        ClearBackground(RAYWHITE);

        // Rysowanie tutaj

        // Zakończenie rysowania i wyświetlenie wyniku
        EndDrawing();

        // Sprawdzenie, czy minęło 5 sekund
        if (GetTime() - startTime >= 5.0)
        {
            // Zamknięcie okna
            CloseWindow();
        }
    }

    return 0;
}

