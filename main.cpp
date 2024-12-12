#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  // Data-asetukset
  const int MAX_HUONEET = 100, HINNAT = 100;
  int varausHuoneet;
  int yoMaara = 0, hintaHuone = 0, hintaSummat = 0;
  string asiakasNimet;
  bool huoneSaatavuus[MAX_HUONEET];
  char toista;
  vector<int>huoneTiedot, yoTiedot, hintaTiedot;

  
  // Oletetaan, että kaikki huoneet ovat saatavilla
  for (int i = 0; i < MAX_HUONEET; i++) {
    huoneSaatavuus[i] = true;
  }

  do {
    // Käyttäjän syötteet
    cout << "Varaa huoneen numeron 1-100 välillä: ";
    cin >> varausHuoneet;
    while(varausHuoneet <=0 || varausHuoneet >100) {
      cout << "Varaa huoneen numeron 1-100 välillä: ";
      cin >> varausHuoneet; 
    }

    // Tarkistetaan, onko huone saatavilla käyttäjää varten
    if (huoneSaatavuus[varausHuoneet-1] == true) {
      cout << "Huone " << varausHuoneet << " on saatavilla." << endl;
      
      while(yoMaara <= 0) {
      cout << "Kuinka yötä haluat yöpyä? ";
      cin >> yoMaara;
      }

    // Lasketaan nykyisen huoneen hinta ja kokonaishinta
      hintaHuone = HINNAT*yoMaara;
      cout << "Tämän huoneen laskusumma on: " << hintaHuone << " euroa." << endl;
      hintaSummat = hintaSummat + hintaHuone;

    // Säilytetään arvoa vektoreihin
      huoneTiedot.push_back(varausHuoneet);
      yoTiedot.push_back(yoMaara);
      hintaTiedot.push_back(hintaHuone);

    // RESET
      huoneSaatavuus[varausHuoneet-1] = false;
      yoMaara = 0;

      cout << "Haluatko varata muita huoneita: (k) tai (e)?";
      cin >> toista;    
    } else {
      cout << "Huone " << varausHuoneet << " ei ole saatavilla.\n Ole hyvä ja valitse toinen huonen yötäsi varten. " << endl;
    }
  } while (toista == 'k' || toista == 'K');

  // Kokonaisinfo
  for (int i = 0; i < huoneTiedot.size(); i++) {
    cout << "Huone numero " << huoneTiedot[i] << " on varattu sinulle " << yoTiedot[i] << " yöksi (" << hintaTiedot[i] << " euroa)." << endl;
  }

  cout << "Koko laskusumma on: " << hintaSummat << " euroa." << endl;


  return 0;
}
