
#include <iostream>
#include "checker.h"


int main(int argc, char** argv)
{
    HICON icon = (HICON)LoadImage(GetModuleHandleA(0), "icon.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);

    HWND hConsole = GetConsoleWindow();
    LRESULT result = SendMessageA(hConsole, WM_SETICON, ICON_BIG, (LPARAM)icon);
    result = SendMessageA(hConsole, WM_SETICON, ICON_SMALL, (LPARAM)icon);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("AML Checker bot [BTC | ETH | LTC | TRON | SOL | POLYGON] - By Cosmo11");

    while (true)
    {
        std::cout << "choose action:\n";
        std::cout << "[1] - check Bitcoin AML.\n";
        std::cout << "[2] - check Ethereum AML.\n";
        std::cout << "[3] - check Litecoin AML.\n";
        std::cout << "[4] - check Dogecoin AML.\n";
        std::cout << "[5] - check Tron AML.\n";
        std::cout << "[6] - check Solana AML.\n";
        std::cout << "[7] - check Polygon AML.\n";

        int type_id = NULL;

        while (true) {
            for (int i = 1; i < 8; ++i) {
                if (GetAsyncKeyState(48 + i) & 1) {
                    type_id = i;
                    break;
                }
            }

            if (type_id != NULL) {
                std::cout << "\nenter target wallet address or transaction hash: ";
                std::string address = "";
                std::cin >> address;

                if (address.size() < 10 || (address.find("0x") == std::string::npos && address.find("bc") == std::string::npos)) {
                    std::cout << "Invalid address or hash format. Please enter correctly";
                    std::cout << std::endl << std::endl;
                    Sleep(1000);
                    continue;
                }

                int aml_risk = (int)get_aml(address, type_id);
                std::cout << std::endl << std::endl;
                std::cout << address << " AML - (";

                if (aml_risk <= 35)
                    SetConsoleTextAttribute(hConsole, 2); // green color
                else
                    SetConsoleTextAttribute(hConsole, 4); // red color

                std::cout << aml_risk << "%";
                SetConsoleTextAttribute(hConsole, 7);
                std::cout << ")\n\n";
                Sleep(1000);
            }
        }


    }

    return 0;
}
