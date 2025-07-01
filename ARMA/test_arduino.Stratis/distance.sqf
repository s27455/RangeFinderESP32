while {true} do {
    private _distance = player distance cursorObject;  // Pobierz dystans do obiektu, na który celujesz

    hint format ["Dystans: %1m", _distance];  // Wyświetl dystans na ekranie
    systemChat format ["Dystans: %1m", _distance];  // Pokaż w konsoli gry

    // Zapisz dystans do schowka (Clipboard) - Python go odczyta
    copyToClipboard str _distance;

    sleep 1;  // Odśwież co 1 sekundę
};
