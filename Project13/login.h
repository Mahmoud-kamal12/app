#pragma once
#include"shop.h"
namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public:
		login(void)
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
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtmail;

	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtpass;

	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtmail = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtpass = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"email or username";
			// 
			// txtmail
			// 
			this->txtmail->Location = System::Drawing::Point(179, 49);
			this->txtmail->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtmail->Name = L"txtmail";
			this->txtmail->Size = System::Drawing::Size(163, 22);
			this->txtmail->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(125, 159);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 39);
			this->button1->TabIndex = 2;
			this->button1->Text = L"login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &login::button1_Click);
			// 
			// txtpass
			// 
			this->txtpass->Location = System::Drawing::Point(179, 97);
			this->txtpass->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtpass->Name = L"txtpass";
			this->txtpass->PasswordChar = '*';
			this->txtpass->Size = System::Drawing::Size(163, 22);
			this->txtpass->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"passowrd";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(403, 236);
			this->Controls->Add(this->txtpass);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtmail);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"login";
			this->Text = L"login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ email = txtmail->Text;
	String^ pass = txtpass->Text;
	MySqlConnection^ con = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=");
	String^ sqlcomand = "SELECT * FROM app.userinof WHERE Email='" + email + "' OR userName='"+email+"' AND hashPass=MD5('" + pass + "');";
	MySqlCommand^ coman = gcnew MySqlCommand(sqlcomand, con);
	MySqlDataReader^ myread;
	con->Open();
	myread = coman->ExecuteReader();

	if (myread->Read())
	{
		shop::id = myread->GetInt32("id");
		shop^ s = gcnew shop();
		this->Hide();
		s->ShowDialog();
	}
	else
	{
		MessageBox::Show("no");
		con->Close();
	}

}
};
}
