#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "InstruccionesForm.h"
#include "CreditosForm.h"


namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Media; //Esto es para cargar musica

	/// <summary>
	/// Resumen de MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	private:

	public:
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::Button^ btnNivel2;


	private: System::Windows::Forms::Button^ btnInstrucciones;

	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnTrailer;
	private: System::Windows::Forms::Button^ btnCreditos;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnTrailer = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(879, 492);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Green;
			this->label1->Location = System::Drawing::Point(273, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(329, 61);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Pokemon Green";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(249, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(179, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre del Jugador";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(469, 113);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(179, 20);
			this->textBox1->TabIndex = 3;
			// 
			// btnNivel1
			// 
			this->btnNivel1->BackColor = System::Drawing::Color::Black;
			this->btnNivel1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnNivel1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel1->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel1->ForeColor = System::Drawing::Color::White;
			this->btnNivel1->Location = System::Drawing::Point(134, 217);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(146, 61);
			this->btnNivel1->TabIndex = 4;
			this->btnNivel1->Text = L"Nivel1";
			this->btnNivel1->UseVisualStyleBackColor = false;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &MenuForm::btnNivel1_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackColor = System::Drawing::Color::Black;
			this->btnNivel2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnNivel2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel2->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel2->ForeColor = System::Drawing::Color::White;
			this->btnNivel2->Location = System::Drawing::Point(136, 316);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(133, 66);
			this->btnNivel2->TabIndex = 5;
			this->btnNivel2->Text = L"Nivel 2";
			this->btnNivel2->UseVisualStyleBackColor = false;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &MenuForm::btnNivel2_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Black;
			this->btnInstrucciones->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnInstrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->ForeColor = System::Drawing::Color::White;
			this->btnInstrucciones->Location = System::Drawing::Point(577, 215);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(195, 44);
			this->btnInstrucciones->TabIndex = 6;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MenuForm::btnInstrucciones_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Black;
			this->btnSalir->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::Color::White;
			this->btnSalir->Location = System::Drawing::Point(768, 436);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(80, 33);
			this->btnSalir->TabIndex = 7;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MenuForm::btnSalir_Click);
			// 
			// btnTrailer
			// 
			this->btnTrailer->BackColor = System::Drawing::Color::Black;
			this->btnTrailer->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnTrailer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTrailer->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTrailer->ForeColor = System::Drawing::Color::White;
			this->btnTrailer->Location = System::Drawing::Point(577, 274);
			this->btnTrailer->Name = L"btnTrailer";
			this->btnTrailer->Size = System::Drawing::Size(195, 44);
			this->btnTrailer->TabIndex = 8;
			this->btnTrailer->Text = L"Trailer";
			this->btnTrailer->UseVisualStyleBackColor = false;
			this->btnTrailer->Click += gcnew System::EventHandler(this, &MenuForm::btnTrailer_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Black;
			this->btnCreditos->FlatAppearance->BorderSize = 0;
			this->btnCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->ForeColor = System::Drawing::Color::White;
			this->btnCreditos->Location = System::Drawing::Point(577, 334);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(195, 44);
			this->btnCreditos->TabIndex = 9;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MenuForm::btnCreditos_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(872, 491);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnTrailer);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->btnNivel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuForm";
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1^ frm = gcnew MyForm1();
	this->Visible = false;
	//spTheme->PlayLooping();
	frm->Show();//Nivel 1 //Aqui es show dialog pero me da problemas tener en cuenta
	//spTheme->Stop();
	this->Visible = true;
}
private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm2^ frm = gcnew MyForm2();
	this->Visible = false;
	frm->Show();//Nivel 1 //Aqui es show dialog pero me da problemas tener en cuenta
	this->Visible = true;
}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnTrailer_Click(System::Object^ sender, System::EventArgs^ e) {
	//Link del video https://www.youtube.com/watch?v=UTt3cXSRia0&ab_channel=Emmanuel

	string link = "start https://www.youtube.com/watch?v=";
	
	link += "UTt3cXSRia0&ab_channel=Emmanuel";
	
	system(link.c_str());
}
private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	InstruccionesForm^ frm3 = gcnew InstruccionesForm();
	this->Visible = false;
	frm3->ShowDialog();//Instrucciones
	this->Visible = true;
}
private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	CreditosForm^ frm4 = gcnew CreditosForm();
	this->Visible = false;
	frm4->ShowDialog();//Creditos
	this->Visible = true;
}
};
}
