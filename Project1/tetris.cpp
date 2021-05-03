#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
using namespace System;
void borrar_movil(int x, int y, int nom)
{
	if (nom == 1)
	{
		if (char(219))
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			Console::SetCursorPosition(x, y - 1);
			cout << " ";
			Console::SetCursorPosition(x + 1, y);
			cout << " ";
			Console::SetCursorPosition(x - 1, y);
			cout << " ";
		}
	}
	if (nom == 2)
	{
		if (char(219))
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			Console::SetCursorPosition(x, y - 1);
			cout << " ";
			Console::SetCursorPosition(x - 1, y - 1);
			cout << " ";
			Console::SetCursorPosition(x - 1, y);
			cout << " ";
		}
	}
	if (nom == 3)
	{
		if (char(219))
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			Console::SetCursorPosition(x, y - 1);
			cout << " ";
			Console::SetCursorPosition(x, y - 2);
			cout << " ";
			Console::SetCursorPosition(x, y - 3);
			cout << " ";
		}
	}
	if (nom == 4)
	{
		if (char(219))
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			Console::SetCursorPosition(x, y - 1);
			cout << " ";
			Console::SetCursorPosition(x - 1, y);
			cout << " ";
			Console::SetCursorPosition(x + 1, y - 1);
			cout << " ";
		}
	}
}
void TetrinomioT(int x, int y)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << char(219);
	Console::SetCursorPosition(x, y - 1);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << char(219);
	Console::SetCursorPosition(x - 1, y);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << char(219);
	Console::SetCursorPosition(x + 1, y);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << char(219);
}
void TetrinomioC(int x, int y)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	cout << char(219);
	Console::SetCursorPosition(x, y - 1);
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	cout << char(219);
	Console::SetCursorPosition(x - 1, y - 1);
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	cout << char(219);
	Console::SetCursorPosition(x - 1, y);
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	cout << char(219);
}
void TetrinomioL(int x, int y)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << char(219);
	Console::SetCursorPosition(x, y - 1);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << char(219);
	Console::SetCursorPosition(x, y - 2);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << char(219);
	Console::SetCursorPosition(x, y - 3);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << char(219);
}
void TetrinomioR(int x, int y)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << char(219);
	Console::SetCursorPosition(x, y - 1);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << char(219);
	Console::SetCursorPosition(x - 1, y);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << char(219);
	Console::SetCursorPosition(x + 1, y - 1);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << char(219);
}
void mov(int &x, int &y, int &dx, int &dy, int tet)
{

	dx = dy = 0;
	if (_kbhit())
	{
		char teclapresionada;
		teclapresionada = _getch();
		teclapresionada = toupper(teclapresionada);
		switch (teclapresionada)
		{
		case 80:dy = 1; dx = 0; break; //80---flecha abajo
		case 75:dx = -1; dy = 0; break; //75---flecha izquierda
		case 77:dx = 1; dy = 0; break; //77---flecha derecha
		} //switch
	} //if(_kbhit())
	if (!(y == 30))
	{
		if ((x + dx) < 0 || (x + 1 + dx) > 79)
			dx = dy = 0;
		if ((y + dy) < 0 || (y + 2 + dy) > 30)
			dy = dx = 0;
		x = x + dx;
		y = y + 1 + dy;
		x = x + dx;
		y = y + dy;
	}
	if (tet == 1)
	{
		TetrinomioT(x, y);
		Sleep(290);
		if (!(y == 30))
		{
			borrar_movil(x, y, tet);
		}
	}
	if (tet == 2)
	{
		TetrinomioC(x, y);
		Sleep(290);
		if (!(y == 30))
		{
			borrar_movil(x, y, tet);
		}
	}
	if (tet == 3)
	{
		TetrinomioL(x, y);
		Sleep(290);
		if (!(y == 30))
		{
			borrar_movil(x, y, tet);
		}
	}
	if (tet == 4)
	{
		TetrinomioR(x, y);
		Sleep(290);
		if (!(y == 30))
		{
			borrar_movil(x, y, tet);
		}
	}
}
void controlador_movil(int x, int y, int dx, int dy, int tet)
{
	while (1)
		mov(x, y, dx, dy, tet);
}
void main()
{
	int tetrinomio;
	Random r;
	tetrinomio = r.Next(1, 5);
	int x, y, dx, dy;
	Console::CursorVisible = false;
	Console::SetWindowSize(80, 30);
	x = 10; y = 6; dx = 0; dy = 0;
	//controlador_movil(x, y, dx, dy, tetrinomio);
	do
	{
		mov(x, y, dx, dy, tetrinomio);
		if (y == 30)
		{
			x = 10; y = 6; dx = 0; dy = 0;
			tetrinomio = r.Next(1, 5);
			mov(x, y, dx, dy, tetrinomio);
			//controlador_movil(x, y, dx, dy, tetrinomio1);
		}
	} while (1);
}