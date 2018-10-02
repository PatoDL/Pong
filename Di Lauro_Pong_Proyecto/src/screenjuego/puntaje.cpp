#include "puntaje.h"

#include "bola.h"
#include "jugador.h"
#include "juego.h"

namespace Juego
{
	namespace Gameplay
	{
		namespace Puntaje
		{
			using namespace Bola;
			using namespace Jugador;

			static const int topeIzq = 0;

			void actualizarPuntaje()
			{
				bool hayPunto = false;

				if (bola.pos.x <= topeIzq)
				{
					jugador2.puntaje++;
					hayPunto = true;
				}
				if (bola.pos.x >= screenWidth)
				{
					jugador1.puntaje++;
					hayPunto = true;
				}
#ifdef AUDIO
				if (hayPunto)
				{
					reproducirPunto();
				}
#endif
			}

			void dibujarPuntaje()
			{
				DrawText(FormatText("%i", jugador1.puntaje), (float)screenWidth / 2.432, screenHeight / 20, screenHeight*screenWidth / 13500, WHITE);
				DrawText(FormatText("%i", jugador2.puntaje), (float)screenWidth / 1.764, screenHeight / 20, screenHeight*screenWidth / 13500, WHITE);
			}
		}
	}
}
