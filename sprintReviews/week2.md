# Revue de Sprint de la Deuxième Semaine pour le Projet Zappy

## Objectifs Initiaux du Sprint

- Gestion de la connectivité entre le client IA et le serveur
- Envoi et réception de commandes pour l'IA
- Implémentation des commandes IA (Look, Inventory, Eject, etc.)
- Parsing des flags pour l'IA
- Définition des stratégies de jeu pour l'IA
- Développement de l'algorithme pour atteindre le niveau 8 pour 6 reines
- Amélioration du GUI avec de nouveaux modèles
- Ajout des œufs sur le plateau de jeu
- Refactor du code GUI pour une meilleure encapsulation en C++

## Réalisations

### IA

#### Connectivité Client-Serveur
- Mise en place d'une connectivité robuste entre le client IA et le serveur.
- Les clients IA peuvent se connecter de manière fiable et échanger des commandes avec le serveur.

#### Gestion des Commandes
- Implémentation complète des commandes que le client IA peut envoyer, comme Look, Inventory, Eject, etc.
- Les drones peuvent percevoir leur environnement, gérer leurs inventaires et interagir avec les éléments du jeu.

#### Parsing des Flags
- Le client IA parse correctement les flags spécifiés lors de son lancement, permettant une configuration flexible.

#### Stratégies de Jeu
- Définition de trois comportements pour les drones :
- - Reines : Restent sur leur case, ramassent les ressources, et effectuent des incantations jusqu'à atteindre le niveau 8.
- - Fork Farmers : Déposent leur nourriture par terre et attendent de mourir, générant de nouveaux slots pour les joueurs.
- - Farmers : Récupèrent des ressources pour les reines et reviennent à la base pour les déposer.

- Algorithme de Niveau 8
Développement de l'algorithme permettant à six reines d'atteindre le niveau 8, atteignant l'objectif ultime du jeu.

### GUI

#### Modèles et Assets
- Amélioration et développement de nouveaux modèles sur Blender pour enrichir le plateau de jeu.
- Ajout visuel des œufs sur le plateau, permettant de suivre l'évolution des équipes.

#### Refactor du GUI

- Petit refactor pour améliorer la structure et la maintenabilité du code.
- Meilleure encapsulation en C++, rendant le code plus propre et extensible.

### Points Positifs

#### IA
- Connectivité et échanges de commandes avec le serveur sont fiables.
- Implémentation réussie des commandes IA, permettant une interaction complète avec le jeu.
- Stratégies de jeu définies et testées avec succès, atteignant le niveau 8 pour six reines.

#### GUI
- Amélioration visuelle du plateau de jeu avec de nouveaux modèles.
- Ajout des œufs pour une meilleure représentation de la reproduction des drones.
- Code du GUI refactorisé, améliorant la qualité et la maintenabilité.

### Points à Améliorer

- Tests : Plus de tests sont nécessaires pour assurer la robustesse sous diverses conditions.
- Optimisation : Améliorer la performance de la gestion des ressources et des équipes.
- Fonctionnalités Avancées : Implémentation des fonctionnalités avancées comme la transmission de son et la gestion des interactions complexes.

### Prochaines Étapes

- Continuer l'implémentation des fonctionnalités du serveur :

- - Gestion de la reproduction des joueurs et de l'éclosion des œufs.
- - Gestion des inventaires et de la transmission de son.
- - Implémentation des actions des joueurs (mouvement, collecte, incantation).

- Avancer le développement du GUI :

- - Améliorer la représentation graphique du monde.
- - Intégrer les assets graphiques créés dans Blender.
- - Développer des interactions utilisateur plus avancées.

- Documentation et Tests :

- - Documenter le code et les fonctionnalités.
- - Augmenter la couverture des tests pour assurer la stabilité et la robustesse du système.

Cette revue de sprint montre des progrès significatifs dans le développement de l'IA et du GUI, posant des bases solides pour les prochaines étapes du projet Zappy.

