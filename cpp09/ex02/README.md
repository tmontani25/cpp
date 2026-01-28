# PmergeMe - Algorithme Ford-Johnson (Merge-Insert Sort)

## 📚 Qu'est-ce que l'algorithme Ford-Johnson ?

L'algorithme **Ford-Johnson** (aussi appelé **Merge-Insert Sort**) est un algorithme de tri qui minimise le nombre de comparaisons nécessaires pour trier une séquence. Il est considéré comme optimal ou proche de l'optimal en termes de comparaisons.

**Référence** : "The Art of Computer Programming, Vol. 3", Donald Knuth, Page 184.

## 🎯 Principe de l'algorithme

L'algorithme fonctionne de manière **récursive** en suivant ces étapes :

### 1️⃣ Former des paires
On groupe les éléments par paires consécutives.
```
[5, 2, 8, 1, 9, 3, 7, 4]  →  [(5,2), (8,1), (9,3), (7,4)]
```

### 2️⃣ Trier chaque paire localement
Dans chaque paire, on met le plus petit en premier, le plus grand en second.
```
[(5,2), (8,1), (9,3), (7,4)]  →  [(2,5), (1,8), (3,9), (4,7)]
```

### 3️⃣ Extraire les "grands" éléments
On prend tous les seconds éléments de chaque paire (les "max").
```
[(2,5), (1,8), (3,9), (4,7)]  →  maxList = [5, 8, 9, 7]
```

### 4️⃣ RÉCURSION : Trier les "grands"
On applique **récursivement** l'algorithme Ford-Johnson sur la liste des "grands".
```
mergeInsertSort([5, 8, 9, 7])  →  [5, 7, 8, 9]
```

Cette étape est **cruciale** : c'est ce qui rend l'algorithme récursif et efficace !

### 5️⃣ Insérer les "petits" avec recherche binaire
Une fois les "grands" triés, on insère les "petits" (premiers éléments des paires) en utilisant la **recherche binaire**.

**Optimisation Ford-Johnson** : Pour chaque "petit" à insérer, on sait qu'il est forcément ≤ à son "grand" associé. Donc on limite la recherche binaire jusqu'à la position de son "grand".

```
Grands triés : [5, 7, 8, 9]
Petits à insérer : [2, 1, 3, 4]

- Insérer 2 (associé à 5) → chercher jusqu'à l'index de 5
- Insérer 1 (associé à 8) → chercher jusqu'à l'index de 8
- Insérer 3 (associé à 9) → chercher jusqu'à l'index de 9
- Insérer 4 (associé à 7) → chercher jusqu'à l'index de 7

Résultat final : [1, 2, 3, 4, 5, 7, 8, 9]
```

### 6️⃣ Gérer l'élément impair
Si la séquence initiale a un nombre impair d'éléments, le dernier élément est mis de côté et inséré à la fin avec recherche binaire complète.

---

## 🔍 Exemple complet pas à pas

Trions `[5, 2, 8, 1, 9, 3, 7, 4]`

### Niveau 1 (Appel principal)
```
Entrée : [5, 2, 8, 1, 9, 3, 7, 4]

1. Paires : [(5,2), (8,1), (9,3), (7,4)]
2. Tri local : [(2,5), (1,8), (3,9), (4,7)]
3. Extraction max : [5, 8, 9, 7]
4. RÉCURSION → trier [5, 8, 9, 7]
```

### Niveau 2 (Appel récursif sur [5, 8, 9, 7])
```
Entrée : [5, 8, 9, 7]

1. Paires : [(5,8), (9,7)]
2. Tri local : [(5,8), (7,9)]
3. Extraction max : [8, 9]
4. RÉCURSION → trier [8, 9]
```

### Niveau 3 (Appel récursif sur [8, 9])
```
Entrée : [8, 9]

1. Paires : [(8,9)]
2. Tri local : [(8,9)]
3. Extraction max : [9]
4. RÉCURSION → trier [9]
```

### Niveau 4 (Cas de base)
```
Entrée : [9]
→ Un seul élément, déjà trié !
RETOUR : [9]
```

