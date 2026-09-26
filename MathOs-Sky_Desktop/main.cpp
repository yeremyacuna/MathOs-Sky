#include "Forms/MainForm.h"
#include "../tests/TestForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MathOsSky::MainForm());
    Application::Run(gcnew MathOsSky::TestForm());

    return 0;
}
