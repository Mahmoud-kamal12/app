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
	/// Summary for adminboard
	/// </summary>
	public ref class adminboard : public System::Windows::Forms::Form
	{
	public:
		adminboard(void)
		{
			InitializeComponent();
			funn();
			//
			//TODO: Add the constructor code here
			//
		}

	public:

	protected:
		MySqlConnection^ con = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=");
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
		~adminboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labname;
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
			this->labname = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labname
			// 
			this->labname->AutoSize = true;
			this->labname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labname->Location = System::Drawing::Point(84, 77);
			this->labname->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labname->Name = L"labname";
			this->labname->Size = System::Drawing::Size(86, 31);
			this->labname->TabIndex = 0;
			this->labname->Text = L"Name";
			// 
			// adminboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 197);
			this->Controls->Add(this->labname);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"adminboard";
			this->Text = L"adminboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void funn()
	{
		String^ sqlcomand = "SELECT * FROM app.admin ;";
		MySqlCommand^ comand = gcnew MySqlCommand(sqlcomand, con);
		MySqlDataReader^ myreader;
		con->Open();
		myreader = comand->ExecuteReader();
		while (myreader->Read())
		{
			String^ name = myreader->GetString("admin_name");
			labname->Text = "Welcome " +"Admain " + name;
		}
		
	}
	};
}
