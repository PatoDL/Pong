#include "juego.h"

#include <ctime>
#include <iostream>
#include "raylib.h"
#include "screenjuego/screenjuego.h"
#include "menu/menu.h"
#include "gameover/gameover.h"
#include "creditos/creditos.h"
#include "screenjuego/bola.h"

namespace Juego
{

	Estado estado = menu;
	Estado estadoAnterior = menu;

	const int screenWidth = 900;
	const int screenHeight = 600;

	static void cambiarEstado();
	static void dibujarTodo();
	static void actualizar();
	static void chequearInput();
	static void actualizarMusica();
	static void inicializar();
	static void finalizar();

	void finalizar()
	{
		CloseWindow();
#ifdef AUDIO
		Menu::cerrarMusicaMenu();
		Gameplay::Bola::cerrarSonidos();
		CloseAudioDevice();
#endif
	}

	void actualizarMusica()
	{
		switch (estado)
		{
		case creditos:
			Creditos::actualizarCreditos();
			break;
		case gameover:
			Gameover::actualizarMusicaGameOver();
			break;
		case jugando:
			Menu::pausarMusicaMenu();
			break;
		case menu:
			if (estadoAnterior == menu)
			{
				Menu::reproducirMusicaMenu();
			}
			Menu::recargarMusicaMenu();
			break;
		}
	}

	void actualizar()
	{
		switch (estado)
		{
		case jugando:
			Gameplay::actualizarJuego();
			break;
		}
#ifdef AUDIO
		actualizarMusica();
#endif
	}

	void dibujarTodo()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (estado)
		{
		case menu:
			Menu::mostrarPantallaInicio();
			break;
		case jugando:
			Gameplay::dibujarJuego();
			break;
		case gameover:
			Gameover::mostrarGameOver();
			break;
		case creditos:
			Creditos::mostrarCreditos();
			break;
		}

		EndDrawing();
	}

	void chequearInput() 
	{
		switch (estado)
		{
		case menu:
			Menu::chequearInputMenu();
			break;
		case jugando:
			Gameplay::chequearInputJugando();
			break;
		case gameover:
			Gameover::chequearInputGameover();
			break;
		case creditos:
			Creditos::chequearInputCreditos();
			break;
		}
	}

	void cambiarEstado() 
	{
		if (estado != estadoAnterior)
		{
			estadoAnterior = estado;

			switch (estado)
			{
			case menu:
				SetExitKey(KEY_ESCAPE);
				break;
			case jugando:
				Gameplay::iniciarGameplay();
				SetExitKey(0);
				break;
			default:
				SetExitKey(0);
				break;
			}
		}
	}

	void inicializar()
	{
		srand(time(0));

		//SetTargetFPS(60);

#ifdef AUDIO
		InitAudioDevice();

		Menu::inicializarMusicaMenu();

		Gameplay::Bola::inicializarSonidos();
#endif
		InitWindow(screenWidth, screenHeight, "pong");

	}

	void ejecutarJuego()
	{
		inicializar();

		while (!WindowShouldClose())
		{
			cambiarEstado();

			chequearInput();

			actualizar();

			dibujarTodo();
		}

		finalizar();
	}
}