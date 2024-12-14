# hotel-lms-fs
Kuten edellä, mutta huoneita on parillinen määrä välillä 40–300, ja niistä puolet (alkupuoli) on yhden hengen ja puolet (loppupuoli) kahden hengen huoneita. Ohjelman valikko pitää olla toteutettu monipuolisesti ja havainnollisesti. Ohjelman pitää suoriutua mahdollisista ongelmatilanteista. Ohjelmassa voidaan varattavat huoneet joko arpoa koneella tai valita käyttäjän toimesta. Varmistu kuitenkin aina siitä, että huonetyyppi on saatavilla(varattavissa).

Huonehinnat ovat

·         1hh: 100 euroa yöltä ja  

·         2hh: 150 euroa yöltä,

Ohjelma arpoo, annetaanko huoneiden loppuhintaan 0 %:n, 10 %:n vai 20 %:n alennus.

Käyttäjä antaa huonekoon ja öiden määrän, ja ohjelma ilmoittaa laskun loppusumman mahdollisen alennuksen jälkeen.

Ohjelma on valmis varaamaan huoneita niin kauan kuin käyttäjä haluaa, kuitenkin enintään em. määrät yhden ja kahden hengen huoneita. Ohjelma tarkistaa aina huonetyypin ennen varausta, jotta voidaan varmistua niiden saatavuudesta.

Ohjelmassa on muodostettu ainakin kaksi olennaisesti erilaista aliohjelmaa.

aikissa yllä mainituissa vaihtoehdoissa on tehtävä virheentarkistus käyttäjän syötteille! 4-5 p työssä listaa lisäksi palautuksen kommenttikenttään ne lisäominaisuudet, jotka olet toteuttanut. Merkitse myös minkä arvosanan mukaisesti olet mielestäsi toteuttanut työn.  

 

Muita harjoitustyön rajauksia, jotka tulee ottaa lopputyössä huomioon:

Varausnumero: (int) on oltava välillä 10000-99999. Ohjelma arpoo varausnumeron satunnaisesti.

Varaajan nimi: (string) esim. Osto, käytä siis getline -komentoa syötteen lukemiseen.

Uutta varausta tehdessäsi, tarkista ensin kyseisen huoneen varaus boolean tyyppisellä aliohjelmalla.

Huoneet -taulukon (tai vektorin) ylärajan voit asettaa 300 huoneeseen. Jos huoneita on tuo

maksimimäärä, niin silloin yhden hengen huoneita on max. 150kpl ja kahden hengen 150kpl.

Ohjelmassa pitää olla mahdollisuus tehdä hakuja varauksiin joko varausnumerolla tai varaajan nimellä.

 

Ohjelman menun rakenteen voit itse suunnitella. Varmistu kuitenkin ensin siitä, että olet ottanut

huomioon sen, mitkä osat ohjelmassa kuuluu toteuttaa. Voit lisäksi tehdä ohjelmaan omia lisäyksiä

sen mukaan, kun aikaa ja energiaa riittää ohjelman tekemiseen. Tähän on loppukurssi aikaa varattuna.

Älä yritä mennä siitä, mistä aita on matalin, vaan haasta itsesi ja pyri aina parhaaseen lopputulokseen.

Ennen kuin alat tekemään varsinaista koodausosuutta, suunnittele ohjelmassa tarvittavat asiat ja niiden

toteutus huolella. Tämä tulee säästämään sinulta paljon aikaa varsinaisen koodin kirjoitusvaiheessa.