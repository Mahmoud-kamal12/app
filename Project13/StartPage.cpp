#include "StartPage.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project13::StartPage form;
	Application::Run(% form);
}