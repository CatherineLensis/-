#include "MyForm.h"
#include "DES.h"

#include "string"
#include <msclr/marshal_cppstd.h>
#include <ctime>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array <String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	srand((unsigned)time(NULL));
	START::MyForm form;
	Application::Run(% form);
}

System::Void START::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton1->Checked == true)
	{
		std::string ���� = ���������_�����();
		textBox1->Text = gcnew String(����.c_str());
	}

	
	return System::Void();
}

System::Void START::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context pre;
	String^ ����� = richTextBox1->Text->ToString(); std::string ����� = pre.marshal_as<std::string>(�����);	std::vector <char>  �����_�_������(�����.begin(), �����.end());
	if (radioButton1->Checked == true)
	{
	String^ ���� = textBox1->Text->ToString(); std::string ���� = pre.marshal_as<std::string>(����); std::vector <bool>  ����_�_����� = ��16�2(����);
	
		std::vector <char> �����_�_������_�������_��������� = ����������_�_���������_���������(�����_�_������);
		std::vector <bool> �����_�_����� = bytes2bits(�����_�_������_�������_���������);
		std::vector <std::vector<bool>> �����_�_�����_��_64 = �������_��_�������_�_�������_��������(�����_�_�����);

		std::vector <bool> �������������_�����;
		for (int i = 0; i < �����_�_�����_��_64.size(); i++)
		{
			append(�������������_�����, DES(�����_�_�����_��_64[i], ����_�_�����, 1));
		}

		std::string B = ��2�16(�������������_�����);
		richTextBox2->Text = gcnew String(B.c_str());
	}
	

	return System::Void();
}

System::Void START::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context pre;
	String^ ������������_����� = richTextBox2->Text->ToString(); std::string ������������_����� = pre.marshal_as<std::string>(������������_�����);
	if (radioButton1->Checked == true)
	{
		String^ ���� = textBox1->Text->ToString(); std::string ���� = pre.marshal_as<std::string>(����);   std::vector <bool>  ����_�_����� = ��16�2(����);
		std::vector <bool> �������������_�����_�_����� = ��16�2(������������_�����);

		std::vector <bool> ���������������_�����;
		std::vector <std::vector<bool>> �����_�_�����_��_64 = �������_��_�������_�_�������_��������(�������������_�����_�_�����);

		for (int i = 0; i < �����_�_�����_��_64.size(); i++)
		{
			append(���������������_�����, DES(�����_�_�����_��_64[i], ����_�_�����, 2));
		}

		std::vector <char> A = bits2bytes(���������������_�����);
		std::string B(A.begin(), A.end());
		richTextBox1->Text = gcnew String(B.c_str());
	}
	
	return System::Void();
}

System::Void START::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ OpenFileDialog1 = gcnew OpenFileDialog();

	OpenFileDialog1->Filter = "txt files (*.txt|*.txt|All files (*.*)|*.*";
	OpenFileDialog1->ShowDialog();

	String^ F;
	F = OpenFileDialog1->FileName;

	msclr::interop::marshal_context pre;
	std::string stdF = pre.marshal_as<std::string>(F);

	std::string line;

	std::ifstream in(stdF); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();     // ��������� ����

	textBox1->Text = gcnew String(line.c_str());

	return System::Void();
}

System::Void START::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ OpenFileDialog1 = gcnew OpenFileDialog();

	OpenFileDialog1->Filter = "txt files (*.txt|*.txt|All files (*.*)|*.*";
	OpenFileDialog1->ShowDialog();

	String^ F;
	F = OpenFileDialog1->FileName;

	msclr::interop::marshal_context pre;
	std::string stdF = pre.marshal_as<std::string>(F);

	std::string line;

	std::ifstream in(stdF); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();     // ��������� ����

	richTextBox1->Text = gcnew String(line.c_str());

	return System::Void();
}

System::Void START::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ OpenFileDialog1 = gcnew OpenFileDialog();
	OpenFileDialog1->Filter = "txt files (*.txt|*.txt|All files (*.*)|*.*";
	OpenFileDialog1->ShowDialog();

	String^ F;
	F = OpenFileDialog1->FileName;

	msclr::interop::marshal_context pre;
	std::string stdF = pre.marshal_as<std::string>(F);

	std::string line;
	std::ifstream in(stdF); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();     // ��������� ����

	richTextBox2->Text = gcnew String(line.c_str());

	return System::Void();

}

System::Void START::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "Text file (*.txt)|*.txt";
	saveFileDialog1->ShowDialog();

	String^ F;
	F = saveFileDialog1->FileName;

	msclr::interop::marshal_context pre;
	std::string stdF = pre.marshal_as<std::string>(F);

	String^ Key = textBox1->Text->ToString();
	std::string stdKey = pre.marshal_as<std::string>(Key);

	std::ofstream out(stdF);
	out << stdKey;
	out.close();

	return System::Void();
}

System::Void START::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "Text file (*.txt)|*.txt";
	saveFileDialog1->ShowDialog();

	String^ F;
	F = saveFileDialog1->FileName;

	msclr::interop::marshal_context pre;
	std::string stdF = pre.marshal_as<std::string>(F);

	String^ Key = richTextBox1->Text->ToString();
	std::string stdKey = pre.marshal_as<std::string>(Key);

	std::ofstream out(stdF);
	out << stdKey;
	out.close();

	return System::Void();
}

System::Void START::MyForm::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "Text file (*.txt)|*.txt";
	saveFileDialog1->ShowDialog();

	String^ F;
	F = saveFileDialog1->FileName;

	msclr::interop::marshal_context pre;
	std::string stdF = pre.marshal_as<std::string>(F);

	String^ Key = richTextBox2->Text->ToString();
	std::string stdKey = pre.marshal_as<std::string>(Key);

	std::ofstream out(stdF);
	out << stdKey;
	out.close();

	return System::Void();
}


 