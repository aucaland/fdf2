# Fil De Fer (FDF)

## Installation and compilation :
- X11 Lib has to be installed :
```bash
sudo apt update
sudo apt install libxext-dev libx11-dev zlib1g-dev libpng-dev
```
- And *libbsd* too :
```bash
sudo apt install libbsd-dev
```

## Résumé
Ce projet consiste à créer graphiquement la représentation schématique d’un terrain en relief.

---

## Préambule

La représentation en relief d’un terrain est une pratique essentielle en cartographie moderne. Elle est cruciale pour l'exploration spatiale ou l’étude des phénomènes tectoniques.

Votre tâche est de modéliser un terrain en trois dimensions en utilisant la bibliothèque MiniLibX.

---

## Introduction

La MiniLibX est une bibliothèque graphique développée en interne qui permet d’ouvrir une fenêtre, créer des images et gérer des événements clavier/souris. Ce projet vous permettra d'apprendre les bases de la programmation graphique, en plaçant et reliant des points dans l’espace.

---

## Objectifs

- Prendre en main la MiniLibX.
- Découvrir la programmation graphique.
- Apprendre à observer une scène en 3D depuis un point de vue donné.

---

### Nom du programme
`fdf`

### Fichiers de rendu
`Makefile`, `*.h`, `*.c`

### Arguments
Un fichier au format `*.fdf`

### Fonctions externes autorisées

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- Bibliothèque mathématique `-lm`
- Toutes les fonctions de la MiniLibX
- `ft_printf` ou équivalent personnel

### Description

Ce projet consiste à créer le rendu fil de fer d’un paysage en reliant les points `(x, y, z)` par des segments.

#### Rendu

- Utilisation d'une **projection isométrique**.
- Lecture des coordonnées depuis un fichier `.fdf` contenant des valeurs d’altitude.

