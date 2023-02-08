#pragma once
#include "Controlador2.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media; //Esto es para cargar musica

	/// <summary>
	/// Resumen de MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpAsh2;
		Bitmap^ bmpFondo;
		Bitmap^ bmpEnemigo1Nivel2;
		Bitmap^ bmpPokebola;
		Bitmap^ bmpBoss;
		Bitmap^ bmpBalaBoss;
		Bitmap^ bmpAliadoFase2;
		Bitmap^ bmpBalasAliadoFase2;
		Bitmap^ barraVidas;
		Bitmap^ bmpEnemigo2Nivel2;
		Bitmap^ bmpBarraVidasBoss;
		Bitmap^ bmpDatosJuegoNivel2;

		//SoundPlayer
		SoundPlayer^ spThemeDisparo; //Instanciamos
		SoundPlayer^ spGanador;
		SoundPlayer^ spPerdedor;

		//Controlador
		Controlador2* controlador;
	private: System::Windows::Forms::Timer^ timerColisiones;

		//Contador
		int Temporizador;

	public:
		MyForm2(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap
			bmpAsh2 = gcnew Bitmap("jugador2.png");
			bmpEnemigo1Nivel2 = gcnew Bitmap("basuraNivel2.png");
			bmpPokebola = gcnew Bitmap("pokebola.png");
			bmpFondo = gcnew Bitmap("fondo2.png");
			bmpBoss = gcnew Bitmap("boss.png");
			bmpBalaBoss = gcnew Bitmap("BalaBoss.png");

			bmpAliadoFase2 = gcnew Bitmap("aliadoFase2.png");
			bmpAliadoFase2->MakeTransparent(bmpAliadoFase2->GetPixel(2, 2));

			bmpBalasAliadoFase2 = gcnew Bitmap("BalaAliadoNivel2.png");
			barraVidas = gcnew Bitmap("barraVidas.png");
			bmpEnemigo2Nivel2 = gcnew Bitmap("basura.png");
			bmpBarraVidasBoss = gcnew Bitmap("vidasBoss.png");
			bmpDatosJuegoNivel2 = gcnew Bitmap("DatosJuegoNivel2.png");

			//SoundPlayer
			spThemeDisparo = gcnew SoundPlayer("Disparo.wav");
			spGanador = gcnew SoundPlayer("sonidoGanador.wav");
			spPerdedor = gcnew SoundPlayer("sonidoPerdedor.wav");

			//Controlador
			controlador = new Controlador2(bmpAsh2, bmpBoss, barraVidas, bmpBarraVidasBoss, bmpDatosJuegoNivel2);

			//Contador
			Temporizador = 0;
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelTemporizador;
	private: System::Windows::Forms::Timer^ timerFase2;
	private: System::Windows::Forms::Timer^ timerBalasBoss;
	private: System::Windows::Forms::Timer^ timerPokebolas;
	private: System::Windows::Forms::Timer^ timerCambiodeFase;
	private: System::Windows::Forms::Label^ labelBasuras;

	private: System::Windows::Forms::Label^ labelPokebolas;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ contador;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm2()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelBasuras = (gcnew System::Windows::Forms::Label());
			this->labelPokebolas = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelTemporizador = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerPokebolas = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerCambiodeFase = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerFase2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerBalasBoss = (gcnew System::Windows::Forms::Timer(this->components));
			this->contador = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerColisiones = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->labelBasuras);
			this->panel1->Controls->Add(this->labelPokebolas);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->labelTemporizador);
			this->panel1->Location = System::Drawing::Point(0, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(978, 644);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Enabled = false;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, -3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(978, 644);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(978, 644);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(940, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 14);
			this->label1->TabIndex = 2;
			this->label1->Text = L"80";
			// 
			// labelBasuras
			// 
			this->labelBasuras->AutoSize = true;
			this->labelBasuras->BackColor = System::Drawing::Color::Black;
			this->labelBasuras->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelBasuras->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBasuras->ForeColor = System::Drawing::Color::White;
			this->labelBasuras->Location = System::Drawing::Point(944, 129);
			this->labelBasuras->Name = L"labelBasuras";
			this->labelBasuras->Size = System::Drawing::Size(17, 16);
			this->labelBasuras->TabIndex = 1;
			this->labelBasuras->Text = L"0";
			// 
			// labelPokebolas
			// 
			this->labelPokebolas->AutoSize = true;
			this->labelPokebolas->BackColor = System::Drawing::Color::Black;
			this->labelPokebolas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelPokebolas->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPokebolas->ForeColor = System::Drawing::Color::White;
			this->labelPokebolas->Location = System::Drawing::Point(905, 87);
			this->labelPokebolas->Name = L"labelPokebolas";
			this->labelPokebolas->Size = System::Drawing::Size(14, 14);
			this->labelPokebolas->TabIndex = 0;
			this->labelPokebolas->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(835, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Temporizador:";
			// 
			// labelTemporizador
			// 
			this->labelTemporizador->AutoSize = true;
			this->labelTemporizador->BackColor = System::Drawing::Color::Black;
			this->labelTemporizador->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTemporizador->ForeColor = System::Drawing::Color::White;
			this->labelTemporizador->Location = System::Drawing::Point(943, 42);
			this->labelTemporizador->Name = L"labelTemporizador";
			this->labelTemporizador->Size = System::Drawing::Size(17, 16);
			this->labelTemporizador->TabIndex = 5;
			this->labelTemporizador->Text = L"0";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			// 
			// timerPokebolas
			// 
			this->timerPokebolas->Enabled = true;
			this->timerPokebolas->Interval = 1500;
			this->timerPokebolas->Tick += gcnew System::EventHandler(this, &MyForm2::timerPokebolas_Tick);
			// 
			// timerCambiodeFase
			// 
			this->timerCambiodeFase->Enabled = true;
			this->timerCambiodeFase->Interval = 30000;
			this->timerCambiodeFase->Tick += gcnew System::EventHandler(this, &MyForm2::timerCambiodeFase_Tick);
			// 
			// timerFase2
			// 
			this->timerFase2->Tick += gcnew System::EventHandler(this, &MyForm2::timerFase2_Tick);
			// 
			// timerBalasBoss
			// 
			this->timerBalasBoss->Interval = 5000;
			this->timerBalasBoss->Tick += gcnew System::EventHandler(this, &MyForm2::timerBalasBoss_Tick);
			// 
			// contador
			// 
			this->contador->Enabled = true;
			this->contador->Interval = 1000;
			this->contador->Tick += gcnew System::EventHandler(this, &MyForm2::contador_Tick);
			// 
			// timerColisiones
			// 
			this->timerColisiones->Enabled = true;
			this->timerColisiones->Interval = 1;
			this->timerColisiones->Tick += gcnew System::EventHandler(this, &MyForm2::timerColisiones_Tick);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 640);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::MyForm2_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void MyForm2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::D:
			controlador->getAsh2()->mover(buffer->Graphics, 'D'); break;
		case Keys::A:
			controlador->getAsh2()->mover(buffer->Graphics, 'A'); break;
		case Keys::P:
			controlador->agregarAliadoFase2(bmpAliadoFase2); break;
			//controlador->agregarEnemigos(bmpEnemigo1Nivel2); break;
		case Keys::Space:
			spThemeDisparo->Play();
			controlador->agregarBalas(bmpPokebola); break;
		}
	
	}


