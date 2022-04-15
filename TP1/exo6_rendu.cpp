#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    Noeud* dernier;
};

struct DynaTableau{
    int* donnees;
    int capacite;
    int nb_valeurs = 0;
};



//fonctions sur DynaTableau
void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->nb_valeurs < tableau->capacite){
        tableau->donnees[tableau->nb_valeurs] = valeur;
        tableau->nb_valeurs ++;
    }
    else{
        //correction
        tableau->capacite++;
        int* newDonnee = (int*)realloc(tableau->donnees, tableau->capacite*sizeof(int));
        tableau->donnees = newDonnee;
        tableau->donnees[tableau->nb_valeurs] = valeur;
        tableau->nb_valeurs ++;
    }
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->capacite = capacite;
    tableau->donnees = (int*)malloc(sizeof(int)*tableau->capacite);
}

bool est_vide(const DynaTableau* liste)
{   
    if(liste->nb_valeurs !=0){
        return false;
    }
    return true;
}

void affiche(const DynaTableau* tableau)
{
    cout << "[ "; 
    for(int i=0; i<tableau->nb_valeurs; i++){
        if(i!= tableau->nb_valeurs-1){
            cout << tableau->donnees[i] << ", ";
        }
        else{
            cout << tableau->donnees[i];
        }
        
    }
    cout << " ]" << endl;
}

int recupere(const DynaTableau* tableau, int n)
{
    return tableau->donnees[n];
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i=0; i<tableau->nb_valeurs; i++){
        if(tableau->donnees[i]==valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n]= valeur;
}

void pousser_file(DynaTableau* liste, int valeur){
    //pareil que la fonction ajoute
    if(liste->nb_valeurs < liste->capacite){
        liste->donnees[liste->nb_valeurs] = valeur;
        liste->nb_valeurs ++;
    }
    else{
        liste->donnees = (int*)malloc(sizeof(int));
    }
}

int retirer_file(DynaTableau* liste){
    if(liste->nb_valeurs == 0){
        return -1;
    }
    int res = liste->donnees[0];
    for(int i=0; i<liste->nb_valeurs; i++){
        if(i==liste->nb_valeurs-1){
            liste->nb_valeurs --;
        }
        else{
            liste->donnees[i] = liste->donnees[i+1];
        }
    }
    return res;
}


void pousser_pile(DynaTableau* liste, int valeur){
    // ajoute au début de la structure

    if(liste->nb_valeurs < liste->capacite){
        liste->nb_valeurs ++;
        for(int i=liste->nb_valeurs-2; i>=0; i--){
            if(i==0){
                liste->donnees[i+1] = liste->donnees[i];
                liste->donnees[i] = valeur;
            }
            else{
                liste->donnees[i+1] = liste->donnees[i];
            }
        }
    }
    else{
        liste->donnees = (int*)malloc(sizeof(int));
    }
   
}


int retirer_pile(DynaTableau* liste){
    int res = liste->donnees[liste->nb_valeurs-1];
    liste->nb_valeurs --;
    return res;
}





//fonctions sur Liste
void initialise(Liste* liste)
{
    //correction
    liste->premier = NULL;
    liste->dernier = NULL;


}

bool est_vide(const Liste* liste)
{
    if(liste->premier == NULL){
        
        return true;
    }
    return false;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* nd = new Noeud();
    nd->donnee = valeur;
    nd->suivant = NULL;

    
    if(liste->premier ==NULL){
        liste->premier = nd;
        liste->dernier = liste->premier;
    }
    else{
        liste->dernier->suivant = nd;
        liste->dernier = nd;
    }
    
}

