#pragma once
#include"adminboard.h"
namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class admin : public System::Windows::Forms::Form 
	{
	public:
		admin(void)
		{
			InitializeComponent();
		}
	private: System::Windows::Forms::Button^ button1;
	public:

	protected:
		MySqlConnection^ con = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=");;
		bool checkconnection(MySqlConnection^ conn) {
			try
			{
				conn->Open();
				return true;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
				return false;
			}
		}
		~admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtname;
	protected:
	private: System::Windows::Forms::TextBox^ txtpass;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnlogin;


	protected:

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
			this->txtname = (gcnew System::Windows::Forms::TextBox());
			this->txtpass = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnlogin = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtname
			// 
			this->txtname->Location = System::Drawing::Point(138, 64);
			this->txtname->Name = L"txtname";
			this->txtname->Size = System::Drawing::Size(171, 22);
			this->txtname->TabIndex = 0;
			// 
			// txtpass
			// 
			this->txtpass->Location = System::Drawing::Point(138, 121);
			this->txtpass->Name = L"txtpass";
			this->txtpass->Size = System::Drawing::Size(171, 22);
			this->txtpass->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(70, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(70, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"pass";
			// 
			// btnlogin
			// 
			this->btnlogin->Location = System::Drawing::Point(176, 192);
			this->btnlogin->Name = L"btnlogin";
			this->btnlogin->Size = System::Drawing::Size(75, 23);
			this->btnlogin->TabIndex = 4;
			this->btnlogin->Text = L"login";
			this->btnlogin->UseVisualStyleBackColor = true;
			this->btnlogin->Click += gcnew System::EventHandler(this, &admin::btnlogin_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(409, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &admin::button1_Click);
			// 
			// admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(515, 281);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnlogin);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtpass);
			this->Controls->Add(this->txtname);
			this->Name = L"admin";
			this->Text = L"admin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnlogin_Click(System::Object^ sender, System::EventArgs^ e) 
{
	
	String ^sqlcomand = "SELECT * FROM app.admin WHERE admin_name='" + txtname->Text + "' AND hashPass=MD5('" + txtpass->Text + "');";
	MySqlCommand^ coman = gcnew MySqlCommand(sqlcomand,con);
	MySqlDataReader^ myread;
	try
	{
		con->Open();
		myread = coman->ExecuteReader();
		if (myread->Read())
		{
			adminboard^ adbo = gcnew adminboard();
			this->Hide();
			adbo->ShowDialog();
		}
		else
		{
			MessageBox::Show("no");
			con->Close();
		}
	}
	catch (Exception ^ex)
	{
		MessageBox::Show(ex->Message);
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	admin::Visible = false;
	StartPage::Visible=

}
};
}
