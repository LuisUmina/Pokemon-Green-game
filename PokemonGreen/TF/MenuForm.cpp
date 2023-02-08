#include "MenuForm.h"

using namespace TF;


int main() {
	srand(time(NULL));
	MenuForm^ frm = gcnew MenuForm();
	Application::Run(frm);
	return 0;
}
