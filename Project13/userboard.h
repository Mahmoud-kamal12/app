#pragma once
#include"login.h"
#include"regustins.h"
namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for userboard
	/// </summary>
	public ref class userboard : public System::Windows::Forms::Form
	{
	public:
		userboard(void)
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
		~userboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnlogin;
	private: System::Windows::Forms::Button^ btnreg;
	protected:

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
			this->btnlogin = (gcnew System::Windows::Forms::Button());
			this->btnreg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnlogin
			// 
			this->btnlogin->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnlogin->Location = System::Drawing::Point(221, 48);
			this->btnlogin->Name = L"btnlogin";
			this->btnlogin->Size = System::Drawing::Size(122, 28);
			this->btnlogin->TabIndex = 0;
			this->btnlogin->Text = L"login";
			this->btnlogin->UseVisualStyleBackColor = true;
			this->btnlogin->Click += gcnew System::EventHandler(this, &userboard::btnlogin_Click);
			// 
			// btnreg
			// 
			this->btnreg->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnreg->Location = System::Drawing::Point(29, 48);
			this->btnreg->Name = L"btnreg";
			this->btnreg->Size = System::Drawing::Size(109, 28);
			this->btnreg->TabIndex = 1;
			this->btnreg->Text = L"Regustns";
			this->btnreg->UseVisualStyleBackColor = true;
			this->btnreg->Click += gcnew System::EventHandler(this, &userboard::btnreg_Click);
			// 
			// userboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(381, 99);
			this->Controls->Add(this->btnreg);
			this->Controls->Add(this->btnlogin);
			this->Name = L"userboard";
			this->Text = L"userboard";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnreg_Click(System::Object^ sender, System::EventArgs^ e) {

		regustins^ re = gcnew regustins();
		this->Hide();
		re->ShowDialog();
	}
	private: System::Void btnlogin_Click(System::Object^ sender, System::EventArgs^ e) {
		login^ re = gcnew login();
		this->Hide();
		re->ShowDialog();
	}
	};
}
