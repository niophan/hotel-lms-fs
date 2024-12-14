#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>



using namespace std;


struct AsiakasInfo
{
  string asiakasNimet;
  vector <int>  huoneTiedot,  
                yoTiedot,
                hintaTiedot;
  int kokonaisHinnat;
};

struct KirjanPito
{
  string varausNumero;
  AsiakasInfo aData;
};

// Funktio prototype
void yleinenTarkistus(bool&virhe);
void menuOptio(const int MAX_HUONEET,  int& varausHuoneet, bool& virhe, KirjanPito& asiakas, vector <KirjanPito>& extractData);
void huonesyoteValinta(const int MAX_HUONEET, int& varausHuoneet, bool& virhe);
void satunnaisValinta(int MAX_HUONEET, int& varausHuoneet, bool& virhe);
void hakuVaraus(KirjanPito& asiakas, vector <KirjanPito>& extractData, bool& virhe);
void yosyoteTarkistus(int& yoMaara, bool& virhe);
void hinnaLaskenta(const int MAX_HUONEET, const int YHH_HINNAT, const int KHH_HINNAT, int& varausHuoneet, int& perusHinnat, int& yoMaara, double& alennusTulos);
void asiakasInfot(KirjanPito& asiakas, int& varausHuoneet, int& yoMaara, int& perusHinnat);
void writeFile(KirjanPito& asiakas, const string filename);
void readFile(vector<KirjanPito>& asiakkaat, vector<KirjanPito>& extractData, const string filename, bool huoneSaatavuus[]);

// Yleinen tarkistus 
void yleinenTarkistus(bool& virhe) {
  cout << "Virhe! Valita uudelleen" << endl;;
  virhe = true;
  cin.clear();
  cin.ignore(80, '\n');
};

// MENU OPTIO
void menuOptio(int MAX_HUONEET,  int& varausHuoneet, bool& virhe, KirjanPito& asiakas, vector <KirjanPito>& extractData) {
  char optio;
  cout << "(A) Haluaisitteko itse valita huoneen numeron?" << endl;
  cout << "(B) Tai haluaisitteko, että annamme teille satunnaisen huoneen numeron?" << endl;
  cout << "(C) Tai haluatteko, että tarkistan huoneen saatavuuden?" << endl;
  cout << "(D) Tai haluatteko poistaa kaikki huoneiden valinnat ja poistua?" << endl;

  do {
    virhe = false;
    cout << "Valitse (A) tai (B) tai (C) tai (D):";
    cin >> optio;

    switch (optio)
    {
      case 'A' :  huonesyoteValinta(MAX_HUONEET, varausHuoneet, virhe);
                  break;       
      case 'B' :  satunnaisValinta(MAX_HUONEET, varausHuoneet, virhe);
                  break;         
      case 'C' :  hakuVaraus(asiakas, extractData, virhe);
                  break;
      case 'D' :  cout << "Kiitos käynnistä!";
                  exit(0);
                  break;                        
      default  :  yleinenTarkistus(virhe);
    }
  } while(virhe);
}


// Itse huoneen varaus ja syötteen tarkistus
void huonesyoteValinta(int MAX_HUONEET, int& varausHuoneet, bool& virhe) {
  char optio;
  int keskiPointi = MAX_HUONEET/2;
  bool optioVirhe;
  cout << "Onko varauksenne yhdelle henkiölle (A) vai kahdelle (B)?" << endl;
  do {
      virhe = false;     
      cout << "Valitse (A) tai (B):";
      cin >> optio;

      if(optio == 'A') {
        do {
          optioVirhe = false;
          cout << "Valitsehan huoneen numero välillä 1-"<< keskiPointi << ":" << endl;
          cin >> varausHuoneet;
          if (cin.fail() || varausHuoneet <= 0 || varausHuoneet > keskiPointi) {
            yleinenTarkistus(optioVirhe);
          }
        } while(optioVirhe);
      } else if (optio == 'B') {
          do {
            optioVirhe = false;
            cout << "Valitsehan huoneen numero välillä " << MAX_HUONEET/2 + 1 << "-" << MAX_HUONEET << ":" << endl;
            cin >> varausHuoneet;
            if (cin.fail() || varausHuoneet < (keskiPointi+1) || varausHuoneet > MAX_HUONEET) {
              yleinenTarkistus(optioVirhe);
            }
          } while(optioVirhe);        
      } else {
          yleinenTarkistus(virhe);
      }
    } while(virhe);
};


