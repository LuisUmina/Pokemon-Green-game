#pragma once
#include <iostream>
#include "Controlador1.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media; //Esto es para cargar musica

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpAsh;
		Bitmap^ bmpMapa;
		Bitmap^ bmpEnemigo1;
		Bitmap^ bmpEnemigo2;
		Bitmap^ bmpSenal;
		Bitmap^ bmpAliado;
		Bitmap^ bmpBasura;
		Bitmap^ bmpDatosJuegoNivel1;
		Bitmap^ bmpBarraVidas;
		Bitmap^ bmpArbolOculto;

		//SoundPlayer
		SoundPlayer^ spTheme; //Instanciamos
		SoundPlayer^ spGanador;
		SoundPlayer^ spPerdedor;

		//Controladora
		Controlador1* controlador;

	public:
		MyForm1(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap
			bmpAsh = gcnew Bitmap("jugador1.png");
			bmpAsh->MakeTransparent(bmpAsh->GetPixel(5, 2));

			bmpMapa = gcnew Bitmap("mapa1.png");

			bmpSenal = gcnew Bitmap("senal.png");//Era point.png pero mejor usamoes este

			bmpAliado = gcnew Bitmap("aliado1.png");

			bmpBasura = gcnew Bitmap("basuraNivel2.png");//Aca era basura.png pero mejor uso esta imagen tmb

			bmpEnemigo1 = gcnew Bitmap("enemigo1.png");//enemigo1.png
			bmpEnemigo1->MakeTransparent(bmpEnemigo1->GetPixel(2, 2));
			bmpEnemigo2 = gcnew Bitmap("enemigo2.png"); //enemigo2.png
			bmpEnemigo2->MakeTransparent(bmpEnemigo2->GetPixel(2, 2));
			bmpDatosJuegoNivel1 = gcnew Bitmap("DatosJuegoNivel1.png");
			bmpBarraVidas = gcnew Bitmap("barraVidas.png");
			bmpArbolOculto = gcnew Bitmap("arbolSecreto.png");

			//SoundPlayer
			spTheme = gcnew SoundPlayer("musicajuego1.wav");
			spGanador = gcnew SoundPlayer("sonidoGanador.wav");
			spPerdedor = gcnew SoundPlayer("sonidoPerdedor.wav");

			controlador = new Controlador1(bmpAsh, bmpEnemigo1, bmpEnemigo2, bmpSenal, bmpBasura, bmpDatosJuegoNivel1, bmpBarraVidas, bmpArbolOculto);
		}

	private: System::Windows::Forms::Timer^ timerParedes;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ labelPikachus;
	private: System::Windows::Forms::Label^ labelBasuras;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->labelBasuras = (gcnew System::Windows::Forms::Label());
			this->labelPikachus = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerParedes = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->labelBasuras);
			this->panel1->Controls->Add(this->labelPikachus);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(978, 641);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Enabled = false;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(-3, -26);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(988, 678);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Enabled = false;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-3, -235);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(981, 876);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// labelBasuras
			// 
			this->labelBasuras->AutoSize = true;
			this->labelBasuras->BackColor = System::Drawing::Color::Black;
			this->labelBasuras->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBasuras->ForeColor = System::Drawing::Color::White;
			this->labelBasuras->Location = System::Drawing::Point(102, 608);
			this->labelBasuras->Name = L"labelBasuras";
			this->labelBasuras->Size = System::Drawing::Size(17, 16);
			this->labelBasuras->TabIndex = 3;
			this->labelBasuras->Text = L"0";
			// 
			// labelPikachus
			// 
			this->labelPikachus->AutoSize = true;
			this->labelPikachus->BackColor = System::Drawing::Color::Black;
			this->labelPikachus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelPikachus->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPikachus->ForeColor = System::Drawing::Color::White;
			this->labelPikachus->Location = System::Drawing::Point(103, 565);
			this->labelPikachus->Name = L"labelPikachus";
			this->labelPikachus->Size = System::Drawing::Size(17, 16);
			this->labelPikachus->TabIndex = 2;
			this->labelPikachus->Text = L"0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(835, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(143, 145);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// timerParedes
			// 
			this->timerParedes->Enabled = true;
			this->timerParedes->Interval = 1;
			this->timerParedes->Tick += gcnew System::EventHandler(this, &MyForm1::timer2_Tick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 640);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		spTheme->PlayLooping();

	}
	private: System::Void MyForm1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
			controlador->getAsh()->mover(buffer->Graphics, 'W'); break;
		case Keys::S:
			controlador->getAsh()->mover(buffer->Graphics, 'S'); break;
		case Keys::A:
			controlador->getAsh()->mover(buffer->Graphics, 'A'); break;
		case Keys::D:
			controlador->getAsh()->mover(buffer->Graphics, 'D'); break;
		case Keys::P:
			controlador->agregarAliados(bmpAliado); break;
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//Colision
		controlador->colisionPared();
		controlador->colision();

		if (controlador->getvalidacionGanaste() == true && controlador->getAsh()->getVidas() > 0 && controlador->getContBasuras() == 4) {
			timer1->Enabled = false;
			timerParedes->Enabled = false;
			//MessageBox::Show("Ganaste :)");
			pictureBox2->Visible = true;
			pictureBox2->Enabled = true;
			spGanador->Play();
		}
		if (controlador->getvalidacionGanaste() == false && controlador->getAsh()->getVidas() == 0) {//NO muere
			timer1->Enabled = false;
			timerParedes->Enabled = false;
			//MessageBox::Show("Perdiste :(");
			pictureBox3->Visible = true;
			pictureBox3->Enabled = true;
			spPerdedor->Play();
		}


		//Aparecer mensaje oculto
		if (controlador->getaparecePicture()) {
			pictureBox1->Visible = true;
			pictureBox1->Enabled = true;
			controlador->setaparecePicture(false);
		}

		//Contadores para labels
		labelPikachus->Text = Convert::ToString(controlador->getContPikachus());
		labelBasuras->Text = Convert::ToString(controlador->getContBasuras());

		//Mover
		controlador->moverEnemigos(buffer->Graphics);

		//Dibujar
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, panel1->Width, panel1->Height);
		controlador->dibujarTodo(buffer->Graphics,bmpAsh, bmpEnemigo1, bmpEnemigo2, bmpSenal, bmpAliado, bmpBasura, bmpDatosJuegoNivel1, bmpBarraVidas, bmpArbolOculto);

		//Render
		buffer->Render(g);
	}
	private: System::Void MyForm1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
	}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	controlador->colisionPared();
}
};
}
