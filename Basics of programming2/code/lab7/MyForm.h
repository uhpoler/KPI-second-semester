#pragma once

namespace lab7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxA1;
	private: System::Windows::Forms::TextBox^ textBoxB1;
	private: System::Windows::Forms::TextBox^ textBoxC1;
	private: System::Windows::Forms::TextBox^ textBoxA2;
	private: System::Windows::Forms::TextBox^ textBoxB2;
	private: System::Windows::Forms::TextBox^ textBoxC2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxA1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxC1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxC2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::HotPink;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(142, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(266, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть корені для 1 рівняння";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::HotPink;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(142, 162);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(266, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введіть корені для 2 рівняння";
			// 
			// textBoxA1
			// 
			this->textBoxA1->BackColor = System::Drawing::Color::Pink;
			this->textBoxA1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxA1->Location = System::Drawing::Point(137, 77);
			this->textBoxA1->Name = L"textBoxA1";
			this->textBoxA1->Size = System::Drawing::Size(43, 29);
			this->textBoxA1->TabIndex = 2;
			this->textBoxA1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxA1_TextChanged);
			// 
			// textBoxB1
			// 
			this->textBoxB1->BackColor = System::Drawing::Color::Pink;
			this->textBoxB1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxB1->Location = System::Drawing::Point(247, 77);
			this->textBoxB1->Name = L"textBoxB1";
			this->textBoxB1->Size = System::Drawing::Size(43, 29);
			this->textBoxB1->TabIndex = 3;
			this->textBoxB1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxB1_TextChanged);
			// 
			// textBoxC1
			// 
			this->textBoxC1->BackColor = System::Drawing::Color::Pink;
			this->textBoxC1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxC1->Location = System::Drawing::Point(339, 77);
			this->textBoxC1->Name = L"textBoxC1";
			this->textBoxC1->Size = System::Drawing::Size(43, 29);
			this->textBoxC1->TabIndex = 4;
			this->textBoxC1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxC1_TextChanged);
			// 
			// textBoxA2
			// 
			this->textBoxA2->BackColor = System::Drawing::Color::Pink;
			this->textBoxA2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxA2->Location = System::Drawing::Point(137, 214);
			this->textBoxA2->Name = L"textBoxA2";
			this->textBoxA2->Size = System::Drawing::Size(43, 29);
			this->textBoxA2->TabIndex = 5;
			this->textBoxA2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxA2_TextChanged);
			// 
			// textBoxB2
			// 
			this->textBoxB2->BackColor = System::Drawing::Color::Pink;
			this->textBoxB2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxB2->Location = System::Drawing::Point(247, 214);
			this->textBoxB2->Name = L"textBoxB2";
			this->textBoxB2->Size = System::Drawing::Size(43, 29);
			this->textBoxB2->TabIndex = 6;
			this->textBoxB2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxB2_TextChanged);
			// 
			// textBoxC2
			// 
			this->textBoxC2->BackColor = System::Drawing::Color::Pink;
			this->textBoxC2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxC2->Location = System::Drawing::Point(339, 214);
			this->textBoxC2->Name = L"textBoxC2";
			this->textBoxC2->Size = System::Drawing::Size(43, 29);
			this->textBoxC2->TabIndex = 7;
			this->textBoxC2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxC2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(181, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 23);
			this->label3->TabIndex = 8;
			this->label3->Text = L"x^2 +";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(291, 80);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 23);
			this->label4->TabIndex = 9;
			this->label4->Text = L"x +";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(383, 80);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 23);
			this->label5->TabIndex = 10;
			this->label5->Text = L"= 0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(181, 217);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 23);
			this->label6->TabIndex = 11;
			this->label6->Text = L"x^2 +";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(296, 217);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 23);
			this->label7->TabIndex = 12;
			this->label7->Text = L"x +";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(383, 217);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 23);
			this->label8->TabIndex = 13;
			this->label8->Text = L"= 0";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::HotPink;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(126, 277);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(313, 86);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Порахувати середнє арифметичне суми квадратних коренів";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Pink;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(220, 383);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(123, 29);
			this->textBox1->TabIndex = 15;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightPink;
			this->ClientSize = System::Drawing::Size(616, 487);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxC2);
			this->Controls->Add(this->textBoxB2);
			this->Controls->Add(this->textBoxA2);
			this->Controls->Add(this->textBoxC1);
			this->Controls->Add(this->textBoxB1);
			this->Controls->Add(this->textBoxA1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Обрахунок середнього арифметичного сум квадратних рівнянь";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxA1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxB1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxC1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxA2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxB2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxC2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
