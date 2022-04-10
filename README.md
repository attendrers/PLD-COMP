# Rendu PLD-COMP H4241

## Membres
    - Walid Oulderra
    - Chenya Wu
    - William Jean
    - Huy Tran
    - Thomas Di Bianca
    - Francine Jin
    - Rim Benzekri

## Lancer le programme

Il suffit de se mettre dans le folder compiler `cd compiler` puis lancer un `make` ou `runmake_ubuntu.sh` selon la distribution.

Ceci crée un exécutable ifcc, pour l'utiliser il suffit de l'appeler avec un fichier .c comme 2éme paramètre: `./ifcc file.c`.

## Lancer les tests (! important de make avant)
On peut lancer l'ensemble des tests en se positionnant sur le dossier compiler et lancer `make test` . 

Pour lancer 1 test sur un fichier ou 1 dossier uniquement utiliser le script python comme ceci en se positionnat dans le dossier tests.
`python3 ifcc-test.py testfiles/11_test_functions` pour ne lancer que les tests lié aux fonctions.

## Fonctinnement Générale
On passe l'arbre parsé de antlr à notre premier visiteur ReadVarsVisitor qui s'occupe de lire toutes les variables et créer une structure de données (FunctionData) pour chaque fonction avec une table d'offset, une tables de types , et la dernière position de sa dernière variable. 
Le premier visiteur permet aussi de détecter les erreurs liés aux variables et throw une erreur quand il y ' a  une erreur dans le fichier.

CodeGenVisitor s'occupe de générer le code assembleur en utilisant les différents fonctions de visit.

### Erreurs géré par le compilateur:
    - Redéclaration d'une variable
    - Lors d'une déclaration ou affectation, la variable de droite n'a pas été déclaré.
    - Lors d'une affectation, la variable de gauche n'a pas encore été déclaré.
    - Warning si une variable n'a pas été utilisé (S'écrit comme un commentaire en haut de l'assembleur généré)
    - Appel d'une fonction avec pas assez ou beaucoup de paramètres

## Fonctionnalités
Notre compilateur compile un sous ensemble du langage de programmation C:

    - Déclaration de variables (int et char) et initialisation
    - Déclaration/Affectation d'une expression ou appel de fonction ou une constante à une variable
    - Initialisation d'un char avec constante simple quote (char a = 'a')
    - Opérateurs arithmétiques : + - * /
    - Opéateurs de comparaison: < > >= <= == !=
    - Opérateurs logiques bit-à-bit & ^ |
    - Définition de fonctions avec paramètres de type int/char avec retour int/char/void (Paramètres limité à 12 correspondant aux registres pouvant être utilisés, les paramètres au delà de 12 sont ignorés)
    - Appel de fonctions avec et sans paramètres et utilisation du retour par exemple pour initialiser une variable.
    - Appel de fonctions dans une expression
    - if else (sans imbriquement)
    - while
