#include "MyForm.h"
#include "quadraticEquation.h"
#include <string>



// простори імен
using namespace System;
using namespace System::Windows::Forms;




//точка входу для форми
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	lab7::MyForm form;
	Application::Run(% form);


}

System::Void lab7::MyForm::textBoxA1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void lab7::MyForm::textBoxB1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void lab7::MyForm::textBoxC1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void lab7::MyForm::textBoxA2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void lab7::MyForm::textBoxB2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void lab7::MyForm::textBoxC2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}








System::Void lab7::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Clear();

	String^ a1s = textBoxA1->Text;
	String^ b1s = textBoxB1->Text;
	String^ c1s = textBoxC1->Text;

	String^ a2s = textBoxA2->Text;
	String^ b2s = textBoxB2->Text;
	String^ c2s = textBoxC2->Text;

	int a1, b1, c1, a2, b2, c2;

	try {

		a1 = validateInput(a1s);
		b1 = validateInput(b1s);
		c1 = validateInput(c1s);

		a2 = validateInput(a2s);
		b2 = validateInput(b2s);
		c2 = validateInput(c2s);



		QuadraticEquation equation1(a1, b1, c1);
		QuadraticEquation equation2(a2, b2, c2);

		double averageRoot1 = equation1.calculateRootsSum();
		double averageRoot2 = equation2.calculateRootsSum();

		double calculateRootsAverage = (averageRoot1 + averageRoot2) / 2;

		textBox1->Text += calculateRootsAverage.ToString("F2");


	}
	catch (const std::invalid_argument& e) {
		String^ errorMessage = msclr::interop::marshal_as<String^>(e.what());
		MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}
	catch (const std::out_of_range& e) {
		String^ errorMessage = msclr::interop::marshal_as<String^>(e.what());
		MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		
	}
	catch (const std::runtime_error& e) {
		String^ errorMessage = msclr::interop::marshal_as<String^>(e.what());
		MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (...) {
		String^ errorMessage = "Сталася невідома помилка.";
		MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}










	return System::Void();
}


System::Void lab7::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->ReadOnly = true;
	return System::Void();
}
