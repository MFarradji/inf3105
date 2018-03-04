# INF3105 - TP1 Hiver 2018 - Dictionnaire

## Exemple pour lire l'entrée standard (pseudo-code)
```
main() {
  Créer une structure de données pour contenir les mots du dictionnaire.
  Créer un tableau de chaînes qui va contenir tous les mots d'une ligne.
  Créer une chaîne de caractères initialement vide.
  Tant que la commande "Quitter" n'est pas entrée:
    Lire un caractère.
    Si le caractère n'est pas un espace, une tabulation ou une fin de ligne:
      Ajouter le caractère dans la chaîne
    Sinon si la chaîne n'est pas vide:
      Ajouter la chaîne dans la ligne
      Vider la chaîne
    Si le caractère est une fin de ligne:
      Traiter la ligne
      Vider la ligne
}
```
