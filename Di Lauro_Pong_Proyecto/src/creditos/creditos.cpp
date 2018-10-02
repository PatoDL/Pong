#include "creditos.h"

#include "raylib.h"
#include "juego.h"
#include "menu/menu.h"

namespace Juego 
{
	namespace Creditos
	{
		void chequearInputCreditos()
		{
			if (IsKeyDown(KEY_ESCAPE))
			{
				estado = menu;
			}
		}

		void actualizarCreditos()
		{
			Menu::recargarMusicaMenu();
		}

		void mostrarCreditos()
		{
			DrawText("Creditos:", screenWidth / 8*3, screenHeight / 4, 50, RED);
			DrawText("Programador: Patricio Di Lauro",screenWidth/7,screenHeight/8*3,40,YELLOW);
			DrawText("Libreria: raylib",screenWidth/7,screenHeight/2,40,BLUE);
			DrawText("Musica y sonidos hechos con Bosca Ceoil",screenWidth/7,screenHeight/8*5,30,GREEN);
			DrawText("Pong v1.0", screenWidth / 15 * 13, 5, screenHeight*screenWidth / 27000, WHITE);
		}
	}
}