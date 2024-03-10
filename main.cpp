

#include "Ui/Ui.h"
#include "Test/Teste.h"

int main() {
    test_All();
    fileRepo f = fileRepo(R"(..\Repo\Jocurifile.txt)");
    Casa_de_marcat_file c = Casa_de_marcat_file(R"(..\Repo\Bancnote.txt)");
    Service s = Service(f,c);
    Ui u = Ui(s);
    u.Meniu();

    return 0;
}
