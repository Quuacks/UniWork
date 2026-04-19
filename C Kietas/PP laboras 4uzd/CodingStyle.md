# Kodavimo stiliaus gaires
1. Kintamieji: is mazosios raides kitas zodis is didziosios
gerai:
int studentuKiekis;
Element *firstElement;
blogai:
int studendu_Kiekis;
Element *first_element;
2. Strukturos: pirma raide didzioji kitos likusios mazosios
gerau:
typedef struct Element {...} Element;
blogai:
typdef struct element_type {...} element_type;
3. Funkciju pavadinimai: pirmas zodis is mazosios raides kiti is didziosios
gerai:
void saveToFile();
blogai:
void Save_To_File();
void save_to_file();
4. Konstantos: Pavadinimas vien didziosios raides
#define FILE_NAME = "duom.txt"

## Kodo isdestymas
1. gerai:
if(a == 1){
    sitas();
}
else{
    kazkas();
}
blogai:
if(a == 1)
{
    sitas();
}
else
{
    kazkas();
}
2. Operatoriai atskirti tarpais
a = b + c;
blogai:
a=b+c;