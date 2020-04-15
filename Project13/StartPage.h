#pragma once
#include"admin.h"
#include"userboard.h"
namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for StartPage
	/// </summary>
	public ref class StartPage : public System::Windows::Forms::Form
	{
	public:
		StartPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	public:
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(167, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Admin";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StartPage::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(21, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(77, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"User";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StartPage::button2_Click);
			// 
			// StartPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 96);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"StartPage";
			this->Text = L"StartPage";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		StartPage::Visible = false;
		admin^ a = gcnew admin();
		a->Visible = true;
	}
		   
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		userboard^ usab = gcnew userboard();
		this->Hide();
		usab->ShowDialog();
	}
	};
}