private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {//Fase 1 
	//Borrar
	buffer->Graphics->Clear(Color::WhiteSmoke);

	if (controlador->getAsh2()->getVidas() <= 0 || controlador->getContBasurasSuelo() >= 15) {
		
		timer1->Enabled = false;
		timerPokebolas->Enabled = false;
		//MessageBox::Show("Perdiste :(");
		pictureBox2->Visible = true;
		pictureBox2->Enabled = true;
		spPerdedor->Play();
	}

	//Colision
	controlador->colisionFase1();

	//Contadores para labels
	labelPokebolas->Text = Convert::ToString(controlador->getContPokebolas());
	labelBasuras->Text = Convert::ToString(controlador->getContBasurasSuelo());
	labelTemporizador->Text = Convert::ToString(Temporizador);

	//Mover
	controlador->moverTodo(buffer->Graphics);

	//Dibujar
	buffer->Graphics->DrawImage(bmpFondo, 0, 0, panel1->Width, panel1->Height);
	controlador->dibujarTodo(buffer->Graphics, bmpAsh2,bmpEnemigo1Nivel2, bmpPokebola, barraVidas, bmpDatosJuegoNivel2);

	//Render
	buffer->Render(g);
}




private: System::Void timerPokebolas_Tick(System::Object^ sender, System::EventArgs^ e) {//basuras
	controlador->agregarEnemigos(bmpEnemigo1Nivel2);
}


