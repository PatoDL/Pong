#define AUDIO
#ifndef JUEGO_H
#define JUEGO_H

namespace Juego
{
	enum Estado
	{
		gameover,
		jugando,
		menu,
		creditos,
	};

	extern Estado estadoAnterior;
	extern Estado estado;

	extern const int screenWidth;
	extern const int screenHeight;

	void ejecutarJuego();
}
#endif //JUEGO_H