// Satunnais huoneen varaus
void satunnaisValinta(int MAX_HUONEET, int& varausHuoneet, bool& virhe) {
  char optio;
  int keskiPointi = MAX_HUONEET/2;
  cout << "Onko varauksenne satunnaisesti yhdelle henkiölle (A) vai kahdelle (B) ?" << endl;
    do {
      virhe = false;     
      cout << "Valitse (A) tai (B):";
      cin >> optio;

      if(optio == 'A') {
        varausHuoneet = 1 + rand() % keskiPointi;
      } else if (optio == 'B') {
        varausHuoneet = 1 + keskiPointi + rand() %  (MAX_HUONEET - keskiPointi);
      } else {
        yleinenTarkistus(virhe);
      }
    } while(virhe);
};

// Hakuvaraus
void hakuVaraus(KirjanPito& asiakas,vector <KirjanPito>& extractData, bool& virhe) {
  string tieto;
  virhe = false;
  cin.ignore(80, '\n');
  cout << "Anna meille jonkun varaustiedot joko varausnumerot tai kokonaisnimet: ";
  getline(cin, tieto);
  if(tieto == asiakas.varausNumero || tieto == asiakas.aData.asiakasNimet) {
    cout << "Siinä ei ole mitään tietoja, kun käytät ohjelmaa ensimmäistä kertaa!" << endl;
    cout << "Kokeile uudelleen! Kiitos!" << endl;
    exit(0);
  };

  for (const auto& customer : extractData) {
        if (customer.aData.asiakasNimet == tieto || customer.varausNumero == tieto) {
            cout << "Tietoja on löytetty" << endl;
            cout << "Nimet: " << customer.aData.asiakasNimet << endl;
            cout << "Varausnumero: " << customer.varausNumero << endl;
            cout << "Sinun tietojen perusteella nämä huoneet eivät ole saatavilla: ";
            for (int huoneSaatavuus : customer.aData.huoneTiedot) {
              cout << huoneSaatavuus << " ";
            }
            cout << endl;
            cout << "Huone on varattu toiselle asiakkaalle." << endl;
            cout << "Aloita ohjelmaa uudelleen! Kiitos" << endl;
            virhe = true;
            exit(0);
        }
    }


    if (!virhe) {
        cout << "Antamasi tiedot eivät pidä paikkaansa! Kokeile uudelleen!" << endl;
        exit(0);
    }

};

// Yömäärän syötteen tarkistus
void yosyoteTarkistus(int& yoMaara, bool& virhe) {
  do {
      virhe = false;
      cout << "Kuinka monta yötä te haluatte yöpyä? ";
      cin >> yoMaara;
      if (cin.fail() || yoMaara <= 0) {
        yleinenTarkistus(virhe);
      }
    } while(virhe); 
};

// Hinnat laskeminen
void hinnaLaskenta(const int MAX_HUONEET, const int YHH_HINNAT, const int KHH_HINNAT, int& varausHuoneet, int& perusHinnat, int& yoMaara, double& alennusTulos) {
  double alennusProsentti;

  if(varausHuoneet <= (MAX_HUONEET/2)) {
    if (alennusTulos == 0) {
      perusHinnat = (yoMaara*YHH_HINNAT);
    cout << "Alennuksia ei ole saatavilla!" << endl;
    } else {
    alennusProsentti = alennusTulos;
      perusHinnat = (yoMaara*YHH_HINNAT)* alennusTulos;
    cout << "(Saat " << (1-alennusProsentti)*100 <<" prosenttia alennusta hinnasta!)" << endl;
    };
    cout << "Tämän yhden hengen huoneen numero (" << varausHuoneet << ") hinta on : " << perusHinnat << " euroa." << endl;

    
  } else {
    if (alennusTulos == 0) {
      perusHinnat = (yoMaara*KHH_HINNAT);
    cout << "Alennuksia ei ole saatavilla!" << endl;
    } else {
    alennusProsentti = alennusTulos;
      perusHinnat = (yoMaara*KHH_HINNAT)* alennusTulos;
    cout << "(Saat " << (1-alennusProsentti)*100 <<" prosenttia alennusta hinnasta!)" << endl;
    };
    cout << "Tämän kahden hengen huoneen numero (" << varausHuoneet << ") hinta on : " << perusHinnat << " euroa." << endl;

  }
};

