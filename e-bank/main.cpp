#include <iostream>

#include "ui.h"

using namespace std;

int main()
{
	// utworzenie obiektu UI
	UI* ui = new UI();

	// uruchomienie programu
	ui->start();

	return 0;
}