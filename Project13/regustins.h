#pragma once

namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for regustins
	/// </summary>
	public ref class regustins : public System::Windows::Forms::Form
	{
	public:
		regustins(void)
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
		~regustins()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtfname;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtpass;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtmail;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtusername;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtlname;

	private: System::Windows::Forms::Button^ btnreg;

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
			this->txtfname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtpass = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtmail = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtusername = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtlname = (gcnew System::Windows::Forms::TextBox());
			this->btnreg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtfname
			// 
			this->txtfname->Location = System::Drawing::Point(127, 26);
			this->txtfname->Name = L"txtfname";
			this->txtfname->Size = System::Drawing::Size(287, 20);
			this->txtfname->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"First Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 191);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// txtpass
			// 
			this->txtpass->Location = System::Drawing::Point(127, 184);
			this->txtpass->Name = L"txtpass";
			this->txtpass->Size = System::Drawing::Size(287, 20);
			this->txtpass->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(31, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Email";
			// 
			// txtmail
			// 
			this->txtmail->Location = System::Drawing::Point(127, 145);
			this->txtmail->Name = L"txtmail";
			this->txtmail->Size = System::Drawing::Size(287, 20);
			this->txtmail->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 109);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"User Name";
			// 
			// txtusername
			// 
			this->txtusername->Location = System::Drawing::Point(127, 106);
			this->txtusername->Name = L"txtusername";
			this->txtusername->Size = System::Drawing::Size(287, 20);
			this->txtusername->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(31, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Last Name";
			// 
			// txtlname
			// 
			this->txtlname->Location = System::Drawing::Point(127, 65);
			this->txtlname->Name = L"txtlname";
			this->txtlname->Size = System::Drawing::Size(287, 20);
			this->txtlname->TabIndex = 8;
			// 
			// btnreg
			// 
			this->btnreg->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnreg->Location = System::Drawing::Point(187, 222);
			this->btnreg->Name = L"btnreg";
			this->btnreg->Size = System::Drawing::Size(156, 33);
			this->btnreg->TabIndex = 10;
			this->btnreg->Text = L"Sign Up";
			this->btnreg->UseVisualStyleBackColor = true;
			this->btnreg->Click += gcnew System::EventHandler(this, &regustins::btnreg_Click);
			// 
			// regustins
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(486, 267);
			this->Controls->Add(this->btnreg);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtlname);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtusername);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtmail);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtpass);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtfname);
			this->Name = L"regustins";
			this->Text = L"regustins";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnreg_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname = txtfname->Text;
		String^ lname = txtlname->Text;
		String^ pass = txtpass->Text;
		String^ mail = txtmail->Text;
		String^ username = txtusername->Text;
		MySqlConnection^ con = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=");
		String^ sqlcomand = "INSERT INTO app.userinof(id,fName,lName,Email,pass,hashPass,userName) VALUES (null,'" + fname + "','" + lname + "','" + mail + "','" + pass + "',MD5('" + pass + "'),'" + username + "');";
		MySqlCommand^ comand = gcnew MySqlCommand(sqlcomand, con);
		MySqlDataReader^ myread;
		try
		{
			con->Open();
			myread = comand->ExecuteReader();
			if (!(myread->Read()))
			{
				MessageBox::Show("doon");
				con->Close();
			}
			else
			{
				MessageBox::Show("no");
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}


		//جرب بس حوار ال ID واسال اسلام على ال !
	}
};
}
