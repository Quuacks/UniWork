# Kuprinės (Knapsack) Programa (C)

## Aprašymas

Ši programa nuskaito duomenis iš failo ir apskaičiuoja didžiausią galimą vertę (`kaina`), neviršijant leidžiamo svorio (`svoris`).

---

## Failai

* `main.c` – pagrindinis programos kodas
* `Makefile` – kompiliavimo instrukcijos (Linux / standartinė aplinka)
* `.cmd` failas – paleidimo skriptas Windows sistemai
* `test.exe` – sukompiliuota programa (po build)

---

## Įvesties formato reikalavimai

Programa tikisi tekstinio failo su tokia struktūra:

### 1 variantas (su elementų skaičiumi):

```
n S
svoris1 kaina1
svoris2 kaina2
...
```

* `n` – daiktų skaičius
* `S` – maksimalus leistinas svoris
* Kiekviena eilutė: `svoris` ir `kaina`

---

## Kompiliavimas ir paleidimas

### 🔹 Windows (naudojant `.cmd` failą)

Tiesiog paleiskite:

```
build.cmd
```

### 🔹 Rankiniu būdu su Makefile

```
make
./test.exe
```

---

## Programos naudojimas

Paleidus programą:

```
File name:
```

Įveskite duomenų failo pavadinimą (pvz., `data.txt`)

Rezultatas:

```
Max kaina: <reikšmė>
```

---

## Pastabos

* Naudojama dinaminė atmintis (`calloc`, `realloc`)
* Algoritmo sudėtingumas: **O(n × S)**
* Įsitikinkite, kad failas egzistuoja ir formatas teisingas

---

## Pavyzdys

Įvesties failas (`data.txt`):

```
3 50
10 60
20 100
30 120
```

Rezultatas:

```
Max kaina: 220
```

---

## Autorius

Armantas Stanevicius 
