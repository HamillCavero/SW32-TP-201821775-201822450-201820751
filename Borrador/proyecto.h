#pragma once
#include "juego.h"
#include <ctime>
namespace TrabajoFinal1 {
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  lbl_creditos;
	private: System::Windows::Forms::TextBox^  txt_instruc1;
	private: System::Windows::Forms::TextBox^  txt_instruc2;
	private: System::Windows::Forms::Label^  lbl_vidas;
	private: System::Windows::Forms::Label^  lbl_tiempo;
	private: System::Windows::Forms::TextBox^  txt_vidas;
	private: System::Windows::Forms::TextBox^  txt_tiempo;
	private: System::Windows::Forms::Label^  lbl_enemigosRestantes;
	private: System::Windows::Forms::Label^  lbl_enemigosNivel;
	private: System::Windows::Forms::Button^  btn_menu;

			 Graphics^ graficador;
			 BufferedGraphics^ buffer;
			 BufferedGraphicsContext^ espacio;
			 Bitmap^ terreno;
			 Bitmap^nuevoJ1;
			 int tiempo_minutos;
			 int tiempo_segundos;
			 int vidas;
			 int direccion;
			 int CurrrentLvL = 1;
			 Juego* Control;
			 Bitmap^ otrasImagenes;
			 float angle;
	private: System::Windows::Forms::Label^  lblVidas;
	private: System::Windows::Forms::Label^  lblTiempo;
			 Bitmap^fondo;
	public:
		MyForm(void)
		{
			InitializeComponent();
			graficador = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(graficador, this->ClientRectangle);
			tiempo_minutos = 0;
			vidas = 0;
			direccion = 0;
			tiempo_segundos = 0;
			angle = 0;
			otrasImagenes = gcnew Bitmap("objetosVarios.png");
			Control = new Juego(otrasImagenes, this->Width, this->Height, 1);
			terreno = gcnew Bitmap("fondo" + Control->getLvl() + ".jpg");
			nuevoJ1 = gcnew Bitmap("jugadorN" + Control->getLvl() + ".png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lbl_creditos = (gcnew System::Windows::Forms::Label());
			this->txt_instruc1 = (gcnew System::Windows::Forms::TextBox());
			this->txt_instruc2 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_vidas = (gcnew System::Windows::Forms::Label());
			this->lbl_tiempo = (gcnew System::Windows::Forms::Label());
			this->txt_vidas = (gcnew System::Windows::Forms::TextBox());
			this->txt_tiempo = (gcnew System::Windows::Forms::TextBox());
			this->lbl_enemigosRestantes = (gcnew System::Windows::Forms::Label());
			this->lbl_enemigosNivel = (gcnew System::Windows::Forms::Label());
			this->btn_menu = (gcnew System::Windows::Forms::Button());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Animar);
			// 
			// timer2
			// 
			this->timer2->Interval = 300;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::Bombas);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(483, 174);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 32);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Como Jugar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(483, 212);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 32);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Créditos";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(483, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// lbl_creditos
			// 
			this->lbl_creditos->AutoSize = true;
			this->lbl_creditos->Location = System::Drawing::Point(643, 136);
			this->lbl_creditos->Name = L"lbl_creditos";
			this->lbl_creditos->Size = System::Drawing::Size(162, 39);
			this->lbl_creditos->TabIndex = 3;
			this->lbl_creditos->Text = L"Este juego fue hecho por \r\nRomario y Hamill\r\npara el curso de programación 2!\r\n";
			this->lbl_creditos->Visible = false;
			// 
			// txt_instruc1
			// 
			this->txt_instruc1->Location = System::Drawing::Point(365, 304);
			this->txt_instruc1->Multiline = true;
			this->txt_instruc1->Name = L"txt_instruc1";
			this->txt_instruc1->ReadOnly = true;
			this->txt_instruc1->Size = System::Drawing::Size(338, 49);
			this->txt_instruc1->TabIndex = 5;
			this->txt_instruc1->Text = L"Intrucciones:\r\nTe mueves con las teclas WASD\r\nDisparas haciendo click dentro de l"
				L"a ventana";
			this->txt_instruc1->Visible = false;
			// 
			// txt_instruc2
			// 
			this->txt_instruc2->Location = System::Drawing::Point(365, 359);
			this->txt_instruc2->Multiline = true;
			this->txt_instruc2->Name = L"txt_instruc2";
			this->txt_instruc2->ReadOnly = true;
			this->txt_instruc2->Size = System::Drawing::Size(283, 59);
			this->txt_instruc2->TabIndex = 6;
			this->txt_instruc2->Text = L"Tu misión es matar a los enemigos sin morir en el intento\r\nCuando acabes con la c"
				L"antidad pedida de enemigos subirás un nivel\r\nCompleta el nivel 5 y gana el juego"
				L"!";
			this->txt_instruc2->Visible = false;
			// 
			// lbl_vidas
			// 
			this->lbl_vidas->AutoSize = true;
			this->lbl_vidas->Enabled = false;
			this->lbl_vidas->Location = System::Drawing::Point(13, 13);
			this->lbl_vidas->Name = L"lbl_vidas";
			this->lbl_vidas->Size = System::Drawing::Size(42, 13);
			this->lbl_vidas->TabIndex = 7;
			this->lbl_vidas->Text = L"VIDAS:";
			this->lbl_vidas->Visible = false;
			// 
			// lbl_tiempo
			// 
			this->lbl_tiempo->AutoSize = true;
			this->lbl_tiempo->Enabled = false;
			this->lbl_tiempo->Location = System::Drawing::Point(135, 13);
			this->lbl_tiempo->Name = L"lbl_tiempo";
			this->lbl_tiempo->Size = System::Drawing::Size(51, 13);
			this->lbl_tiempo->TabIndex = 8;
			this->lbl_tiempo->Text = L"TIEMPO:";
			this->lbl_tiempo->Visible = false;
			// 
			// txt_vidas
			// 
			this->txt_vidas->Location = System::Drawing::Point(401, 268);
			this->txt_vidas->Name = L"txt_vidas";
			this->txt_vidas->Size = System::Drawing::Size(100, 20);
			this->txt_vidas->TabIndex = 9;
			this->txt_vidas->Text = L"33";
			this->txt_vidas->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::reconocerNumero);
			// 
			// txt_tiempo
			// 
			this->txt_tiempo->Location = System::Drawing::Point(589, 268);
			this->txt_tiempo->Name = L"txt_tiempo";
			this->txt_tiempo->Size = System::Drawing::Size(100, 20);
			this->txt_tiempo->TabIndex = 10;
			this->txt_tiempo->Text = L"3";
			this->txt_tiempo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::reconocerNumero);
			// 
			// lbl_enemigosRestantes
			// 
			this->lbl_enemigosRestantes->AutoSize = true;
			this->lbl_enemigosRestantes->Enabled = false;
			this->lbl_enemigosRestantes->Location = System::Drawing::Point(251, 13);
			this->lbl_enemigosRestantes->Name = L"lbl_enemigosRestantes";
			this->lbl_enemigosRestantes->Size = System::Drawing::Size(110, 13);
			this->lbl_enemigosRestantes->TabIndex = 11;
			this->lbl_enemigosRestantes->Text = L"Enemigos Restantes!:";
			this->lbl_enemigosRestantes->Visible = false;
			// 
			// lbl_enemigosNivel
			// 
			this->lbl_enemigosNivel->AutoSize = true;
			this->lbl_enemigosNivel->Enabled = false;
			this->lbl_enemigosNivel->Location = System::Drawing::Point(416, 12);
			this->lbl_enemigosNivel->Name = L"lbl_enemigosNivel";
			this->lbl_enemigosNivel->Size = System::Drawing::Size(94, 13);
			this->lbl_enemigosNivel->TabIndex = 12;
			this->lbl_enemigosNivel->Text = L"Enemigos Totales:";
			this->lbl_enemigosNivel->Visible = false;
			// 
			// btn_menu
			// 
			this->btn_menu->Enabled = false;
			this->btn_menu->Font = (gcnew System::Drawing::Font(L"BubbleGum", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_menu->Location = System::Drawing::Point(442, 240);
			this->btn_menu->Name = L"btn_menu";
			this->btn_menu->Size = System::Drawing::Size(206, 87);
			this->btn_menu->TabIndex = 13;
			this->btn_menu->Text = L"Volver a jugar\?";
			this->btn_menu->UseVisualStyleBackColor = true;
			this->btn_menu->Visible = false;
			this->btn_menu->Click += gcnew System::EventHandler(this, &MyForm::btn_menu_Click);
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(278, 262);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(104, 26);
			this->lblVidas->TabIndex = 14;
			this->lblVidas->Text = L"Vidas: deben ser de \r\n10 a 100";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(695, 262);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(112, 26);
			this->lblTiempo->TabIndex = 15;
			this->lblTiempo->Text = L"El tiempo debe ser de \r\n3 a 10 minutos\r\n";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1105, 595);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->btn_menu);
			this->Controls->Add(this->lbl_enemigosNivel);
			this->Controls->Add(this->lbl_enemigosRestantes);
			this->Controls->Add(this->txt_tiempo);
			this->Controls->Add(this->txt_vidas);
			this->Controls->Add(this->lbl_tiempo);
			this->Controls->Add(this->lbl_vidas);
			this->Controls->Add(this->txt_instruc2);
			this->Controls->Add(this->txt_instruc1);
			this->Controls->Add(this->lbl_creditos);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"Juego!";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Apretar);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Soltar);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Animar(System::Object^  sender, System::EventArgs^  e) {
		if (Control->getLvl() != 6 && Control->getSoldado()->getVida() > 0 && tiempo_segundos > 0)
		{
			Control->Dibujar(buffer, nuevoJ1, terreno, this->ClientRectangle, otrasImagenes, angle);
			Control->MoverPersonaje(direccion, this->Width, this->Height);
			Control->MoverEnemigos(Control->getSoldado()->getX(), Control->getSoldado()->getY(), this->Width, this->Height);
			Control->moverbala();
			Control->Eliminar(this->Width, this->Height);

			lbl_vidas->Text = "Vidas: " + Control->getSoldado()->getVida();
			lbl_tiempo->Text = "Tiempo: " + tiempo_segundos / 30 ;
			lbl_enemigosRestantes->Text = "Enemigos restantes: " + Control->getEnemigosRestantes();
			lbl_enemigosNivel->Text = "Enemigos a matar: " + Control->getEnemigosTotales();
			if (Control->getEnemigosRestantes() <= Control->getEnemigosTotales() / 2) {
				Control->subirNivel(this->Width, this->Height);
				if (Control->getLvl() < 6)
				{
					Control->destruirBalas();
					timer1->Interval -= 10;
					timer2->Interval -= 20;
					Control->AgregarVArias(otrasImagenes, this->Width, this->Height);
					Control->setEnemigosRestantes();
					terreno = gcnew Bitmap("fondo" + Control->getLvl() + ".jpg");
					nuevoJ1 = gcnew Bitmap("jugadorN" + Control->getLvl() + ".png");
				}
			}
			buffer->Render();
			tiempo_segundos--;
		}
		else
		{
			timer1->Enabled = false;
			timer2->Enabled = false;
			if (Control->getLvl() == 6)
			{
				this->Text = L"GANASTE YAY!";
				MessageBox::Show("GANASTE MUAJAJAJAJA");
			}
			else
			{
				this->Text = L"PERDISTE OHNO!";
				MessageBox::Show("PERDISTE MUAJAJAJAJA");
			}
			btn_menu->Enabled = true;
			btn_menu->Visible = true;
		}
	}
	private: System::Void Bombas(System::Object^  sender, System::EventArgs^  e) {
		Control->EnemigoDisparo();
	}
	private: System::Void Apretar(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		e->Handled = true;
		e->SuppressKeyPress = true;
		switch (e->KeyCode)
		{

		case Keys::W: direccion = 1; break;   //arriba
		case Keys::S: direccion = 2; break;	  //abajo
		case Keys::D: direccion = 3; break;	  //derecha
		case Keys::A: direccion = 4; break;	  //izquierda
		default:
			break;
		}
		if (e->KeyCode == Keys::P)
		{
			if (Control->getPausa())
			{
				Control->setPausa(false);
				timer1->Stop();
				//timer2->Stop();

			}
			else
			{
				Control->setPausa(true);
				timer1->Start();
				//timer2->Start();
			}
		}

	}
	private: System::Void Soltar(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		direccion = 0;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int vidas = int::Parse(txt_vidas->Text);
		tiempo_minutos = int::Parse(txt_tiempo->Text);
		tiempo_segundos = tiempo_minutos * 60 * 30;
		if (vidas <= 100 && vidas >= 10)
		{
			if (tiempo_minutos >= 3 && tiempo_minutos <= 10) {
				button1->Visible = false;
				button1->Enabled = false;

				button2->Visible = false;
				button2->Enabled = false;

				button3->Visible = false;
				button3->Enabled = false;

				lbl_creditos->Visible = false;
				lbl_creditos->Enabled = false;

				txt_instruc1->Visible = false;
				txt_instruc1->Enabled = false;
				txt_instruc2->Visible = false;
				txt_instruc2->Enabled = false;

				lbl_vidas->Visible = true;
				lbl_vidas->Enabled = true;
				lbl_tiempo->Visible = true;
				lbl_tiempo->Enabled = true;
				timer1->Enabled = true;
				timer2->Enabled = true;
				Control->getSoldado()->iniciarVida(vidas);
				txt_vidas->Visible = false;
				txt_vidas->Enabled = false;
				txt_tiempo->Visible = false;
				txt_tiempo->Enabled = false;

				lblTiempo->Visible = false;
				lblTiempo->Enabled = false;
				lblVidas->Visible = false;
				lblVidas->Enabled = false;

				lbl_enemigosNivel->Visible = true;
				lbl_enemigosNivel->Enabled = true;
				lbl_enemigosRestantes->Visible = true;
				lbl_enemigosRestantes->Enabled = true;
			}
			else
			{
				MessageBox::Show("Valor de tiempo incorrecto!");
			}
		}
		else
		{
			if (tiempo_minutos >= 3 && tiempo_minutos <= 10)
			{
				MessageBox::Show("Valor de vidas incorrecto!");
			}
			else
			{
				MessageBox::Show("Valor de vidas incorrecto!");
				MessageBox::Show("Valor del tiempo tambien está incorrecto lol!");
			}
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (txt_instruc1->Visible == true)
		{
			txt_instruc1->Visible = false;
			txt_instruc2->Visible = false;
		}
		else
		{
			txt_instruc1->Visible = true;
			txt_instruc2->Visible = true;
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (lbl_creditos->Visible == true)
		{
			lbl_creditos->Visible = false;
		}
		else
		{
			lbl_creditos->Visible = true;
		}
	}
	private: System::Void reconocerNumero(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) e->Handled = true;
	}
	private: System::Void btn_menu_Click(System::Object^  sender, System::EventArgs^  e) {
		vidas = int::Parse(txt_vidas->Text);
		tiempo_minutos = int::Parse(txt_tiempo->Text);
		Control->getSoldado()->iniciarVida(vidas);
		Control->reiniciar(otrasImagenes, this->Width, this->Height);

		terreno = gcnew Bitmap("fondo" + Control->getLvl() + ".jpg");
		nuevoJ1 = gcnew Bitmap("jugadorN" + Control->getLvl() + ".png");
		timer1->Interval = 100;
		timer2->Interval = 300;
		timer2->Start();
		timer1->Start();
		btn_menu->Enabled = false;
		btn_menu->Visible = false;
	}
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		Control->agregarbala(e->X, e->Y, this->Width, this->Height);
	}
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		angle = atan2(Control->getSoldado()->getY() + (Control->getSoldado()->getAlto() / 2) - e->Y, Control->getSoldado()->getX() + (Control->getSoldado()->getAncho() / 2) - e->X) / 3.1416 * 180;
	}
	};

}