private: System::Void timerCambiodeFase_Tick(System::Object^ sender, System::EventArgs^ e) {
	timerPokebolas->Enabled = false;
	timer1->Enabled = false;
	timerFase2->Enabled = true;
	timerBalasBoss->Enabled = true;
	controlador->eliminarCambioFase();
	controlador->getBoss()->setX(440);
	if(timerPokebolas->Enabled == false && timerFase2->Enabled == true && timer1->Enabled==false && timerBalasBoss->Enabled==true )
		timerCambiodeFase->Enabled = false;
}

//FASE 2

private: System::Void timerFase2_Tick(System::Object^ sender, System::EventArgs^ e) {
	//Borrar
	buffer->Graphics->Clear(Color::WhiteSmoke);

	//Validaciones de banners de ganaste y perdiste
	if (controlador->getAsh2()->getVidas() <= 0 || controlador->getContBasurasSuelo()>=15 || Temporizador >= 150) {
		timerFase2->Enabled = false;
		timerBalasBoss->Enabled = false;
		timerColisiones->Enabled = false;
		//MessageBox::Show("Perdiste :(");
		pictureBox2->Visible = true;
		pictureBox2->Enabled = true;
		spPerdedor->Play();
	}
	if (controlador->getBoss()->getVidas() <= 0) {//NO muere
		timerFase2->Enabled = false;
		timerBalasBoss->Enabled = false;
		timerColisiones->Enabled = false;
		//MessageBox::Show("Ganaste :)");
		pictureBox1->Visible = true;
		pictureBox1->Enabled = true;
		spGanador->Play();
	}




	controlador->colisionFase2();

	//Contadores para labels
	labelPokebolas->Text = Convert::ToString(controlador->getContPokebolas());
	labelBasuras->Text = Convert::ToString(controlador->getContBasurasSuelo());
	labelTemporizador->Text= Convert::ToString(Temporizador);

	controlador->moverTodoFase2(buffer->Graphics);

	//Dibujar

	buffer->Graphics->DrawImage(bmpFondo, 0, 0, panel1->Width, panel1->Height);
	controlador->dibujarTodoFase2(buffer->Graphics, bmpAsh2, bmpBoss, bmpBalaBoss, bmpPokebola, bmpAliadoFase2, bmpBalasAliadoFase2, barraVidas, bmpEnemigo2Nivel2, bmpBarraVidasBoss, bmpDatosJuegoNivel2);
	//controlador->dibujarTodo(buffer->Graphics, bmpAsh2, bmpEnemigo1Nivel2, bmpPokebola);

	//Render
	buffer->Render(g);
}
private: System::Void timerBalasBoss_Tick(System::Object^ sender, System::EventArgs^ e) {
	controlador->agregarBalasBoss(bmpBalaBoss);
	controlador->agregarBalasAliadoNivel2(bmpBalasAliadoFase2);
	controlador->agregarEnemigos2(bmpEnemigo1Nivel2);
}

private: System::Void contador_Tick(System::Object^ sender, System::EventArgs^ e) {
	//PONER VARIABLE DE CONTADOR
	Temporizador++;
}
private: System::Void timerColisiones_Tick(System::Object^ sender, System::EventArgs^ e) {
	//En este timer validamos las coliciones porque es mas exacto
	controlador->colisionFase1();
	controlador->colisionFase2();
	controlador->validacionBarraVidas();
	controlador->validacionBarraVidasBoss();
}
};
}