void affiche(const Liste* liste)
{
    Noeud* copie = liste->premier; //pour pouvoir parcourir la liste sans la modifier
    while(copie!= NULL){
        cout << copie->donnee << endl;
        copie = copie->suivant;
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud* copie = liste->premier;
    
    for(int i=0; i<n; i++){
        copie = copie->suivant;
    }
    return copie->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* copie = liste->premier;
    int indice = 0;

    while(copie!=NULL){
        if(copie->donnee == valeur){
            return indice;
        }
        else{
            copie = copie->suivant;
            indice++;
            
        }
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* copie = liste->premier;
    for(int i=0; i<n; i++){
        copie = copie->suivant;
    }
    copie->donnee = valeur;
}


void pousser_file(Liste* liste, int valeur)
{
    //meme fonction que ajoute
    Noeud* nd = new Noeud();
    nd->donnee = valeur;
    nd->suivant = NULL;

    
    if(liste->premier ==NULL){
        liste->premier = nd;
        liste->dernier = liste->premier;
    }
    else{
        liste->dernier->suivant = nd;
        liste->dernier = nd;
    }
}

int retirer_file(Liste* liste){
    int res = liste->premier->donnee;
    liste->premier = liste->premier->suivant;
    return res;

}

void pousser_pile(Liste* liste, int valeur)
{
    Noeud* tete = new Noeud();
    tete->donnee = valeur;
    tete->suivant = liste->premier;

    liste->premier = tete;
    
}

int retirer_pile(Liste* liste){
    Noeud* copie = liste->premier;
    Noeud* copie_der = liste->dernier;
    int res = liste->dernier->donnee;
    while(copie->suivant != copie_der){
        copie= copie->suivant;
    }
    copie->suivant = NULL;

    return res;
}





int main(){

    //utilisation fonctions initialise, ajoute et affiche
    DynaTableau Dy_Tab; 
    initialise(&Dy_Tab,20);
    ajoute(&Dy_Tab, 5);
    ajoute(&Dy_Tab, 8);
    ajoute(&Dy_Tab, 17);
    cout << "La liste : " << endl;
    affiche(&Dy_Tab);

    cout << '\n'; 

    //fonction recupere et cherche
    cout << "Valeur recuperee : " << recupere(&Dy_Tab, 1) << endl;
    cout << "Indice de la valeur cherchee : " << cherche(&Dy_Tab, 8) << endl;

    cout << '\n'; 

    //utilisation fonction stocke
    int val_stock = 12;
    int indice_stock = 0;
    stocke(&Dy_Tab,indice_stock,val_stock);
    cout << "Fonction stocke : " << endl;
    affiche(&Dy_Tab);

    cout << '\n'; 

    //retirer et pousser (file ou pile)
    cout << "pousser pile : "; 
    pousser_pile(&Dy_Tab,7);
    affiche(&Dy_Tab);

    cout << "retirer pile : " << retirer_pile(&Dy_Tab)<< endl;
    affiche(&Dy_Tab);

    cout << "retirer file: " << retirer_file(&Dy_Tab)<< endl;
    affiche(&Dy_Tab);

    cout << "pousser file : ";
    pousser_file(&Dy_Tab, 152);
    affiche(&Dy_Tab);

    cout << '\n'; 
    cout << '\n'; 

    Liste lst;
    initialise(&lst);
   
    ajoute(&lst, 5);
    ajoute(&lst,6);
    ajoute(&lst,7);
    cout << "La liste de base: " << endl;
    affiche(&lst);

    pousser_pile(&lst, 10);
    cout << "La liste avec une nouvelle valeur au début: " << endl;
    affiche(&lst);

    retirer_file(&lst);
    cout << "La liste sans la 1ere valeur: " << endl;
    affiche(&lst);

    retirer_pile(&lst);
    cout << "La liste sans la derniere valeur: " << endl;
    affiche(&lst);


    //est_vide
    if(est_vide(&lst)==1){
        cout << "La liste est vide" << endl;
    }
    else{
        cout<< "La liste n'est pas vide" <<endl;
    }

    int recup = recupere(&lst, 2);
    cout << "Voici la valeur souhaitée : " << recup << endl;
    int find = cherche(&lst, 7);
    cout << "L'index vaut : " << find << endl;

    stocke(&lst, 2, 158);
    cout << "La liste modifiée: " << endl;
    affiche(&lst);
    
    
    return 0;
}