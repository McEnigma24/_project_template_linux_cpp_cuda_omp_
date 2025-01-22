#!/bin/bash

# Znajdź zmienione pliki w stage (dodane lub zmodyfikowane), które są plikami C, CPP, H, HPP
FILES=$(git diff --cached --name-only --diff-filter=ACM | grep -E '\.(c|cpp|h|hpp)$')

# Jeśli nie znaleziono plików, zakończ skrypt
if [ -z "$FILES" ]; then
    echo "Brak plików do formatowania."
    exit 0
fi

# Formatowanie zmienionych plików
echo "Formatowanie zmienionych plików za pomocą ClangFormat..."
for FILE in $FILES; do
    echo "$FILE"
    clang-format -i "$FILE"        # Formatowanie pliku
    git add "$FILE"                # Ponowne dodanie do stage po formatowaniu
done

echo "Pliki sformatowane i dodane do commita."
exit 0