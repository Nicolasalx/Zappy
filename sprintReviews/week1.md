# Revue de Sprint de la Première Semaine pour le Projet Zappy

## Objectifs Initiaux du Sprint

- Mise en place du serveur
- Gestion de la connectivité avec les clients
- Création du monde de jeu en forme de torus
- Génération des ressources sur le sol
- Gestion des équipes
- Parsing des flags
- Implémentation de commandes d'aide pour l'utilisateur
- Finalisation du serveur
- Début du développement de l'interface graphique (GUI)
- Connexion du GUI au serveur
- Gestion des commandes reçues par le GUI
- Gestion des flags du GUI
- Recherche et création d'assets graphiques pour le plateau de jeu

## Réalisations
### Serveur

#### Connectivité Client:

- Le serveur est capable d'accepter de nouveaux clients.
- Il gère la réception et l'envoi de messages avec les clients.


#### Création du Monde:

- Le monde a été généré en tant que torus, ce qui signifie que les bords se connectent (gauche-droite et haut-bas).

#### Génération des Ressources:

- Les ressources (alimentaires et minérales) sont générées de manière équitable sur le sol, selon les règles définies (densité des ressources).

#### Gestion des Équipes:

- Le serveur peut gérer plusieurs équipes et attribuer les clients aux équipes correspondantes.

#### Parsing des Flags:

- Tous les flags spécifiés dans la ligne de commande sont correctement parsés et interprétés.

#### Commandes d'Aide:

- Implémentation des commandes spéciales comme "give", "immortal" et "tp" pour faciliter le développement et les tests.
#### Finalisation du Serveur:

- Le serveur a atteint un état fonctionnel initial, capable de gérer les connexions, la génération de ressources et la gestion des équipes.

### GUI

#### Connectivité:

- Le client GUI est capable de se connecter au serveur.

#### Gestion des Commandes:

- Le GUI peut recevoir et interpréter les commandes envoyées par le serveur.

#### Gestion des Flags:

- Les flags spécifiés pour le GUI sont correctement parsés et utilisés.

#### Recherche et Création d'Assets:

- Recherche de différents assets graphiques.
- Création de modèles 3D sur Blender pour représenter le plateau de jeu.

### Points Positifs

#### Avancée du Serveur:
- La connectivité et la gestion des messages fonctionnent correctement.
- Le monde de jeu et les ressources sont bien générés.
- Les équipes sont correctement gérées.

#### GUI:
- Le GUI est capable de se connecter et de communiquer avec le serveur.
- Les bases de la gestion des commandes et des flags sont en place.
- Les premières étapes de la création graphique sont complétées avec succès.

### Points à Améliorer
- Tests:
Plus de tests doivent être effectués pour s'assurer que le serveur et le GUI fonctionnent correctement sous diverses conditions.

- Optimisation:
Optimisation de la gestion des ressources et des équipes pour améliorer la performance.

- Fonctionnalités Avancées:
Implémentation des fonctionnalités avancées comme la reproduction des joueurs, la gestion des inventaires et la transmission de son.

#### Prochaines Étapes

- Continuer l'implémentation des fonctionnalités du serveur:
- - Gestion de la reproduction des joueurs et de l'éclosion des œufs.
- - Gestion des inventaires et de la transmission de son.
- - Implémentation des actions des joueurs (mouvement, collecte, incantation).

- Avancer le développement du GUI:
- - Améliorer la représentation graphique du monde.
- - Intégrer les assets graphiques créés dans Blender.
- - Développer des interactions utilisateur plus avancées.

- Documentation et Tests:
- - Documenter le code et les fonctionnalités.
- - Augmenter la couverture des tests pour assurer la stabilité et la robustesse du système.


Cette revue de sprint montre que nous avons bien avancé sur les fondations du projet Zappy et que nous avons une bonne base pour les prochains développements.

