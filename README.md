# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`

## Question 1: 

Une **lambda** est une fonction anonyme écrite directement à l’endroit où on en a besoin. Dans `std::sort`, elle sert à comparer deux livres pour déterminer lequel vient en premier. 

Dans Library::getBooksSorted, on passe une lambda à `std::sort` :

```cpp
sort(sorted.begin(), sorted.end(), [byTitle](const Book* a, const Book* b) {
        if (byTitle) {
            return toLower(a->getTitle()) < toLower(b->getTitle());
        }
        return toLower(a->getAuthor()) < toLower(b->getAuthor());
    });
```

Les crochets `[key]` permettent à la lambda d’utiliser une copie de la variable `key` pour savoir si elle doit trier par titre ou par auteur. Avec `[&isbn]`, la variable est plutot utilisée par référence, sans être copiée.

Le compilateur transforme la lambda en un objet qui peut être appelé comme une fonction. On utilise `<` pour comparer les valeurs et respecter les règles de tri de `std::sort`.