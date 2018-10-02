#include "gameover.h"

#include "raylib.h"
#include "juego.h"
#include "screenjuego/screenjuego.h"
#include "menu/menu.h"
#include "screenjuego/jugador.h"

namespace Juego
{
	namespace Gameover
	{
		void chequearInputGameover()
		{
			if (IsKeyDown(KEY_ENTER))
			{
				estado = jugando;
			}
			if (IsKeyDown(KEY_ESCAPE))
			{
				estado = menu;
			}
		}

		void actualizarMusicaGameOver()
		{
			Menu::reproducirMusicaMenu();
			Menu::recargarMusicaMenu();
		}

		void chequearGameover()
		{
			int puntajeGan = 1;
			if (Gameplay::Jugador::jugador1.puntaje == puntajeGan || Gameplay::Jugador::jugador2.puntaje == puntajeGan)
			{
				estado = gameover;
			}
		}

		void mostrarGameOver()
		{
			int jugadorGanador;

			if (Gameplay::Jugador::jugador1.puntaje> Gameplay::Jugador::jugador2.puntaje)
			{
				jugadorGanador = 1;
			}
			else
			{
				jugadorGanador = 2;
			}

			if (Gameplay::cantJugs == 2)
			{
				DrawText(FormatText("Felicitaciones Jugador %i", jugadorGanador), screenWidth / 10, screenHeight / 2 - screenHeight / 7.5,
					screenHeight*screenWidth / 9000, WHITE);

				DrawText("Ganaste!", screenWidth / 3, screenHeight / 1.80, screenHeight*screenWidth / 9000, WHITE);
			}
			else
			{
				if (jugadorGanador == 2)
				{
					DrawText("Felicitaciones, ha ganado", screenWidth / 10, screenHeight / 2 - screenHeight / 7.5, screenHeight*screenWidth / 9000, WHITE);
				}
				else
				{
					DrawText("Ha ganado la computadora", screenWidth / 10, screenHeight / 2 - screenHeight / 7.5, screenHeight*screenWidth / 9100,WHITE);
				}
			}
			DrawText("presiona enter para volver a jugar", screenWidth/4, screenHeight - screenHeight/10, screenHeight*screenWidth/27000, WHITE);
		}

	}
}
