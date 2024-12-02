# Vedie_Matteo_Plateau

1. Menu Principal
Le projet démarre avec un menu principal qui comprend :

	- Explication des règles affichées sur un côté.
	- Deux boutons principaux :
		- Jouer : Démarre le jeu en chargeant le niveau principal.
		- Quitter : Ferme l'application.

2. Niveau Principal :jeu de Plateau
Le niveau principal est un plateau de jeu composé de cases. 
Chaque case a un effet différent selon son type. Voici comment elles fonctionnent :
	- Case Neutre : Elles ne font rien de particulier lorsqu’un joueur tombe dessus.Elles servent simplement à déplacer les joueurs.

	- Case Ajoute des Points / Retire des Points : Lorsqu'un joueur tombe sur une de ces cases, on identifie quel joueur est sur la case et on récupère son score actuel.	Ensuite, on ajoute ou retire un certain montant (par exemple, +10 points ou -5 points) au score du joueur.
	Enfin, une notification informe le joueur qu'il a gagné ou perdu des points.

	- Case Déplacement : Lorsqu'un joueur tombe sur cette case, on détermine son ID pour identifier quel joueur est sur la case. Ensuite, il se déplace du nombre de cases 	prédéfini, que ce soit en avant ou en arrière. Pour cela on récupère sa case actuel et la case sur laquelle il va allez pour le faire se déplacer dessus.
	
	- Case Mini-Jeux : Quand le joueur tombe dessus un widget s'affiche pour lui indiquer a quelle mini-jeu il va jouer et un bouton commencer lui permet de lancer le 	mini-	jeu qui sont au nombre de 2 :

		- Mini-Jeu Memory : Le joueur voit un certain nombre de cartes (représentant des billets). Les cartes sont cachées, et le joueur doit cliquer sur celles qui 			correspondent à ce qu'il a mémorisé.
		Les points collectés sont ensuite ajoutés au score du joueur principal.
		
		- Mini-Jeu Collectible : Le joueur contrôle un personnage en vue à la troisième personne.
		Les contrôles sont simples : ZQSD pour se déplacer. Espace pour sauter (avec une animation).
		Le but est de collecter des objets (appelés "collectibles", représentant des billets) dispersés dans le labyrinthe avant que le temps imparti ne s’écoule.
		Les objets collectés ajoutent des points au score, et ils disparaissent une fois ramassés.

	- Fonctionnement des Collectibles :

		Lorsqu’un joueur marche sur un collectible, le système détecte la collision.
		Ensuite, il ajoute la valeur de cet objet au score du joueur.
		Enfin, l’objet disparaît pour éviter qu'il ne soit collecté plusieurs fois.

	- Gestion du Temps :

		Un timer décompte le temps restant. Si le temps atteint zéro, le mini-jeu s’arrête automatiquement, et le joueur retourne au plateau principal.

3. Gestion en C++ : Logique du Mini-jeu Collectible

	a. Gestion des Collectibles
		- Les collectibles sont des objets que le joueur peut ramasser pour gagner ou perdre des points. Ils sont gérés par la classe ACollectible.

		- Chaque collectible contient :
			- Un nombre de points (positif ou négatif).
			- Une interaction automatique lorsqu'un joueur entre en collision avec lui.
			- Une animation de rotation pour le rendre visuellement identifiable.

		- Points attribués :
			- Chaque collectible a une variable Points définie dans le Blueprint, qui peut être configurée pour ajouter ou retirer des points. Lorsqu'un joueur 			interagit avec un collectible (collision), ces points sont transmis au GameMode via la fonction AddToScore().

		- Interaction avec le joueur :
			- Quand un joueur passe sur un collectible, la fonction NotifyActorBeginOverlap() est déclenchée :

				- Elle vérifie si l'objet en collision est un joueur.
				- Elle appelle le GameMode pour ajouter ou soustraire des points au score global.
				- Le collectible est détruit après l'interaction.
	- Résumé des étapes pour un collectible
		- Initialisation :
			- Les collectibles sont créés avec des points configurables et un maillage (mesh) défini dans le Blueprint.

		- Rotation visuelle :
			- Ils tournent en continu grâce à AddActorLocalRotation.

		- Interaction joueur :
			- Quand un joueur passe dessus :

	- On détermine si c'est bien un joueur.
	- On transmet les points au GameMode.
	- Le collectible est détruit après utilisation.


	b. GameMode
	
	- Le score global :
		- Dans le GameMode, la gestion du score est assurée par la variable Score et la fonction AddToScore(). Chaque fois qu'un joueur interagit avec un collectible (par exemple, un billet), le GameMode est appelé via AddToScore() pour ajouter les points correspondants au score global.

	- Le timer pour les mini-jeux
		- Le timer est initialisé dans BeginPlay() et mis à jour chaque seconde avec la fonction UpdateTimer(). Il est utilisé pour limiter la durée des mini-jeux. Q		- Quand le timer atteint zéro la fonction EndGame() est appelée. Elle met le jeu en pause et retourne au menu principal en ouvrant le niveau correspondant 		(ici, le niveau "Game").

	- En résumé :
		- Score global : Géré par la fonction AddToScore(), qui met à jour une variable accessible globalement (Score).
		- Timer des mini-jeux : Utilisé pour décompter le temps restant dans le mini-jeu via UpdateTimer() et la gestion du temps se fait avec FTimerHandle.
		- Fin du jeu : Déclenchée par EndGame(), qui pause le jeu et ouvre un autre niveau.


Feedbacks et Interface Utilisateur

	- Notifications des Cases :
		- Chaque fois qu’un joueur tombe sur une case (par exemple, gagne ou perd des points), un message ou une animation informe le joueur de l'effet appliqué.
	- HUD Principal
		- Affiche des informations essentielles pour les joueurs :
		- Le score actuel.
		- Le temps restant pour les mini-jeux.
	- Écran de Fin
		- Lorsque le jeu se termine, un écran affiche le joueur gagnant, c'est-à-dire celui qui a accumulé le plus de points.

