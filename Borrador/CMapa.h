#pragma once
#include <vector>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include"CObjeto.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
class Mapa :public CObjeto
{
public:
	Mapa() : CObjeto() {}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ img, Rectangle tmñ)
	{
		buffer->Graphics->DrawImage(img, tmñ);
	}
};
