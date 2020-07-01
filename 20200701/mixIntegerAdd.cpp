#include <iostream>
using namespace std;
int main()
{
    size_t UI{100};
    int SI{-1};
    cout << "UI + SI = " << UI + SI << endl;
    cout << "static_cast<size_t>(UI + SI) = "
         << static_cast<size_t>(UI + SI) << endl;
    if (UI > SI) cout << "UI > SI" << endl;
    else cout << "UI <= SI" << endl;

    if (UI + SI < UI) cout << "UI + SI < UI" << endl;
    else cout << " UI + SI >= UI" << endl;
}