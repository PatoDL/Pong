#include "bola.h"
#include <iostream>
#include "juego.h"
#include "screenjuego.h"
#include "jugador.h"

namespace Juego
{
	namespace Gameplay
	{
		namespace Bola
		{
			using namespace Jugador;

			const int topeArriba = screenHeight / 6;

			Bola bola;

			Sound golpePaleta;
			Sound golpePared;
			Sound punto;

			void reproducirPunto()
			{
				PlaySound(punto);
			}

			Direcciones elegirDirBola()
			{
				int direccion = rand() % 4;

				switch (direccion)
				{
				case 0:
					return NO;
					break;
				case 1:
					return NE;
					break;
				case 2:
					return SO;
					break;
				case 3:
					return SE;
					break;
				}

			}

			void chequeardirBola()
			{
				float diferenciaEnX = (float)screenWidth * 0.001;

				switch (bola.dir)
				{
				case NO:
					bola.pos.x -= (bola.vel + diferenciaEnX)*GetFrameTime();
					bola.pos.y -= bola.vel * GetFrameTime();
					break;
				case NE:
					bola.pos.x += (bola.vel + diferenciaEnX) * GetFrameTime();
					bola.pos.y -= bola.vel * GetFrameTime();
					break;
				case SO:
					bola.pos.x -= (bola.vel + diferenciaEnX) * GetFrameTime();
					bola.pos.y += bola.vel * GetFrameTime();
					break;
				case SE:
					bola.pos.x += (bola.vel + diferenciaEnX) * GetFrameTime();
					bola.pos.y += bola.vel * GetFrameTime();
					break;
				}
			}

			int colisionConJugadores()
			{
				bool toque = false;

				if (bola.pos.x <= jugador1.sprite.x + jugador1.sprite.width && bola.pos.x >= jugador1.sprite.x &&
					bola.pos.y >= jugador1.sprite.y && bola.pos.y <= jugador1.sprite.y + jugador1.sprite.height)
				{
					if (bola.dir == SO)
					{
						if (bola.pos.y >= jugador1.sprite.y + jugador1.sprite.height / 4 && bola.pos.y <= jugador1.sprite.y + jugador1.sprite.height)
						{
							bola.dir = SE;
						}
						else
						{
							bola.dir = NE;
							bola.vel *= 1.03;
						}
					}
					if (bola.dir == NO)
					{
						if (bola.pos.y >= jugador1.sprite.y  && bola.pos.y <= jugador1.sprite.y + jugador1.sprite.height * 3 / 4)
						{
							bola.dir = NE;
						}
						else
						{
							bola.dir = SE;
							bola.vel *= 1.03;
						}
					}
						bola.vel *= 1.29;
						toque = true;
				}
				
				if (bola.pos.x >= jugador2.sprite.x && bola.pos.x <= jugador2.sprite.x + jugador1.sprite.width &&
					bola.pos.y >= jugador2.sprite.y && bola.pos.y <= jugador2.sprite.y + jugador1.sprite.height)
				{
					if (bola.dir == NE)
					{
						if (bola.pos.y >= jugador2.sprite.y  && bola.pos.y <= jugador2.sprite.y + jugador1.sprite.height * 3 / 4)
						{
							bola.dir = NO;
						}
						else
						{
							bola.dir = SO;
							bola.vel *= 1.03;
						}
					}

					if (bola.dir == SE)
					{
						if (bola.pos.y >= jugador2.sprite.y + jugador1.sprite.height / 4 && bola.pos.y <= jugador2.sprite.y + jugador1.sprite.height)
						{
							bola.dir = SO;
						}
						else
						{
							bola.dir = NO;
							bola.vel *= 1.03;
						}
					}
					bola.vel *= 1.29;
					toque = true;
				}

				int maxVel = 555.66f;
				if (bola.vel >= maxVel)
				{
					bola.vel = maxVel;
				}
#ifdef AUDIO
				if (toque)
				{
					PlaySound(golpePaleta);
				}
#endif
				toque = false;
				return bola.dir;
			}

			void inicializarSonidos()
			{
				punto = LoadSound("res/audio/pong_fail.wav");
				golpePaleta = LoadSound("res/audio/pong_hit.wav");
				golpePared = LoadSound("res/audio/pong_wall.wav");
			}

			void cerrarSonidos()
			{
				UnloadSound(golpePaleta);
				UnloadSound(golpePared);
				UnloadSound(punto);
			}

			void chequearLimitesBola()
			{
				bool toque = false;
				if (bola.pos.y <= topeArriba && bola.dir == NO)
				{
					bola.dir = SO;
					toque = true;
				}
				if (bola.pos.y <= topeArriba && bola.dir == NE)
				{
					bola.dir = SE;
					toque = true;
				}
				if (bola.pos.y >= screenHeight - bola.radio / 2 && bola.dir == SO)
				{
					bola.dir = NO;
					toque = true;
				}
				if (bola.pos.y >= screenHeight - bola.radio / 2 && bola.dir == SE)
				{
					bola.dir = NE;
					toque = true;
				}
#ifdef AUDIO
				if (toque)
				{
					PlaySound(golpePared);
				}
#endif
				toque = false;
			}

			void reiniciarBola()
			{
				bola.vel = 200.0f;
				bola.pos.x = screenWidth / 2;
				bola.pos.y = screenHeight / 2;
				bola.dir = elegirDirBola();
			}

			void dibujarBola()
			{
				DrawCircleV(bola.pos, bola.radio, GREEN);
			}

		}
	}
}