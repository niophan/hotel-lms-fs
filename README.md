# hotel-lms-fs
# C++ Harjoitustyö: Hotellihuoneen Varausohjelma

## Projektin Tavoite

Tämä ohjelmoinnin perusteiden harjoitustyön tavoitteena on yhdistää kurssilla opittuja ohjelmoinnin käsitteitä ja menetelmiä käytäntöön toimivassa ja hyvin suunnitellussa C++-ohjelmassa. Työn tarkoituksena on kehittää ohjelmointitaitoja ja harjoitella seuraavia osa-alueita:

- Muuttujien, valinta- ja toistorakenteiden, sekä loogisten ja aritmeettisten operaatioiden käyttöä.
- Aliohjelmien suunnittelua ja toteutusta.
- Taulukoiden tai vektorien hyödyntämistä tiedon säilömisessä ja hakemisessa.
- Hyvien ohjelmointitapojen noudattamista, kuten koodin modulaarisuutta, kuvaavia nimiä ja kattavia kommentteja.
- Virheentarkistusta ja käyttäjäystävällisyyden huomioimista.

## Ohjelman Kuvaus

Hotellihuoneen varausohjelma tarjoaa seuraavat toiminnot:

1. **Huoneiden Varaus:**
   - Hotellihuoneet on jaettu yhden ja kahden hengen huoneisiin.
   - Huoneiden määrä vaihtelee (40-300 huonetta), ja ne arvotaan ohjelman alussa.
   - Huoneiden hinnat:
     - 1hh: 100 €/yö
     - 2hh: 150 €/yö
   - Ohjelma arpoo mahdollisen alennuksen (0 %, 10 % tai 20 %) loppusummaan.

2. **Virheentarkistus:**
   - Varmistaa, että syötteet ovat oikeanlaisia ja ohjelma kestää virheellisiä syötteitä kaatumatta.

3. **Varausten Hakeminen:**
   - Varauksia voi hakea joko varausnumerolla tai varaajan nimellä.

4. **Käyttöliittymä:**
   - Selkeä ja monipuolinen valikko, joka ohjaa käyttäjää eri toiminnoissa.

5. **Modulaarisuus:**
   - Ohjelmassa on käytetty useita aliohjelmia, esimerkiksi varausten tarkistamiseen, varausten tallentamiseen ja tiedon hakemiseen.

## Ominaisuudet

- **Satunnaislukujen Käyttö:** Huoneiden määrä ja hinnat arvotaan ohjelman alussa.
- **Tietorakenteet:** Taulukot tai vektorit tallentavat huoneiden varaustiedot.
- **Syötteen Tarkistus:** Virheentarkistus kattaa sekä ei-numeeriset syötteet että huoneiden saatavuuden.
- **Varausnumero:** Satunnaisesti arvottu numero (10000–99999).
- **Käyttäjän Tunnistaminen:** Varaajan nimen tallennus getline-komennolla.

## Tekninen Toteutus

- Ohjelmassa ei ole globaaleja muuttujia, mutta globaaleja vakioita käytetään tarpeen mukaan.
- Työssä on vähintään kaksi olennaisesti erilaista aliohjelmaa:
  + Huoneen varaamisen tarkistava aliohjelma (palauttaa boolean-arvon).
  + Varausten tallentaminen ja hakeminen.
- Kaikki muuttujat ja funktiot on nimetty kuvaavasti.

## Palautus

- **Palautuspäivä:** Maanantai 9.12. klo 23:45
- **Palautettavat tiedostot:**
  - Kaikki ohjelmakoodit.
  - Lyhyt (1–2 sivua) PDF-kuvaus ohjelman sisällöstä ja toiminnasta.
- **Palautustapa:** Git-repositorion jakaminen.

## Arviointikriteerit

| Arvosana | Kriteerit                                                                                   |
|----------|--------------------------------------------------------------------------------------------|
| 0        | Työtä ei palautettu.                                                                      |
| 1        | Perustoiminnallisuus, mutta suuria puutteita tai ohjelma ei toimi oikein.                  |
| 2        | Ohjelma toimii, mutta on suppea tai sisältää puutteita ja bugeja.                          |
| 3        | Hyvä ja selkeä perustoteutus, joka täyttää vaatimukset ilman suuria puutteita.            |
| 4        | Keskivertoa vaativampi ja laadukas toteutus, hyvä ohjelmointityyli ja modularisoitu koodi. |
| 5        | Poikkeuksellisen hyvin toteutettu ja erottuu edukseen muiden töiden joukosta.             |

## Lisäominaisuudet

- Työssä voi toteuttaa omia lisäyksiä ohjelman toimintoihin.
- Palautuksen yhteydessä kommentoi lisäominaisuudet sekä arvio omasta suoritustasosta.

## Vinkit Onnistumiseen

- Suunnittele ohjelman rakenne ja tarvittavat aliohjelmat etukäteen.
- Pidä koodi modulaarisena ja hyvin kommentoituna.
- Testaa ohjelmaa erilaisilla syötteillä varmistaaksesi sen toimivuuden.
- Haasta itsesi ja pyri toteuttamaan mahdollisimman laadukas työ.
