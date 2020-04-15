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
	/// Summary for shop
	/// </summary>
	public ref class shop : public System::Windows::Forms::Form
	{
	public:
		shop(void)
		{
			InitializeComponent();
			fun();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~shop()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labwelcom;
	protected:
	public:static int^ id;
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
			this->labwelcom = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labwelcom
			// 
			this->labwelcom->AutoSize = true;
			this->labwelcom->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labwelcom->Location = System::Drawing::Point(128, 174);
			this->labwelcom->Name = L"labwelcom";
			this->labwelcom->Size = System::Drawing::Size(0, 52);
			this->labwelcom->TabIndex = 0;
			// 
			// shop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 488);
			this->Controls->Add(this->labwelcom);
			this->Name = L"shop";
			this->Text = L"shop";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void fun()
		{
			MySqlConnection^ con = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=");
			String^ sqlcomand = "SELECT * FROM app.userinof WHERE id ='"+id+"';";
			MySqlCommand^ coman = gcnew MySqlCommand(sqlcomand, con);
			MySqlDataReader^ myread;
			try
			{
				con->Open();
				myread = coman->ExecuteReader();
				while (myread->Read())
				{
					String^ fname, ^ lname;
					fname = myread->GetString("fName");
					lname = myread->GetString("fName");
					labwelcom->Text = "Wlcome user " + " " + fname + " " + lname;
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}





		}
#pragma endregion

	};
}
