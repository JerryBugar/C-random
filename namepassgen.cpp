#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main() {
  // Seed random number generator
  srand(time(NULL));

  // Daftar karakter untuk nama
  string nameCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";

  // Daftar karakter untuk password (termasuk simbol)
  string passwordCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
  string symbolCharacters = "!@#*$";

  // Input dari user
  int desiredLengthName, desiredLengthPassword, desiredCount;
  int capitalizationChoice;

  cout << "Masukkan jumlah huruf per nama: ";
  cin >> desiredLengthName;
  cout << "Masukkan jumlah karakter per password: ";
  cin >> desiredLengthPassword;
  cout << "Masukkan jumlah nama dan password yang ingin dibuat: ";
  cin >> desiredCount;

  cout << "Pilih kapitalisasi nama dan password:" << endl;
  cout << "1. Kapital Besar" << endl;
  cout << "2. Kapital Kecil" << endl;
  cout << "3. Keduanya" << endl;
  cout << "Masukkan pilihan Anda (1-3): ";
  cin >> capitalizationChoice;

  // Generate nama dan password
  for (int i = 0; i < desiredCount; i++) {
    string randomName, randomPassword;

    // Generate nama random tanpa simbol
    for (int j = 0; j < desiredLengthName; j++) {
      int randomIndex = rand() % nameCharacters.length();
      char randomChar = nameCharacters[randomIndex];

      // Pilih kapitalisasi berdasarkan pilihan user
      if (capitalizationChoice == 1) {
        randomName += toupper(randomChar);
      } else if (capitalizationChoice == 2) {
        randomName += tolower(randomChar);
      } else {
        if (j % 2 == 0) {
          randomName += toupper(randomChar);
        } else {
          randomName += tolower(randomChar);
        }
      }
    }

    // Generate password random dengan simbol di akhir
    for (int j = 0; j < desiredLengthPassword - 1; j++) {
      int randomIndex = rand() % passwordCharacters.length();
      char randomChar = passwordCharacters[randomIndex];

      // Pilih kapitalisasi berdasarkan pilihan user
      if (capitalizationChoice == 1) {
        randomPassword += toupper(randomChar);
      } else if (capitalizationChoice == 2) {
        randomPassword += tolower(randomChar);
      } else {
        if (j % 2 == 0) {
          randomPassword += toupper(randomChar);
        } else {
          randomPassword += tolower(randomChar);
        }
      }
    }

    // Tambahkan simbol acak di akhir password
    int randomSymbolIndex = rand() % symbolCharacters.length();
    randomPassword += symbolCharacters[randomSymbolIndex];

    // Output dengan format "|"
    cout << randomName << "|" << randomPassword << endl;
  }

  return 0;
}