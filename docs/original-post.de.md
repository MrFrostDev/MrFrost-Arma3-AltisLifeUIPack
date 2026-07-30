# Originaler Forenbeitrag

Archivkopie des Release-Beitrags aus dem Native-Network-Forum. Der Beitrag lag
dem Download als `Beitrag.txt` bei; diese Datei ist beim Aufräumen für dieses
Repository aus `src/` entfernt und hier abgelegt worden.

Der Text ist unverändert im Wortlaut wiedergegeben — inklusive Rechtschreibung
und Zeilenumbrüchen —, weil die Original-URL und der Dateianhang irgendwann
verschwinden werden. Er ist reines Archivmaterial und **keine Anleitung**: die
Hinweise zum tatsächlichen Umgang mit den Dateien stehen in
[installation.md](installation.md), die bekannten Fehler in
[known-issues.md](known-issues.md).

---

## Beitrag (Beitrag.txt)

Moin Leute,

Nach einigen Jahren habe ich meine Festplatte wieder aufgeräumt und noch einige Dinge gefunden, die für den Papierkorb zu schade sind.

Folgend finden Sie den ersten Upload einer Mission mit einigen UIs, die damals als Auftragsarbeit erstellt wurden. Das Projekt ist nie zustande gekommen, weshalb ich jetzt einfach alles raushauen werde, was ich dazu noch habe.

Das Projekt besitzt keine Rechte an den UIs, ich besitze jedoch auch keine an ihrem Logo. Da ich schon seit einer Weile nicht mehr in Arma unterwegs bin, mache ich mir nicht die Arbeit, die Logos noch auszutauschen. Sollte der Inhaber des Logos damit ein Problem haben, kann er gerne Kontakt zu mir aufnehmen, ich werde die Datei dann noch einmal abändern.

Ich übernehme keinen Support für diesen Upload.

Ich bitte euch, die Dateien nicht an anderer Stelle hochzuladen, dieser Download soll der Native-Network/Native-Servers Community vorbehalten bleiben.

Viel Spaß mit dem Download

MrFrost

---

## Anmerkung 2026

**Das Logo ist inzwischen ausgetauscht.** Im Beitrag steht, dass sich der Autor
die Arbeit nicht mehr macht, die Logos zu ersetzen. In diesem Repository ist das
nachgeholt: `pictures/GUI/Logo_Mammut.paa` ist eine erzeugte, vollständig
transparente 1024×1024-DXT5-Datei. Sie lädt fehlerfrei und zeichnet nichts. Der
Dateiname und alle fünf Verweise in den Dialogen bleiben unverändert, damit der
Code exakt so bleibt, wie er veröffentlicht wurde. Details in
[`src/Dialog.VR/pictures/GUI/README.md`](../src/Dialog.VR/pictures/GUI/README.md).

**Zur Bitte, die Dateien nicht anderswo hochzuladen.** Diese Bitte war die des
Autors selbst und richtete sich 2021 an die Leser des Forums. Dieses Repository
ist die Veröffentlichung des Autors selbst — es ist keine Weiterverbreitung
durch Dritte. Zu den Rechten an den enthaltenen Fremddateien siehe den Abschnitt
*Terms* in der [README](../README.md).

**Zum Zustand des Codes.** Der Satz „Ich übernehme keinen Support für diesen
Upload“ gilt weiterhin. Der Inhalt ist seit 2021 nicht mehr ausgeführt worden
und wird nicht gewartet. Was vor einem Einsatz zu beachten ist — allen voran das
nirgends definierte Makro `MrFrost_IDD_Interaction` und der Umstand, dass zu den
Dialogen **keine** Steuerungsfunktionen mitgeliefert werden —, steht in
[known-issues.md](known-issues.md).