// Säilytetään asiakkaiden tiedot
void asiakasInfot(KirjanPito& asiakas, int& varausHuoneet, int& yoMaara, int& perusHinnat) {
  asiakas.aData.huoneTiedot.push_back(varausHuoneet);
  asiakas.aData.yoTiedot.push_back(yoMaara);
  asiakas.aData.hintaTiedot.push_back(perusHinnat);
  asiakas.aData.kokonaisHinnat += perusHinnat;
};

void readFile(vector<KirjanPito>& asiakkaat,vector<KirjanPito>& extractData, const string filename, bool huoneSaatavuus[]) {
  string line;
  KirjanPito asiakas;
  ifstream readFile(filename);
  if (readFile.is_open()) {
    while (getline(readFile, line)) {
        if (line.find("Varausnumero:") != string::npos) {
            asiakas.varausNumero = line.substr(line.find(":") + 2); 
        } 
        else if (line.find("Asiakas:") != string::npos) {
            asiakas.aData.asiakasNimet = line.substr(line.find(":") + 2);
        } 
        else if (line.find("Varattu huone numero:") != string::npos) {
            int huoneNumero = stoi(line.substr(line.find(":") + 2));
            asiakas.aData.huoneTiedot.push_back(huoneNumero);
            huoneSaatavuus[huoneNumero -1 ] = false;
        }
        else if (line.find("Yömäärät vastaavasti:") != string::npos) {
            int yo = stoi(line.substr(line.find(":") + 2));
            asiakas.aData.yoTiedot.push_back(yo);
        }
        else if (line.find("Hinta: ") != string::npos) {
            int hinta = stoi(line.substr(line.find(":") + 2));
            asiakas.aData.hintaTiedot.push_back(hinta);  
        }
        else if (line.find("Summa:") != string::npos) {
            asiakas.aData.kokonaisHinnat = stoi(line.substr(line.find(":") + 2)); 
            extractData.push_back(asiakas); 
            asiakas = KirjanPito();  
        }
    }
    readFile.close();
  } else {
    cout << "Virhe: Tiedostoa ei voitu avata." << endl;
  }
};

void writeFile(KirjanPito& asiakas, const string filename) {
  auto now = chrono::system_clock::now();
  ofstream writeFile(filename, ios::app);
  time_t now_time = chrono::system_clock::to_time_t(now);

   if (writeFile.is_open()) {
    writeFile << "Varausnumero: " << asiakas.varausNumero << endl;
    writeFile << "Asiakas: " << asiakas.aData.asiakasNimet << endl;

    for(int i = 0; i < asiakas.aData.huoneTiedot.size(); i++) {
      writeFile << "Varattu huone numero: " << asiakas.aData.huoneTiedot[i]
                << ", Yömäärät vastaavasti: " << asiakas.aData.yoTiedot[i]
                << ", Hinta: " << asiakas.aData.hintaTiedot[i] << " euroa." << endl;
    }

    writeFile << "Summa: " << asiakas.aData.kokonaisHinnat << " euroa." << endl;

    writeFile << "Aika: " << ctime(&now_time) << endl;
    writeFile.close();
    cout << "Tiedosto kirjoitettu onnistuneesti." << endl;
  } else {
    cout << "Virhe: Tiedostoa ei voitu avata." << endl;
  }

  

};


