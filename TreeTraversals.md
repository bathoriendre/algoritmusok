# Fa bejárások

Három általános módja van a bináris fa csomópontjainak bejárásának:

	Preorder: Először dolgozza fel a gyökeret, majd a bal oldali részfát, végül a jobb oldali részfát.
	Inorder: Először a bal oldali részfát dolgozzuk fel, majd a gyökeret, végül a jobb oldali részfát.
	Postorder: Először a bal oldali részfát dolgozzuk fel, majd a jobb oldali részfát, végül a gyökeret.

Van egy n csomópontból álló bináris fa, külön címkével. Megkapjuk a fa preorder és inorder bejárását, és a feladatunk, hogy meghatározza a fa postorder bejárását.

## Input

Az első bemeneti sorban van egy n egész szám: a csomópontok száma. A csomópontok számozása 1,2, ... ,n.

Ezt követően két sor írja le a fa preorder és inorder bejárását. Mindkét sor n egész számból áll.

Feltételezheti, hogy a bemenet egy bináris fának felel meg.

## Output

Írjuk ki a fa postorder bejárását.

## Megszorítások

1 <= n <= 10^5

## Példa bemenet

5
5 3 2 1 4
3 5 1 2 4

## Példa kimenet

3 1 4 2 5

## Feladat helye

https://cses.fi/problemset/task/1702