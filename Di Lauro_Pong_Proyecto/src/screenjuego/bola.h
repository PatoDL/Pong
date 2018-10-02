#ifndef BOLA_H
#define BOLA_H
#include "raylib.h"
namespace Juego
{
	namespace Gameplay
	{
		namespace Bola
		{
			enum Direcciones 
			{
				NO,
				NE,
				SE,
				SO
			};

			struct Bola
			{
				int radio;
				float velInicial;
				float vel;
				Direcciones dir;
				Vector2 pos;
			};

			extern const int topeArriba;

			extern Bola bola;

			void chequeardirBola();
			void chequearLimitesBola();
			int colisionConJugadores();
			void reiniciarBola();
			void inicializarSonidos();
			void cerrarSonidos();
			void reproducirPunto();
			void dibujarBola();
		}
	}
}

#endif // BOLA_H