### Remontée niveau 3
```
Max triés : [9]
Insertion des min : [8]
→ Insérer 8 avant 9
RETOUR : [8, 9]
```

### Remontée niveau 2
```
Max triés : [8, 9]
Insertion des min : [5, 7]
→ Insérer 5 (associé à 8) → [5, 8, 9]
→ Insérer 7 (associé à 9) → [5, 7, 8, 9]
RETOUR : [5, 7, 8, 9]
```

### Remontée niveau 1 (final)
```
Max triés : [5, 7, 8, 9]
Insertion des min : [2, 1, 3, 4]
→ Insérer 2 (associé à 5) → [2, 5, 7, 8, 9]
→ Insérer 1 (associé à 8) → [1, 2, 5, 7, 8, 9]
→ Insérer 3 (associé à 9) → [1, 2, 3, 5, 7, 8, 9]
→ Insérer 4 (associé à 7) → [1, 2, 3, 4, 5, 7, 8, 9]
RÉSULTAT FINAL : [1, 2, 3, 4, 5, 7, 8, 9]
```

---

## 💡 Pourquoi c'est efficace ?

1. **Récursion intelligente** : On réduit le problème de moitié à chaque niveau (on ne trie que les "grands")
2. **Recherche binaire** : Au lieu de comparer linéairement, on utilise O(log n) comparaisons
3. **Optimisation des comparaisons** : On limite la recherche binaire grâce à la contrainte min ≤ max
4. **Complexité** : O(n log n) avec un nombre de comparaisons proche du minimum théorique

---

## 📊 Comparaison vector vs deque

Le programme compare les performances de deux conteneurs STL :

- **std::vector** : Conteneur contigu en mémoire, accès rapide par index
- **std::deque** : "Double-ended queue", permet insertion rapide en début et fin

Les temps varient selon la taille de la séquence et les opérations d'insertion.

---

## 🚀 Utilisation

```bash
# Compiler
make

# Exemples
./PmergeMe 3 5 9 7 4
./PmergeMe $(seq 1 100 | sort -R | tr '\n' ' ')
./PmergeMe $(seq 1 3000 | sort -R | tr '\n' ' ')

# Erreur si nombre négatif
./PmergeMe 3 -5 7
```

---

## 📁 Structure du code

### [PmergeMe.hpp](PmergeMe.hpp)
- Déclarations des fonctions
- Inclusions des headers nécessaires

### [PmergeMe.cpp](PmergeMe.cpp)
- `parseNumbers()` : Parse et valide les arguments
- `formPairs()` : Forme les paires d'éléments
- `sortPairs()` : Trie chaque paire localement
- `extractMax()` / `extractMin()` : Extrait les grands/petits
- `mergeInsertSort()` : **Cœur de l'algorithme récursif**
- `insertMin()` : Insère les petits avec recherche binaire optimisée
- `binaryInsert()` : Insertion binaire limitée
- `findIndex()` : Trouve la position d'un élément

### [main.cpp](main.cpp)
- Gestion des entrées/sorties
- Mesure du temps d'exécution (en microsecondes)
- Comparaison vector vs deque

---

## ✅ Testé avec

- ✓ 5 éléments
- ✓ 10 éléments
- ✓ 100 éléments
- ✓ 3000 éléments
- ✓ Gestion d'erreurs (nombres négatifs, entrées invalides)
- ✓ Nombre impair d'éléments
- ✓ Compatible C++98

---

## 🎓 Points clés à retenir

1. **C'est un algorithme RÉCURSIF** : `mergeInsertSort()` s'appelle lui-même
2. **La recherche binaire est optimisée** : On limite jusqu'à la position du "grand" associé
3. **L'insertion est la clé** : Contrairement au tri fusion classique, on insère intelligemment
4. **Templates C++** : Le même code fonctionne pour vector et deque
5. **Mesure précise** : On utilise `gettimeofday()` pour des microsecondes

---

**Auteur** : PmergeMe - Exercice cpp09
**Date** : 2026
**Norme** : C++98
