/** @file TREE.cpp */
#include <iostream>
using namespace std;

//! Funkcija, kotoraja sovershaet obhod dereva v prjamom porjadke.
/**
	@param node - uzel
	@param n - kolichetvo uzlov
	@param *pTr_one - ukazatel' na nachalo massiva uzlov
**/
void Direct_order(int node, int n, int *pTr_one) 
{
	cout << node + 1 << " ";
	
	int *Tr_two = new int [n];	
	for (int i = 0; i < n; i++) Tr_two[i] = 0;		
	
	for (int j = 0; j < n; j++)
		if (pTr_one[j] == node + 1) Tr_two[j] = pTr_one[j];		   
		
	for (int k = 0; k < n; k++)		
		if (Tr_two[k]) Direct_order(k, n, pTr_one);	
	
	delete []Tr_two;
}

//! Funkcija, kotoraja sovershaet obhod dereva v obratnom porjadke.
/**
	@param node - uzel
	@param n - kolichetvo uzlov
	@param *pTr_one - ukazatel' na nachalo massiva uzlov
**/
void inDirect_order(int node, int n, int *pTr_one)
{
	int *Tr_three = new int [n];
	for (int i = 0; i < n; i++) Tr_three[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr_one[j] == node + 1) Tr_three[j] = pTr_one[j];		 
	
	for (int k = 0; k < n; k++)		
		if (Tr_three[k]) inDirect_order(k, n, pTr_one);

	cout << node + 1 << " ";
	
	delete []Tr_three;
}

//! Funkcija, kotoraja sovershaet obhod dereva v simmetrichnom porjadke.
/**
	@param node - uzel
	@param n - kolichetvo uzlov
	@param *pTr_one - ukazatel' na nachalo massiva uzlov
**/
void Symmetric_order(int node, int n, int *pTr_one)
{
	int *Tr_four = new int [n];
	for (int i = 0; i < n; i++) Tr_four[i] = 0;	
	
	for (int j = 0; j < n; j++)
		if (pTr_one[j] == node + 1) Tr_four[j] = pTr_one[j]; 	
	
	for (int k = 0; k < n; k++)			
		if (Tr_four[k]) Symmetric_order(k, n, pTr_one);
	
	int q = 0;
	for (int z = 0; z < n; z++)		
		if (pTr_one[z] == node+1) q++;		
	
	if (q == 0) cout << node + 1 << " ";	
	if ((pTr_one[node-1] != pTr_one[node]) && (pTr_one[node]))
	cout << pTr_one[node] << " "; 
	
	delete []Tr_four;
}

//! Glavnaja funkcija.
int main()
{
	//setlocale(LC_ALL, "RUS");
	int n;
	cout << "Vvedite kolichestvo uzlov dereva: "; cin >> n; /// Vvod kolichestva uzlov
	int *Tr_one = new int [n];
	cout << "Vvedite uzly: "; /// Vvod uzlov
	for (int i = 0; i < n; i++) cin >> Tr_one[i]; 
	
	cout << "Prjamoj obhod dereva: "; /// Vyzov funkcij obhoda dereva:
	Direct_order(0, n, Tr_one); /// - Prjamoj obhod
	cout << "\nObratnyj obhod dereva: ";
	inDirect_order(0, n, Tr_one); /// - Obratnyj obhod
	cout << "\nSimmetrichnyj obhod dereva: ";
	Symmetric_order(0, n, Tr_one); /// - Simmetrichnyj obhod
	cout << endl;

	delete []Tr_one;
	system("pause");
}
