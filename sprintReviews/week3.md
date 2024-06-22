# Revue de Sprint de la Troisième Semaine pour le Projet Zappy

## Objectifs Initiaux du Sprint

- Refactorisation du GUI pour une meilleure organisation et maintenabilité
- Connectivité entre le GUI et le serveur via ASIO
- Ajout d'une barre de défilement sur le GUI pour modifier la fréquence du jeu
- Finalisation de l'IA pour qu'elle atteigne le niveau 8

## Réalisations

### IA

#### Algorithme de Niveau 8
- L'algorithme permettant à l'IA de six reines d'atteindre le niveau 8 a été finalisé.
- Tests concluants montrant que les reines peuvent maintenant atteindre leur objectif de niveau 8 de manière fiable.

### GUI

#### Refactorisation du GUI
- Réorganisation complète du code du GUI pour améliorer la structure et la maintenabilité.
- Mise en place d'une meilleure encapsulation en C++.
- Introduction de nouveaux modules pour isoler les différentes fonctionnalités, rendant le code plus modulaire et extensible.

#### Connectivité GUI-Serveur avec ASIO
- Intégration de la bibliothèque ASIO pour gérer la connectivité entre le GUI et le serveur.
- Les échanges de données entre le GUI et le serveur sont maintenant plus robustes et réactifs, améliorant l'expérience utilisateur.

#### Barre de Défilement pour Modifier la Fréquence
- Ajout d'une barre de défilement sur le GUI permettant de modifier la fréquence du jeu en temps réel.
- Les utilisateurs peuvent maintenant ajuster la fréquence de manière dynamique, offrant plus de contrôle sur le déroulement du jeu.

### Points Positifs

#### IA
- Finalisation réussie de l'algorithme pour atteindre le niveau 8.
- Les reines atteignent le niveau 8 de manière fiable, atteignant l'objectif ultime du jeu.

#### GUI
- Refactorisation du code améliore la lisibilité, la maintenabilité et la modularité.
- Connectivité entre le GUI et le serveur est plus stable et réactive grâce à ASIO.
- La nouvelle barre de défilement offre une flexibilité accrue aux utilisateurs pour ajuster la fréquence du jeu.

### Points à Améliorer

- Tests : Augmenter le nombre de tests pour assurer la robustesse des nouvelles fonctionnalités et des refactorisations.
- Optimisation : Continuer à améliorer la performance du GUI et de la gestion des ressources.
- Interface Utilisateur : Ajouter plus de feedback visuel et des indications pour guider les utilisateurs dans l'utilisation de la nouvelle barre de défilement.
