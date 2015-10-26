/*
 * Main.cc
 *
 *  Created on: 2 de out de 2015
 *      Author: lfnogoseke
 */
#include <iostream>
#include <string>
#include <strings.h>
#include "simplexTypes.h"
using namespace std;

int main(){
	/*cout << "Tipo do problema: Max ou Min?" << endl;
	string type="";
	while(type.compare("Max")!=0 || type.compare("max")!=0){
		getline(cin, type);
		cout<<type;
	}

	cout << "Numero de variaveis: ";
	int vars=0;
	while(vars <1 || vars%1!=0 )
		cin >> vars;
   */
	SimplexModel model;

	std::cout << model.solve() << std::endl;

	return 0;
}



