# Projet Programmation
Projet de programmation effectué en première année d'école d'ingénieurs.
![alt text](https://github.com/vavab/projet-programmation/blob/main/sch%C3%A9ma-archi-logicielle.png)
## Sujet
Le but du projet est de d'analyser la base de données des arbres de Paris, stockée au format CSV, afin d'en
extraire un sous-arbre (au sens des graphes) de poids minimum.
Imaginez que vous vouliez relier tous les arbres de Paris avec des cordes, de telle sorte que les écureils
puissent se balader partout. Cependant vous voulez utiliser le moins de corde possible.
Votre programme doit accepter au moins deux arguments -i BASE_DE_DONNEEE et -o
FICHIER_DE_SORTIE afin d'indiquer où se situe le fichier CSV de la base de donnée, et où doit être
sauvegarder le résultat.
Le projet doit s'effectuer seul. Vous devez écrire un rapport (max 5 pages) expliquant rapidement la
structure de votre programme et vos choix d'implémentation. Le code source et le rapport doivent
être déposé sur un projet git sur le git de l'unistra (l'enseignant doit être ajouté dans les membres du
projet pour y avoir accés). 
Vous avez le droit d'utiliser du code source trouvé sur internet, mais vous devez le cité clairement dans le
code source et vous devez comprendre ce que vous avez copié (il pourra y avoir des questions dessus par
exemple du type "à quoi sert cette ligne", donc ne copiez que ce que vous comprennez entièrement).
La grille de notation sera similaire au projet de programmation. C'est-à-dire que la note tiendra compte de
la clareté du code, de la structure, des choix d'implémentation, des tests et de la quantité de choses
réalisées.
Notamment vous devez:
organisez vos fichier correctement
écrire un makefile afin des règles appropriées
rendre un projet qui compile sans erreurs ni warning.
écrire des tests qui permettent de vérifier que vos fonctions sont correctes.
Détail sur le projet
Votre programme doit prendre un fichier csv contenant la position des arbres de paris (disponible à
l'adresse suivante: https://opendata.paris.fr/explore/dataset/les-arbres/information/ ), et doit donner en
sortie un fichier texte contenant les informations suivantes:
La longueur totale de corde nécessaire pour relier tous les arbres entre eux.
la liste des paires d'arbres à relier par une corde (on pourra utiliser l'identifiant des arbres de la base
de données).
Pour cela vous devez représenter la base de données des arbres par un graphe en mémoire à l'aide de
structures de données adaptées. Vous devez ensuite calculer à l'aide d'un algorithme le plus petit sous-graphe permettant de connecter tous les arbres. La gestion des arguments de ligne de commande doit être
modulaire (par exemple, vous pouvez utiliser getopt). Les différentes parties de votre programme doivent
être correctement découpées et organisées. Les fichiers d'entêtes doivent être clairement documentés.
