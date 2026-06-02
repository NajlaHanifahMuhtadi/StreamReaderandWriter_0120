#include <iostream>
#include <exception>
#include <array>
using namespace std;

int main(){
    cout << "Awal Program" << endl;
    try 
    {
        //deklarasi array data dengan panjang index 5
        array <int, 3> data = {1, 2, 3};
        //memanggil array elemnt ke-5 yang berarti akan terjadi error
        cout << data.at(5) << endl;
    }
    //kondisi jika terjadi error
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    cout << "Baris program terakhir" << endl; //penanda 2
    return 0;
}