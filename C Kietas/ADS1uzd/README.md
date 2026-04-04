# Eilės (Queue) realizacija C kalba

## Aprašymas

Šiame projekte realizuota **eilės (Queue)** duomenų struktūra C
programavimo kalba, naudojant **vienkryptį susietą sąrašą**.

Eilė veikia pagal **FIFO principą (First In, First Out)** -- pirmas
įdėtas elementas yra pirmas pašalinamas.

Projektas leidžia: - inicializuoti eilę - pridėti elementą į eilės
galą - pašalinti elementą iš eilės pradžios - gauti pirmą arba paskutinį
elementą - patikrinti ar eilė tuščia - gauti eilės dydį

Paleisti programą galima su Makefile arba cmd failu.

# Duomenų struktūros

## Element

Struktūra, aprašanti vieną eilės elementą.

    typedef struct Element{
        int data;
        struct Element *nextElement;
    } Element;

Laukai:

-   **data** -- saugoma sveiko skaičiaus reikšmė
-   **nextElement** -- rodyklė į kitą eilės elementą

------------------------------------------------------------------------

## Queue

Struktūra, aprašanti pačią eilę.

    typedef struct Queue{
        Element *head;
        Element *tail;
        size_t size;
    } Queue;

Laukai:

-   **head** -- rodyklė į pirmą eilės elementą
-   **tail** -- rodyklė į paskutinį eilės elementą
-   **size** -- elementų skaičius eilėje

------------------------------------------------------------------------

# Funkcijos

## initQueue

Inicializuoja eilę.

    void initQueue(Queue *queue);

Nustato: - `head = NULL` - `tail = NULL` - `size = 0`

------------------------------------------------------------------------

## enqueue

Prideda naują elementą į eilės galą.

    int enqueue(Queue *queue, int value);

Grąžina:

-   `1` -- jei elementas sėkmingai pridėtas
-   `0` -- jei nepavyko skirti atminties

------------------------------------------------------------------------

## dequeue

Pašalina pirmą eilės elementą.

    int dequeue(Queue *queue, int *out);

Parametrai:

-   **out** -- kintamasis, į kurį įrašoma pašalinto elemento reikšmė

Grąžina:

-   `1` -- jei operacija sėkminga
-   `0` -- jei eilė tuščia

------------------------------------------------------------------------

## getFront

Grąžina rodyklę į pirmą eilės elementą.

    Element* getFront(Queue *queue);

------------------------------------------------------------------------

## getRear

Grąžina rodyklę į paskutinį eilės elementą.

    Element* getRear(Queue *queue);

------------------------------------------------------------------------

## isEmpty

Patikrina ar eilė tuščia.

    int isEmpty(Queue *queue);

Grąžina:

-   `1` -- eilė tuščia
-   `0` -- eilė turi elementų

------------------------------------------------------------------------

## queueSize

Grąžina elementų skaičių eilėje.

    size_t queueSize(Queue *queue);

------------------------------------------------------------------------