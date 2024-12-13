#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

void huonesyoteTarkistus(int MAX_HUONEET, int& varausHuoneet, bool& virhe);
void yosyoteTarkistus(int& yoMaara, bool& virhe);
void menuOptio(int MAX_HUONEET,  int& varausHuoneet, int& optio, bool& virhe);

// Huoneen syötteen tarkistus
void huonesyoteTarkistus(int MAX_HUONEET, int& varausHuoneet, bool& virhe) {
  do {
      virhe = false;     
      cout << "Valitsehan huoneen numero välillä 1-"<< MAX_HUONEET << ":" << endl;
      cin >> varausHuoneet;
      if (cin.fail() || varausHuoneet <=0 || varausHuoneet >MAX_HUONEET) {
        cout << "Virhe. Anna huoneen numero uudestaan!" << endl;
        virhe = true;
        cin.clear();
        cin.ignore(80, '\n');
      }
    } while(virhe);
};

// Yömäärän syötteen tarkistus
void yosyoteTarkistus(int& yoMaara, bool& virhe) {
  do {
      virhe = false;
      cout << "Kuinka monta yötä te haluatte yöpyä? ";
      cin >> yoMaara;
      if (cin.fail() || yoMaara <=0) {
        cout << "Virhe. Anna yömäärän numero uudestaan!" << endl;
        virhe = true;
        cin.clear();
        cin.ignore(80, '\n');
      }
    } while(virhe); 
};

// MENU OPTIO
void menuOptio(int MAX_HUONEET,  int& varausHuoneet, int& optio, bool& virhe) {
    cout << "Voinko auttaa huoneen varaamisessa? " << endl;
    cout << "Haluaisitteko itse valita huoneen numeron? (1)" << endl;
    cout << "Tai haluaisitteko, että annamme teille satunnaisen huoneen numeron? (2)" << endl;

    do {
      virhe = false;
      cout << "Valitse (1) tai (2):";
      cin >> optio;

      if (optio == 1) {
      // Käyttäjän huoneen numeron syötteen tarkistus
      huonesyoteTarkistus(MAX_HUONEET, varausHuoneet, virhe);
      } else if (optio == 2) {
      varausHuoneet = 1+ rand() % MAX_HUONEET;
      } else {
      cout << "Virhe!";
      virhe = true;
      cin.clear();
      cin.ignore(80, '\n');
      }
    } while(virhe);

}


int main() {
  srand(time(0));

  // Data-asetukset
const int MAX_HUONEET = 30 + rand() % 41;
  const int HINNAT = 80 + rand() % 21;
  int varausHuoneet, optio, yoMaara = 0, hintaHuone = 0, hintaSummat = 0;
  string asiakasNimet;
  bool huoneSaatavuus[MAX_HUONEET], virhe;
  char toista;
  vector<int>huoneTiedot, yoTiedot, hintaTiedot;
// Annetaan huoneen saatavuudet ja hinnat asiakkaalle:
  cout << "Hyvää päivää, ja tervetuloa hotelliimme!" << endl;
  cout << "---------------------------------------------" << endl;
  cout << "Meillä on tällä hetkellä " << MAX_HUONEET << " vapaata huonetta." << endl;
  cout << "Huoneen hinta on " << HINNAT << " euroa yöltä." << endl;
  cout << "---------------------------------------------" << endl;

  // Alustetaan huoneiden saatavuus ja asiakkaan nimet
  for (int i = 0; i < MAX_HUONEET; i++) {
    huoneSaatavuus[i] = true;
  };

  cout << "Mikä on sinun nimi?";
  getline(cin, asiakasNimet);
do {  

  menuOptio(MAX_HUONEET, varausHuoneet, optio, virhe);
    
  // Tarkistetaan, onko huone saatavilla
  if (huoneSaatavuus[varausHuoneet-1] == true) {
    cout << "Huone " << varausHuoneet << " on saatavilla." << endl;
// Käyttäjän yömäärän syötteen tarkistus
    yosyoteTarkistus(yoMaara, virhe);

    // Lasketaan nykyisen huoneen hinta ja kokonaishinta
      hintaHuone = HINNAT*yoMaara;
      cout << "Tämän huoneen laskusumma on: " << hintaHuone << " euroa." << endl;
      hintaSummat += hintaHuone;

    // Säilytetään arvoa vektoreihin
      huoneTiedot.push_back(varausHuoneet);
      yoTiedot.push_back(yoMaara);
      hintaTiedot.push_back(hintaHuone);
    // Päivitetään huoneen saatavuus
      huoneSaatavuus[varausHuoneet-1] = false;
      yoMaara = 0;
       cout << "Haluatteko varata muita huoneita: (k) tai (e)?";
      cin >> toista;    
    } else {
           cout << "Huone " << varausHuoneet << " ei ole saatavilla." << endl;
      cout << "Ole hyvä ja valitse itse toinen huonen yötäsi varten. " << endl;
    }
  } while (toista == 'k' || toista == 'K');

  // Kokonaisinfo
  cout << "----------------------------------------------" << endl;
  cout << asiakasNimet << endl;
  for (int i = 0; i < huoneTiedot.size(); i++) {
    cout << "Huone numero " << huoneTiedot[i] << " on varattu sinulle " << yoTiedot[i] << " yöksi (" << hintaTiedot[i] << " euroa)." << endl;
  }
  cout << "Koko laskusumma on: " << hintaSummat << " euroa." << endl;
  cout << "Olkaa hyvä. Avaimet huoneeseenne. Mukavaa lomaa!" << endl;

  return 0;
}

