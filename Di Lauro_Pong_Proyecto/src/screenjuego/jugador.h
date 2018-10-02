#ifndef JUGADOR_H
#define JUGADOR_H
#include "raylib.h"
namespace Juego
{
	namespace Gameplay
	{
		namespace Jugador
		{
			struct Paleta
			{
				int puntaje;
				Rectangle sprite;
				bool laser;
			};

			extern int topeArribaJugador;
			extern int topeAbajoJugador;

			extern Paleta jugador1;
			extern Paleta jugador2;

			void moverJugadores();
			void limitarPaletas();
			void reiniciarPaletas();
			void dibujarJugadores();
			void moverIA();
		}
	}
}
#endif //JUGADOR_H