int main() {
  srand(time(0));

  // Data-asetukset
  const int MAX_HUONEET = 300;
  const int YHH_HINNAT = 100;
  const int KHH_HINNAT = 150;
  const string filename = "/Users/nerdylab/C++/Projects/hotelli-c/kirjanpito.txt";
  bool huoneSaatavuus[MAX_HUONEET], virhe;
  int varausHuoneet, perusHinnat = 0, yoMaara = 0;
  double satunnaisPercentti, alennusTulos;
  char toista;
  vector <KirjanPito> asiakkaat, extractData;
  asiakkaat.push_back(KirjanPito());
  asiakkaat.back().aData.kokonaisHinnat = 0;
  asiakkaat.back().varausNumero = to_string(10000 + rand() % 90000);

  // Alustetaan huoneiden saatavuus ja asiakkaan nimet
  for (int i = 0; i < MAX_HUONEET; i++) {
    huoneSaatavuus[i] = true;
  };

  // Arvotaan alennusHinta
  satunnaisPercentti = (double)rand() /RAND_MAX;
  if (satunnaisPercentti <0.33)
  {
    alennusTulos = 0;
  } else if (satunnaisPercentti < 0.66) {
    alennusTulos = 0.9;
  } else {
    alennusTulos = 0.8;
  }
  
  // Saadaan tiedot txt-tiedostosta
  readFile(asiakkaat, extractData, filename, huoneSaatavuus);
  
  // Annetaan huoneen saatavuudet ja hinnat asiakkaalle:
  cout << "Hyvää päivää, ja tervetuloa hotelliimme!" << endl;
  cout << "---------------------------------------------" << endl;
  cout << "Meidän hotelissamme on " << MAX_HUONEET << " huonetta." << endl;
  cout << "Yhden hengen huoneen hinta on " << YHH_HINNAT << " euroa yöltä." << endl;
  cout << "Kahden hengen huoneen hinta on " << KHH_HINNAT << " euroa yöltä." << endl;
  cout << "---------------------------------------------" << endl;

  cout << "Mikä on sinun nimi? ";
  getline(cin, asiakkaat.back().aData.asiakasNimet);
  cout << "Voinko auttaa huoneen varaamisessa? " << endl;
  cout << "Sinun varausnumero on: " << asiakkaat.back().varausNumero << endl;
  cout << "---------------------------------------------" << endl;

  do {  
    menuOptio(MAX_HUONEET, varausHuoneet, virhe, asiakkaat.back(), extractData);
    
    // Tarkistetaan, onko huone saatavilla
    if (huoneSaatavuus[varausHuoneet-1] == true) {
      cout << "Huone " << varausHuoneet << " on saatavilla." << endl;
      
      // Käyttäjän yömäärän syötteen tarkistus
      yosyoteTarkistus(yoMaara, virhe);

      //Lasketaan nykyisen huoneen hinta ja kokonaishinta
      hinnaLaskenta(MAX_HUONEET, YHH_HINNAT, KHH_HINNAT, varausHuoneet, perusHinnat, yoMaara, alennusTulos);
      
      // Säilytetään arvoa vektoreihin
      asiakasInfot(asiakkaat.back(), varausHuoneet, yoMaara, perusHinnat);

      // Päivitetään huoneen saatavuus
      huoneSaatavuus[varausHuoneet-1] = false;
      yoMaara = 0;

      cout << "Haluatteko varata muita huoneita: (k) tai (e)?";
      cin >> toista;    
    } else {
      cout << "Edellinen huoneen numero (" << varausHuoneet << ") on varattu." << endl;
      cout << "Ole hyvä ja valitse itse toinen huonen yötäsi varten. " << endl;
    }
  } while (toista == 'k' || toista == 'K');

  // Lisätään tiedot txt-tiedostoon
  writeFile(asiakkaat.back(), filename);
  
  // Kokonaisinfo
  cout << "-------------------------------------------------------------------------" << endl;
  cout << "Kiitos varauksestanne! Olemme vastaanottaneet varauksenne onnistuneesti!" << endl;
  cout << "-------------------------------------------------------------------------" << endl;

  cout << "Moi " << asiakkaat.back().aData.asiakasNimet <<  "," << endl;
  cout << "Varaustietonne on seuraava:" << endl;
  cout << "Varausnumero on " << asiakkaat.back().varausNumero << "." <<endl;
  for (int i = 0; i < asiakkaat.back().aData.huoneTiedot.size(); i++) {
    cout << "Huone numero " << asiakkaat.back().aData.huoneTiedot[i] << " on varattu sinulle " 
    << asiakkaat.back().aData.yoTiedot[i] << " yöksi (" 
    << asiakkaat.back().aData.hintaTiedot[i] << " euroa)." << endl;
  }
  cout << "Koko laskusumma on: " << asiakkaat.back().aData.kokonaisHinnat << " euroa." << endl;
  cout << "-------------------------------------------------------------------------" << endl;
  cout << "Kiitos, että valitsitte hotellimme!  Odotamme innolla vierailuanne." << endl;

  return 0;
}
