Vlad Ioana Gabriela, grupa 132
GitHub: https://github.com/ioanavlad3/game-Adopt-an-animal-

Proiect "Adapost de animale"
La adapost vin vizitatori care doresc sa isi gaseasca un animal de companie. 
Ei au anumite criterii pentru animalul lor:
ce animal sa fie (caine, pisica), rasa lui, varsta si caracteristici ale 
animalului (prietenos, cuminte, etc).
Daca s-a gasit o compatibilitate, vizitatorul poate sa se joace putin cu animalul respectiv:
trebuie sa parcurga o matrice fara sa intre in coliziuni si sa nu se scurga tot timpul.  
Daca s-a realizat jocul cu succes, atunci il poate lua acasa.

Clase:
    Animal:
        Dog:
            Golden Retriever, Bichon, Pooddle, Bulldog
        Cat:
			Sfinx, Siamese, Persian
    Game
    Button
    AnimalException:
	    SpeciesNotFoundException, InvalidAgeException, EmptyNameException

Animal:
	    Am creat functii virtuale pure pentru a afisa sunetul animalului, care va fi suprascris
	in clasele derivate., iar alte functii virtuale pentru a afisa caracteristicile
	animalului, care vor fi suprascrise in clasele derivate.

	Dog, Cat:
	M-am folosit de mostenire pentru a crea clasele derivate.
	M-am folosit de supraincarcarea functiilor pentru a crea constructori:
		Am creat un constructor care primeste numele, varsta si dimensiunea animalului.
		Am creat un constructor care primeste numele, varsta, dimensiunea si caracteristicile
		animalului.
		Am creat o functie care returneaza dimensiunea animalului in functie de rasa.
        Am creat o functie care se ajuta de clasele pentru tratarea erorilor , 
	pentru a crea un animal in siguranta (cu nume si varste corecte).
    
    clase derivate din Dog:
			Golden Retriever, Bichon, Poodle, Bulldog
            Am suprascris functia makesound() pentru a afisa un sunet diferit fiecarui animal.
    clase derivate din Cat:
			Sfinx, Siamese, Persian

Button:
	Am creat o clasa care contine un buton, cu functii pentru a-l desena si a verifica
	daca a fost apasat. 
	Am creat un constructor care primeste textul butonului, coordonatele si dimensiunea
	butonului.

Game:
	Am creat o clasa care contine un vector de animale, un vector de caini, un vector de pisici.
	Am creat functii pentru a adauga animale, a afisa animalele, a afisa rasele 
    de caini si pisici.
	Am creat functii pentru a afisa sunetul animalului, a afisa caracteristicile sale
	Am creat o functie addAnimal care adauga un animal in functie de tipul lui 
	(caine sau pisica), ajutandu-ma de dynamic_cast.
	Am creat o functie care afiseaza animalele in functie de rasa lor, afiseaza 
caracteristicile fiecarui animal, iar daca este apasat un buton, se va afisa animalul
	corespunzator rasei respective.


Bibliografie:

Pentru instalarea librariei Raylib si pentru a-i intelege bazele:
https://www.youtube.com/watch?v=RGzj-PF7D74&list=PLwR6ZGPvjVOTIMqUXnqyWaIfQg0xdHNZn&ab_channel=ProgrammingWithNick

Pentru a include butoane in proiect m-am ajutat de acest tutorial:
https://www.youtube.com/watch?v=0Ct9ZWEUm7M&list=PLwR6ZGPvjVOTIMqUXnqyWaIfQg0xdHNZn&index=10&ab_channel=ProgrammingWithNick

De aici m-am inspirat cum sa accesez diferite ferestre ale proiectului:
https://www.tutorialspoint.com/cplusplus/cpp_enumeration.htm


De aici m-am inspirat cum sa misc in camera un obiect:
https://www.reddit.com/r/raylib/comments/1hs4pg7/trying_to_add_camera_tracking_that_moves_with_the


Pentru a insera un text:
https://www.raylib.com/examples/text/loader.html?name=text_input_box 
