import pyperclip
import time

file_path = "C:\\Users\\Tom\\Desktop\\armaRangefinderTest\\arma_distance.txt"

while True:
    try:
        distance = pyperclip.paste().strip()
        if distance and distance.replace(".", "").isdigit():  # Sprawdź, czy to liczba
            with open(file_path, "w") as file:
                file.write(distance)
            print(f"Dystans zapisany: {distance} m")
    except Exception as e:
        print(f"Błąd: {e}")
    
    time.sleep(1)  # Aktualizacja co sekundę
