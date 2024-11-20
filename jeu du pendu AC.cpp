/*  Salut!!!
* 
* Langage C++.
* 
* Ce programme est une version du "jeu du pendu" en Affichage console. 
* C'est un jeu ou un 1ere joueur va donner un mot le le 2eme va essaye de le deviner.
* S'il reussit a deviner le mot mystere il gagne. Dans le cas contraire il perd.
* 
* Le lien vers le projet github est en description.
* 
* let's play.
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
char to_lower(char* chaine);
int longueur(const char* chaine);
void draw_pendu(int erreurs);

int main(int argc, char** argv)
{
	char lettre;
	int erreurs = 0;
	int lim_erreurs = 6;
	bool gagne = false;
	std::vector <char> carac_try;
	std::string message = "     JEU DU PENDU A.C.     ";
	for (char lettre : message) {
		std::cout << lettre;
		usleep(100000);
	}
	std::cout << std::endl;
	char mot[20];
	std::cout << "joueur A: veuillez proposer le mot a deviner: ";
	std::cin >> mot;
	char* ch = mot;
	system("CLS");
	*ch = to_lower(ch);
	std::string mot_d;
	int l_ong = 0;
	l_ong = longueur(mot);
	mot_d.resize(l_ong, '_');
	while (erreurs < lim_erreurs && !gagne) {
		std::cout << "\nMot a deviner : " << mot_d << std::endl;
		draw_pendu(erreurs);
		std::cout << "\nLes lettres deja essayees : ";
		for (char l : carac_try) {
			std::cout << l << " ";
		}
		std::cout << std::endl;
		std::cout << "\nDeviner une lettre du mot : ";
		std::cin >> lettre;
		if (lettre == '1') {
			break;
		}
		char* ch1 = &lettre;
		*ch1 = to_lower(ch1);
		bool carac_d_try = false;
		for (char l : carac_try) {
			if (l == lettre) {
				carac_d_try = true;
				break;
			}
		}
		if (carac_d_try) {
			std::cout << "Cette lettre a deja ete essayee " << std::endl;
			continue;
		}
		carac_try.push_back(lettre);
		bool trouve_carac = false;
		for (int i = 0; i < l_ong; i++) {
			if (mot[i] == lettre) {
				mot_d[i] = lettre;
				trouve_carac = true;
			}
		}if (!trouve_carac) {
			erreurs++;
			std::cout << "Lettre incorecte " << std::endl;
		}
		if (mot_d == mot) {
			gagne = true;
		}
	}
	if (gagne) {
		system("CLS");
		std::cout << "\nVous avez gagne. le mot a deviner etait : " << mot << std::endl;
		draw_pendu(erreurs);
	}
	else {
		system("CLS");
		std::cout << "Vous avez perdu. Le mot a deviner etait : " << mot << std::endl;
		draw_pendu(erreurs);
	}
	return 0;
}

int longueur(const char* chaine) {
	int l = 0;
	while (*chaine != '\0') {
		l++;
		chaine++;
	}
		return l;
}
void draw_pendu(int erreurs) {
	std::cout << "   +------+" << std::endl;
	std::cout << "   |      |" << std::endl;
	if (erreurs >= 1) {
		std::cout << "   O      |" << std::endl;
	}
	else {
		std::cout << "          |" << std::endl;
	}
	if (erreurs >= 2) {
		std::cout << "   |      |" << std::endl;
	}
	else {
		std::cout << "          |" << std::endl;
	}
	if (erreurs >= 3) {
		std::cout << "  /|))    |" << std::endl;
	}
	else {
		std::cout << "          |" << std::endl;
	}
	if (erreurs >= 4) {
		std::cout << "   |      |" << std::endl;
	}
	else {
		std::cout << "          |" << std::endl;
	}
	if (erreurs >= 5) {
		std::cout << "  / ))    |" << std::endl;
	}
	else {
		std::cout << "          |" << std::endl;
	}
	if (erreurs >= 6) {
		std::cout << " pendu!!! |" << std::endl;
	}
	else {
		std::cout << "          |" << std::endl;
	}
	std::cout << "===========" << std::endl;
}
char to_lower(char* chaine) {
	int l = 0;
	l = longueur(chaine);
	for (int i = 0; i < l; i++) {
		if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
			chaine[i] = chaine[i] + ('a' - 'A');
		}
	}
	return *chaine;
}